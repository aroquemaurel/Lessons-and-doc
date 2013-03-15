#define POSIX_C_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LONG_MAX_NOM 20
#define FAILURE_FILE 1
typedef struct {
	char Nom[LONG_MAX_NOM+1];
	int Age;
	int NbEnfants;
	int numFiche;
} Infos;

int creation(char* fileName);
int consultation(char* nomFichier);
void affichageFiche(const Infos pFiche);

int main(int argc, char** argv) {
	int choix;	
	char* fileName;
	printf("Que voulez vous faire ?\n");
	printf("1. Ecrire des fiches\n");
	printf("2. Lire des fiches\n");
	printf("0. Quitter\n");
	scanf("%d", &choix);
	switch(choix) {
		case 1:
	if(creation("./superFichier") != 0) {
		return 1;	
	}
			break;
		case 2:
	consultation("superFichier");
			break;
	}
	return 0;
}
int creation(char* fileName) {
	int fileDesc;
	int i = 1;
	char continuer;	
	Infos infos;
	fileDesc = open(fileName, O_WRONLY);
	char* buffAge = "\nAge: ";
	char* buffNbEnfants = "\nnombre d'enfants: ";
	char* buffNom = "Nom: ";
	char buff[64];
	if(fileDesc == -1) {
		perror(fileName);
		return FAILURE_FILE;
	}
	printf("Veuillez saisir les informations ");
	do {
		printf("Nom: ");
		scanf("%s", (infos.Nom));
		printf("Age: ");
		scanf("%s", &(infos.Age));
		printf("NbEnfants: ");
		scanf("%s", &(infos.NbEnfants));
		infos.numFiche = i;
		printf("continuer?(Y/N): ");
		sprintf(buff, "%d", i); 
		write(fileDesc, &infos, sizeof(infos));
		scanf(" %c", &continuer);
		printf("\n\n");
		++i;
	} while(continuer == 'Y' || continuer == 'y');
	close(fileDesc);
}

int consultation(char* nomFichier) {
	int fileDesc;
	int i=0;
	char* buff;
	Infos infos;
	fileDesc = open(nomFichier, O_RDONLY);
	int numFiche;	
	while(read(fileDesc,&infos,sizeof(infos))){ 
		++i;
	}
	printf("Il y a %d fiches présentes\n", i+1);
	do {
		printf("Quelle fiche voulez vous lire ? (-1 = STOP)");
		scanf(" %d", &numFiche);
		if(numFiche != -1) {
			lseek(fileDesc, sizeof(Infos) * (numFiche-1), SEEK_SET); 
			read(fileDesc,&infos,sizeof(Infos)); 
			affichageFiche(infos);
		}
		printf("\n\n");
	} while(numFiche!=-1); 
}

void affichageFiche(const Infos pFiche) {
	printf("Fiche numéro %d\n", pFiche.numFiche);
	printf("Nom: %s\n", pFiche.Nom);
	printf("Age: %d\n", pFiche.Age);
	printf("NbEnfants: %d\n", pFiche.NbEnfants);
}
