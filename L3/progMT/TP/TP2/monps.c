#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "erreur.h"
int main(int argc, char** argv) {
	int pipePsGrep[2];

	if(pipe(pipePsGrep) == -1) {
		error("Erreur lors de la création du tube", 2);	
	}
	
	switch(fork()) {
		case -1:
			error("Erreur lors de la création du fork", 3);	
		case 0:
			close(pipePsGrep[0]);
			dup2(pipePsGrep[1], 1);
			close(pipePsGrep[1]);
			execlp("ps", "ps", "-aef", NULL);
			error("Erreur lors de l'execution de ps");
	}

	switch(fork()) {
		case -1:
			error("Erreur lors de la création du fork", 3);	
		case 0:
			close(pipePsGrep[1]);
			dup2(pipePsGrep[0], 0);	
			close(pipePsGrep[0]);
			execlp("grep", "grep", argv[1], NULL);
			error("Erreur lors de l'execution de grep");
	}

	return EXIT_SUCCESS;
}
