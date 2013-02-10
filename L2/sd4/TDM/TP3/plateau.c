#include "plateau.h"

Plateau plateau_initialiser(const int pNbelement) {
	int i;
	Plateau newPlateau = (Plateau) malloc(sizeof(T_pile)*3);

	for(i=0; i < 3 ; ++i) {
		initialiser_pile(&newPlateau[i]);
	}

	for(i=pNbelement ; i > 0 ; --i) {
		empiler(&newPlateau[0], i);
	}

	return newPlateau;
}

bool plateau_deplacementEstPossible(Plateau pPlateau, const int pBegin, const int pEnd) {
	return (!pile_vide(pPlateau[pBegin]) && ( 
			sommet_pile(pPlateau[pEnd]) > sommet_pile(pPlateau[pBegin]) || pile_vide(pPlateau[pEnd])));
}

void plateau_deplacerAnneau(Plateau pPlateau, const int pBegin, const int pEnd) {
	if(plateau_deplacementEstPossible(pPlateau,pBegin,pEnd)) {
	empiler(&pPlateau[pEnd], sommet_pile(pPlateau[pBegin]));
	depiler(&pPlateau[pBegin]);
	}
}

void plateau_afficher(Plateau pPlateau) {
	int i;
	for(i = 0 ; i < 3 ; ++i) {
		printf("Pile %d:\n", i+1);
		afficher_pile(pPlateau[i]);
	}
}
