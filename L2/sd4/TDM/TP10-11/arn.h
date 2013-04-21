#ifndef __ARN
#define __ARN_
#include <stdio.h>
#include "noeud.h"
/*  Bibliothèque pour utiliser l'arbre rouge noir.  */


typedef struct ARN_t { // Permet d'éviter les retour de type ARN ou les pointeurs
    Noeud racine;
} *ARN;

// fonction de comparaison de deux élément.
// Retourne 0 si égale, -1 si premiereOperande < secondeOperande et 1 sinon
typedef void* (*compare_fct)(void* premiereOperande, void* secondeOperande); 

// Fonction d'affichage d'une valeur. 
// L'affichage peut se faire en fonction de la couleur couleur
typedef void (*afficher_fct)(void* valeur, Couleur couleur);
typedef char* (*stringAffichage_fct)(void* valeur, Couleur couleur);

ARN arn_creer(void);
void arn_insererer(ARN t, void* valeur, compare_fct compare);
void arn_supprimer(ARN t, void* key, compare_fct compare);
void arn_afficherOrdreCroissant(ARN t, afficher_fct afficher);
void arn_ecrireFichierDot(ARN t, stringAffichage_fct afficherNoeud, FILE* fichierDot);

#endif
