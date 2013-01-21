/**
 * \file bruteForce.c
 * \brief Fonctions de brute force.
 * \author Antoine de Roquemaurel
 * \date 27/12/2012 17:58:29
 *
 * Implémentation des fonctions utilisant la force brute. 
 * Ces fonctions ne sont appelés que depuis le main
 *
 */

#include "bruteForce.h"
#include "util.h"

Tour bruteForce_bestPath(Instance pInstance) {
	Tour buffTour, bestTour;
	buffTour = tour_new(pInstance);
	bestTour = buffTour;

	do {
		tour_calculLength(&buffTour);
		if(buffTour.length < bestTour.length) {
			bestTour = buffTour;
            if(gVerboseMode) {
                printf("Tour : ");
                tour_display(buffTour);
                printf("\n\n");
            }
		}
        

	}while(tour_nextPermutation(&buffTour));

	return (bestTour);
}