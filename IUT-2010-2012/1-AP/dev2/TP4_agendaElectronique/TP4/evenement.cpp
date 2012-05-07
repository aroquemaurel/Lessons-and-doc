/*
	TP4: Agenda Electronique
	Langage: C++

	Fichier: evenement.cpp
	Rôle: Corps des fonctions liés aux evenements 

	Réalisé par: Antoine de Roquemaurel et Fabrice Valleix
	Dernière modification le 26/03/2011 à 03:52
*/

#include "evenement.h"

using namespace std;
void validerEvenement(const Evenement e)
throw (string)
{
	if(e.jour < 1 || e.jour > 7)
		throw string("Jour invalide");
	else if(e.hDeb < 8.0 || e.hDeb > 19.5 || !heureValide(e.hDeb))
		throw string("Heure de début invalide");
	else if(e.hFin < 8.5 || e.hFin > 20.0 || !heureValide(e.hFin))
		throw string("Heure de fin invalide");
	else if(e.hFin - e.hDeb >= 0.5)
		throw string("Heure évenement incohérent");

}

bool heureValide(const float h )
{
	int hEntier;
	int hDecimal;
	bool valide=false;

	hEntier = floor(h);
	hDecimal = (h-hEntier)*100;

	if( hDecimal == 0 || hDecimal == 50 ) {
		valide = true;
	}
	
	return valide;
}

void initialiserEvenement(const int j, const float hD, const float hF, string a,
						  string d, Evenement &e)
{
	e.jour = j;
	e.hDeb = hD;
	e.hFin = hF;
	e.descAb = a;
	e.descEt = d;

	validerEvenement(e);
}

void afficherEvenement(const Evenement e)
{
cout << "	" << e.hDeb << " - " << e.hFin << " - " << e.descAb << " " 
		<< e.descEt << endl;
}

void saisirEvenement(Evenement &e)
{
	int j;

	cout << "Selectionner le jour de l'evenement: " << endl;
	cout << "1. Lundi" << endl;
	cout << "2. Mardi" << endl;
	cout << "3. Mercredi" << endl;
	cout << "4. Jeudi" << endl;
	cout << "5. Vendredi" << endl;
	cout << "6. Samedi" << endl;
	cout << "7. dimanche" << endl;
	cin >> e.jour;

	cout << "heure de début" << endl;
	cin >> e.hDeb;

	cout << "heure de fin" << endl;
	cin >> e.hFin;

	cout << "description abrégée" << endl;
	cin >> e.descAb;

	cout << "description étendue" << endl;
	cin >> e.descEt;

	cout << endl;
	
	validerEvenement(e);
}

void afficherJourSemaine(const int j)
throw (string)
{
	if(j < 1 || j > 7)
		throw string("Jour invalide");

	switch ( j ) {
		case 1 :
			cout << "Lundi";
			break;
		case 2 :
			cout << "Mardi";
			break;
		case 3 :
			cout << "Mercredi";
			break;
		case 4 :
			cout << "Jeudi";
			break;
		case 5 :
			cout << "Vendredi";
			break;
		case 6 :
			cout << "Samedi";
			break;
		case 7 :
			cout << "Dimanche";
			break;
	}
}

void afficherDebutJourSemaine(const int j)
throw (string)
{
	if(j < 1 || j > 7)
		throw string("Jour invalide");

	switch ( j ) {
		case 1 :
			cout << "Lu";
			break;
		case 2 :
			cout << "Ma";
			break;
		case 3 :
			cout << "Me";
			break;
		case 4 :
			cout << "Je";
			break;
		case 5 :
			cout << "Ve";
			break;
		case 6 :
			cout << "Sa";
			break;
		case 7 :
			cout << "Di";
			break;
	}
}
bool estAnterieur(const Evenement e1, const Evenement e2)
{
	bool anterieur = true;
	if(e1.jour > e2.jour)
		anterieur = false;
	else if(e1.hDeb > e2.hDeb)
		anterieur = false;
	else
		anterieur = true;

	return anterieur;
}


