#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "pileDynamique.h"
#include "pileStatique.h"
#include "pileMixte.h"

PileMixte pileMixteCreer(void) {
	return NULL;
}

int pileMixteEstVide(PileMixte pPile) {
	return (pPile == NULL);
}

int pileMixteEstPleine(PileMixte pPile) {
	return false; 
}

void pileMixteEmpiler(PileMixte* pPile, int pElement) {
	PileStatique nouvellePile ;
	PileStatique pileCourrante; 
	if(pileMixteEstVide(*pPile) || (pileStatiqueEstPleine(pileDynamiqueSommet(*pPile)))) {
		nouvellePile = pileStatiqueCreer();
		pileDynamiqueEmpiler(pPile, nouvellePile);
	}
	pileCourrante = pileDynamiqueSommet(*pPile);
	pileStatiqueEmpiler(&pileCourrante, pElement);
}

int pileMixteDepiler(PileMixte* pPile) {
	int retour;
	PileStatique pileCourrante;
	assert(!pileMixteEstVide(*pPile)); 
	pileCourrante = pileDynamiqueSommet(*pPile);
	retour = pileStatiqueDepiler(&pileCourrante);

	if(pileStatiqueEstVide(pileDynamiqueSommet(*pPile))) {
		pileDynamiqueDepiler(pPile);	
	}

	return retour;
}

int pileMixteSommet(PileMixte pPile) {
	assert(!pileMixteEstVide(pPile));
	return (pileStatiqueSommet(pileDynamiqueSommet(pPile)));	
}

void pileMixteDetruire(PileMixte *pPile) {
	while(!pileMixteEstVide(*pPile)) {
		pileMixteDepiler(pPile);
	}
}

