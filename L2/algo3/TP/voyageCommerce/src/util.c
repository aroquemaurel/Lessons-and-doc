/*
 * =====================================================================================
 *
 *       Filename:  util.c
 *
 *    Description: Implémentations des fonctions pouvant être utiles dans tout le projet.
 *					Ce sont des fonctions simples, qui doivent être indépendantes du projet.
 *
 *        Version:  1.0
 *        Created:  19/11/2012 16:27:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */
#include "util.h"

int util_searchFirstOccurenceInArray(char** pArray, const int pSize, char* pSearch) {
	int position=0;

	while(position < pSize -1 && strcmp(pArray[position], pSearch) != 0 ) {
		++position;
	}

	return (position == pSize-1 && strcmp(pArray[position], pSearch) != 0) ? -1 : position;
}

inline void util_displayVerboseMode(char* pString) {
	if(gVerboseMode) {
		printf("%s", pString);
	}

}
