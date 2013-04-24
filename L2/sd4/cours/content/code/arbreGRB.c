typedef struct etCell {
	struct etCell* gauche;
	struct etCell* droite;
	int racine;
} Cell;

Arbre creerGrd(void) {
	return (NULL);
}

Arbre ajout(const Arbre arbre, int e) {
	Cell* newCell;
	newCell = (Cell*)malloc(sizeof(Cell));
	newCell->racine = e;
	newCell->gauche = NULL;
	newCell->gauche = NULL;
	if(estVide(arbre)) {
		arbre = newCell;	
	} else {
		if(e <= arbre->racine) {
			arbre->gauche = ajout(arbre->gauche, e);
		} else {
			arbre->droite = ajout(arbre->droite, e);
		}
	}

	return arbre;
}

// Parcours infixe
void afficher(const Arbre arbre) {
	Cell* cous = a;
	if(!estVide(a)) {
		affiche(a->gauche);
		printf("%d", a->racine);
		afficher(a->droite);
	} 
}

int estVide(const Arbre arbre) {
	return (arbre != NULL);
}

int appartient(const Arbre arbre, int val) {
	if(estVide(arbre))
		return 0;
	if(val <= arbre->racine)
		return appartient(arbre->gauche, val);
	if(val > arbre->racine)
		return appartient(arbre->droite, val);

	return 1;
}
// Private
Arbre restructure(Arbre pArbre) {
	// on est sur le noeud à creer
	Arbre droit, gauche, aux;
	droit = pArbre->droit;
	gauche = pArbre->gauche;

	if(droit == NULL) {
		// on a rien à insérer
		return gauche;
	} 
	aux = droit;
	while(aux->gauche != NULL) {
		aux = aux->gauche;
	}
	aux->gauche = gauche;
	free(pArbre);

	return droit;
}
// Private
Arbre supprimerUnElement(Arbre pArbre, int val) {
	assert(!estVide(pArbre));
	if(pArbre->racine == val) {
		return(restructure(pArbre,val));
	} 
	if((pArbre->racine < val) && (pArbre->gauche != NULL)) {
		pArbre->droit = supprimerUnElement(a->droit, val);
	} else if((a->racine > val) && (a->gauche != NULL)) {
		pArbre->gauche = supprimerUnElement(a->gauche, val);
	}

	return pArbre;
}

Arbre supprime(Arbre pArbre, int v) {
	while(appartient(pArbre,v)) {
		pArbre = supprimerUnElement(pArbre,v);
	}
	return pArbre;
}

