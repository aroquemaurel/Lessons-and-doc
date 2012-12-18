/*
 * Spécification disponible dans specification.pdf
 */
#include <stdio.h>
#include <stdlib.h>

#define N 100

void fillArray(int* array, int size) ;
void displayArray(int* array, int size) ;

int main(int argc, char** argv) {
	int i;
	int tab[N];
	int size = 10;
	int nbEltsNoNull = 0;

	fillArray(tab, size);
	displayArray(tab, size);

	// remplace les valeurs impaires par zéro
	for(i = 0 ; i < size ; ++i) {
		if(tab[i] % 2 != 0) {
			tab[i] = 0;
		}
	}
	displayArray(tab, size);

	// remplaçant le contenu des cases d'indices impaires par zéro
	for(i = 0 ; i < size ; ++i) {
		if(i % 2 != 0) {
			tab[i] = 0;
		}
		if(tab[i] != 0) {
			++nbEltsNoNull;
		}
	}
	displayArray(tab, size);

	printf("%d élément(s) non nuls", nbEltsNoNull);
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

