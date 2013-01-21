/**
 * \file tour.c
 * \brief Fonctions des tournées.
 * \author Antoine de Roquemaurel
 * \date 21/11/2012 22:04:08
 *
 * Implémentation des fonctions se rapportant à une tournée. 
 *
 */

#include "tour.h"
#include "path.h"
#include "util.h"

Tour tour_new(Instance pInstance) {
    Tour ret;
	int i;
	ret.nbTowns = pInstance.nbTowns;
	ret.length = -1;
	for(i=0; i < pInstance.nbTowns; ++i) {
		ret.towns[i] = pInstance.towns[i];
	}
    ret.distances = pInstance.distances;
	tour_calculLength(&ret);
    
    return ret;
}
bool tour_nextPermutation(Tour* pPermutation) {
	int i=pPermutation->nbTowns-1;
	Town buff;
	bool found=false;
	int k=pPermutation->nbTowns-1; 

	while(pPermutation->towns[k].id >= pPermutation->towns[k+1].id && k >= 0) {
		--k;
	}
	if(k != -1) {
		found = true;
		while(pPermutation->towns[k].id >= pPermutation->towns[i].id && i > k+1) {
			--i;
		}
		buff = pPermutation->towns[k];
		pPermutation->towns[k] = pPermutation->towns[i];
		pPermutation->towns[i] = buff;
		util_reverseArray(pPermutation->towns, k+1, pPermutation->nbTowns-1); 
	}
	return found;
}

void tour_calculLength(Tour* pTour) {
	int i;
	double length=0;

	for (i = 0; i < pTour->nbTowns ; ++i) { 
		if(i+1 != pTour->nbTowns) {
			length += distance_calculDistance(pTour->towns[i], pTour->towns[i+1]);
		} else {
			length += distance_calculDistance(pTour->towns[i], pTour->towns[0]);
		}
	}
	pTour->length = length;	
}

void tour_display(const Tour pTour) {
    int i;
    for(i = 0 ; i < pTour.nbTowns ; ++i) {
        printf("%d ", pTour.towns[i].id);
    }
    printf("\nLa longueur de ce tour est %f", pTour.length);
}

Tour tour_randomWalk(const Instance pInstance) {
    Tour ret;
    ret = tour_new(pInstance);
	int i=0;
	int j=0;
	Town temp;

	for(i = 0; i< ret.nbTowns;i++){
		j=util_rand(0,ret.nbTowns-1);
		temp = ret.towns[i];
		ret.towns[i] = ret.towns[j];
		ret.towns[j] = temp;
	}
    tour_calculLength(&ret);
    return ret;
}


void tour_2opt(Tour* pTour, int pFirst, int pSecond) {
    pFirst--;
    if(pFirst > pSecond) {
        pFirst ^= pSecond ^= pFirst ^= pSecond;
    } 
    if(pSecond >= 10) {
        pSecond = 0;
    }
    util_reverseArray(pTour->towns, pFirst+1, pSecond-1);     
    tour_calculLength(pTour);
}

void tour_addTown(Tour* pTour, Town pTown) {
    pTour->towns[pTour->nbTowns++] = pTown;
}
void tour_addSeveralTowns(Tour* pTour, Town* pTowns, const int pNbTowns) {
    int i ;

    for(i=0 ; i < pNbTowns ; ++i) { 
        tour_addTown(pTour, pTowns[i]);
    }
}

void tour_replaceTheWorstTour(Tour* pTours, const int pSize, Tour pTour) {
    int least=0;
    int i;
    
    for(i=0 ; i < pSize ; ++i) {
        if(pTours[i].length > pTours[least].length) {
            least = i;
        }
    }
    
    pTours[least] = pTour;
}