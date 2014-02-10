#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

char** buildBinaryArray(int argc, char** argv);
bool linkEdition(char** argv, const int argc, const bool compileOk);
void getFileNameErr(char* fileNameC, char* fileNameErr);
int main(int argc,char** argv) {
	int i;
	int status;
	char fileErr[256];
	char buff[256];
	bool compilOk = true;
	bool retEdition;
	int pid;
	int f;

	for(i = 1 ; i < argc ; ++i) {
		switch(fork()) {
			case -1:
				error("Erreur dans la création du fils");
			case 0:
				getFileNameErr(argv[i], fileErr);
				if((f = open(fileErr, O_CREAT|O_WRONLY, 0755)) == -1) {
					error("Erreur lors de l'ouverture du fichier", EXIT_FAILURE);
				}
				dup2(2, f); 
				execlp("gcc", "gcc", "-c", argv[i], NULL);
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
		for(i=1 ; i < argc ; ++i) {
			getFileNameErr(argv[i], fileErr);
			remove(fileErr);
		}
	}
	
	retEdition = linkEdition(argv, argc, compilOk);

	return retEdition ? EXIT_SUCCESS : EXIT_FAILURE;
}
bool linkEdition(char** argv, const int argc, const bool compileOk) {
	bool ret = true;
	char** argBinaires;
	if(compileOk) {
		switch(fork()) {
			case -1:
				error("Erreur dans la création du fils");
			case 0:
				argBinaires = buildBinaryArray(argc, argv);
				execvp("gcc", argBinaires);
				error("Erreur dans le traitement de gcc", 51);
				break;
		}
	} else {
		fprintf(stderr, "Erreur dans la compilation, l'édition de lien n'a pas été effectuée");
		ret = false;
	}

	return ret;
}
char** buildBinaryArray(int argc, char** argv) {
	char** argBinaires;
	int i;

	argBinaires = (char**)malloc(argc*sizeof(char*)+1);
	argBinaires[0] = malloc(strlen(argv[0]));		
	strcpy(argBinaires[0], "gcc");

	for(i=1 ; i < argc ; ++i) {
		argBinaires[i] = malloc(strlen(argv[i]));		
		strcpy(argBinaires[i], argv[i]);
		argBinaires[i][strlen(argBinaires[i])-1] = 'o';
	}

	argBinaires[i] = NULL;

	return argBinaires;
}

void getFileNameErr(char* fileNameC, char* fileNameErr) {
	strcpy(fileNameC, fileNameC);
	fileNameErr[strlen(fileNameC)-2] = '\0'; // on supprime le .c
	sprintf(fileNameErr, "%s.err", fileNameC);
}
