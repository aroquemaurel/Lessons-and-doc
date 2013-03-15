#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define NBMOTSMAX 20

int decoupe(char* chaine, char** pMots);
void message(char* proc);
int main(int argc, char** argv) {
	int i;
	int circ;
	char* mots[256];
	for(i = 1; i < argc ; ++i) {
		switch(fork()) {
			case -1:
				printf("erreur dans le fork");
				return EXIT_FAILURE;
			case 0:
				decoupe(argv[i], mots);
				message(argv[i]);
				execvp(mots[0], mots);
				break;
		}
		printf("\n");
	}
	while(wait(&circ) != -1) {
		if(circ == 0) {
			printf("[%d] %s à été executé avec succes (code erreur %d) \n", getpid(), argv[i], circ);
		} else {
			printf("[%d] Erreur dans l'execution de %s (code erreur %d)\n", getpid(), argv[i], circ);
		}
	}
	return 0;
}

int decoupe(char* chaine, char** pMots) {
	char *p;
	int NbMots=0;
	p=chaine; /*  On commence par le debut */
		/*  Tant que la fin de la chaine n’est pas atteinte et qu’on ne deborde pas */
		while ((*p)!='\0' && NbMots<NBMOTSMAX)
		{
			while ((*p)==' ' && (*p)!='\0') p++; /*  Recherche du debut du mot */
			if ((*p)=='\0') break; /*  Fin de chaine atteinte */
			pMots[NbMots++]=p; /*  Rangement de l’adresse du 1er caractere du mot */
			while ((*p)!=' ' && (*p)!='\0') p++; /*  Recherche de la fin du mot */
			if ((*p)=='\0') break; /*  Fin de chaine atteinte */
			*p='\0'; /*  Marquage de la fin du mot */
			p++; /*  Passage au caractere suivant */
		}
	pMots[NbMots]=NULL; /*  Derniere adresse */
	return NbMots;
}
void message(char* proc) {
	printf("[%d] Création du fils %s\n", getppid(), proc);
}
