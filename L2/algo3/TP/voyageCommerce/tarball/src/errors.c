/**
 * \file errors.c
 * \brief Fonctions sur les erreurs.
 * \author Antoine de Roquemaurel
 * \date 21/11/2012 17:42:31
 *
 * Implémentation des fonctions concernant les erreurs du programme.  
  *
 */

#include "errors.h"

Errors errors_new() {
    Errors ret;
	ret.errorNbArguments = NULL;
	ret.errorTagFNotFound = NULL;
	ret.errorFileNotFound = NULL;
	ret.errorNoAlgoSpecified = NULL;
    ret.errorMissingParameterGa = NULL;
    ret.errorMissingParameterLsnr = NULL;
    ret.errorMissingParameterLsr = NULL;
    ret.errorNoValidParameterGa = NULL;
    ret.errorNoValidParameterLsnr = NULL;
    ret.errorNoValidParameterLsr = NULL;
	ret.nbErrors = 0;
    
    return ret;
}
void errors_displayErrorsMessage(const Errors pErrors) {
	printf("%d erreur%s lors de la saisie de la commande\n",
				pErrors.nbErrors, (pErrors.nbErrors > 1)? "s" : "");
	printf("Usage: ./travellingSalesman [-v] -f file -bf|-lsr nbEssai|-lsnr nbEssai|-ga nbGeneration tauxMutation \n\n");				

	if(pErrors.errorNbArguments != NULL)
		printf("%s", pErrors.errorNbArguments);

	if(pErrors.errorTagFNotFound!= NULL)
		printf("%s", pErrors.errorTagFNotFound);
	
	if(pErrors.errorFileNotFound != NULL)
		printf("%s", pErrors.errorFileNotFound);
	
	if(pErrors.errorNoAlgoSpecified != NULL)
		printf("%s", pErrors.errorNoAlgoSpecified);
	
    if(pErrors.errorMissingParameterLsr != NULL)
		printf("%s", pErrors.errorMissingParameterLsr);
        
    if(pErrors.errorMissingParameterLsnr != NULL)
		printf("%s", pErrors.errorMissingParameterLsnr);
        
    if(pErrors.errorMissingParameterGa != NULL)
		printf("%s", pErrors.errorMissingParameterGa);        
    
    if(pErrors.errorNoValidParameterLsr != NULL)
		printf("%s", pErrors.errorNoValidParameterLsr);        
    
    if(pErrors.errorNoValidParameterLsnr != NULL)
		printf("%s", pErrors.errorNoValidParameterLsnr);        

    if(pErrors.errorNoValidParameterGa != NULL)
		printf("%s", pErrors.errorNoValidParameterGa);        
}

void errors_setTagFNotFound(Errors* pErrors) {
	++pErrors->nbErrors;
	pErrors->errorTagFNotFound = "ERREUR: Balise -f non trouvée\n";
}

void errors_setFileNotFound(Errors* pErrors, char* fileName) {
	++pErrors->nbErrors;
	pErrors->errorFileNotFound = "ERREUR: Fichier non trouvée\n";
}

void errors_setNoAlgoSpecified(Errors* pErrors) {
	++pErrors->nbErrors;
	pErrors->errorNoAlgoSpecified = "ERREUR: Algorithme non spécifié\n";
}

void errors_setMissingParameterLsr(Errors* pErrors) {
    ++pErrors->nbErrors;
    pErrors->errorMissingParameterLsr = "ERREUR: Paramètre manquant après -lsr\n";
}

void errors_setMissingParameterLsnr(Errors* pErrors) {
    ++pErrors->nbErrors;
    pErrors->errorMissingParameterLsnr = "ERREUR: Paramètre manquant après -lsnr\n";
}

void errors_setMissingParameterGa(Errors* pErrors) {
    ++pErrors->nbErrors;
    pErrors->errorMissingParameterGa = "ERREUR: Paramètre manquant après -ga\n";
}

void errors_setNoValidParameterLsr(Errors* pErrors) {
    ++pErrors->nbErrors;
    pErrors->errorNoValidParameterLsr = "ERREUR: Paramètre non valide après -lsr\n";
}

void errors_setNoValidParameterLsnr(Errors* pErrors) {
    ++pErrors->nbErrors;
    pErrors->errorNoValidParameterLsnr = "ERREUR: Paramètre non valide après -lsnr\n";
}

void errors_setNoValidParameterGa(Errors* pErrors) {
    ++pErrors->nbErrors;
    pErrors->errorNoValidParameterGa = "ERREUR: Paramètre non valide après -ga\n";
}
