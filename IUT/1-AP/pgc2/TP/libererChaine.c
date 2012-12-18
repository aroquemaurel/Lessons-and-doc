/* procedure libererChaine */

#include "chaine.h"

void libererChaine (ChaineDyn * ch )
{ 
    free(ch->ptrCar) ;
    ch->nbCar = 0 ;
    ch->ptrCar = NULL ;
}
