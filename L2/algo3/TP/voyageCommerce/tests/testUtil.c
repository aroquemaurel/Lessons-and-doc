/*
 * =====================================================================================
 *
 *       Filename:  testUtil.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/11/2012 18:48:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lib/util.h"
#include "testUtil.h"

void test_searchFirstOccurenceInArray(const int pNumTest) {
	int returnExpected, returnObtained;
	char* array1[6] = {"test", "truc", "chose", "chouette", "", "unMot"};
	char* array2[1] = {"truc"};
	int  array3[4] =  {0, 1, 2, 3};

	char* fctName = "test_searchFirstOccurenceInArray";
	bool test = true;
	switch(pNumTest) {
		case 1:
			returnExpected = 0;
			test = ((returnObtained = util_searchFirstOccurenceInArray(array1, 6, "test")) == returnExpected);
			break;
		case 2:
			returnExpected = -1;
			test = ((returnObtained = util_searchFirstOccurenceInArray(array1, 6, "testouilleeuuh")) == returnExpected);
			break;
		case 3:
			returnExpected = 5;
			test = ((returnObtained = util_searchFirstOccurenceInArray(array1, 6, "unMot")) == returnExpected);
			break;
		case 4:
			returnExpected = 4;
			test = ((returnObtained = util_searchFirstOccurenceInArray(array1, 6, "")) == returnExpected);
			break;
		case 5:
			returnExpected = -1;
			test = ((returnObtained = util_searchFirstOccurenceInArray(array2, 1, "unMot")) == returnExpected);
			break;
		case 6:
			break;
	}
	displayResults(test, pNumTest,fctName, returnObtained, returnExpected);
}

