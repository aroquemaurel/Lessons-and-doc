/***********************************************
*  ASR => Gpr3                                 *
************************************************
*  Login : drn0073a                            *
*                                              *
************************************************
*  Groupe: B                                   *
*                                              *
************************************************
*  Nom-prénom : de ROQUEMAUREL Antoine         *
*  Nom-prénom : SOUM Mathieu                   *
*                                              *
*                                              *
************************************************
*  TP n: 1                                    *
************************************************
*  Nom du fichier : p2fils2.c                  *
***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
	printf("Ici le processus fils 2 de PID %d !\n", getpid());
	printf("Le paramètre en décimal est %d(10) et en hexadécimal %x(16) !\n", atoi(argv[1]), atoi(argv[1]));
	exit(0);

	return 0;
}