#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int traiter_donnees(int* dataLine);
void askData(int** data);
int main(int argc, char** argv) {
	int i;
	int nbSuccess = 0;
	int** data;
	int nbLignes, nbColonnes;
	int status;
	int pid;

	askData(data, &nbLignes, &nColonnes);	
	for(i = 0 ; i < nbLignes; ++i) {
		switch(fork()) {
			case -1:
				perror("Erreur lors de la création du fils");
				exit(1);
			case 0:
				return traiter_donnees(data[i]);
			default:
		}
	}
	while(wait(&status)) {
		if(WEXISTTUS(status)) {
			++nbSuccess;
		}
	}
	printf("nombre de lignes ayant obtenu un résultat positif: %d", nbSuccess);


	return EXIT_SUCCESS;
}

