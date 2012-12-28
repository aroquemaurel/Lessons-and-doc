/*
 * File:   tourTest.c
 * Author: aroquemaurel
 *
 * Created on 28 déc. 2012, 02:59:52
 */

#include <stdio.h>
#include <stdlib.h>
#include "tour.h"

/*
 * Simple C Test Suite
 */

void tour_toString(Tour pTour);

void testTour_display() {
	Tour pTour;
	tour_toString(pTour);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testTour_display (tourTest) message=error message sample\n");
	}
}

void tour_initialize(Tour* pTour, Instance pInstance);

void testTour_initialize() {
	Tour* pTour;
	Instance pInstance;
	tour_initialize(pTour, pInstance);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testTour_initialize (tourTest) message=error message sample\n");
	}
}

_Bool tour_nextPermutation(Tour* pPermutation);

void testTour_nextPermutation() {
	Tour* pPermutation;
	_Bool result = tour_nextPermutation(pPermutation);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testTour_nextPermutation (tourTest) message=error message sample\n");
	}
}

void tour_calculLength(Tour* pTour, Distance* pDistance);

void testTour_calculLength() {
	Tour* pTour;
	Distance* pDistance;
	tour_calculLength(pTour, pDistance);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testTour_calculLength (tourTest) message=error message sample\n");
	}
}

int main(int argc, char** argv) {
	printf("%%SUITE_STARTING%% tourTest\n");
	printf("%%SUITE_STARTED%%\n");

	printf("%%TEST_STARTED%%  testTour_display (tourTest)\n");
	testTour_display();
	printf("%%TEST_FINISHED%% time=0 testTour_display (tourTest)\n");

	printf("%%TEST_STARTED%%  testTour_initialize (tourTest)\n");
	testTour_initialize();
	printf("%%TEST_FINISHED%% time=0 testTour_initialize (tourTest)\n");

	printf("%%TEST_STARTED%%  testTour_nextPermutation (tourTest)\n");
	testTour_nextPermutation();
	printf("%%TEST_FINISHED%% time=0 testTour_nextPermutation (tourTest)\n");

	printf("%%TEST_STARTED%%  testTour_calculLength (tourTest)\n");
	testTour_calculLength();
	printf("%%TEST_FINISHED%% time=0 testTour_calculLength (tourTest)\n");

	printf("%%SUITE_FINISHED%% time=0\n");

	return (EXIT_SUCCESS);
}
