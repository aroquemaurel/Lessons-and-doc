#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv) {
	int nombre = 0;	

	printf("Entrez une année ");
	scanf("%d", &nombre);

	if((nombre%4 == 0 && nombre%100 != 0) || nombre%400 == 0) {
		printf("L'année est bissextile");
	} else {
		printf("L'année n'est pas bissextile");
	}
 
	return 0;
}
