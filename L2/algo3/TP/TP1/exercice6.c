#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double solutionEquation(int delta, int a, int b, int c) ;

int main(int argc, char** argv) {
	bool bContinue = true;
	char continueAnswer; 
	int a = 0, b = 0, c = 0;
	int delta = 0;
	double solution = 0;

	while(bContinue) {
		printf("Entrez les coefficients de l'équation");	
		printf(" a = ");
		scanf("%d", &a);
		printf(" b = ");
		scanf("%d", &b);
		printf(" c = ");
		scanf("%d", &c);

		delta = b*b - 4 * a * c;
		solution = solutionEquation(delta, a, b, c);
		printf("Le résultat est %f\n \n", solution);
		printf("Voulez vous résoudre une nouvelle équation ? (y = oui; n = non)");
		scanf(" %c", &continueAnswer);

		bContinue = (continueAnswer == 'y') ? true : false;
	}

	return 0;
}

double solutionEquation(const int delta, const int a, const int b, const int c) {
	double solution;

	if(delta > 0) {
		solution = (b*b + sqrt(4 * a * c));
	} else if(delta < 0) {
		solution = (b*b - sqrt(4 * a * c));
	} else if (delta == 0) {
		solution = -b*b/2*a;
	}

	return solution;
}
