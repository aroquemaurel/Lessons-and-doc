/*
 * Spécification disponible dans specification.pdf
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

void fillArray(int* array, int size) ;
void displayArray(int* array, int size) ;
bool isPalindrome(int* array, int size) ;

int main(int argc, char** argv) {
	int i;
	int tab[N];
	int size = 0;

	printf("Donnez la dimension du tableau ");
	do {
		scanf("%d", &size);
	} while (i > 10);

	fillArray(tab, size);
	displayArray(tab, size);

	if(isPalindrome(tab, size)) {
		printf("Le tableau est un palindrome");
	} else {
		printf("Le tableau n'est pas un palindrome");
	}

	return 0;
}

bool isPalindrome(int* array, int size) {
	int i = 0;

	for(i = 0 ; i <= size/2 ; ++i) {
		if(array[i] != array[size-i-1])	{
			return false;	
		}
	}

	return true;
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

