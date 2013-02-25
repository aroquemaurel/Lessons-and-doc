/* fichier d'entete pour la bibliotheque de traitement */
/* des chaines de caracteres de type ChaineDyn  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>


/* definition du type chaine de caracteres ChaineDyn */

typedef char * PointeurCar;

typedef struct
{
    int nbCar;
    PointeurCar ptrCar;
} ChaineDyn;

typedef enum {FALSE, TRUE}Bool;

/* prototypes des S/P de la bibliotheque    */

void creerChaineVide(ChaineDyn * ch);

void convertirChaine(ChaineDyn * ch1, const char * ch2, jmp_buf ptRep);

int longueurChaine(const ChaineDyn ch);

void copierChaine(ChaineDyn * ch1, const ChaineDyn ch2, jmp_buf ptRep);                      

void libererChaine(ChaineDyn * ch);

int comparerChaine(const ChaineDyn ch1, const ChaineDyn ch2);

/* .... */
