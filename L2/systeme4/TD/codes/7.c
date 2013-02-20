#define _POSQIX_C_SOURCE 1
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	pid_t fils;
	switch ( fils = fork() ) {
		case -1 :
			perror("Erreur fork");
			exit(EXIT_FAILURE);
		case 0 :
			execlp("ls", "ls", "-l", NULL);
			perror("Erreur execp");
			exit(EXIT_FAILURE);
		default :
			wait(NULL);
			break;
	}

	switch ( fils=fork() ) {
		case -1 :
			perror("Erreur fork");
			exit(EXIT_FAILURE);
		case 0 :
			execlp("pwd", "pwd", NULL);
			perror("Erreur execp");
			exit(EXIT_FAILURE);
		default :
			wait(NULL);
			break;
	}

	return EXIT_SUCCESS;
}
