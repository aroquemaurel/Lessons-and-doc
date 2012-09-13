#include <stdlib.h>
#include <stdio.h>
#include "chaine.h" 

void collerSousChaine(ChaineDyn *ch1, const ChaineDyn ch2, 
		const int p, const int n);

int main(int argc, char *argv[])
{
	collerSousChaine(&ch1, ch2, p, n);
}

void collerSousChaine(ChaineDyn *ch1, const ChaineDyn ch2, 
		const int p, const int n)
{
	int lgCh1, lgCh2, lgSousCh2;
	char *ptrAlloc; 

	if(p < 1 || p > lgCh2 || n < 0) {
		perror("Erreur paramètre(s)");	
		exit(1);
	}
	lgSousCh2 = lgCh2 - p + 1;
	if(lgSousCh2 > n){
		lgSousCh2 = n;
	}
	if(lgSousCh2 > 0){
		lgCh1 = (*ch1).nbCar;
		ptrAlloc = malloc(lgCh1 + lgSousCh2);
		if (ptrAlloc = NULL){
			perror("Erreur allocation");
			exit(1);
		}
		memcpy(ptrAlloc, (*ch1).ptrCar, lgCh1);
		memcpy(ptrAlloc + lgCh1, (ch2.ptrCar+p-1), lgSousCh2);
		if((*ch1).ptrCar != NULL){
			free((*ch1).ptrCar);
		}
		(*ch1).nbCar = lgCh1 + lgSousCh2;
		(*ch1).ptrCar = ptrAlloc;
	}
	
}
