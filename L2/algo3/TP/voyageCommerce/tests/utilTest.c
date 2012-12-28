/*
 * File:   utilTest.c
 * Author: aroquemaurel
 *
 * Created on 28 déc. 2012, 03:01:01
 */

#include <stdio.h>
#include <stdlib.h>

#include "util.h"
/*
 * Simple C Test Suite
 */

_Bool util_arrayIsEqual(int* pTab1, int* pTab2, int pSize);

void testUtil_arrayIsEqual() {
	int* pTab1;
	int* pTab2;
	int pSize;
	_Bool result = util_arrayIsEqual(pTab1, pTab2, pSize);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testUtil_arrayIsEqual (utilTest) message=error message sample\n");
	}
}

void util_reverseArray(Town* pTab, const int pBegin, const int pEnd);

void testUtil_reverseArray() {
	Town* pTab;
	const int pBegin;
	const int pEnd;
	util_reverseArray(pTab, pBegin, pEnd);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testUtil_reverseArray (utilTest) message=error message sample\n");
	}
}

int util_searchFirstOccurenceInArray(char** pArray, const int pSize, char* pSearch);

void testUtil_searchFirstOccurenceInArray() {
	char** pArray;
	const int pSize;
	char* pSearch;
	int result = util_searchFirstOccurenceInArray(pArray, pSize, pSearch);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testUtil_searchFirstOccurenceInArray (utilTest) message=error message sample\n");
	}
}

int util_sum(const int pBegin, const int pEnd);

void testUtil_sum() {
	const int pBegin;
	const int pEnd;
	int result = util_sum(pBegin, pEnd);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testUtil_sum (utilTest) message=error message sample\n");
	}
}

void util_swap(int* a, int* b);

void testUtil_swap() {
	int* a;
	int* b;
	util_swap(a, b);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testUtil_swap (utilTest) message=error message sample\n");
	}
}

int main(int argc, char** argv) {
	printf("%%SUITE_STARTING%% utilTest\n");
	printf("%%SUITE_STARTED%%\n");

	printf("%%TEST_STARTED%%  testUtil_arrayIsEqual (utilTest)\n");
	testUtil_arrayIsEqual();
	printf("%%TEST_FINISHED%% time=0 testUtil_arrayIsEqual (utilTest)\n");

	printf("%%TEST_STARTED%%  testUtil_reverseArray (utilTest)\n");
	testUtil_reverseArray();
	printf("%%TEST_FINISHED%% time=0 testUtil_reverseArray (utilTest)\n");

	printf("%%TEST_STARTED%%  testUtil_searchFirstOccurenceInArray (utilTest)\n");
	testUtil_searchFirstOccurenceInArray();
	printf("%%TEST_FINISHED%% time=0 testUtil_searchFirstOccurenceInArray (utilTest)\n");

	printf("%%TEST_STARTED%%  testUtil_sum (utilTest)\n");
	testUtil_sum();
	printf("%%TEST_FINISHED%% time=0 testUtil_sum (utilTest)\n");

	printf("%%TEST_STARTED%%  testUtil_swap (utilTest)\n");
	testUtil_swap();
	printf("%%TEST_FINISHED%% time=0 testUtil_swap (utilTest)\n");

	printf("%%SUITE_FINISHED%% time=0\n");

	return (EXIT_SUCCESS);
}
