#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* 
 * Gestion des erreurs 
 */
void error(char* message, int returnCode) {
	char* buff = (char*)malloc(strlen(message)+5+1);

	sprintf(buff, "[%d] %s", returnCode, message);
	perror(buff);
	free(buff);

	exit(returnCode);
}
