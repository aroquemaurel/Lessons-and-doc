Arbre afficherIteratif(Arbre pArbre) {
	Cell n;
	Arbre aux;
	if(!estVide(pArbre)) {
		Pile p = creer();
		p = empiler(p, *pArbre);
		while(!pileEstVide(p)) {
			n = sommetPile(p);
			p = depiler(p);
			if((n.gauche == NULL) && (n.droite == NULL)) {
				printf("%d ", n.racine);
			} else {
				if(n.droit != NULL) {
					p = empiler(p, *(n.droit));
				} 
				aux = n.gauche;
				n.droit = NULL;
				n.gauche = NULL;
				p = empiler(p,n);
				if(aux != NULL) {
					p = empiler(p, *aux);
				}
			}
		}
	}
}
