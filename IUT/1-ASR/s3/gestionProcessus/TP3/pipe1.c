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
*  Nom du fichier : pipe.c                     *
***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>

#define OK 0
#define PAS_OK -1

void traitementFils (void);

int main(int argc, char *argv[]) { 
	pid_t pidFils1, pidPere;
	int descFichier[2];
	int erreur, tailleChaine = 0;
	FILE* data;
	char entreeAuClavier[256];
	char chaineAEcrire[256];
	char* ptr;

	pidPere = getpid();

	system("date");
	system("echo Login $USER");
	system("echo UID $UID");

	erreur = pipe(descFichier);
	if (erreur == -1) {
		perror("echec pipe");
		exit(1);
	}

	ptr = fgets(entreeAuClavier, 256, stdin);
	for (tailleChaine = 0 ; entreeAuClavier[tailleChaine] != '\0' ; tailleChaine++);

	pidFils1 = fork();

	if (pidPere != getpid()) {
		switch (pidFils1) {
			case PAS_OK :
				perror("Erreur processus fils");
				exit(1);
			case OK :
				erreur = read(descFichier[0], chaineAEcrire, tailleChaine);
				data = fopen("data.txt", "w");
				fwrite(chaineAEcrire, tailleChaine, 1, data);
				erreur = fclose(data);
				if (erreur == -1)
					printf("Erreur de fermeture du fichier data.txt");
				erreur = close(descFichier[0]);
				if (erreur == -1)
					printf("Erreur de fermeture du tube -- descFichier[0]");
				exit(0);
		}
	} else {
		if (ptr == NULL)
			printf("Oh my GOOOD !!");

		write(descFichier[1], entreeAuClavier, tailleChaine);
		erreur = close(descFichier[1]);
		if (erreur == -1)
			printf("Erreur de fermeture du tube -- descFichier[1]");
	}
	
	return 0;
}
