/*
 * =====================================================================================
 *
 *       Filename:  errors.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/11/2012 17:42:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */

#include "errors.h"
void errors_initialize(Errors* pErrors) {
	pErrors->errorNbArguments = NULL;
	pErrors->errorTagFNotFound = NULL;
	pErrors->errorFileNotFound = NULL;
	pErrors->errorNoAlgoSpecified = NULL;
	pErrors->errorLsrNotValidParameter = NULL;
	pErrors->nbErrors = 0;
}
void errors_displayErrorsMessage(Errors* pErrors) {
	++pErrors->nbErrors;
}

void errors_setNbArguments(Errors* pErrors) {
	++pErrors->nbErrors;
}

void errors_setTagFNotFound(Errors* pErrors) {
	++pErrors->nbErrors;
}

void errors_setFileNotFound(Errors* pErrors, char* fileName) {
	++pErrors->nbErrors;
}

void errors_setNoAlgoSpecified(Errors* pErrors) {
	++pErrors->nbErrors;
}

void errors_setLsrNotValidParameter(Errors* pErrors) {
	++pErrors->nbErrors;
}

