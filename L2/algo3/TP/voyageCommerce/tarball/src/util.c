/**
 * \file util.c
 * \brief Fonctions utiles.
 * \author Antoine de Roquemaurel
 * \date 19/11/2012 16:27:39
 *
 * Entêtes des fonctions pouvant être utiles dans tout le projet. 
 * Ce sont des fonctions simples, qui doivent être indépendantes du projet.
 *
 */
#include "tour.h"

#include "util.h"

int util_searchFirstOccurenceInArray(char** pArray, const int pSize, char* pSearch) {
	int position=0;

	while(position < pSize -1 && strcmp(pArray[position], pSearch) != 0 ) {
		++position;
	}

	return (position == pSize-1 && strcmp(pArray[position], pSearch) != 0) ? -1 : position;
}

void util_reverseArray(Town* pTab, const int pBegin, const int pEnd) {
	int i = pBegin;
	int j = pEnd;
	Town buff;
	while(i < j) {
		buff = pTab[i];
		pTab[i] = pTab[j];
		pTab[j] = buff;
		++i;
		--j;
	}
}

void util_displayArray(const int* pTab, const int pSize) {
	int i;
	for(i=0 ; i < pSize ; ++i) {
		printf("%d ", pTab[i]);
	}
}

int util_sum(const int pBegin, const int pEnd) {
	int i=pBegin;
	int ret=0;
	while(i <= pEnd) {
		ret += i;
		++i;
	}

	return ret;
}

void util_swap(Town* a, Town* b) {
	Town buff;
	buff = *a;
	*a = *b;
	*b = buff;
}

int util_rand(const int pMin, const int pMax) {
    return ((rand() % (pMax - pMin + 1)) + pMin);
}


bool util_sousTabExist(Tour pChild, const int pBegin, const int pEnd, Tour pParent, bool pRecursvite) {
    int i, j;
    bool ret = false;
    for(i=0; i < pParent.nbTowns ; ++i) {
        if(pParent.towns[i].id == pChild.towns[pBegin].id) {
            ret=true; 
            for(j=1 ; j < pEnd-pBegin+1 ; ++j) {
                if(pParent.towns[i+j].id != pChild.towns[pBegin+j].id) {
                    if(pRecursvite) {
                        util_reverseArray(pChild.towns, pBegin, pEnd);
                        ret=util_sousTabExist(pChild, pBegin, pEnd, pParent, false);
                    } else {
                        ret = false;
                    }
                    break;
                }
            }
        }
    }

    return ret;
}

void util_deleteArrayValue(Path* pArray, int pSize, int pDeleteIndice) {
    int i;
    for(i = pDeleteIndice ; i < pSize ; ++i) {
        pArray[i] = pArray[i+1];
    }
}