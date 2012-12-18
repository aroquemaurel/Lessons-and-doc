#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main(int argc, char** argv) {
	int i = 0;
	int number;
	int randomNumber;
	bool find = false;

	srand(time(NULL));

	printf("Taper un nombre N :");
	scanf("%d", &number);

	printf("Entiers aléatoires : ");
	for(i = 0 ; i < number ; ++i) {
		randomNumber = rand()%100+1;
		printf(" %d ", randomNumber);
		if(randomNumber % 10 == 0) {
			printf("\nLe premier multiple de 10 est le %de généré : %d", i+1, randomNumber);
			find = true;
			break;
		}
	}

	if(!find) {
		printf("\nIl n'y a pas de multiple de 10 dans les nombres générés");
	}
	return 0;
}
