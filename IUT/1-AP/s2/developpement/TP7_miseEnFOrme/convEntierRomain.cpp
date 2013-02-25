/*
  ________________________________________________
 |
 |     Programme: TP5 nombres romains 
 |     Langage: C++
 |     Auteur: Antoine de Roquemaurel & Fabrice Valleix
 |
 |     Fichier: convRomain.h 
 |     Date de modification: 21/05/11
 |
 |________________________________________________
*/

#include <iostream>
#include <sstream>
#include "convEntierRomain.h"

int nbChiffreNb(const int nombre[]){
	int nbChiffre = 4;

	if(nombre[3] == 0){
		nbChiffre--;
		if(nombre[2] == 0){
			nbChiffre--;
			if(nombre[1] == 0)
				nbChiffre--;
		}
	}

	return nbChiffre;

}

void extraireChiffre(const int nombre, int chiffre[]) {
	if(nombre < 1000){
		chiffre[0] = nombre % 10;						
		chiffre[1] = ((nombre % 100) - chiffre[3])/10;

		chiffre[2] = (nombre / 100);
		if(chiffre[2] != 0 && chiffre[2] >= 10)
			chiffre[2] -= (chiffre[0]*10);						

		chiffre[3] = nombre / 1000;						
	}
	else{
		chiffre[0] = (nombre % 100)%10;
		chiffre[1] = ((nombre - chiffre[0])%100)/10;
		chiffre[2] = (nombre / 100)%10;
		chiffre[3] = nombre / 1000;
	}
}

std::string convertirEntierRomain(const int entier) throw (std::string) {
	if(entier > 3999)
		throw std::string("Le nombre est trop grand pour être converti\n");

	int chiffre[4] = {0,0,0,0};
	int nbChiffre;

	std::string nbRomain;
	extraireChiffre(entier, chiffre);
	nbChiffre = nbChiffreNb(chiffre);
	for(int i=nbChiffre; i > 0; i--) {
		nbRomain += conv[chiffre[i-1]][i-1]; 
	}

	return nbRomain;
}

void testerNombre(std::string nombre) throw (std::string) {
	for(int i=0; i < nombre.size(); i++){
		if(!(nombre[i] >= '0' && nombre[i] <= '9'))
			throw std::string("La chaine n'est pas un entier \n\n");
	}
}

int conversionStringEntier(std::string chaine) {
	int nbEntier;

	testerNombre(chaine);
	std::istringstream ch(chaine);
	ch >> nbEntier;

	return nbEntier;
}
