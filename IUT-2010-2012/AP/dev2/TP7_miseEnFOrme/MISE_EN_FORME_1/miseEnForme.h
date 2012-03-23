#include <iostream>

using namespace std;

const int TAILLE = 80;

typedef char TabCaracteres[TAILLE];

struct Ligne
{
    TabCaracteres ch;
    int lg;
};

struct Balise
{
    char cadrage;
    int largeur;
    int retrait;
};

struct Mot
{
    TabCaracteres ch;
    int lg;
};

typedef Mot TabMots[TAILLE / 2];

struct ListeMots
{
    TabMots mots;
    int nbMots;
    int nbCaracteres; // nombre total de caracteres des mots de la liste
};      

// teste si le caractere est un separateur
bool estBlanc(const char c);

// convertit un caractere ('0'..'9') en sa valeur numerique
int valeur(const char c);

// lit le mot suivant du fichier (mot ou balise)
void lireMot(Mot &mot);

// renvoie vrai si l'element est une balise
bool estUneBalise(const Mot &mot);

// construit une balise a partir d'un element balise
Balise constructionBalise(const Mot &mot);

// remplit la liste de mots correspondant a une ligne
void remplirListeDeMots(ListeMots &l, Mot &motEnAttente, 
const int largeurLigne);

// justifie une ligne
void justifierLigne(Ligne &ligne, const ListeMots &l, const int largeur, 
const int retrait);

// cadre une ligne a gauche
void cadrerGaucheLigne(Ligne &ligne, const ListeMots &l, const int largeur, 
const int retrait);

// cadre une ligne a droite
void cadrerDroiteLigne(Ligne &ligne, const ListeMots &l, const int largeur);

// centre une ligne
void centrerLigne(Ligne &ligne, const ListeMots &l, const int largeur);

// ecrire une ligne dans le fichier resultat
void ecrireLigne(const Ligne &ligne);

// recopie un mot dans la ligne
void recopierUnMot(Ligne &ligne, const Mot &mot);

// recopie les mots de la liste dans la ligne separes par un nombre de blancs
// donne
void recopierMots(Ligne &ligne, const ListeMots &l, const int nbBlancs);

// recopie des blancs dans la ligne
void recopierBlancs(Ligne &ligne, const int nbBlancs);

// traite un paragraphe
void traiterParagraphe(Mot &motEnAttente);

// justifie un paragraphe
void justifierParagraphe(Mot &motEnAttente, const int largeur, const int retrait);

// cadre a droite un paragraphe
void cadrerDroiteParagraphe(Mot &motEnAttente, const int largeur);

// cadre a gauche un paragraphe
void cadrerGaucheParagraphe(Mot &motEnAttente, const int largeur, const int retrait);

// centre un paragraphe
void centrerParagraphe(Mot &motEnAttente, const int largeur);
