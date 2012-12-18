/*
	TP4: Agenda Electronique
	Langage: C++

	Fichier: clientAgenda.cpp
	Rôle: Programme Principal

	Réalisé par: Antoine de Roquemaurel et Fabrice Valleix
	Dernière modification le 27/03/2011 à 21:52
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "evenement.h"
#include "agenda.h"

using namespace std;

int main(void)
{
	int choix=0;
	bool continuer = true;
	Evenement eve;
	Agenda a;
	string truc, truc2;

	try{
		while(continuer){
			cout << "--- MENU ---" << endl 
				<< "Que voulez vous faire?" << endl 
				<< "1. Saisir un évenement dans l'agenda" << endl       
				<< "2. Afficher l'agenda détaillé" <<endl
				<< "3. Afficher l'agenda global" << endl
				<< "9. Quitter le programme" << endl;

			cin >> choix;
			switch(choix){
				case 1:
					saisirEvenement(eve);
					afficherEvenement(eve);
					placerEvenement(a, eve);
					break;
				case 2:
					afficherAgendaDetail(a);
					break;
				case 3:
					afficherAgendaGlobal(a);
				break;
				case 9:
					return 0; // On quitte
					break;
			}
		}
	}
	catch(string & message){
		cout << message << endl;
	}
}
