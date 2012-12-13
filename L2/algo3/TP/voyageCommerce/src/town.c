/*
 * =====================================================================================
 *
 *       Filename:  town.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/11/2012 22:35:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */

#include "town.h"
void town_initialize(Town* pTown, const int pId, const int pX, const int pY) {
	pTown->id = pId;
	pTown->x = pX;
	pTown->y = pY;
/*  char** test;
	int i=0, j=0;
	int size;
	test = util_split(pString, ' ', &size);
	while(i < size-1) {
		++i;
		if(strcmp(test[i], "\0") != 0) { // Si ce n'est pas une chaine vide, c'est pour nous :) 
			if(j == 0)
				pTown->id = atoi(test[i]);
			if(j == 1)
				pTown->x = atoi(test[i]);
			if(j == 2)
				pTown->y = atoi(test[i]);
			++j;
		}
	}
 */
}
