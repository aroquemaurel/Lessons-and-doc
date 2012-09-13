/*************************************************
  *  ASR => Gpr3                                 *
  ************************************************
  *  Login : drn0073a                            *
  *                                              *
  ************************************************
  *  Groupe: B                                   *
  *                                              *
  ************************************************
  *  Nom-prénom : de ROQUEMAUREL Antoine		 *
  *  Nom-prénom : SOUM Mathieu                   *
  *                                              *
  *                                              *
  ************************************************
  *  TP n: 1                                    *
  ************************************************
  *  Nom du fichier : proc2.c                    *
  ***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define OK      0
#define PAS_OK -1

int main(int argc, char *argv[]) { 
	pid_t idFils1, idFils2, pidPere, idProcRetour;
	int rapport, numSig, statut, err1, err2;
	char* argP2fils2[] = { "main", "42", NULL };

	pidPere = getpid();

	system("date");
	system("echo Le login est $\$$USER et l UID $\$$UID\n");
	system("echo --------------------------------------------\n");
	printf("\n\n");

	idFils1 = fork(); // On créer le premier fils
	if (pidPere == getpid()) { // Si c'est le père, on créé un deuxième fils!
		idFils2 = fork(); 
	}

	switch ( idFils1 ) {
		case PAS_OK :
			perror("Erreur de lancement du processus fils1");
			exit(1);
			break;
		case OK :
			err1 = execl("p2fils1", "main", "une super chaine de caracteres", NULL);
			if (err1 == -1) {
				perror("Erreur au niveau du execl");exit(2);
			}
			break;
	}
	switch ( idFils2 ) {
		case PAS_OK:
			perror("Erreur de lancement du processus fils2");
			exit(1);
			break;
		case OK :
			err2 = execvp("p2fils2", argP2fils2);
			if (err2 == -1) {
				perror("Erreur au niveau du execvp");exit(2);
			}
			break;
	}
	
	idProcRetour = wait($\&$rapport);
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
