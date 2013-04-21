#include "service_liaison.h"
#include <unistd.h>

void emettre_sur_liaison(char* adr_src, char* adr_dest, char* msg, int lg_msg) {
 	int i;
	int ev;
	static int numeroTrame = 0;
	static int premierAppel = 1;
	trame_t trame;
	trame_t ack;
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
	trame.ctrl = 4;
	
	if(premierAppel) { // c'est la première trame
		printf("Première trame ! \n");
		vers_canal(&trame, sizeof(trame_t));
		premierAppel = 0;
	} else { 
		ev = attendre();
		if(ev == RECEPTION) { // on a reçus qque chose 
			de_canal(&ack,sizeof(trame_t));
			if(ack.info[0] == numeroTrame) { // c'est le bon acquittement
				 // c'est le bon acquittement
				numeroTrame++;
				trame.num_seq = numeroTrame;
				vers_canal(&trame, sizeof(trame_t));
				printf("On peut passer à la trame suivante!\n");
			}
		}
	}
	ev = attendre();
}
int recevoir_de_liaison(char* adr_src, char* adr_dest,char* msg) {
	int ev;
	int i;
	trame_t trame;
	trame_t acquitement;
	trame.lg_info = 0;
	acquitement = trame;
	acquitement.ctrl = 5;
 	for(i=0; i < 6 ; ++i) {
		acquitement.adr_src[i] = trame.adr_src[i];
	}
	for(i=0; i < 6 ; ++i) {
		acquitement.adr_dst[i] = trame.adr_dst[i];
	}
	ev = attendre();
	if(ev == RECEPTION) {
		de_canal(&trame,sizeof(trame));
		for(i = 0 ; i < trame.lg_info; ++i) {
			msg[i] = trame.info[i];
		}
		acquitement.lg_info = 1;
		acquitement.info[0] = trame.num_seq;
		sleep(1);
		vers_canal(&acquitement, sizeof(trame_t));	
					
	}
	return trame.lg_info;
}

