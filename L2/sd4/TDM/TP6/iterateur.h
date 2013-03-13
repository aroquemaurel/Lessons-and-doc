typedef struct etIte* Iterateur;

Iterateur creerIterateur(LDC);
Element next(Iterateur);
Element previous(Iterateur);
void begin(Iterateur);
void end(Iterateur);
int hasNext(Iterateur);
int hasPrevious(Iterateur);

