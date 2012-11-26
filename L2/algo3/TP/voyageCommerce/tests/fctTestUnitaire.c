/*
 * =====================================================================================
 *
 *       Filename:  fctTestUnitaire.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/11/2012 20:18:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */
#include "fctTestUnitaire.h"

inline void displayResults(const bool pResult, const int pNumTest, char* pFctName, const int pReturnObtained, const int pReturnExpected) {
	(pResult) ? printf("\033[32m[Passed]\033[0m Test %d on %s.", pNumTest, pFctName) : 
				printf("\033[031m[Failed]\033[0m Test %d on %s Return %d instead of %d.", pNumTest, pFctName, pReturnObtained, pReturnExpected);

	printf("\n");
}
