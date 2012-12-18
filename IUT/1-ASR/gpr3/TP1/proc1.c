/*
  ________________________________________________
 |
 |     Programme: 
 |     Langage: C
 |     Auteur:
 |
 |     Fichier:
 |     Date de modification:
 |
 |_________________________________________________
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define OK 0
#define PAS_OK -1

void traitement_fils1(void);
void traitement_fils2(void);

int main(int argc, char *argv[]) { 
	pid_t pidFils1, pidFils2, pidPere, idProcRetour;
	int rapport, numSig, statut;

	pidPere = getpid();

	system("date");
	system("echo Login $USER");
	system("echo UID $UID");

	pidFils1 = fork();
	if (pidFils1 != getpid()) {
		pidFils2 = fork();
		switch ( pidFils1 ) {
			case PAS_OK :
				perror("cacamou");
				exit(1);
				break;
			case OK :
				traitement_fils1();
				break;
		}
		if (pidFils2 != getpid()) {
			switch ( pidFils2 ) {
				case PAS_OK:
					perror("cacamou 2");
					exit(1);
					break;
				case OK :
					traitement_fils2();
					break;
			}
		}
	}
	
	idProcRetour = wait(&rapport);

	while (idProcRetour != -1) {
		numSig = rapport & 0x7F;

		switch (numSig) {
			case 0 :
				statut = (rapport >> 8) & 0xFF;
				printf("fin normale du PID fils=%d, statut=%d\n", idProcRetour, statut);
				break;
			default:
				printf("fin anormale du PID fils=%d, numéro du signal=%d\n", idProcRetour, numSig);
				break;
		}
		idProcRetour = wait(&rapport); 
	}

	return 0;
}

void traitement_fils1(void) {
	exit(3);
}

void traitement_fils2(void) {
	int* ptr = NULL;

	*ptr = 42;
	exit(OK);
}

