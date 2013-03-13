#include "service_liaison.h"
#include <unistd.h>

void emettre_sur_liaison(char* adr_src, char* adr_dest, char* msg, int lg_msg) {
 	int i;
	int ev;
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
	
	sleep(1);
	vers_canal(&trame, sizeof(trame_t));
	depart_compteur(1,1000);
	ev = attendre();
	if(ev == 1) {
		vers_canal(&trame, sizeof(trame_t));
	}
}
int recevoir_de_liaison(char* adr_src, char* adr_dest,char* msg) {
	int ev, i;
	unsigned char fcs = 0;
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
		for(i = 0 ; i < lg_msg; ++i) {
			fcs ^= trame.info[i]; 
		}
		if(fcs == trame.fcs) {
			acquitement.lg_info = 1;
			acquitement.info[0] = trame.num_seq;
			vers_canal(&trame, sizeof(trame_t));	
		}
	}
	return trame.lg_info;
}

