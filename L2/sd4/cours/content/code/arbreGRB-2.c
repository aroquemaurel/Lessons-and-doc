Arbre afficherLargeurIteratif(Arbre pArbre) {
	Cell n;
	if(!estVide(pArbre)) {
		File p = creer();
		p = enfiler(p, *pArbre);
		while(!fileEstVide(p)) {
			n = sommetFile(p);
			p = defiler(p);
			printf("%d ", n.racine);
			if(n.gauche != NULL) {
				p = enfiler(p, *(n.gauche));
			} 
			p = enfiler(p,n);
			if(n.droit != NULL) {
				p = enfiler(p, n.droit);
			}
		}
	}
}
