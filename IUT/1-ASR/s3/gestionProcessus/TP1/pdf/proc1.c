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
*
************************************************
*  TP n 1                                    *
************************************************
*  Nom du fichier : proc1.c                    *
***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define OK 0
#define PAS_OK -1

void traitement_fils1(void);
void traitement_fils2(void);

int main(int argc, char *argv[]) { 
	pid_t idFils1, idFils2, pidPere, idProcRetour;
	int rapport, numSig, statut;

	pidPere = getpid();

	system("date");
	system("echo Le login est $\$$USER\n");
	printf("L'IUD est %d\n", getuid());
	printf("--------------------------------------------\n\n\n");

	idFils1 = fork(); // On créer le premier fils
	if (pidPere == getpid())  // Si c'est le père, on créé un deuxième fils!
		idFils2 = fork(); 

	switch ( idFils1 ) {
		case PAS_OK :
			perror("Erreur de lancement du processus fils1");
			exit(1);
		case OK :
			traitement_fils1();
			break;
	}
	switch ( idFils2 ) {
		case PAS_OK:
			perror("Erreur de lancement du processus fils2");
			exit(1);
		case OK :
			traitement_fils2();
			break;
	}
	
	idProcRetour = wait(&rapport);
	// tant que le processus n'est pas arrêté
	while (idProcRetour != -1) {
		numSig = rapport & 0x7F; 

		switch (numSig) {
			case 0 :
				statut = (rapport >> 8) & 0xFF;
				printf("fin normale du PID fils=%d, statut=%d\n", idProcRetour, statut);
				break;
			default:
				printf("fin anormale fils PID=%d, numéro du signal=%d\n", idProcRetour, numSig);
				break;
		}
		idProcRetour = wait(&rapport); 
	}

	return 0;
}

// processus fils 1
void traitement_fils1(void) {
	printf("Processus fils 1. son PID est %d\n", getpid());
	exit(3);
}

// processus fils 2
void traitement_fils2(void) {
	int* ptr = NULL;
	printf("Processus fils 2. son PID est %d\n", getpid());

	*ptr = 42;
	exit(OK);
}

