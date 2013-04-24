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
	}
	for(i=0; i < 6 ; ++i) {
		trame.adr_dst[i] = adr_dest[i];
	}
	trame.lg_info = lg_msg;
	for(i = 0 ; i < lg_msg; ++i) {
		trame.info[i] = msg[i];
	}
	trame.fcs = 0;
	for(i = 0 ; i < lg_msg; ++i) {
		trame.fcs ^= trame.info[i]; 
	}
	trame.ctrl = 4;

	trame.num_seq = num_seq;
	return trame;
}
void emettre_sur_liaison(char* adr_src, char* adr_dest, char* msg, int lg_msg) {
	static int numeroTrame = 0;
	static int nbEssai=0;
	int ev;
	trame_t trame;
	trame_t ack;
	
	trame = remplirTrame(adr_src,adr_dest,msg,lg_msg, numeroTrame);
	vers_canal(&trame, sizeof(trame_t));
	depart_compteur(1,1500);
	ev = attendre();
	if(ev == RECEPTION) { // on a reçus qque chose 
		de_canal(&ack,sizeof(trame_t));
		if(ack.info[0] == numeroTrame) { // c'est le bon acquittement
			arreter_compteur(1);
			numeroTrame++;
			nbEssai = 0;
		} else if(ack.fcs != ack.info[0] ^ 0) { // Erreur de reception, on demande de renvoyer
			emettre_sur_liaison(adr_src,adr_dest,msg,lg_msg);
		}
	} else if(ev == 1) { // Le compteur à claqué
		if(nbEssai >= 15) {
			fprintf(stderr, "Erreur de connexion");
			exit(1);
		}
		++nbEssai;
		emettre_sur_liaison(adr_src,adr_dest,msg,lg_msg);
	}
}
int recevoir_de_liaison(char* adr_src, char* adr_dest,char* msg) {
	int ev, i;
	static int numeroTrame = 0;
	unsigned char fcs = 0;
	trame_t trame;
	trame_t ack;

	trame.lg_info = 0;
	ack = trame;
	ack.ctrl = 5;
	ack.fcs = 0;
 	for(i=0; i < 6 ; ++i) {
		ack.adr_src[i] = trame.adr_src[i];
	}
	for(i=0; i < 6 ; ++i) {
		ack.adr_dst[i] = trame.adr_dst[i];
	}
	ev = attendre();
	if(ev == RECEPTION) {
		de_canal(&trame,sizeof(trame)); 
		for(i = 0 ; i < trame.lg_info; ++i) {
			msg[i] = trame.info[i];
		}
		for(i = 0 ; i < trame.lg_info ; ++i) {
			fcs ^= trame.info[i]; 
		}
		ack.lg_info = 1;
		ack.info[0] = trame.num_seq;
		ack.fcs ^= ack.info[0];
		// Si la trame est valide et qu'on ne l'a pas déjà reçus
		if(fcs == trame.fcs && numeroTrame == trame.num_seq) {
			numeroTrame = trame.num_seq+1;
		} else { // sinon on rejette la trame
			trame.lg_info = 0; 
		}
		if(fcs == trame.fcs) {
			vers_canal(&ack, sizeof(trame_t));	
		}
//		sleep(1);
	}

	return trame.lg_info;
}

