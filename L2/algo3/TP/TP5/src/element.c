/*
 * =====================================================================================
 *
 *       Filename:  element.c
 *
 *    Description:  Implémentation des fonctions sur les éléments
 *
 *        Version:  1.0
 *        Created:  06/11/2012 18:14:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */
#include "../lib/element.h"

void elem_display(const Element pElem) {
	printf("nb : %d", pElem.nb);
}

void elem_saisir(Element* pElem) {
	printf("Entrer nb: ");
	scanf("%d", &(pElem->nb));
}

void elem_affect(Element* pElem1, const Element pElem2) {
	pElem1->nb = pElem2.nb;
}

void elem_initialize(Element* pElem) {
	pElem->nb = 0;
}
