/*
 * File:   distanceTest.c
 * Author: aroquemaurel
 *
 * Created on 28 déc. 2012, 02:56:47
 */

#include <stdio.h>
#include <stdlib.h>
#include "distance.h"
/*
 * Simple C Test Suite
 */

Distance distance_searchDistance(Distance* pDistances, const int pFirst, const int pSecond);

void testDistance_searchDistance() {
	Distance* pDistances;
	const int pFirst;
	const int pSecond;
	Distance result = distance_searchDistance(pDistances, pFirst, pSecond);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testDistance_searchDistance (distanceTest) message=error message sample\n");
	}
}

void distance_new(Distance* pDistance, Town* pFirstTown, Town* pSecondTown);

void testDistance_new() {
	Distance* pDistance;
	Town* pFirstTown;
	Town* pSecondTown;
	distance_new(pDistance, pFirstTown, pSecondTown);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testDistance_new (distanceTest) message=error message sample\n");
	}
}

double distance_calculDistance(const Town pTown1, const Town pTown2);

void testDistance_calculDistance() {
	const Town pTown1;
	const Town pTown2;
	double result = distance_calculDistance(pTown1, pTown2);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testDistance_calculDistance (distanceTest) message=error message sample\n");
	}
}

double distance_betweenTowns(Distance* pDistances, int i, int j);

void testDistance_betweenTowns() {
	Distance* pDistances;
	int i;
	int j;
	double result = distance_betweenTowns(pDistances, i, j);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testDistance_betweenTowns (distanceTest) message=error message sample\n");
	}
}

int main(int argc, char** argv) {
	printf("%%SUITE_STARTING%% distanceTest\n");
	printf("%%SUITE_STARTED%%\n");

	printf("%%TEST_STARTED%%  testDistance_searchDistance (distanceTest)\n");
	testDistance_searchDistance();
	printf("%%TEST_FINISHED%% time=0 testDistance_searchDistance (distanceTest)\n");

	printf("%%TEST_STARTED%%  testDistance_new (distanceTest)\n");
	testDistance_new();
	printf("%%TEST_FINISHED%% time=0 testDistance_new (distanceTest)\n");

	printf("%%TEST_STARTED%%  testDistance_calculDistance (distanceTest)\n");
	testDistance_calculDistance();
	printf("%%TEST_FINISHED%% time=0 testDistance_calculDistance (distanceTest)\n");

	printf("%%TEST_STARTED%%  testDistance_betweenTowns (distanceTest)\n");
	testDistance_betweenTowns();
	printf("%%TEST_FINISHED%% time=0 testDistance_betweenTowns (distanceTest)\n");

	printf("%%SUITE_FINISHED%% time=0\n");

	return (EXIT_SUCCESS);
}
