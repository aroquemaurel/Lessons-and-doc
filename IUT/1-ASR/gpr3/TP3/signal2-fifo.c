/***********************************************
*  ASR => Gpr3                                 *
************************************************
*  Login : drn0073a                            *
*          smm0569a                            *
************************************************
*  Groupe: B                                   *
*                                              *
************************************************
*  Nom-prénom : de ROQUEMAUREL Antoine         *
*  Nom-prénom : SOUM Mathieu                   *
*                                              *
*                                              *
************************************************
*  TP n°: 3                                    *
************************************************
*  Nom du fichier : signal2-fifo.c             *
***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

int main(void) {
	int* pidAKill = malloc(sizeof(int));
	int descFIFO;
	
	descFIFO = open("data.FIFO", O_RDONLY);

	read(descFIFO, pidAKill, sizeof(int));

	kill(*pidAKill, SIGUSR1);

	return 0;
}

