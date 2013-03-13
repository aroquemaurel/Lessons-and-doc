#include "element.h"
#include "listeDoublementChaine.h"
#include <stdio.h>
int main(void) {
	LDC liste = creer();
	Element elem;

	if(estVide(liste)) {
		printf("La liste est vide\n");
	}
	elem.val = 0;
	elem.nom = "test";
	ajouter(liste, elem);

	elem.val = 3;
	elem.nom = "autre test";
	ajouter(liste, elem);

	elem.val = 2;
	elem.nom = "machin";
	ajouter(liste, elem);

	affichageCroisant(liste);

	supprimer(liste,elem); 
	printf("\n");

	affichageCroisant(liste);
	printf("\n");

	affichageDecroissant(liste);
	return 0;
}
