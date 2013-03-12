typedef struct etCell* Arbre;

Arbre creerGrd(void);
Arbre ajout(const Arbre arbre, int e);
void afficher(const Arbre arbre);
Arbre afficherIteratif(Arbre pArbre);
int estVide(const Arbre arbre);
int appartient(const Arbre arbre, int racine);
