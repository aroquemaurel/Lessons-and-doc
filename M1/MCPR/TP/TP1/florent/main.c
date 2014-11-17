#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

int getSemaphore(int i);
void destroySemaphor(int semid);
void sem_print(int process, int semaphor, int nextSemaphor);
void v(int semid);
void p(int semid);

int main (int argc, char** argv) {
    int* semaphores;
    int nbProcessus;
	unsigned long long test;
    pid_t processus;

    int identifiantProcessus;
    if (argc != 2) {
        printf("Args error: exe nbProcessus\n");
        exit(1);
    }
	nbProcessus = atoi(argv[1]);
	semaphores = malloc(sizeof(int)*nbProcessus);
    printf("%d processus \n",nbProcessus);
    
    
    // Création des sémaphores
    for (int i=0; i<nbProcessus; ++i) {
        semaphores[i] = semget((key_t)26+i, 1, IPC_CREAT|0666);
        if (semaphores[i] == -1) {
            perror("Failed to initialize the shsem\n");
            exit(2);
        }
        // initialise les sémaphores à 0
        if (semctl(semaphores[i], 0, SETVAL, 0) == -1) {
            perror("Semaphore failed to initialize\n");
            exit(3);
        }
    }
    for (int numeroProcessus=0; numeroProcessus<nbProcessus; ++numeroProcessus) {
        switch (processus = fork()) {
            case -1:
                printf("Fork failed \n");
                exit(4);
                break;
            case 0: // Child 
                if (numeroProcessus == nbProcessus-1) {
                    sem_print(numeroProcessus, semaphores[numeroProcessus], semaphores[0]);
                } else {
                    sem_print(numeroProcessus, semaphores[numeroProcessus], semaphores[numeroProcessus+1]);
                }
                exit(5);
                break;
        }
    }

	// First semaphore
    v(semaphores[0]);
    for (int i=0; i<nbProcessus; ++i) {
        wait(NULL);
    }
    
    for (int i=0; i<nbProcessus; ++i) {
        /* shared memory detach */
        if(semctl(semaphores[i], IPC_RMID, 0)) {
            perror("Error : shmctl operation impossible\n");
        }
    } 
	free(semaphores);
}

int getSemaphore(int i) {
	int semid;
	
	// Get semaphore id
	if ((semid = semget((key_t)i+55, 1, IPC_CREAT | 0666)) == -1) {
		perror("Erreur in id attribution of semaphore\n");
		exit(6);
	}
	
	// init semaphore with 0
	if ((semctl(semid, 0, SETVAL, 0)) == -1) {
		perror("we can't initialize the semaphore\n");
		exit(7);
	}	
	
	return semid;
}

void destroySemaphor(int semid) {
	if (semctl(semid, IPC_RMID, 0) == -1) {
		perror("Error in semaphore destruction\n");
		exit(8);
	}
}

void p(int shsem) {
    struct sembuf sb = {0,1,0};
    sb.sem_op=-1; //Lock
    if (semop(shsem,(struct sembuf *)&sb,1) == -1) {
		perror("P error\n");
	}
}

void v(int shsem) {
    struct sembuf sb = {0,1,0};
    sb.sem_op=1;//Unlock
    if (semop(shsem,(struct sembuf *)&sb,1) == -1) {
		perror("V error\n");
	}
}

void sem_print(int numeroProcessus, int sonSemaphore, int prochainSemaphore) {
    for (int i=0; i<5; ++i) {
        p(sonSemaphore);
        printf("process number: %d\n", numeroProcessus);
        v(prochainSemaphore);
    }
}
