#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int Element;
typedef struct etCel {
	Element value;
	struct etCel* next;
} Cel;
#include "pileDynamique.h"


int main(int argc, char** argv) {
	Pile p = pile_init();
	p = pile_saisir(p);
	pile_afficher(p);
	printf("\n");
	pile_depiler(&p);
	pile_depiler(&p);
	pile_empiler(&p, 42);

	pile_afficher(p);
	return 0;
}

Pile pile_init() {
	return (NULL);	
}

void pile_afficher(Pile pStack) {
	while(!pile_estVide(pStack)) {
		printf("| %d |\n", pStack->value);
		pStack = pStack->next;
	}
}

bool pile_estVide(const Pile pStack) {
	return (pStack == NULL);
}

bool pile_pleine(const Pile pStack) {
	return false; // dynamique donc jamais pleine
}

void pile_empiler(Pile* pStack, Element pElem) {
	Pile buffStack;
	buffStack = (Pile)malloc(sizeof(Cel));

	assert(buffStack != NULL);
	buffStack->value = pElem;
	buffStack->next= *pStack;
	*pStack = buffStack;
}

void pile_empilerPlusieursElements(Pile* pStack, Element* pElem, int nbElem) {
	int i;
	for(i=0; i < nbElem ; ++i) {
		pile_empiler(pStack, pElem[i]);
	}
}
Element pile_depiler(Pile* pStack) {
	Pile buffStack= NULL;

	if(!pile_estVide(*pStack)) {
		buffStack = (*pStack)->next;;
		free(*pStack);
	}
	*pStack = buffStack;	

	return (buffStack->value);
}

Pile pile_saisir() {
	Pile stack = pile_init();
	Element elem = 0;
	scanf(" %d", &elem);
	while(elem != -1) {
		pile_empiler(&stack, elem);
		scanf(" %d", &elem);
	}

	return stack;
}

Element pile_sommet(Pile pStack) { 
	return (pStack->value);
}
