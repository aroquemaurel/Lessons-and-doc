#include "element.h"
#include "listeDoublementChaine.h"

int main(void) {
	LDC liste = creer();
	Element elem;
	int saisie;
	do {
		printf("Gestion de voyage\n");
		printf("1. Ajouter une destination avant une autre");
		printf("2. Ajouter une destination après une autre");
		printf("3. Changer la durée d'une destination");
		printf("4. quitter");
		scanf(" %d", &saisie);

		switch(saisie) {
			case 1:
				// TODO
				break;
			case 2:
				// TODO
				break;
			case 3:
				// TODO
				break;
		}
		printf("\n\n");
	} while(saisie != 4);
	return 0;
}
