/*
 * File:   instanceTest.c
 * Author: aroquemaurel
 *
 * Created on 28 déc. 2012, 02:56:56
 */

#include <stdio.h>
#include <stdlib.h>

#include "instance.h"
/*
 * Simple C Test Suite
 */

void test1() {
	printf("instanceTest test 1\n");
}

void test2() {
	printf("instanceTest test 2\n");
	printf("%%TEST_FAILED%% time=0 testname=test2 (instanceTest) message=error message sample\n");
}

int main(int argc, char** argv) {
	printf("%%SUITE_STARTING%% instanceTest\n");
	printf("%%SUITE_STARTED%%\n");

	printf("%%TEST_STARTED%% test1 (instanceTest)\n");
	test1();
	printf("%%TEST_FINISHED%% time=0 test1 (instanceTest) \n");

	printf("%%TEST_STARTED%% test2 (instanceTest)\n");
	test2();
	printf("%%TEST_FINISHED%% time=0 test2 (instanceTest) \n");

	printf("%%SUITE_FINISHED%% time=0\n");

	return (EXIT_SUCCESS);
}
