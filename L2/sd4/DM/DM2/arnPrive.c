#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "couleur.h"
#include "noeud.h"
#include "arnPrive.h"

Noeud chercherNoeud(ARN t, void* valeur, compare_fct compare) {
	Noeud n = t->racine;
	while (n != NULL) {
		void* comparaisonResultat = compare(valeur, n->valeur);
		if (comparaisonResultat == 0) {
			return n;
		} else if (comparaisonResultat < 0) {
			n = n->gauche;
		} else {
			assert(comparaisonResultat > 0);
			n = n->droite;
		}
	}
	return n;
}
void insertionCas1(ARN t, Noeud n) {
	if (n->parent == NULL)
		n->couleur = NOIR;
	else
		insertionCas2(t, n);
}

void insertionCas2(ARN t, Noeud n) {
	if (couleurNoeud(n->parent) == NOIR)
		return; 
	else
		insertionCas3(t, n);
}
void insertionCas3(ARN t, Noeud n) {
	if (couleurNoeud(oncle(n)) == ROUGE) {
		n->parent->couleur = NOIR;
		oncle(n)->couleur = NOIR;
		grandPere(n)->couleur = ROUGE;
		insertionCas1(t, grandPere(n));
	} else {
		insertionCas4(t, n);
	}
}
void insertionCas4(ARN t, Noeud n) {
	if (n == n->parent->droite && n->parent == grandPere(n)->gauche) {
		rotationGauche(t, n->parent);
		n = n->gauche;
	} else if (n == n->parent->gauche && n->parent == grandPere(n)->droite) {
		rotationDroite(t, n->parent);
		n = n->droite;
	}
	insertionCas5(t, n);
}
void insertionCas5(ARN t, Noeud n) {
	n->parent->couleur = NOIR;
	grandPere(n)->couleur = ROUGE;
	if (n == n->parent->gauche && n->parent == grandPere(n)->gauche) {
		rotationDroite(t, grandPere(n));
	} else {
		assert (n == n->parent->droite && n->parent == grandPere(n)->droite);
		rotationGauche(t, grandPere(n));
	}
}

void suppressionCas1(ARN t, Noeud n) {
	if (n->parent == NULL)
		return;
	else
		suppressionCas2(t, n);
}
void suppressionCas2(ARN t, Noeud n) {
	if (couleurNoeud(frere(n)) == ROUGE) {
		n->parent->couleur = ROUGE;
		frere(n)->couleur = NOIR;
		if (n == n->parent->gauche)
			rotationGauche(t, n->parent);
		else
			rotationDroite(t, n->parent);
	}
	suppressionCas3(t, n);
}
void suppressionCas3(ARN t, Noeud n) {
	if (couleurNoeud(n->parent) == NOIR &&
			couleurNoeud(frere(n)) == NOIR &&
			couleurNoeud(frere(n)->gauche) == NOIR &&
			couleurNoeud(frere(n)->droite) == NOIR)
	{
		frere(n)->couleur = ROUGE;
		suppressionCas1(t, n->parent);
	}
	else
		suppressionCas4(t, n);
}
void suppressionCas4(ARN t, Noeud n) {
	if (couleurNoeud(n->parent) == ROUGE &&
			couleurNoeud(frere(n)) == NOIR &&
			couleurNoeud(frere(n)->gauche) == NOIR &&
			couleurNoeud(frere(n)->droite) == NOIR)
	{
		frere(n)->couleur = ROUGE;
		n->parent->couleur = NOIR;
	}
	else
		suppressionCas5(t, n);
}
void suppressionCas5(ARN t, Noeud n) {
	if (n == n->parent->gauche &&
			couleurNoeud(frere(n)) == NOIR &&
			couleurNoeud(frere(n)->gauche) == ROUGE &&
			couleurNoeud(frere(n)->droite) == NOIR)
	{
		frere(n)->couleur = ROUGE;
		frere(n)->gauche->couleur = NOIR;
		rotationDroite(t, frere(n));
	}
	else if (n == n->parent->droite &&
			couleurNoeud(frere(n)) == NOIR &&
			couleurNoeud(frere(n)->droite) == ROUGE &&
			couleurNoeud(frere(n)->gauche) == NOIR)
	{
		frere(n)->couleur = ROUGE;
		frere(n)->droite->couleur = NOIR;
		rotationGauche(t, frere(n));
	}
	suppressionCas6(t, n);
}
void suppressionCas6(ARN t, Noeud n) {
	frere(n)->couleur = couleurNoeud(n->parent);
	n->parent->couleur = NOIR;
	if (n == n->parent->gauche) {
		assert (couleurNoeud(frere(n)->droite) == ROUGE);
		frere(n)->droite->couleur = NOIR;
		rotationGauche(t, n->parent);
	}
	else
	{
		assert (couleurNoeud(frere(n)->gauche) == ROUGE);
		frere(n)->gauche->couleur = NOIR;
		rotationDroite(t, n->parent);
	}
}


void rotationGauche(ARN t, Noeud n) {
	Noeud r = n->droite;
	remplacerNoeud(t, n, r);
	n->droite = r->gauche;
	if (r->gauche != NULL) {
		r->gauche->parent = n;
	}
	r->gauche = n;
	n->parent = r;
}

void rotationDroite(ARN t, Noeud n) {
	Noeud L = n->gauche;
	remplacerNoeud(t, n, L);
	n->gauche = L->droite;
	if (L->droite != NULL) {
		L->droite->parent = n;
	}
	L->droite = n;
	n->parent = L;
}

void remplacerNoeud(ARN t, Noeud ancienNoeud, Noeud nouveauNoeud) {
	if (ancienNoeud->parent == NULL) {
		t->racine = nouveauNoeud;
	} else {
		if (ancienNoeud == ancienNoeud->parent->gauche)
			ancienNoeud->parent->gauche = nouveauNoeud;
		else
			ancienNoeud->parent->droite = nouveauNoeud;
	}
	if (nouveauNoeud != NULL) {
		nouveauNoeud->parent = ancienNoeud->parent;
	}
}

void afficherNoeudsOrdreCroissant(Noeud n, afficher_fct afficher) {
	if (n == NULL) {
		printf("<empty tree>");
		return;
	}
	if (n->gauche != NULL) {
		afficherNoeudsOrdreCroissant(n->gauche, afficher);
	}

	afficher(n->valeur, n->couleur);

	if (n->droite != NULL) {
		afficherNoeudsOrdreCroissant(n->droite, afficher);
	}
}

void ecrireNoeudsFichierDot(Noeud n, stringAffichage_fct affiche, FILE* fichierDot) {
	static int null = 0;
	static char* chaineDot;
	if (n == NULL) {
		return;
	}
	fprintf(fichierDot, "\t%s [color=%s]\n", affiche(n->valeur, n->couleur), (n->couleur == ROUGE) ? "red" : "black");
	fprintf(fichierDot, affiche(n->valeur, n->couleur));
	fprintf(fichierDot, "->");
	if(n->gauche != NULL) { 
		fprintf(fichierDot, affiche(n->gauche->valeur, n->couleur));
		fprintf(fichierDot, "\t");
	} else {
		fprintf(fichierDot, "null%d",null);
		fprintf(fichierDot, "\n\tnull%d [label=\"null\", color=\"gray\"]",null);
		++null;
	}
	fprintf(fichierDot, "\n\t");
	fprintf(fichierDot, affiche(n->valeur, n->couleur));
	fprintf(fichierDot, "->");
	if(n->droite != NULL) {
		fprintf(fichierDot, affiche(n->droite->valeur, n->couleur));
	} else {
		fprintf(fichierDot, "null%d",null);
		fprintf(fichierDot, "\n\tnull%d [label=\"null\", color=\"gray\"]",null);
		++null;
	}
	fprintf(fichierDot, "\n\t");
	if (n->gauche != NULL) {
		ecrireNoeudsFichierDot(n->gauche, affiche, fichierDot);
	}
	if (n->droite != NULL) {
		ecrireNoeudsFichierDot(n->droite, affiche, fichierDot);
	}
}
