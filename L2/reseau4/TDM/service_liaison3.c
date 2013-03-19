#include "service_liaison.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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

}

/*  Primitive pour notifier d’une demande de connexion */
/*  Equivalent dans le monde OSI : L_CONNECT.ind */
void recevoir_demande_connexion_liaison(char* adr_src, char* adr_dest) {

}

/*  Primitive de réponse à la demande de connexion */
/*  Equivalent dans le monde OSI : L_CONNECT.resp */
void repondre_demande_connexion_liaison(int reponse) {

}

/*  Primitive pour transférer une unité de données au sein d'une connexion */
/*  Equivalent dans le monde OSI : L_TX_DATA.req */
void emettre_sur_liaison_connectee(char* msg, int lg_msg) {

}

/*  Primitive pour récupérer une unité de données au sein d'une connexion */
/*  Equivalent dans le monde OSI : L_TX_DATA.ind */
/*  Valeur de retour : taille du message */
int recevoir_de_liaison_connectee(char* msg){
}

/*  Primitive pour mettre fin à une connexion */
/*  Equivalent dans le monde OSI : L_DISCONNECT.req */
void terminer_connexion_liaison() {

}

/*  Primitive de notification d'une fermeture de connexion */
/*  Equivalent dans le monde OSI : L_DISCONNECT.ind */
void recevoir_terminaison_connexion_liaison() {

}
