#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

int entryNumber() ;
int calculateDivisorsSum(int number) ;
bool isPerfectNumber(int number) ;
int* allPerfectNumber(int beginInterval, int endInterval) ;
void displayPerfectNumber(int beginInterval, int endInterval) ;
void switchIntervalNumber(int* beginInterval, int*  endInterval) ;
bool isFriends(int nombre1, int nombre2) ;
void displayFriendsCouple(int nombre1, int nombre2) ;
int sumDivides(int nombre) ;

int main(int argc, char** argv) {
	int numberChoice = 0;
	do {
		printf("Choisissez: \n\n");
		printf("1: Un entier est-il parfait?\n");
		printf("2: Chercher le parfait le plus proche.\n");
		printf("3: Tous les parfaits d'un intervalle.\n");
		printf("4: Deux entiers sont-ils amis ?\n");
		printf("5: Toutes les paires d'amis d'un intervalle.\n");
		printf("Pour s'arreter taper 6.\n");
		numberChoice = entryNumber();	

		switch(numberChoice) {
			case 1:
				printf("Entrez un nombre: ");
				(isPerfectNumber(entryNumber())) ?  printf("Le nombre est parfait !\n") : 
													printf("Le nombre n'est pas parfait\n");
				break;
			case 2:
				printf("Entrez un nombre: ");
				printf("Le nombre parfait le plus proche est %d\n", nearestPerfectNumbers(entryNumber()));
				break;
			case 3:
				printf("Entrez un intervalle: ");
				displayPerfectNumber(entryNumber(), entryNumber());
				break;
			case 4:
				(isFriends(entryNumber(), entryNumber())) ? printf("Les nombres sont amis") : printf("Les nombres ne sont pas amis");
				break;
			case 5:
				printf("Entrez un intervalle: ");
				displayFriendsCouple(entryNumber(), entryNumber());
				break;
			case 6:
				printf("Au revoir, et à bientôt pour de nouvelles aventures!\n");
				break;
			default:
				printf("Mauvais chiffre ! Essaye encore");

		}
	} while(numberChoice != 6);
	return 0;
}

int entryNumber() {
	int number = 0;

	do {
		scanf( "%d", &number);	
	} while(number <= 0);

	return (number);
}

int calculateDivisorsSum(int number) {
	int sum = 0;
	int i = 1;
	
	for(; i < number ; ++i) {
		if(number % i == 0) {
			sum += i;
		}
	}

	return (sum);
}

bool isPerfectNumber(int number) {
	int i;
	int sum = 0;

	for (i = 1 ; i <= number/2  ; ++i) {
		if (number % i == 0) {
			sum += i;
		}
	}

	return (sum == number);
}
void switchIntervalNumber(int* beginInterval, int* endInterval) {
	int buff;
	if(*beginInterval > *endInterval) {
		buff = *beginInterval;
		*beginInterval = *endInterval;
		*endInterval = buff;
	}
}
int* allPerfectNumber(int beginInterval, int endInterval) {
	int perfectsNumbers[N];
	int i;
	int j = 0;
	switchIntervalNumber(&beginInterval, &endInterval);

	for(i=beginInterval ; i < endInterval; ++i) {
		if(isPerfectNumber(i)) {
			perfectsNumbers[j] = i;
			++j;
		}
	}

	printf("\n ");
	perfectsNumbers[j] = -1; // Flag de fin du tableau

	return perfectsNumbers;

}

int nearestPerfectNumbers(int number) {
	int i = 0, j = 0;
	int distanceLower = 0;
	int distanceUpper= 0;

	for(i=number ; !isPerfectNumber(i) ; --i) {
		++distanceLower;
	}
	for(j=number ; !isPerfectNumber(j) ; ++j) {
		++distanceUpper;
	}

	return((distanceLower < distanceUpper) ? i : j);
}

void displayPerfectNumber(int beginInterval, int endInterval) {
	int i;
	int* perfectsNumbers = allPerfectNumber(beginInterval, endInterval);

	for(i = 0 ; perfectsNumbers[i] != -1 ; ++i) {
		printf("%d ", perfectsNumbers[i]);
	}
}
int sumDivides(int number) {
	int i; 
	int sum = 0;
	for( i=1 ; i < number; ++i ) {
		if( number % i ) {
			sum += i;
		}
	}

	return sum;
}
bool isFriends(int nombre1, int nombre2) {
	return (nombre1 == sumDivides(nombre2) && nombre2 == sumDivides(nombre1));
}

void displayFriendsCouple(int nombre1, int nombre2) {
	int friends[N];
	int i, j;
	int aux;
	switchIntervalNumber(&nombre1, &nombre2);

	printf("Les couple de nombres amis entre %d et %d sont :", nombre1, nombre2);
	for (i=nombre1 ; i<nombre2 ; ++i) {
		for (j=i ; j<nombre2 ; ++j) {
			if (isFriends(i,j)) {
				printf(" %d et %d ;", i, j);
			}
		}
	}
	printf("\n");

}
