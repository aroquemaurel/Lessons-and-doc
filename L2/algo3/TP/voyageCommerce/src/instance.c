/*
 * =====================================================================================
 *
 *       Filename:  instance.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/11/2012 22:03:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */
#include "instance.h"


// TODO name/type/DISPLAY_DATA_SECTION => parsing.
void instance_initialize(Instance* pInstance, FILE* pFile) {
	int i;
	char buffFgets[1000] = "";
	
	Town townBuff;
	pInstance->nbTown = 0;
	for(i=0 ; !feof(pFile); ++i) {
		fgets(buffFgets, 1000, pFile);
		printf("%s\n", buffFgets);
		town_initialize(&townBuff, buffFgets);
		instance_push(pInstance, townBuff);
	}
}

void instance_display(const Instance pInstance) {

}

void instance_push(Instance* pInstance, const Town pTown) { // TODO exception nbTown != 500. TODO Defines
	pInstance->towns[pInstance->nbTown++] = pTown;
}
