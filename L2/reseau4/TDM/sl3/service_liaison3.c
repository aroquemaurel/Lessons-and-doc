#include "service_liaison.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
char gAdrSrc[6];
char gAdrDst[6];
int connexionEnCours=0;
trame_t remplirTrame(char* msg, int lg_msg, int num_seq) {
	int i;
	trame_t trame;
	trame.deb_trame = 0;
	trame.fin_trame = 1;
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
/*  Primitive de demande d'établissement d'une connexion */
/*  Equivalent dans le monde OSI : L_CONNECT.req et L_CONNECT.conf */
/*  Valeur de retour : réponse à la demande de connexion
 *  (1 acceptation, 0 refus) */
int etablir_connexion_liaison(char* adr_src, char* adr_dest) {
	trame_t trame;
	trame_t reception;
	trame_t ack;
	int i;
	int ev;
	static int nbEssai=0;
	trame.ctrl = 0;
	trame.deb_trame = 0;
	trame.fin_trame = 0;
	trame.num_seq = 0;
	trame.lg_info = 0;
	ack = trame;
	ack.ctrl = 5;
	

	vers_canal(&trame, sizeof(trame_t)); /* TODO si la trame se perd */
	depart_compteur(1,TPS_TIMER);
	ev = attendre();
	if(ev == RECEPTION) {
		de_canal(&reception,sizeof(trame_t)); 
		nbEssai=0;
		if(reception.ctrl == 1) {
			for(i=0; i < 6 ; ++i) {
				gAdrDst[i] = adr_dest[i];
				gAdrSrc[i] = adr_src[i];
				connexionEnCours = 1;
			}
		}
		vers_canal(&ack, sizeof(trame_t));
		arreter_compteur(1);
	} else if(ev == 1) {
		 // Le compteur à claqué
		if(nbEssai >= 15) {
			fprintf(stderr, "Impossible d'envoyer cette trame. Erreur de connexion");
			exit(1);
		}
		++nbEssai;
		return etablir_connexion_liaison(adr_src, adr_dest);
	}

	return (reception.ctrl == 1);
}

/*  Primitive pour notifier d’une demande de connexion */
/*  Equivalent dans le monde OSI : L_CONNECT.ind */
void recevoir_demande_connexion_liaison(char* adr_src, char* adr_dest) {
	trame_t trame;
	trame_t trameReponse;
	int i;
	int reponse;
	int ev, ev2;
	ev = attendre();
	if(ev == RECEPTION) {
		de_canal(&trame,sizeof(trame_t)); 
		if(trame.ctrl == 0) {
			/*  si on a pas de connexion existante ctrl = 1 sinon 2*/
			reponse = (!connexionEnCours) ? 1 : 2;
			repondre_demande_connexion_liaison(reponse);
			if(reponse == 1) {
				for(i = 0 ; i < 6 ; ++i) {
					gAdrSrc[i] = adr_src[i];
					gAdrDst[i] = adr_dest[i];
				}
			}
		}
	}
}

/*  Primitive de réponse à la demande de connexion */
/*  Equivalent dans le monde OSI : L_CONNECT.resp */
void repondre_demande_connexion_liaison(int reponse) {
	trame_t trameReponse;
	trame_t ack;
	int ev2, i;
	trameReponse.ctrl = reponse;	
	trameReponse.deb_trame = trameReponse.fin_trame = trameReponse.lg_info = 0;
	vers_canal(&trameReponse,sizeof(trame_t));
	depart_compteur(2,TPS_TIMER);
	ev2 = attendre();
	if(ev2 == RECEPTION) {
		de_canal(&ack,sizeof(trame_t)); // TODO gérer le ack
		if(reponse == 1) {
			connexionEnCours = 1;
		}
		arreter_compteur(2);
	} else if(ev2 == 2) {
		repondre_demande_connexion_liaison(reponse);
	}

}

/*  Primitive pour transférer une unité de données au sein d'une connexion */
/*  Equivalent dans le monde OSI : L_TX_DATA.req */
void emettre_sur_liaison_connectee(char* msg, int lg_msg) {
	static int numeroTrame = 0;
	static int nbEssai=0;
	int ev;
	trame_t trame;
	trame_t ack;
	
	trame = remplirTrame(msg,lg_msg, numeroTrame);
	vers_canal(&trame, sizeof(trame_t));
	depart_compteur(1,TPS_TIMER);
	ev = attendre();
	if(ev == RECEPTION) { // on a reçus qque chose 
		de_canal(&ack,sizeof(trame_t));
		if(ack.num_seq == numeroTrame) { // c'est le bon acquittement
			if(ack.ctrl == 5) { // La trame à été bien reçus
				arreter_compteur(1);
				numeroTrame++;
			} else if(ack.ctrl == 6) { //Il faut renvoyer la trame
				emettre_sur_liaison_connectee(msg,lg_msg);
			}
			nbEssai = 0;
		} 
		arreter_compteur(1);
	} else if(ev == 1) { // Le compteur à claqué
		if(nbEssai >= 15) {
			fprintf(stderr, "Impossible d'envoyer cette trame. Erreur de connexion");
			exit(1);
		}
		++nbEssai;
		emettre_sur_liaison_connectee(msg,lg_msg);
	}
}

/*  Primitive pour récupérer une unité de données au sein d'une connexion */
/*  Equivalent dans le monde OSI : L_TX_DATA.ind */
/*  Valeur de retour : taille du message */
int recevoir_de_liaison_connectee(char* msg){
	int ev, i;
	static int numeroTrame = 0;
	unsigned char fcs = 0;
	trame_t trame;
	trame_t ack;

	trame.lg_info = 0;
	ack = trame;
	ack.ctrl = 5;
	ack.fcs = 0;
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
		ack.num_seq = trame.num_seq;
		ack.fcs ^= ack.info[0];
		// Si la trame est valide et qu'on ne l'a pas déjà reçus
		if(fcs == trame.fcs && numeroTrame == trame.num_seq) {
			numeroTrame = trame.num_seq+1;
			ack.ctrl = 5;
			vers_canal(&ack, sizeof(trame_t));	
		} else if(fcs != trame.fcs && numeroTrame == trame.num_seq) { 
			ack.ctrl = 6;
			vers_canal(&ack, sizeof(trame_t));	
			trame.lg_info = 0;
		} else {// sinon on rejette la trame
			return 0; 
		}

//		sleep(1);
//		Si c'est la dernière trame, on attend d'être sûr que l'acquittement soit
//		bien arrivé pour le renvoyer le cas échéant
		if(trame.info[0] == '\a' & trame.lg_info == 1) { 
			ev = attendre();
			depart_compteur(2,TPS_TIMER);
			if(ev == RECEPTION) {
				recevoir_de_liaison_connectee(msg);
				arreter_compteur(2);
			} else if(ev == 2) {
				return trame.lg_info;
			}
		}
	}

	return trame.lg_info;
}

/*  Primitive pour mettre fin à une connexion */
/*  Equivalent dans le monde OSI : L_DISCONNECT.req */
void terminer_connexion_liaison(void) {
	trame_t trame;
	trame_t ack;
	int ev;

	trame.ctrl = 3;
	trame.deb_trame = 0;
	trame.fin_trame = 0;
	trame.num_seq = 0;
	trame.lg_info = 0;

	vers_canal(&trame, sizeof(trame_t)); 
	depart_compteur(1,TPS_TIMER);

	ev = attendre();	
	if(ev == RECEPTION) {
		de_canal(&ack,sizeof(trame_t)); 
		if(ack.ctrl == 5) {
			connexionEnCours=0;
		}
		arreter_compteur(1);
	} else if(ev == 1) {
		terminer_connexion_liaison();		
	}

}

/*  Primitive de notification d'une fermeture de connexion */
/*  Equivalent dans le monde OSI : L_DISCONNECT.ind */
void recevoir_terminaison_connexion_liaison() {
	trame_t trame;

	if(attendre() == RECEPTION) {
		de_canal(&trame,sizeof(trame_t)); 
		if(trame.ctrl == 3) {
			connexionEnCours = 0;
			envoyerAckTerminaisonConnexion();
		} else {
			recevoir_terminaison_connexion_liaison();
		}
	}

}

void envoyerAckTerminaisonConnexion() {
	trame_t ack;
	trame_t trame;

	ack.ctrl = 5; 
	ack.deb_trame = ack.fin_trame = ack.lg_info = 0;
	vers_canal(&ack, sizeof(trame_t));
	depart_compteur(1,TPS_TIMER);
	if(attendre() == RECEPTION) {
		de_canal(&trame,sizeof(trame_t)); 
		envoyerAckTerminaisonConnexion();
		arreter_compteur(1);
	} 
}
