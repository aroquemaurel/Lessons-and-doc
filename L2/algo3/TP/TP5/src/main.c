/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description: Fichier d'entrée du programme 
 *
 *        Version:  1.0
 *        Created:  06/11/2012 18:03:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */

#include <stdio.h>

#include "../lib/element.h"
#include "../lib/pile.h"

int main (int argc, char** argv) {
	Element test1, test2, test3, test4;	
	Stack stack;
	stack_initialize(&stack);
	
	elem_initialize(&test1);
	elem_initialize(&test2);
	elem_initialize(&test3);
	elem_initialize(&test4);
	test1.nb = 1;	
	test2.nb = 2;	
	test3.nb = 3;	
	test4.nb = 4;	
	
	stack_push(&stack, test1);
	stack_push(&stack, test2);
	stack_push(&stack, test3);
	stack_display(stack);
	printf("%d", stack_top(stack).nb);
	printf("\n\n");
	stack_pop(&stack);
	stack_display(stack);
	stack_push(&stack, test4);
	printf("\n\n");
	stack_display(stack);
	
	
	return 0;
}

