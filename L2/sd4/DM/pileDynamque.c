#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/*
 * TODO element.h
 */
typedef int Element;
typedef struct etCel {
	Element value;
	struct etCel* next;
} Cel;
#include "PileDynamiqueDynamique.h"


PileDynamique PileDynamiqueCreer() {
	return (NULL);	
}

bool PileDynamiqueEstVide(const PileDynamique pStack) {
	return (pStack == NULL);
}

bool PileDynamiqueEstPleine(const PileDynamique pStack) {
	return false; // dynamique donc jamais pleine
}

void PileDynamiqueEmpiler(PileDynamique* pStack, Element pElem) {
	PileDynamique buffStack;
	buffStack = (PileDynamique)malloc(sizeof(Cel));

	assert(buffStack != NULL);
	buffStack->value = pElem;
	buffStack->next= *pStack;
	*pStack = buffStack;
}

Element PileDynamiqueDepiler(PileDynamique* pStack) {
	PileDynamique buffStack= NULL;

	if(!PileDynamique_estVide(*pStack)) {
		buffStack = (*pStack)->next;;
		free(*pStack);
	}
	*pStack = buffStack;	

	return (buffStack->value);
}

Element PileDynamiqueSommet(PileDynamique pStack) { 
	return (pStack->value);
}

void PileDynamiqueAfficher(PileDynamique pStack) {
	while(!PileDynamique_estVide(pStack)) {
		printf("| %d |\n", pStack->value); // TODO fonction de élément
		pStack = pStack->next;
	}
}

