/*
 * =====================================================================================
 *
 *       Filename:  tour.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/11/2012 22:04:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */
#include "tour.h"

bool tour_nextPermutation(Town* pPermutation, const int pSize) {
	int i=pSize-1;
	Town buff;
	bool found=false;
	int k=pSize-1; 

	while(pPermutation[k].id >= pPermutation[k+1].id && k >= 0) {
		--k;
	}

	if(k != -1) {
		found = true;
		while(pPermutation[k].id >= pPermutation[i].id && i > k+1) {
			--i;
		}
		buff = pPermutation[k];
		pPermutation[k] = pPermutation[i];
		pPermutation[i] = buff;

		util_reverseArray(pPermutation, k+1, pSize-1); 
	}

	return found;
}
