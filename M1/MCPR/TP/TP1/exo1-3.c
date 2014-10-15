/*  TP1 -- Exo1 -- variante 3 */

/* 
 * Modifier le code précédent pour utiliser maintenant un segment de mémoire
 * partagée pour implanter ce compteur.
 */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int KEY = 1234;
int* cpt;

void treatmentIncrement(const int nbIncrement);
void treatmentDecrement(const int nbDecrement);

int main(int argc, char** argv) {
	int memId;
	if(argc <= 1) {
		perror("Arguments errors");
		exit(1);
	}


	if ((memId = shmget(KEY, sizeof(int), 0666|IPC_CREAT)) < 0) {
		perror("shmget");											
		exit(1);
	}
	if ((cpt = shmat(memId, NULL, 0)) == (void*) -1) {
		perror("shmat");					
		exit(1);
	}

	switch(fork()) {
		case 0:
			treatmentIncrement(atoi(argv[1]));
			break;
		default:
			treatmentDecrement(atoi(argv[1]));
			break;
	}
	shmdt(cpt);
	wait(NULL);
	shmctl(memId, IPC_RMID, NULL);
}

void treatmentIncrement(const int nbIncrement) {
	for(int i = 0 ; i < nbIncrement; ++i) {
		printf("\tIncrement: %d\n",++(*cpt));
	}

}

void treatmentDecrement(const int nbDecrement) {
	for(int i = 0 ; i < nbDecrement; ++i) {
		printf("Decrement: %d\n",--(*cpt));
	}

}
