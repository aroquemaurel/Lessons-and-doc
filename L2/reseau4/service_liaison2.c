#include "service_liaison.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

trame_t remplirTrame(char* adr_src, char* adr_dest, char* msg, int lg_msg, int num_seq) {
	int i;
	trame_t trame;
	trame.deb_trame = 0;
	trame.fin_trame = 1;
 	for(i=0; i < 6 ; ++i) {
		trame.adr_src[i] = adr_src[i];
		trame.adr_dst[i] = adr_dest[i];
	}

	trame.fcs = 0;
	trame.lg_info = lg_msg;
	for(i = 0 ; i < lg_msg; ++i) {
		trame.info[i] = msg[i];
		trame.fcs ^= trame.info[i]; 
	}
	trame.fin_trame = i;
	trame.ctrl = CTRL_TRANSFERT_DONNEES;

	trame.num_seq = num_seq;
	return trame;
}
void emettre_sur_liaison(char* adr_src, char* adr_dest, char* msg, int lg_msg) {
	static char numeroTrame = 0;
	static int nbEssai = 0;
	trame_t trame;
	trame_t ack;
	
	trame = remplirTrame(adr_src, adr_dest, msg,lg_msg, numeroTrame);
	vers_canal(&trame, sizeof(trame_t)); //on envoie la trame
	depart_compteur(1,TPS_TIMER);

	switch(attendre()) {
		case RECEPTION:
			 // on a reçus qque chose 
			de_canal(&ack,sizeof(trame_t));
			nbEssai = 0;
			if(ack.num_seq == numeroTrame && ack.ctrl == 5) { // c'est le bon acquittement
				numeroTrame = (numeroTrame + 1)%2;
				arreter_compteur(1);
			} else { // sinon, on renvoie la trame
				emettre_sur_liaison(adr_src, adr_dest, msg,lg_msg);
			}
			break;
		case 1:
			 // Le compteur à claqué
			if(nbEssai >= NB_ESSAI && trame.info[0] != '\a') {
				fprintf(stderr, "Impossible d'envoyer cette trame. Erreur de connexion");
				exit(1);
			}
			// Cas de la dernière trame
			if(!(trame.info[0] == '\a' && nbEssai >= NB_ESSAI/2)) { 
				++nbEssai;
				emettre_sur_liaison(adr_src, adr_dest, msg,lg_msg);
			}
			break;
	}
}
int recevoir_de_liaison(char* adr_src, char* adr_dest,char* msg) {
	int i;
	static char numeroTrame = 0;
	unsigned char fcs = 0;
	trame_t trame;
	trame_t ack;

	trame.lg_info = 0;
	ack = trame;

	if(attendre() == RECEPTION) {
		de_canal(&trame,sizeof(trame)); 
		for(i = 0 ; i < trame.lg_info; ++i) {
			msg[i] = trame.info[i];
			fcs ^= trame.info[i]; 
		}

		ack.lg_info = 1;
		ack.num_seq = trame.num_seq;

		// Si la trame est valide et qu'on ne l'a pas déjà reçus
		if(fcs == trame.fcs && numeroTrame == trame.num_seq) {
			numeroTrame = (trame.num_seq+1) % 2;
			ack.ctrl = CTRL_ACK_POSITIF;
		} else if(fcs != trame.fcs && numeroTrame == trame.num_seq) { 
			ack.ctrl = CTRL_ACK_NEGATIF;
			trame.lg_info = 0;
		} else {// sinon on rejette la trame
			trame.lg_info = 0;
		}

		vers_canal(&ack, sizeof(trame_t));	

//		sleep(1);
//		Si c'est la dernière trame, on attend d'être sûr que l'acquittement soit
//		bien arrivé pour le renvoyer le cas échéant
		if(trame.info[0] == '\a') { 
			depart_compteur(1,TPS_TIMER*3);
			switch(attendre()) {
				case RECEPTION:
					arreter_compteur(1);
					recevoir_de_liaison(adr_src, adr_dest, msg);
					break;
				case 2:
					return trame.lg_info;
					break;
			}
		}
	}

	return trame.lg_info;
}

