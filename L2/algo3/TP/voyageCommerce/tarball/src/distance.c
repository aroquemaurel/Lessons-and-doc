/**
 * \file distance.c
 * \brief Fonctions des distances 
 * \author Antoine de Roquemaurel
 * \date 01/12/2012 20:33:39
 *
 * Entêtes des fonctions se rapportant aux distances
 *
 */

#include "distance.h"
#include "util.h"
Distance distance_new(Town pFirstTown, Town pSecondTown) {    
    Distance newDistance;
	newDistance.firstTown = pFirstTown;
	newDistance.secondTown = pSecondTown;
	newDistance.distance = distance_calculDistance(pFirstTown, pSecondTown);
    
    return newDistance;
}

double distance_calculDistance(const Town pTown1, const Town pTown2) {
	double x1=pTown1.x, x2=pTown2.x;
	double y1=pTown1.y, y2=pTown2.y;
	return (sqrt(pow(x1 - x2, 2) + 
            pow(y1 - y2, 2)
			)); //Pythagore
}

Distance distance_betweenTowns(Distance* pDistances, Town i, Town j) {
	if(i.id < j.id) {
		util_swap(&i, &j);
	} 

	return (pDistances[util_sum(0,i.id-1)+j.id-1]);
}
