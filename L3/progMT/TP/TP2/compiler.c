#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc,char** argv) {
	int i;
	int status;
	char buff[256];
	char buff2[256];
	bool compilOk = true;
	int pid;
	int f;

	for(i = 1 ; i < argc ; ++i) {
		switch(fork()) {
			case -1:
				error("Erreur dans la création du fils");
			case 0:
				strcmp(buff2, argv[i]);
				buff2[strlen(buff2)-2] = '\0'; // on supprime le .c
				sprintf(buff, "%s.err", buff2);
				printf(":)%s", buff);
				if((f = open(buff, O_CREAT|O_WRONLY)) == -1) {
					error("Erreur lors de l'ouverture du fichier", EXIT_FAILURE);
				}
				dup2(2, f); 
				execlp("gcc", "gcc", "-c", argv[i]);
				error("Erreur dans le traitement de gcc", 42);
				break;
		}
	}

	while ((pid = wait(&status)) > 0) {
		if(WEXITSTATUS(status) != 0) {
			compilOk = false;
		}
	}

	
	if(compilOk) {
		switch(fork()) {
			case -1:
				error("Erreur dans la création du fils");
			case 0:
				execlp("gcc", "gcc", "");
				error("Erreur dans le traitement de gcc", 51);
				break;
		}
		
	} else {
		fprintf(stderr, "Erreur dans la compilation, l'édition de lien n'a pas été effectuée");
	}

	return EXIT_SUCCESS;
}
