#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "exo1.h"

int main(void) {
	srand(NULL);
	return 0;
}

Ensemble ensemble_vide() {
	Ensemble newEnsemble; 
	newEnsemble.nbElement = 0;

	return newEnsemble;
}

Ensemble ensemble_ajout(Ensemble e1, Element x) {
	if(!ensemble_appartient(e1, x)) {
		e1.ensemble[++e1.nbElement] = x;
	}

	return e1;
}

Booleen ensemble_appartient(Ensemble e, Element x) {
	int i;
	Booleen appartient = faux;
	for(i = 0; i < e.nbElement ; ++i) {
		if(e.ensemble[i] == x) {
			appartient = vrai;
			break;
		}
	}

	return appartient;
}

Booleen ensemble_estVide(Ensemble e) {
	return (e.nbElement == 0);
}

Ensemble ensemble_union(Ensemble e1, Ensemble e2) {
	Ensemble newEnsemble;
	int i;
	for(i = 0; i < e1.nbElement ; ++i) {
		newEnsemble = ensemble_ajout(newEnsemble, e1.ensemble[i]);
	}
	for(i=0; i < e2.nbElement ; ++i) {
		if(!ensemble_appartient(newEnsemble, e2.ensemble[i])) {
			newEnsemble = ensemble_ajout(newEnsemble, e2.ensemble[i]);
		}
	}

	return newEnsemble;
}

Ensemble ensemble_intersection(Ensemble e1, Ensemble e2) {
	Ensemble newEnsemble;
	int i;	

	for(i = 0; i < e1.nbElement ; ++i) {
		if(ensemble_appartient(e2, e1.ensemble[i])) {
			newEnsemble = ensemble_ajout(newEnsemble, e1.ensemble[i]);
		}
	}

	return (newEnsemble);
}

Booleen ensemble_inclusion(Ensemble e1, Ensemble e2) {
	int i=0;
	while(ensemble_appartient(e1, e2.ensemble[i])) {
		++i;
	}

	return (i == e2.nbElement);
}

int ensemble_cardinal(Ensemble e) {
	return (e.nbElement);
}

Ensemble ensemble_supprimer(Ensemble e, Element x) {
	int i,j;
	assert(ensemble_appartient(e, x));
	while(e.ensemble[i] != x) {
		++i;
	}
	--e.nbElement;	
	for( ; i < e.nbElement ; ++i) {
		e.ensemble[i] == e.ensemble[i+1];
	}
}

Element ensemble_choisir(Ensemble e) {
	return e.ensemble[rand()%(e.nbElement)];
}

