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
*  Nom du fichier : reception.c                *
***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>

int main (void) {
	int erreur;
	int descFIFO;
	char chaineLue[256];
	int position;

	unlink("bal.fifo");

	system("echo Login : $USER");
	system("echo UID : $UID");
	system("date");
	
	erreur = mkfifo("bal.fifo", 0622);
	if (erreur == -1) {
		perror("echec mkfifo");
		exit(1);
	}

	while (1) {
		descFIFO = open("bal.fifo", O_RDONLY);
		if (descFIFO == -1) {
			perror("echec open");
			exit(1);
		}

		read(descFIFO, chaineLue, PIPE_BUF);

		printf("Message : %s", chaineLue);
		close(descFIFO);
	}

	return 0;
}

