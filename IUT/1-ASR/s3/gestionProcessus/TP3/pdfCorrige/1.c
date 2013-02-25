#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void traitFils(int tube[2]);

int main (int argc, char** argv){
	int unTube[2];
	int err;
	pid_t pidProc;
	char tampon[512];
	int statut;

	/*  processus père */
	/*  Création du tube */
	err = pipe(unTube);
	if(err = -1){
		perror("Echec pipe");
		exit(1);
	}
	/*  création du fils*/
	pidProc = fork();
	switch(pidProc){
		case -1:
			perror("fork");
			exit(1);
		case 0:
			tratFils(unTube);
			exit(2);
	}
	/*  suite du processus père */
	/*  Fermeture du tube en lecture -- absolumment necessaire !! */
	/*  Lecture d'une suite de chaines au clavier et écriture dans le tube */
	printf("\nPere->Entrez une chaine ou stop pour arrêter.\n");
	fgets(tampon,sizeof(tampon),stdin);
	while(strcmp(tampon,"stop\n") != 0){
		write(unTube[1], tamon, strlen(tampon)+1);

		/*  attente de la terminaison du fils */
		pidProc = wait(&statut);
	}
	/*  Création du fils */
	pidProc = fork();
	switch (pidProc){
		case -1 :
			perror("fork");
			exit(1);
		case 0:
			traitFils(unTube);
			exit(2);
	}
}
