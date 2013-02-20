#include "service_liaison.h"

void emettre_sur_liaison(char* adr_src, char* adr_dest, char* msg, int lg_msg) {
	trame_t trame = initialiser_trame();
	//
	
	vers_canal(&trame, sizeof(trame_t));
}
int recevoir_de_liaison(char* adr_src, char* adr_dest,char* msg) {
	trame_t trame;
	int ev;
	int lg_donnees;
	ev = attendre();
	if(ev == RECEPTION) {
		de_canal();
		///... return lg_donnees
	}
}
trame_t initialiser_trame(void) {
	trame_t trame;
	///
	// construire la trame
	// ///
	trame_t trame;
	trame.deb_trame = 0;
	trame.fin_trame = 1;
	trame.adr_src = adr_src;
	trame.adr_dst = adr_dest;
	for(i = 0 ; i < 10 ; ++i) {
		
	}
	// for .. 
	// info
	// lg_info  
	// trame.fcs = 0;
	// XOR bit à bit entre fcs et différents octets de l'info
	for(i = 0 ; i < lg_info ; ++i) {
		trame.fcs ^= trame.info[i]; 
	}
	trame.ctrl = 4;

	return trame;
}
