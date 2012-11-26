/*
 * =====================================================================================
 *
 *       Filename:  parsing.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/11/2012 17:17:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __PARSING
#define __PARSING

#include "util.h"
#include "errors.h"
typedef enum { BRUTEFORCE, LOCALSEARCH_RANDOM, LOCALSEARCH_SYSTEMATIC, GENETIC} AlgoType;
bool parsing_parseVerboseMode(char** pTab, const int pSize);
char* parsing_parseFileName(char** pTab, const int pSize, Errors* pErrors);
AlgoType parsing_algoType(char** pTab, const int pSize, Errors* pErrors, int* param1AlgoType, int* param2AlgoType);

#endif


