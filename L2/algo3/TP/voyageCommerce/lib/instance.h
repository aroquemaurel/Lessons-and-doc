/*
 * =====================================================================================
 *
 *       Filename:  instance.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/11/2012 22:03:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __INSTANCE
#define __INSTANCE

#include "town.h"
#include <stdbool.h>
typedef struct {
	Town towns[512];
	int nbTown;
	char* name;
	char* type;
}Instance;

void instance_display(const Instance pInstance);
void instance_initialize(Instance* pInstance, FILE* pFile);
void instance_push(Instance* pInstance, const Town pTown);

#endif


