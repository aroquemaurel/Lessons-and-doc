#include "/usr/local/public/BIBLIOC++/entreeSortie.h"
#include "/usr/local/public/BIBLIOC++/chaine.h"
int main ()
{
  try
  {
    Chaine ch ;
    ecrire (uneChaine ("entrer une chaine : ")) ;
    lire (ch) ;
    ecrireNL (ieme (ch, 6)) ;
  }
  catch (const Chaine message)
  {
  ecrireNL (message);
  }
}

int main ()
{
    int a, b ;
    a = 1024 ;
    b = a*a*a-1 ;
    a = 2*b ;
    b = a+1 ;
    a = b+1 ;
    b = 4*b ;
    a = 2*a ;
    b = b/a ;
}

