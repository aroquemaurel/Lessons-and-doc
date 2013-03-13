#include <stdlib.h>
#include "file.h"
#include "arbreGRB.h"

void viderTampon(File* tampon, Arbre* arbre);
int main(void) {
	int val;
	File tampon;
	ArbreGRB arbre
	do {
		scanf("%d", &val);
		enfile(tampon,val);
		if(fileEstPleine(tampon)) {
			viderTampon(&tampon, &arbre);
		}
	} while(val != -1);
	viderTampon(&tampon, &arbre);	
	
	while(!fileEstPleine(tampon)) {
			
	}
	return EXIT_SUCCESS;
}

void viderTampon(File* tampon, Arbre* arbre) {
	while(!fileEstVide(*tampon)) {
		ajouterEntier(*arbre,dernier(*tampon));
		*tampon = defiler(*tampon);
	}
}

