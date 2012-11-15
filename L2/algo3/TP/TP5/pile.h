/*
 * =====================================================================================
 *
 *       Filename:  pile.h
 *
 *    Description:  Prototypes des méthodes sur les piles
 *
 *        Version:  1.0
 *        Created:  06/11/2012 18:24:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __PILE
#define __PILE

#include "element.h"
#include <stdbool.h>

#define MAX_TAB 100

typedef struct {
	Element tab[MAX_TAB];
	int lastIndice;	
	
} Stack;

void stack_initialize(Stack* pStack);
bool stack_isEmpty(const Stack pStack);
bool stack_isFull(const Stack pStack);
Element stack_top(const Stack pStack);
int stack_push(Stack* pStack, const Element pElem);
int stack_pop(Stack* pStack);
void stack_display(const Stack pStack);

#endif


