#include <stdlib.h>
#include <assert.h>
#include "element.h"
#include "listeDoublementChaine.h"
#include "iterateur.h"

typedef struct etIte {
	LDC l;
	struct etCell* cour;
} etIterateur;


Iterateur creerIterateur(LDC liste) {
	Iterateur ite;
	ite = (Iterateur) malloc(sizeof(etIterateur));
	assert(ite != NULL); 
	ite->l = liste;
	ite->cour = liste->premier;

	return ite;
}

Element next(Iterateur iterateur) {
	Element ret = iterateur->cour->val;
	assert(hasNext(iterateur));
	iterateur->cour = iterateur->cour->suiv;

	return ret;
}

Element previous(Iterateur iterateur) {
	Element ret;
	assert(hasPrevious(iterateur));
	if(iterateur->cour != NULL) 
		iterateur->cour = iterateur->cour->prec;
	else
		iterateur->cour = iterateur->l->dernier;

	ret = iterateur->cour->val;

	return ret;
}
void begin(Iterateur iterateur) {
	iterateur->cour = iterateur->l->premier;
}
void end(Iterateur iterateur) {
	iterateur->cour = NULL; 
}
int hasNext(Iterateur iterateur) {
	return (iterateur->cour != NULL);
}
int hasPrevious(Iterateur iterateur) {
	return (iterateur->cour != iterateur->l->premier);
}
