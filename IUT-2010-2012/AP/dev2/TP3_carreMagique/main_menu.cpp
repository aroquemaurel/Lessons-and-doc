#include <iostream>
#include <string> 

#include "matrices.h"//Les opérations sur les matrices
#include "carreMagique.h" //Les fonctions sur les carrés Magique 

using namespace std;

// affiche les propositions du menu
void propositionMenu(int &choix);
//si l'utilisateur veut savoir si la matrice est un carré magique
void menuEstCarreMagique(void);
//si l'utilisateur veut générer une carré magique
void menuGenererCarreMagique(void); 

int main(void)
{
	int choix;

	while(choix != 3){
		propositionMenu(choix);
		switch(choix){
			case 1:
				menuEstCarreMagique();
				break;
			case 2:
				menuGenererCarreMagique();
				break;
			case 3:
				cout << "Vous avez quitté le programme" << endl;
				break;
			default:
				propositionMenu(choix);	
		}
	}
}

void propositionMenu(int &choix)
{
	cout << "Que voulez-vous faire ?" << endl;
	cout << "1. Saisir une matrice carré et determiner si elle correspond à un carré magique"
				<< endl;
	cout << "2. Calculer et afficher le carré magique d'une matrice carré d'ordre n" 
				<< endl ;
	cout << "3. Quitter l'application" << endl;
	cout << "Votre choix ";
	cin >> choix;
	cout << endl << endl;
}

void menuEstCarreMagique(void)
{
	Carre matrix;
	int n;
	bool estCarre;
	
	cout << "Taille de la matrice: " ; 
	cin >> n;

	try {
		lireCarre(matrix, n);
		cout << "Matrice entrée: " << endl;	
		ecrireCarre(matrix, n);
		estCarre = estCarreMagique(matrix, n);

		if(estCarre){
			cout << "La matrice entrée est un carré magique" << endl << endl;
		}
		else{
			cout << "La matrice entrée n'est pas un carré magique" << endl 
					<< endl;
		}

	}
	catch(const string & message){
		cout << message << endl << endl << endl;
	}
	
}

void menuGenererCarreMagique(void)
{
	Carre matrix;
	int n;

	cout << "Générer un carré magique d'ordre ";
	cin >> n;
	cout << endl;

	try {
		if(n == 6){
			construireCarreMagique6(matrix);
			ecrireCarre(matrix, n);
		}
		else{
			construireCarreMagique(matrix, n);
			ecrireCarre(matrix, n);
		}
	}
	catch(const string & message){
		cout << message << endl << endl << endl;
	}
}
