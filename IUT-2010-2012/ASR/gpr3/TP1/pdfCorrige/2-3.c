#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int nbParam, char** tabParam) {
	int nbre;
	int* ptr = NULL;

	switch (nbParam) {
		case 2 : /* conversion du parametre 1 */
			sscanf(tabParam[1], "%d",&nbre);
		break;
		default : 
			printf("***fils2 --> nombre de parametres incorrect!!!");
		  exit(1);
	}

	printf("\n***fils2 --> PID= %d\n", getpid());
	printf("***fils2 --> tabParam[1]= %d\n", nbre);

	*ptr = 42; //woops, une seg fault
}

