#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(int nbParam, char** tabParam) {
	int err;
	pid_t pid;

	switch (nbParam) {
	   case 2 : 
			sscanf(tabParam[1], "%d", &pid);
			printf("envoi du signal SIGUSR1 au processus= %d\n", pid);
			err=kill( pid, SIGUSR1 );

			if (err == -1) { 
				perror("echec kill");
				exit(1); 
			}
		break;
		default : 
			printf("***nombre de parametres incorrect!!!\n"); 
			exit(1);
   }
}

