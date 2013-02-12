#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define NBPROC 4 //nombre de processus fils
#define N 5 // nombre d'affichage

void affichage(pid_t pid);

int main(int argc, char** argv) {
	pid_t fils, fils_termine;
	pid_t successeur;
	int i;
	int circonstance;

	successeur = getpid();

	for(i = NBPROC; i > 0 ; --i) {
		switch(fils = fork()) {
			case -1:
				perror("Erreur fork");
				exit(EXIT_FAILURE);
			case 0:
				printf("Je suis le fils %d, je m'apelle %d mon successeur est %d\n", 
							i, (int)getpid(), successeur);
				affichage(getpid());
				printf("[%d] fin\n", (int)getpid());
				exit(i);
			default:
				successeur = fils;
		}
	}

	printf("Je suis le père, je m'appelle %d mon successeur est %d", 
			(int)getpid(), (int)successeur);
	while(fils_termine = wait(&circonstance) != -1) {
		printf("[%d] : Mon fils %d est terminé avec le code %d\n", 
				(int)fils_termine, WEXITSTATUS(circonstance));
	}
	printf("Tous les fils sont terminés");

	return EXIT_SUCCESS;
}

void affichage(pid_t pid) {
	int k;
	for (k=0 ; k < N ; ++k) {
		printf("[%d] : c'est moi\n", (int) pid);
		sleep(2); // processus pas de l'état élu à l'état bloqué
	}
}
