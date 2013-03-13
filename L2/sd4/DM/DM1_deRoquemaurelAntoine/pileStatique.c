#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pileStatique.h"

struct pileStatiqueCachee {
	int tab[TAILLE_MAX];
	int nb;
};

PileStatique pileStatiqueCreer(void) {
	PileStatique pile;
	pile = (PileStatique) malloc(sizeof(struct pileStatiqueCachee));
	assert(pile != NULL);

	pile->nb = 0;

	return pile;
}

void pileStatiqueEmpiler(PileStatique* pPile, int pValeur) {
	assert((*pPile)->nb < TAILLE_MAX);
	(*pPile)->tab[(*pPile)->nb] = pValeur;
	(*pPile)->nb++;
}

int pileStatiqueEstVide(PileStatique pPile) {
	return (pPile->nb == 0);
}

int pileStatiqueEstPleine(PileStatique pPile) {
	return (pPile->nb == TAILLE_MAX);
}
int pileStatiqueDepiler(PileStatique* pPile) {
	assert(!pileStatiqueEstVide(*pPile));
	(*pPile)->nb--;

	return ((*pPile)->tab[(*pPile)->nb-2]);
}

int pileStatiqueSommet(PileStatique pPile) {
	assert(!pileStatiqueEstVide(pPile));
	return (pPile->tab[pPile->nb-1]);
}

void pileStatiqueDetruire(PileStatique *p) {
	while(!pileStatiqueEstVide(*p)) {
		pileStatiqueDepiler(*p);
	}
}

void pileStatiqueAfficher(PileStatique p) {
	int i;
	for(i=0 ; i < p->nb ; ++i) {
		printf("%d ", p->tab[i]);
	}
}
