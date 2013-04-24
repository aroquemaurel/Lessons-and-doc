#include "service_liaison.h"

void emettre_sur_liaison(char* adr_src, char* adr_dest, char* msg, int lg_msg) {
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
	trame.ctrl = 4;

	vers_canal(&trame, sizeof(trame_t));
}
int recevoir_de_liaison(char* adr_src, char* adr_dest,char* msg) {
	trame_t trame;
	trame.lg_info = 0;
	int ev;
	int i;
	ev = attendre();
	if(ev == RECEPTION) {
		de_canal(&trame,sizeof(trame));
		for(i = 0 ; i < trame.lg_info; ++i) {
			msg[i] = trame.info[i];
		}
	}
	return trame.lg_info;
}

