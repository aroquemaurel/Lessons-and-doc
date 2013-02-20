#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
typedef struct cell {
	T_element value;
	struct cell* next;
} T_cell;


void initialiser_pile(T_pile *p) {
	*p = NULL;
}

void afficher_pile(T_pile p) {
	printf("+---+\n");
	while(!pile_vide(p)) {
		printf("| %d |\n", p->value);
		p = p->next;
	}
	printf("+---+\n");
}

bool pile_vide(T_pile p) {
	return (p == NULL);
}

bool pile_pleine(T_pile p) {
	return false; // dynamique donc jamais pleine
}

void empiler(T_pile *p, T_element pElem) {
	T_pile buffStack;
	buffStack = (T_pile) malloc(sizeof(T_cell));

	assert(buffStack != NULL);
	buffStack->value = pElem;
	buffStack->next= *p;
	*p = buffStack;
}

void depiler(T_pile *p) {
	T_pile buffStack= NULL;

	if(!pile_vide(*p)) {
		buffStack = (*p)->next;;
		free(*p);
	}
	*p = buffStack;	
}

T_element sommet_pile(T_pile p) {
	if(p != NULL) 
		return (p->value);
	else 
		return NULL;
}
