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


void instance_initialize(Instance* pInstance, FILE* pFile) {
	int dimension;
	bool displayData = false;
	char buffTag[255] = "";
	char buffValue[255] = "";
	int buffId;
	float buffX;
	float buffY;
	char name[256] = "";
	
	Town townBuff;
	pInstance->nbTown = 0;
	pInstance->name = "";
	while(!feof(pFile)) {
		if(!displayData) {
			fscanf(pFile, " %s %s", buffTag, buffValue);
		} else {
			fscanf(pFile, " %f %f", &buffX, &buffY);
			town_initialize(&townBuff, ++buffId, buffX, buffY);
			instance_push(pInstance, townBuff);

			if(buffId >= dimension) {
				fscanf(pFile, " %s", buffTag);
				displayData = false;
			}
		}

		if(strcmp(buffTag, "NAME:") == 0) {
			strcpy(name, buffValue);
		} else if(strcmp(buffTag, "DIMENSION:") == 0) {
			dimension = atoi(buffValue);
		} else if(strcmp(buffTag, "DISPLAY_DATA_SECTION") == 0) {
			displayData = true;
		}
	}
	pInstance->name = name;
}

void instance_display(const Instance pInstance) {

}

void instance_push(Instance* pInstance, const Town pTown) { // TODO exception nbTown != 500. TODO Defines ou dynamique
	pInstance->towns[pInstance->nbTown++] = pTown;
}
