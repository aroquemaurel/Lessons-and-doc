/*
 * File:   townTest.c
 * Author: aroquemaurel
 *
 * Created on 28 déc. 2012, 02:59:31
 */

#include <stdio.h>
#include <stdlib.h>

#include "town.h"
/*
 * Simple C Test Suite
 */

void town_initialize(Town* pTown, const int pId, const int pX, const int pY);

void testTown_initialize() {
	Town* pTown;
	const int pId;
	const int pX;
	const int pY;
	town_initialize(pTown, pId, pX, pY);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testTown_initialize (townTest) message=error message sample\n");
	}
}

int main(int argc, char** argv) {
	printf("%%SUITE_STARTING%% townTest\n");
	printf("%%SUITE_STARTED%%\n");

	printf("%%TEST_STARTED%%  testTown_initialize (townTest)\n");
	testTown_initialize();
	printf("%%TEST_FINISHED%% time=0 testTown_initialize (townTest)\n");

	printf("%%SUITE_FINISHED%% time=0\n");

	return (EXIT_SUCCESS);
}
