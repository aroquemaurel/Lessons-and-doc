/*
	TP4: Agenda Electronique
	Langage: C++

	Fichier: evenement.h
	Rôle: Prototypes des fonctions et TAD liés aux evenements 

	Réalisé par Antoine de Roquemaurel et Fabrice Valleix
	Dernière modification le 24/03/11 à 22:30
*/

#ifndef EVENEMENT
#define EVENEMENT

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define LUNDI 1 
#define MARDI 2 
#define MERCREDI 3 
#define JEUDI 4 
#define VENDREDI 5 
#define SAMEDI 6 
#define DIMANCHE 7 

struct Evenement {
	int jour;
	float hDeb;
	float hFin;
	std::string descAb;
	std::string descEt;
};

/* 
 teste la validité d’un événement
 nécessite jour dans la semaine compris entre 1 et 7
 nécessite heureDébut compris entre 8.0 et 19.5 heures
 nécessite heureFin compris entre 8.5 et 20.0 heures
 nécessite partie décimale des heures égales à .0 ou .5
 nécessite heureFin - heureDébut >= 0.5
*/
void validerEvenement(const Evenement e) throw (std::string);


// retourne vrai si la partie décimale de h est égale à 0.0 ou 0.5
bool heureValide(const float h );

/*
 saisit un événement e au clavier
 nécessite jour dans la semaine compris entre 1 et 7
 nécessite heureDébut compris entre 8.0 et 19.5 heures
 nécessite heureFin compris entre 8.5 et 20.0 heures
 nécessite partie décimale des heures égales à .0 ou .5
 nécessite heureFin - heureDébut >= 0.5
 */
void saisirEvenement(Evenement &e) ;


/*
 initialise un événement e à partir de j : jour de la semaine,
 hD : heure de début, hF : heure de fin, a : description abrégé et
 d : description détaillée
 nécessite 1 <= jour <= 7
 nécessite 8.0 <= heureDébut <= 19.5
 nécessite 8.5 <= heureFin <= 20.0
 nécessite partieDécimale(heureDébut) = 0.0 ou 0.5
 nécessite partieDécimale(heureFin) = 0.0 ou 0.5
 nécessite heureFin - heureDébut >= 0.5*/
void initialiserEvenement(const int j, 
						  const float hD, 
						  const float hF, 
						  std::string a, 
						  std::string d, 
						  Evenement &e);


/*
 affiche un événement e sous la forme
 heureDebut(4 positions) - heureFin(4 positions) : description
 par exemple :
 8.0 - 9.5 : Controle Acsi MLD
 9.5 - 11.0 : Controle Acsi MLD suite et fin*/
void afficherEvenement(const Evenement e);


// teste si l'événement e1 est antérieur à l'événement e2
bool estAnterieur(const Evenement e1, 
				  const Evenement e2);


/* affiche le jour j de la semaine en toutes lettres
 nécessite 1 <= j <= 7*/
void afficherJourSemaine(const int j) throw(std::string);


/*
 affiche le jour j de la semaine en toutes lettres
 nécessite 1 <= j <= 7*/
void afficherDebutJourSemaine(const int j) throw(std::string); 

#endif


