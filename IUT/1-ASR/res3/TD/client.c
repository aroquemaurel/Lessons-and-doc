/*
 * =====================================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/10/2011 16:40:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Antoine de Roquemaurel (), 
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char** argv) {
	int ecode;
	int sizeBuff;
	int descSockRDV;
	struct addrinfo* hints;

	descSockRDV = socket(AF_INET, SOCK_STREAM, 0);
	if(descSockRDV == -1){
		perror("erreur socket RDV");
		exit(2);
	}

	return EXIT_SUCCESS;
}
