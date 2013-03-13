typedef struct etCell* Arbre;

Arbre creerArbreGRD(void);
Arbre ajouterEntier(const Arbre arbre, int e);
void triGRD(const Arbre arbre);
int estVideGRD(const Arbre arbre);
int appartientGRB(const Arbre arbre, int racine);
