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
*  Nom du fichier : emission.c                 *
***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main (void) {
	int erreur;
	int descFIFO;
	int tailleChaine;
	int i;
	char entreeAuClavier[256];
	char pathFile[256];

	descFIFO = open("bal.fifo", O_WRONLY);
	if (descFIFO == -1) {
		perror("echec open");
		exit(1);
	}

	while(1) {
		printf("Votre message : ");

		fgets(entreeAuClavier, 256, stdin);
		for (tailleChaine = 0 ; entreeAuClavier[tailleChaine] != '\0' ; tailleChaine++);

		write(descFIFO, entreeAuClavier, tailleChaine + 1);
	}

	close(descFIFO);

	printf("Merci!");

	return 0;
}
