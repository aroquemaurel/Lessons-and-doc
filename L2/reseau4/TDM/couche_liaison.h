#ifndef __COUCHE_LIAISON
#define __COUCHE_LIAISON
typedef struct trame_s {
	unsigned char deb_trame;
	unsigned char adr_dst[6];
	unsigned char adr_src[6];
	unsigned char ctrl;
	unsigned char num_seq;
	unsigned char lg_info;
	unsigned char info[82];
	unsigned char fcs;
	unsigned char fin_trame;
} trame_t;

#endif 
