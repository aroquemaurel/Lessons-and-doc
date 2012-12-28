/*
 * =====================================================================================
 *
 *       Filename:  distance.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2012 20:33:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */
#include "distance.h"
#include "util.h"
void distance_new(Distance* pDistance, Town* pFirstTown, Town* pSecondTown) {
	pDistance->firstTown = *pFirstTown;
	pDistance->secondTown = *pSecondTown;
	pDistance->distance = distance_calculDistance(*pFirstTown, *pSecondTown);
}

double distance_calculDistance(const Town pTown1, const Town pTown2) {
	double x1=pTown1.x, x2=pTown2.x;
	double y1=pTown1.y, y2=pTown2.y;
	return (sqrt(pow((x1 > x2) ? x1 - x2 : x2 - x1, 2) + 
				 pow((y1 > y2) ? y1 - y2 : y2 - y1, 2)
			)); //Pythagore
}

Distance distance_searchDistance(Distance* pDistances, const int pFirst, const int pSecond) {
	int i = util_sum(0,pFirst-1);
	int j;
	int search = 0;

	Distance test;
	
	return (pDistances[i+pSecond-1]);
}

double distance_betweenTowns(Distance* pDistances, int i, int j) {
	Distance distance;
	if(i < j) {
		util_swap(&i, &j);
	} else if(j == i) {
		return 0;
	}
	distance = distance_searchDistance(pDistances, i, j);

	return (distance.distance);
}
