#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv) {
	int nombre = 0;	

	printf("Entrez un nombre entre 0 et 127 svp ");
	scanf("%d", &nombre);
 
	if (nombre >= 0 || nombre < 31 || nombre == 127){
		printf("Caractere non affichable");
	} else if (nombre >= 65 || nombre < 90) {
		printf("Alphabet latin majuscule");
	} else if (nombre >= 97 || nombre < 122) {
		printf("Alphabet latin minuscule");
	} else if (nombre >= 48 || nombre < 57) {
		printf("Chiffre de 0 à 9");
	} else {
		printf("Le nombre n'est pas compris entre 0 et 127");
	}

	return 0;
}
