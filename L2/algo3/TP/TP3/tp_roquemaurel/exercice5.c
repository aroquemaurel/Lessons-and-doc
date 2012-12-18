#include <stdio.h>

#define N 100

void fillArray(int* array, int size) ;
void displayArray(int* array, int size) ;
void insertSort(int* tab, int size) ;

int main(int argc, char** argv) {
	int tab[N];
	int size = 0;
	int i = 0;
printf("Donnez la dimension du tableau ");
	do {
		scanf("%d", &size);
	} while (i > 100);
	
	fillArray(tab, size);
	insertSort(tab, size);	
	displayArray(tab, size);

	return 0;
}
void insertSort(int* tab, int size) {
	int i, j;
	int elem;
	for (i = 1; i < size; ++i) {
		elem = tab[i];
		for (j = i; j > 0 && tab[j-1] > elem; --j) {
			tab[j] = tab[j-1];
		}

		tab[j] = elem;
	}
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

