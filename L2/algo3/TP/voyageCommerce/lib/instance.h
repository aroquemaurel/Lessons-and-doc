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
#include "distance.h"
#include "util.h"
#include <stdbool.h>
#include <string.h>

#define N 512
typedef struct {
	Town towns[N];
	Distance distances[N];
	int nbTown;
	char* name;
	char* type;
} Instance;

void instance_display(const Instance pInstance);
void instance_initialize(Instance* pInstance, FILE* pFile);
void instance_push(Instance* pInstance, const Town pTown);
void instance_initializeDistances(Instance* pInstance);
#endif


