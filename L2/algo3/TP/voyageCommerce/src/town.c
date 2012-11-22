/*
 * =====================================================================================
 *
 *       Filename:  town.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/11/2012 22:35:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */
#include "town.h"
void town_initialize(char* pString) {
	char** test;
	int i=0;
	test = util_split(pString, ' ');
	while(test[i] != 0) {
		++i;
		if(strcmp(test[i], "\0") != 0) // TODO erreur de seg
			printf("%s|", test[i]);
	}
}
