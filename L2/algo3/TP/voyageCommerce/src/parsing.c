/*
 * =====================================================================================
 *
 *       Filename:  parsing.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/11/2012 17:17:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */
#include "parsing.h"

bool parsing_parseVerboseMode(char** pTab, const int pSize) {
	return (util_searchFirstOccurenceInArray(pTab, pSize, "-v") != -1);
}

char* parsing_parseFileName(char** pTab, const int pSize, Errors* pErrors) {
	int posTiretF = util_searchFirstOccurenceInArray(pTab, pSize, "-f");
	if(posTiretF == -1) {
		errors_setTagFNotFound(pErrors);
		return (NULL);
	}

	return (pTab[posTiretF+1]);
}

AlgoType parsing_algoType(char** pTab, const int pSize, Errors* pErrors, int* param1AlgoType, int* param2AlgoType) {
	AlgoType returnAlgoType;
	int positionTag;
	if(util_searchFirstOccurenceInArray(pTab, pSize, "-bf") != -1) {
		returnAlgoType = BRUTEFORCE;	
	} else if((positionTag = util_searchFirstOccurenceInArray(pTab, pSize, "-lsr")) != -1) {
		if(pTab[positionTag+1] == NULL) {
				//TODO Paramètre manquant 
		} else if(atoi(pTab[positionTag+1]) == 0) {
			/// TODO Erreur paramètre après -lsr non entier ou = 0	
		} else {
			*param1AlgoType = atoi(pTab[positionTag+1]);
			returnAlgoType =LOCALSEARCH_RANDOM ;	
		}
	} else if((positionTag = util_searchFirstOccurenceInArray(pTab, pSize, "-lsnr")) != -1) {
		if(pTab[positionTag+1] == NULL) {
				//TODO Paramètre manquant 
		} else if(atoi(pTab[positionTag+1]) == 0) {
			/// TODO Erreur paramètre après -lsnr non entier ou = 0	
		} else {
			*param1AlgoType = atoi(pTab[positionTag+1]);
			returnAlgoType =LOCALSEARCH_SYSTEMATIC;	
		}
	} else if((positionTag = util_searchFirstOccurenceInArray(pTab, pSize, "-ga")) != -1) {
		if(pTab[positionTag+1] == NULL) {
				//TODO Paramètre manquant 
		} else if(atoi(pTab[positionTag+1]) == 0) {
			/// TODO Erreur paramètre après -lsnr non entier ou = 0	
		} else {
			*param1AlgoType = atoi(pTab[positionTag+1]);
			if(pTab[positionTag+2] == NULL) {
				//TODO Paramètre manquant 
			} else if(atoi(pTab[positionTag+2]) == 0) {
				/// TODO Erreur paramètre après -lsnr non entier ou = 0	
			} else {
				*param2AlgoType = atoi(pTab[positionTag+2]);
				returnAlgoType = GENETIC;
			}
		}
	} else {
		errors_setNoAlgoSpecified(pErrors);
	}

	return returnAlgoType;
}