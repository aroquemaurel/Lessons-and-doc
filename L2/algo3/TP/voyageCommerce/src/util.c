/*
 * =====================================================================================
 * *       Filename:  util.c *
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

char** util_split(char* str, const char c, int* size ) {
	static char* tmp[256];
	int current = 0;
	tmp[current++] = str;

	while(*str) {
		if (*str == c) {
			*str = '\0';
			tmp[current++] = str+1; 
		}

		++str;
	}
	tmp[current] = 0;

	*size = current;

	return tmp;
} 

inline void util_displayVerboseMode(char* pString) {
	if(gVerboseMode) {
		printf("%s", pString);
	}
}

void util_reverseArray(int* pTab, const int pBegin, const int pEnd) {
	int i = pBegin;
	int j = pEnd;
	int buff;

	while(i < j) {
		buff = pTab[i];
		pTab[i] = pTab[j];
		pTab[j] = buff;
		++i;
		--j;
	}
}

bool util_arrayIsEqual(int* pTab1, int* pTab2, int pSize) {
	int i = 0;
	bool equals = true;
	for(i=0 ; (i < pSize) ; ++i) {
		if(pTab1[i] != pTab2[2]) {
			equals = false;
			break;
		}
	}

	return equals;
}

void util_displayArray(const int* pTab, const int pSize) {
	int i;
	for(i=0 ; i < pSize ; ++i) {
		printf("%d ", pTab[i]);
	}
}
