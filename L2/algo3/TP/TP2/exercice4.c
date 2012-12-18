#include <stdio.h>
#include <stdbool.h>

bool isPerfectNumber(int number) ;

int main(int argc, char** argv) {
	bool thereIsPerfect = false;

	int i = 0;
	int number1;
	int number2;

	isPerfectNumber(496);	

	printf("Taper le premier nombre ");
	scanf(" %d", &number1);
	printf("Taper le second nombre ");
	scanf(" %d", &number2);

	if(number1 > number2) { //on inverse les deux variables.
		number1 ^= number2 ^= number1 ^= number2;
	}

	for(i = number1; i <= (number2) ; ++i) {
		if(isPerfectNumber(i)) {
			printf(" %d ", i);
			thereIsPerfect = true;
		}
	}

	if(!thereIsPerfect) {
		printf("Il n'y a pas de nombres parfaits");
	}

	return 0;
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
