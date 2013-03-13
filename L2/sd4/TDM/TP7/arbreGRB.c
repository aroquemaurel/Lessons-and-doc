#include <stdlib.h>
#include "arbreGRB.h"
typedef struct etCell {
	struct etCell* gauche;
	struct etCell* droite;
	int racine;
} Cell;

Arbre creerArbreGRD(void) {
	return (NULL);
}
Arbre ajouterEntier(Arbre arbre, int e) {
	Cell* newCell;
	newCell = (Cell*)malloc(sizeof(Cell));
	newCell->racine = e;
	newCell->gauche = NULL;
	newCell->gauche = NULL;
	if(estVideGRD(arbre)) {
		arbre = newCell;	
	} else {
		if(e <= arbre->racine) {
			arbre->gauche = ajouterEntier(arbre->gauche, e);
		} else {
			arbre->droite = ajouterEntier(arbre->droite, e);
		}
	}

	return arbre;
}
void triGRD(const Arbre a) {
	if(!estVideGRD(a)) {
		triGRD(a->gauche);
		printf("%d ", a->racine);
		triGRD(a->droite);
	} 
}
int estVideGRD(const Arbre arbre) {
	return (arbre == NULL);
}
int appartientGRB(const Arbre arbre, int val) {
	int retour;
	if(estVideGRD(arbre)) {
		retour = 0;
	} else if(val <= arbre->racine) {
		retour = appartientGRB(arbre->gauche, val);
	} else if(val > arbre->racine) {
		retour = appartientGRB(arbre->droite, val);
	} else {
		retour = 1;
	}

	return retour;
}

