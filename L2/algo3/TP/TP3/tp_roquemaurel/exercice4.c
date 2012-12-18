/*
 * Spécification disponible dans specification.pdf
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

void fillArray(int* array, int size) ;
void displayArray(int* array, int size) ;

void sortArrayWithArraySup(int* array, int size) ;
void sortArrayWithoutArraySup(int* array, int size) ;

int main(int argc, char** argv) {
	int i;
	int tab[N];
	int size = 0;

	printf("Donnez la dimension du tableau ");
	do {
		scanf("%d", &size);
	} while (i > 100);
	
	fillArray(tab, size);
//	sortArrayWithArraySup(tab, size);
	sortArrayWithoutArraySup(tab, size);
	return 0;
}
void sortArrayWithArraySup(int* array, int size) {
	int i = 0;
	int iPair = 0;
	int iImpair = size-1;
	int tab[N];

	for(i = 0 ; i < size ; ++i) {
		if(array[i] % 2 == 0) {
			tab[iPair] = array[i];
			++iPair;
		} else {
			tab[iImpair] = array[i];
			--iImpair;
		}
	}

	array = tab;
	displayArray(array, size);
}

void sortArrayWithoutArraySup(int* array, int size) {
	int i = 0;
	int iPair = 0;
	int iImpair = size-1;
	int buff;

	for(i = 0 ; i < size/2 ; ++i) {
		if(array[i] % 2 != 0) {
			while(array[iImpair] % 2 != 0 && iImpair != 0) {
				iImpair--;
			}
			buff = array[iImpair];
			array[iImpair] = array[i];
			array[i] = buff;
		}

	}

	displayArray(array, size);
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

