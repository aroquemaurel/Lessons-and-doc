#define N 1000

typedef int Element ;
typedef struct {
	int nbElement;
	Element ensemble[N];
} Ensemble;
typedef enum{vrai=1, faux=0} Booleen;

Ensemble ensemble_vide();
Ensemble ensemble_ajout(Ensemble pEnsemble, Element pElement);
Booleen ensemble_appartient(Ensemble p1, Element p2);
Booleen ensemble_estVide(Ensemble pEnsemble);
Ensemble ensemble_union(Ensemble p1, Ensemble p2);
Ensemble ensemble_union(Ensemble p1, Ensemble p2);
Ensemble ensemble_intersection(Ensemble p1, Ensemble p2);
Booleen ensemble_inclusion(Ensemble p1, Ensemble p2);
int ensemble_cardinal(Ensemble pEnsemble);
Ensemble ensemble_supprimer(Ensemble p1, Element p2);
Element ensemble_choisir(Ensemble p1, Element p2);
