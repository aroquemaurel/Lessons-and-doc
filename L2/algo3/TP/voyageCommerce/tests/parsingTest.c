/*
 * File:   parsingTest.c
 * Author: aroquemaurel
 *
 * Created on 28 déc. 2012, 02:57:15
 */

#include <stdio.h>
#include <stdlib.h>

#include "parsing.h"
/*
 * Simple C Test Suite
 */

AlgoType parsing_algoType(char** pTab, const int pSize, Errors* pErrors, int* param1AlgoType, int* param2AlgoType);

void testParsing_algoType() {
	char** pTab;
	const int pSize;
	Errors* pErrors;
	int* param1AlgoType;
	int* param2AlgoType;
	AlgoType result = parsing_algoType(pTab, pSize, pErrors, param1AlgoType, param2AlgoType);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testParsing_algoType (parsingTest) message=error message sample\n");
	}
}

char* parsing_parseFileName(char** pTab, const int pSize, Errors* pErrors);

void testParsing_parseFileName() {
	char** pTab;
	const int pSize;
	Errors* pErrors;
	char* result = parsing_parseFileName(pTab, pSize, pErrors);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testParsing_parseFileName (parsingTest) message=error message sample\n");
	}
}

_Bool parsing_parseVerboseMode(char** pTab, const int pSize);

void testParsing_parseVerboseMode() {
	char** pTab;
	const int pSize;
	_Bool result = parsing_parseVerboseMode(pTab, pSize);
	if (1 /*check result*/) {
		printf("%%TEST_FAILED%% time=0 testname=testParsing_parseVerboseMode (parsingTest) message=error message sample\n");
	}
}

int main(int argc, char** argv) {
	printf("%%SUITE_STARTING%% parsingTest\n");
	printf("%%SUITE_STARTED%%\n");

	printf("%%TEST_STARTED%%  testParsing_algoType (parsingTest)\n");
	testParsing_algoType();
	printf("%%TEST_FINISHED%% time=0 testParsing_algoType (parsingTest)\n");

	printf("%%TEST_STARTED%%  testParsing_parseFileName (parsingTest)\n");
	testParsing_parseFileName();
	printf("%%TEST_FINISHED%% time=0 testParsing_parseFileName (parsingTest)\n");

	printf("%%TEST_STARTED%%  testParsing_parseVerboseMode (parsingTest)\n");
	testParsing_parseVerboseMode();
	printf("%%TEST_FINISHED%% time=0 testParsing_parseVerboseMode (parsingTest)\n");

	printf("%%SUITE_FINISHED%% time=0\n");

	return (EXIT_SUCCESS);
}
