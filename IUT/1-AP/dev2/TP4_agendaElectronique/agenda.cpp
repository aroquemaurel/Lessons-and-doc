/*
	TP4: Agenda Electronique
	Langage: C++

	Fichier: agenda.cpp
	Rôle: Corps des fonctions liés à l'agenda 

	Réalisé par: Antoine de Roquemaurel et Fabrice Valleix
	Dernière modification le 26/03/2011 à 03:52
*/

#include <iostream>
#include <fstream>
#include <string>


#include "evenement.h"
#include "agenda.h"

using namespace std;

// initialise à vide l'agenda a
void initialiserAgenda(Agenda &a)
{
	for( int i = 0 ; i < NB_EVENEMENTS ; i++ ) {
		a.sem[i].jour = 0;
		a.sem[i].hDeb = 0;
		a.sem[i].hFin = 0;
		a.sem[i].descAb = "";
		a.sem[i].descEt = "";
	}
	a.nbEvenement = 0;
}

/* ajoute à la bonne place un événement e dans l'agenda a trié par ordre
   chronologique des événenements
   nécessite agenda non plein*/
void placerEvenement(Agenda &a, const Evenement e) throw (string)
{
	if(a.nbEvenement > NB_EVENEMENTS)
		throw string("Agenda plein");

	int i;
	if(a.nbEvenement != 0){
		for( i = 0 ; (a.sem[i].jour < e.jour) && (i < a.nbEvenement)  ; i++ ); 
		for( int j = a.nbEvenement; j >= i ; j-- ) {
			a.sem[j+1] = a.sem[j];	
		}
		a.sem[i] = e; 
	}
	else{ 
		a.sem[0] = e; 
	}

}

/* édite l'agenda a en affichant les événements pour chaque jour
   de la semaine*/
void afficherAgendaDetail(const Agenda a)
{
	int jour = 0;
	for( int i = 0 ; i < a.nbEvenement ; i++ ) {
		if(a.sem[i].jour == LUNDI && jour < LUNDI){
			cout << "Lundi: " << endl;
			jour = 1;
		}
		else if(a.sem[i].jour == MARDI && jour < MARDI){
			cout << "Mardi: " << endl;
			jour = 2;
		}
		else if(a.sem[i].jour == MERCREDI && jour < MERCREDI){
			cout << "Mercredi: " << endl;
			jour = 3;
		}
		else if(a.sem[i].jour == JEUDI && jour < JEUDI){
			cout << "Jeudi: " << endl;
			jour = 4;
		}
		else if(a.sem[i].jour == VENDREDI && jour < VENDREDI){
			cout << "Vendredi: " << endl;
			jour = 5;
		}
		else if(a.sem[i].jour == SAMEDI && jour < SAMEDI){
			cout << "Samedi: " << endl;
			jour = 6;
		}
		else if(a.sem[i].jour == DIMANCHE && jour < DIMANCHE){
			cout << "Dimanche: " << endl;
			jour = 7;
		}

		afficherEvenement(a.sem[i]);
	}
}
// édite l'agenda global a
void afficherAgendaGlobal(const Agenda a)
{
	string agendaGlobal[8]=
		{"08 - 09 - 10 - 11 - 12 - 13 - 14 - 15 - 16 - 17 - 18 - 19",
		 "                                                         ",
		 "                                                         ",
		 "                                                         ",
		 "                                                         ",
		 "                                                         ",
		 "                                                         ",
		 "                                                         "};
	int jour = 0;

	cout << agendaGlobal[0] << endl;
	cout << agendaGlobal[1] << endl;
	cout << a.sem[1].jour;
	for( int i = 0 ; i < a.nbEvenement ; i++ ) {
			jour = a.sem[i].jour;
			agendaGlobal[jour] += a.sem[i].descAb;
	}
	cout << agendaGlobal[3] << endl;	
}

