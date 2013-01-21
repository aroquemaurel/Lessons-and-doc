/**
 * \file parsing.c
 * \brief Fonctions de parsing des arguments.
 * \author Antoine de Roquemaurel
 * \date 21/11/2012 17:17:18
 *
 * Implémentation des fonctions permettant de parser les arguments, et ainsi d'appeler les différents 
 * algorithmes demandés, d'utiliser le mode verbeux et de spécifier le fichier.
 *
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

void parsing_algoType(char** pTab, const int pSize, Errors* pErrors, Algo* algos) {
	int positionTag;
    int numberAlgo = 0;
	if(util_searchFirstOccurenceInArray(pTab, pSize, "-bf") != -1) {
		algos[numberAlgo].type = BRUTEFORCE;	
        algos[numberAlgo].firstParameter = algos[numberAlgo].secondParameter = -1;
        numberAlgo++;
	} 
    
    if((positionTag = util_searchFirstOccurenceInArray(pTab, pSize, "-lsr")) != -1) {
		if(pTab[positionTag+1] == NULL) {
            errors_setMissingParameterLsr(pErrors);
		} else if(atoi(pTab[positionTag+1]) == 0) {
            errors_setNoValidParameterLsr(pErrors);
		} else {
			algos[numberAlgo].type = LOCALSEARCH_RANDOM ;	
            algos[numberAlgo].firstParameter = atoi(pTab[positionTag+1]);
            numberAlgo++;
		}
	} 
    
    if((positionTag = util_searchFirstOccurenceInArray(pTab, pSize, "-lsnr")) != -1) {
		if(pTab[positionTag+1] == NULL) {
            errors_setMissingParameterLsnr(pErrors);
		} else if(atoi(pTab[positionTag+1]) == 0) {
            errors_setNoValidParameterLsnr(pErrors);
		} else {
			algos[numberAlgo].type =LOCALSEARCH_SYSTEMATIC;	
            algos[numberAlgo].firstParameter = atoi(pTab[positionTag+1]);
            numberAlgo++;
		} 
	} 
    
    if((positionTag = util_searchFirstOccurenceInArray(pTab, pSize, "-ga")) != -1) {
		if(pTab[positionTag+1] == NULL) {
            errors_setMissingParameterGa(pErrors);
		} else if(atoi(pTab[positionTag+1]) == 0) {
			errors_setNoValidParameterGa(pErrors);
		} else {
            algos[numberAlgo].firstParameter =  atoi(pTab[positionTag+1]);
			if(pTab[positionTag+2] == NULL) {
				errors_setMissingParameterGa(pErrors);
			} else if(atof(pTab[positionTag+2]) == 0) {
                errors_setNoValidParameterGa(pErrors);
			} else {
				algos[numberAlgo].secondParameter = atof(pTab[positionTag+2]);
				algos[numberAlgo].type = GENETIC;
                numberAlgo++;
			}
		}
	} 
    
    if(numberAlgo == 0) {
		errors_setNoAlgoSpecified(pErrors);
	}
    
    algos[numberAlgo].type = END; //Flag de fin
}