/*
 * =====================================================================================
 *
 *       Filename:  element.h
 *
 *    Description: Prototypes des fonctions sur les éléments 
 *
 *        Version:  1.0
 *        Created:  06/11/2012 18:14:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __ELEMENT
#define __ELEMENT

typedef struct {
	int nb;
} Element;


void elem_display(const Element pElem);
void elem_saisir(Element* pElem);
void elem_affect(Element* pElem1, const Element pElem2);
void elem_initialize(Element* pElem);

#endif

