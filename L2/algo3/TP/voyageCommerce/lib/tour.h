/*
 * =====================================================================================
 *
 *       Filename:  tour.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/11/2012 22:04:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __TOUR
#define __TOUR

#include <stdlib.h>
#include <stdbool.h>

#include "town.h"
#include "instance.h"
#include "distance.h"
typedef struct {
	Town towns[N];
	int nbTowns;
	double length;
}Tour;

void tour_initialize(Tour* pTour, Instance pInstance);
bool tour_nextPermutation(Tour* pPermutation);
void tour_calculLength(Tour* pTour, Distance* pDistance);
#endif


