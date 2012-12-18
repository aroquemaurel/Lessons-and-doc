/*
 * Spécification disponible dans specification.pdf
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

void fillArray(int* array, int size) ;
void displayArray(int* array, int size) ;

int main(int argc, char** argv) {
	int i = 0 ;
	int array[N];
	int size = 3;
	int buff;

	fillArray(array, size);
	displayArray(array, size);

	for(i = 0 ; i <= size/2 ; ++i) {
		buff = array[i];
		array[i] = array[size-i-1];
		array[size-i-1] = buff;
	}
	displayArray(array, size);
	return 0;
}

void fillArray(int* array, int size) {
	int i = 0;

	for(; i < size ; ++i) {
		printf("Entrez la valeur numéro %d ", i+1);	
		scanf("%d", array+i);
	}
	printf("\n");
}

void displayArray(int* array, int size) {
	int i = 0;

	for(; i < size ; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

