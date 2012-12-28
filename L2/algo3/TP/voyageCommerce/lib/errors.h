/*
 * =====================================================================================
 *
 *       Filename:  errors.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/11/2012 17:42:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __ERRORS
#define __ERRORS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char* errorNbArguments;
	char* errorTagFNotFound;
	char* errorFileNotFound;
	char* errorNoAlgoSpecified;
	char* errorLsrNotValidParameter;
	int nbErrors;
} Errors;

void errors_initialize(Errors* pErrors);
void errors_displayErrorsMessage(const Errors pErrors);
void errors_setNbArguments(Errors* pErrors);
void errors_setTagFNotFound(Errors* pErrors);
void errors_setFileNotFound(Errors* pErrors, char* fileName);
void errors_setNoAlgoSpecified(Errors* pErrors);
void errors_setLsrNotValidParameter(Errors* pErrors);
#endif

