#ifndef __NOEUD
#define __NOEUD
/*  Fonctions et types de données sur les noeuds */
#include "couleur.h"

typedef struct Noeud_t {
    void* valeur;
    struct Noeud_t* gauche;
    struct Noeud_t* droite;
    struct Noeud_t* parent;
    Couleur couleur;
} *Noeud;

Noeud grandPere(Noeud n);
Noeud frere(Noeud n);
Noeud oncle(Noeud n);
Couleur couleurNoeud(Noeud n);
Noeud nouveauNoeud(void* valeur, Couleur couleurNoeud, Noeud gauche, Noeud droite);
Noeud noeudMaximum(Noeud racine);

#endif


