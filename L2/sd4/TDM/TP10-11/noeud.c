#include <stdlib.h>
#include <assert.h>
#include "noeud.h"

Noeud nouveauNoeud(void* valeur, Couleur couleurNoeud, Noeud gauche, Noeud droite) {
	Noeud retour = malloc(sizeof(struct Noeud_t));
	retour->valeur = valeur;
	retour->couleur = couleurNoeud;
	retour->gauche = gauche;
	retour->droite = droite;
	if (gauche != NULL) {
		gauche->parent = retour; 
	}
	if (droite != NULL) {
		droite->parent = retour;
	}
	retour->parent = NULL;

	return retour;
}

Couleur couleurNoeud(Noeud n) {
	return (n == NULL ? NOIR : n->couleur);
}

Noeud noeudMaximum(Noeud n) {
	assert (n != NULL);
	while (n->droite != NULL) {
		n = n->droite;
	}
	return n;

}


Noeud grandPere(Noeud n) {
	assert (n != NULL);
	assert (n->parent != NULL); 
	assert (n->parent->parent != NULL); 

	return n->parent->parent;
}
Noeud frere(Noeud n) {
	assert (n != NULL);
	assert (n->parent != NULL); /* racine Noeud has no frere */

	return (n == n->parent->gauche) ? n->parent->droite : n->parent->gauche;
}
Noeud oncle(Noeud n) {
	assert (n != NULL);
	assert (n->parent != NULL); /* racine Noeud has no oncle */
	assert (n->parent->parent != NULL); /* Children of racine have no oncle */

	return frere(n->parent);
}
