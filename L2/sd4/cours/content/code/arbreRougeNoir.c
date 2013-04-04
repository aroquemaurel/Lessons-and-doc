#define NOIR 1
#define ROUGE 0

typedef struct etNoeud {
	int racine;
	struct etNoeud *sag;
	struct etNoeud *sad;
	struct etNoeud *pere;
	int couleur; /* 1 = noir, 0 rouge */
} Noeud;
typedef Noeud* ARN;

ARN creerRN(void) {
	return (NULL);
}

ARN rotationDroite(ARN a) {
	Noeud buff;
	if((a != NULL) && (a->sag != NULL)) {
		buff = a->sag;
		buff->pere = a->pere;
		a->sad = aux->sag;
		if(a->sag != NULL)
			a->sag->pere = a;
		buff->sad =a ;
		buff->sad->pere = buff;

		return buff;
	} else {
		return a;
	}

	return a;
}

ARN rotationGauche(ARN a) {
	Noeud buff;
	if((a != NULL) && (a->sad != NULL)) {
		buff = a->sad;
		buff->pere = a->pere;
		a->sag = aux->sad;
		if(a->sad != NULL)
			a->sad->pere = a;
		buff->sag =a ;
		buff->sag->pere = buff;

		return buff;
	} 

	return a;
}

void miseAJourLien(ARN nouveauFils, ARN ancienFils, ARN pere, ARN* origineArbre) {
	if(pere == NULL) {
		*origineArbre = nouveauFils;
	} else if(pere->sag == ancienfils) {
		pere->sag = nouveauFils;
	} else {
		pere->sad = nouveauFils;
	}
}
/*
 * @param aux pointeur sur x
 * @param a pointeur sur le pointeur sur la racine de l'arbre 
 * @return Le pointeur sur la cellule à partir de laquelle on propage
 *		Si NULL pas de propagation
 */
ARN equilibre(ARN aux, ARN* a) { 
	// aux est la racine de l'arbre ou aux à un père non vide
	if(aux->pere == NULL || aux->pere->couleur == NOIR) { 
		return NULL;
	}

	// le père de aux n'est pas vide et il est rouge
	if(aux->pere->pere == NULL) { // Cas 0
		aux->pere->couleur = NOIR;
		return NULL;
	}

	// le grand père de aux n'est pas vide
	// Donc il existe un frère du père
	// Identification du frère et des symétries
	int pereAGauche = 0;
	int auxAGauche = 0;
	ARN frere;
	ARN pere = aux->pere;

	if(pere->pere->sag == pere) {
		pereAGauche = 1;
		frère = pere->pere->sad;
	} else {
		frere = pere->pere->sag;
	}

	auxAGauche = (pere->sag == aux);

	if((frere != NULL) && (frere->couleur = ROUGE)) { // cas 1
		pere->pere->couleur = ROUGE;
		frere->couleur = NOIR;
		return (pere->pere);
	}

	// le frère du père est noir
	// Cas 2 
	if(pereAGauche == auxAGauche) { // Cas 2a
		ARN = aGdPere = pere->pere->pere;
		ARN = gdPere = pere->pere;
		aux = (pereAGauche) ? rotationDroite(gdPere) : rotationGauche(gdPere);
		// mise à jour eventuelle de la racine de l'arbre
		miseAJourLien(aux, gdPere, a); 
		aux->couleur = NOIR;

		// Mise à jour de la couleur de l'ancien grand père
		if(pereAGauche) {
			aux->sad->couleur = ROUGE;
		} else {
			aux->sag->couleur = ROUGE;
	 	}
	} else { // cas 2b
		ARN gdPere = pere->pere;

		aux = (pereAGauche) ? rotationGauche(pere) : rotationDroite(pere);

		miseAJourLien(aux, pere, gdPere, a);
		gdPere = aux->pere->pere;
		pere = aux->pere;

		aux = (pereAGauche) ? rotationDroite(pere) : rotationGauche(pere);

		miseAJourLien(aux, pere, gdPere, a);
		aux->couleur = NOIR;

		if(pereAGauche) {
			aux->sad->couleur = ROUGE;
		} else {
			aux->sag->couleur = ROUGE;
		}

		return NULL;
	}
}

/*
 * @param aux L'adresse de l'adresse où on à ajouté
 */ 
ARN ajoutGrd(ARN a, int v, ARN* aux) {
	return ajoutGrdaux(a,v,aux,NULL); // NULL <=> L'adresse du père
}
ARN ajoutGrdAux(ARN a, int v, ARN* aux, ARN pere) {
	if(a != NULL) {
		if(a->racine < v) {
			a->sad = ajoutGrdAux(a->sad, v, aux, a);
		} else {
			a->sag = ajouterARN(a->sad, v, aux, a);
		}

		return a;
	} else {
		// on ajoute ici
		*aux = (ARN) malloc(sizeof(sizeof(noeud)));
		assert(*aux != NULL);
		(*aux)->racine = v;
		(*aux)->racine = v;
		(*aux)->sad = NULL;
		(*aux)->sag = NULL;
		(*aux)->couleur = rouge;
		(*aux)è>pere = pa;

		return *aux;
	}
}
ARN ajouterARN(ARN a, int v) {
	ARN aux;
	/*  en completant avec la mise à jour du père et de la couleur rouge*/
	a = ajouterGrd(a, v, &aux); // TODO Ajout d'un troisième paramètre
	
	while(aux != NULL) {
		aux = equilibre(aux, &a);
	}

	return a;
}
