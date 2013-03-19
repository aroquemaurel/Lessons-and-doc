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

ARN ajouter(ARN a, int x) {
	ARN aux;
	/*  en completant avec la mise à jour du père et de la couleur rouge*/
	a = ajouterGrd(a, x);
	
	while(!nonFini) {
		aux = equilibre(aux, a);
	}

	// TODO comment indiquer au programme que l'équilibrage est fini !
	// quelle est la valeur de aux à faie passer à équilibre ? 
}
