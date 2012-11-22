/*
 * =====================================================================================
 *
 *       Filename:  util.h
 *
 *    Description: Entêtes des fonctions pouvant être utiles dans tout le projet.
 *					Ce sont des fonctions simples, qui doivent être indépendantes du projet.
 *
 *        Version:  1.0
 *        Created:  19/11/2012 16:27:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __UTIL
#define __UTIL

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool gVerboseMode;

int util_searchFirstOccurenceInArray(char** pArray, const int pSize, char* pSearch);

inline void util_displayVerboseMode(char* pString);

#endif
