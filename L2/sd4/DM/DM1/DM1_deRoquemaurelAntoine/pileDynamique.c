#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "pileDynamique.h"

typedef struct etCell {
	Element value;
	struct etCell* next;
} Cell;


PileDynamique pileDynamiqueCreer(void) {
	return (NULL);	
}

int pileDynamiqueEstVide(PileDynamique pPile) {
	return (pPile == NULL);
}

int pileDynamiqueEstPleine(PileDynamique pPile) {
	return false; 
}

void pileDynamiqueEmpiler(PileDynamique* pPile, Element pElement) {
	PileDynamique buffPile;
	buffPile = (PileDynamique)malloc(sizeof(Cell));
	assert(buffPile != NULL);

	buffPile->value = pElement;
	buffPile->next= *pPile;
	*pPile = buffPile;
}

Element pileDynamiqueDepiler(PileDynamique* pPile) {
	PileDynamique buffPile = NULL;

	if(!pileDynamiqueEstVide(*pPile)) {
		buffPile = (*pPile)->next;;
		free(*pPile);
	}
	*pPile = buffPile;	

	return ((!pileDynamiqueEstVide(*pPile) ? buffPile->value: NULL));
}

Element pileDynamiqueSommet(PileDynamique pPile) {
	assert(!pileDynamiqueEstVide(pPile));
	return (pPile->value);
}

void pileDynamiqueDetruire(PileDynamique *pPile) {
	while(!pileDynamiqueEstVide(*pPile)) {
		pileDynamiqueDepiler(pPile);
	}
}
