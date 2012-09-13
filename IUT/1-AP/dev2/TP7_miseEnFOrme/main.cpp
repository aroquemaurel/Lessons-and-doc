/*
  ________________________________________________
 |
 |     Programme: TP5 nombres romains 
 |     Langage: C++
 |     Auteur: Antoine de Roquemaurel & Fabrice Valleix
 |
 |     Fichier: main.cpp
 |     Date de modification: 21/05/11
 |
 |________________________________________________
*/

#include <iostream>
#include <string>

#include "convRomainEntier.h"
#include "convEntierRomain.h"

void menu_ConvRomainEntier(void);
void menu_ConvEntierRomain(void);

int main(void) {
	try{
		bool continuer = true;
		int choix;	

		while(continuer) {
			std::cout << "Que voulez vous faire? " << std::endl;
			std::cout << "1. Convertir un nombre romain en entier" << std::endl;
			std::cout << "2. Convertir un entier en nombre romain (max 3999)" << std::endl;
			std::cout << "Tout autre caractère pour quitter" << std::endl;
			std::cin >> choix;

			if(choix == 1)
				menu_ConvRomainEntier();
			else if (choix == 2) 
				menu_ConvEntierRomain();
			else if(choix == 0)
				continuer = false;

			std::cout << std::endl << std::endl;
		}
	}
	catch(const std::string & message) {
		/* exception, on affiche l'exception à 
		   l'utilisateur et on redemande un nombre entier*/
		std::cout << message;
		main();
	}
}
void menu_ConvRomainEntier(void) {
	int nbEntier; std::string nbRomain;
	std::cout << "Veuillez entrer un nombre romain à convertir: ";
	std::cin >> nbRomain;
	std::cout << "Vous avez entré "<< nbRomain << std::endl;

	testerNbRomain(nbRomain);
	nbEntier = convertirRomainEntier(nbRomain);
	std::cout << nbRomain << " = " << nbEntier << std::endl;

}
void menu_ConvEntierRomain(void) {
	std::string nbEntierChaine;
	int	nbEntier;
	std::string nbRomain;

	std::cout << "Veuillez entrer un nombre entier à convertir(max 3999): ";
	std::cin >> nbEntierChaine;

	nbEntier = conversionStringEntier(nbEntierChaine);
	std::cout << "Vous avez entré "<< nbEntier << std::endl;
	nbRomain = convertirEntierRomain(nbEntier);
	std::cout << nbEntier << " = " << nbRomain<< std::endl;

} 
