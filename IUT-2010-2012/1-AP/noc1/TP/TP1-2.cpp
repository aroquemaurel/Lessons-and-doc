#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"

int fonction (const int n) ;
int main ()
{
    int n ;
    int f ;
    ecrire (uneChaine ("entrer une valeur entiere : ")) ;
    lire (n) ;
    f = fonction (n) ;
    ecrireNL (f) ;
}
int fonction (const int n)
{
    int v ;
    int r ;
    v = n ;
    r = 1 ;
    while (v > 1)
    {
        r = r*v ;
        v = v-1 ;
    }
    return (r) ;
}

