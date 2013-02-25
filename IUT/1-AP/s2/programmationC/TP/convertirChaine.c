/* procedure convertirChaine */

#include "chaine.h"

void convertirChaine (ChaineDyn * ch1, const char * ch2, jmp_buf ptRep)
{
    static char * ERR_ALLOC = "Erreur Allocation" ;
    int lgCh2 ;
    char * ptrAlloc ;

    lgCh2 = strlen(ch2) ;
    if (lgCh2 == 0)
    {
        ptrAlloc = NULL ;
    }
    else
	{
        ptrAlloc = (char *)malloc (lgCh2) ;
        if (ptrAlloc == NULL)
        {
            longjmp (ptRep, (int)ERR_ALLOC) ;
        }
        memcpy (ptrAlloc, ch2, lgCh2) ;
    }   
        
    if (ch1->ptrCar != NULL)
    {
        free(ch1->ptrCar) ;
    } 
    ch1->nbCar = lgCh2 ;
    ch1->ptrCar = ptrAlloc ;

}
