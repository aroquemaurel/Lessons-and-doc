/*
	TP4: Agenda Electronique
	Langage: C++

	Fichier: agenda.h
	Rôle: Prototypes des fonctions et TAD lié à l'agenda

	Réalisé par Antoine de Roquemaurel et Fabrice Valleix
	Dernière modification le 23/03/11 à 17:30
*/

#ifndef AGENDA 
#define AGENDA 

#define NB_EVENEMENTS 7*5

typedef Evenement Semaine[NB_EVENEMENTS];

struct Agenda
{
	Semaine sem;
	int nbEvenement;
};

// initialise à vide l'agenda a
void initialiserAgenda(Agenda &a);

/* ajoute à la bonne place un événement e dans l'agenda a trié par ordre
   chronologique des événenements
   nécessite agenda non plein*/
void placerEvenement(Agenda &a, const Evenement e) throw (std::string);

/* édite l'agenda a en affichant les événements pour chaque jour
   de la semaine*/
void afficherAgendaDetail(const Agenda a);

// édite l'agenda global a
void afficherAgendaGlobal(const Agenda a);

#endif

