#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char** argv) {
	int nombre = 0;	

	printf("Entrez un nombre svp ");
	scanf("%d", &nombre);
	
	printf("%d * %d = %d\n", nombre, nombre, nombre*nombre);
	printf("sqrt(%d) = %f\n", nombre, sqrt(nombre));
	printf("exp(%d) = %f\n", nombre, exp(nombre));

	return 0;
}
