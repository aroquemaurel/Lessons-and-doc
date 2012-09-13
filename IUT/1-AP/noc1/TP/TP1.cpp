------------------------------------------
TP : TP1
------------------------------------------
#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

// Ce programme ne sert à rien !

int main (void)
{
    int v ;
    int r ;

    ecrire (uneChaine ("entrer une valeur entiere : ")) ;
    lire (v) ;
    r = 1 ;

    while (v > 1)
    {
        r*=(v--) ;
    }

    ecrireNL (r);

}
