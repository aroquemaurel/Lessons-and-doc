#ifndef __ARN_PRIVE
#define __ARN_PRIVE
#include "noeud.h"
#include "arn.h"

/*  fonctions privées du module ARN. */
void afficherNoeudsOrdreCroissant(Noeud n, afficher_fct afficherNoeud);
void ecrireNoeudsFichierDot(Noeud n, stringAffichage_fct affiche, FILE* fichierDot);

Noeud chercherNoeud(ARN t, void* key, compare_fct compare);
void rotationGauche(ARN t, Noeud n);
void rotationDroite(ARN t, Noeud n);
void remplacerNoeud(ARN t, Noeud ancienNoeud, Noeud nouveauNoeud);
void insertionCas1(ARN t, Noeud n);
void insertionCas2(ARN t, Noeud n);
void insertionCas3(ARN t, Noeud n);
void insertionCas4(ARN t, Noeud n);
void insertionCas5(ARN t, Noeud n);
void suppressionCas1(ARN t, Noeud n);
void suppressionCas2(ARN t, Noeud n);
void suppressionCas3(ARN t, Noeud n);
void suppressionCas4(ARN t, Noeud n);
void suppressionCas5(ARN t, Noeud n);
void suppressionCas6(ARN t, Noeud n);


#endif


