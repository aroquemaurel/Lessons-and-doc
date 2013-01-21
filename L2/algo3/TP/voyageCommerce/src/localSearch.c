/**
 * \file localSearch.c
 * \brief Fonctions de recherche locale
 * \author Antoine de Roquemaurel
 * \date 27/12/2012 18:00:13
 *
 * Entêtes des fonctions ayant rapport avec les algorithmes de recherches locales. 
 *
 */
#include "util.h"
#include "localSearch.h"
#include "instance.h"
#include "tour.h"

Tour localSearch_randomBestPath(Instance pInstance, int pTryNb) {
	Tour ret, buffTour;
	int first2opt, second2opt;
	int i;

	buffTour = tour_randomWalk(pInstance);	
	ret = buffTour;
    if(gVerboseMode) {
        printf("Random walk:\n ");
        tour_display(buffTour);
        printf("\n\n");
    }
	for(i=0 ; i < pTryNb ; ++i) { 
		do { 
            first2opt = util_rand(1, pInstance.nbTowns);
            second2opt = util_rand(1, pInstance.nbTowns);
		} while(first2opt == second2opt || 
				(first2opt == second2opt-1 || second2opt == first2opt-1));
		tour_2opt(&buffTour, first2opt, second2opt); 

		if(buffTour.length < ret.length) { 
			ret = buffTour;
            if(gVerboseMode) {
                printf("\nMeilleur tour après 2opt numéro %d: \n", i+1);  
                tour_display(ret);
                printf("\n");
            }

		}
	}

	return ret;
}

Tour localSearch_systematicBestPath(Instance pInstance, int pTryNb) {
	Tour ret, buffTour;
	int first2opt, second2opt;
	int i;
	buffTour = tour_randomWalk(pInstance);	
	ret = buffTour;
	for(i=0 ; i < pTryNb ; ++i) {
		for(first2opt=1 ; first2opt <= buffTour.nbTowns ; ++first2opt) {
            for(second2opt=first2opt+2 ; second2opt <= buffTour.nbTowns ; ++second2opt ) {
                tour_2opt(&buffTour, first2opt, second2opt);
                if(buffTour.length < ret.length) {
                    ret = buffTour;
                    if(gVerboseMode) {
                        printf("\nMeilleur tour\n", i+1);  
                        tour_display(ret);
                        printf("\n");
                    }

                }
            }
		}
	}

	return ret;
}