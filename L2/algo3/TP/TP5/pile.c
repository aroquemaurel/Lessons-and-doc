/*
 * =====================================================================================
 *
 *       Filename:  pile.c
 *
 *    Description:  Implémentation des fonction sur les piles
 *
 *        Version:  1.0
 *        Created:  06/11/2012 18:24:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */

#include "pile.h"

void stack_initialize(Stack* pStack) {
	int i;
	pStack->lastIndice = -1;
	for(i = 0; i < MAX_TAB ; ++i) {
		elem_initialize(pStack->tab+i);	
	}
}

bool stack_isEmpty(const Stack pStack) {
	return (stack_size(pStack) == 0);
}

bool stack_isFull(const Stack pStack) {
	return (pStack.lastIndice > MAX_TAB);
}

void stack_display(const Stack pStack) {
	int i;
	for(i = 0; i < stack_size(pStack) ; ++i) {
		printf("+---------+\n");
		elem_display(pStack.tab[pStack.lastIndice]);
		printf("+---------+\n");
	}
}

Element stack_top(const Stack pStack) {
	return (pStack.tab[pStack.lastIndice]);	
}

int stack_push(Stack* pStack, const Element pElem) {
	int returnCode = 0;

	if(!stack_isFull(*pStack)) {
		++pStack->lastIndice;
		pStack->tab[pStack->lastIndice] = pElem;
	} else {
		returnCode = -1;
	}

	return returnCode;
}

int stack_pop(Stack* pStack) {
	int returnCode = 0;

	if(!stack_isEmpty(*pStack)) {
		--pStack->lastIndice;
	} else {
		returnCode = -1;
	}

	return returnCode;
}

int stack_size(const Stack pStack) {
	return pStack.lastIndice+1;
}
