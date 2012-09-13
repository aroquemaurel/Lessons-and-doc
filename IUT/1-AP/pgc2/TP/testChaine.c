/* ETUDE DE CAS                                     */
/* programme de test de creation et de manipulation */
/* de chaines  du type ChaineDyn                    */

#include "chaine.h"

void afficherMenu () ;
void saisirChoix (int *) ;
void attente () ;
void saisirChaineC (char *) ;
void afficherChaine (const ChaineDyn) ;
void saisirEntier (int *) ;

void convertir () ;
void longueur () ;
void copier () ;
void comparer() ;


int main()
{
    int choix ;       
    
    choix = 0 ;
    while (choix != 9)
    {
        afficherMenu( ) ;
        saisirChoix( &choix) ;
        switch (choix)
        {
            case 1 : 
                convertir () ;
                attente () ;
                break ;
            case 2 : 
                longueur () ;
                attente () ;
                break ;
        	case 3 : 
                copier () ;
                attente () ;
                break ;
        	case 4 : 
                comparer () ;
                attente () ;
                break ;
          			           
            case 9 : 
                printf ("***Termine!!!\n");
                break ;
        	default : 
                printf ("***choix invalide!!!\n") ;
                attente () ;
        }   
    }     
}


void afficherMenu ()
{
    printf ("\n   MENU \n") ;
    printf ("   ---- \n\n") ;
    printf (" 1- Convertir une chaine C en type ChaineDyn\n") ;
    printf (" 2- Afficher la longueur d'une chaine du type ChaineDyn\n") ;
    printf (" 3- Copier une chaine du type ChaineDyn dans une autre\n") ;
    printf (" ........\n") ;
    printf (" 9- Arret du programme\n\n") ;
}

void saisirChoix (int * choix)
{
    char tampon [256] ;
    int err ;
    
	printf ("Entrer votre choix: ") ;
    fgets (tampon, 256, stdin) ;
    err = sscanf (tampon,"%d", choix) ;
    if (err == 0) 
    {
        * choix = 0 ;
    }       
}

void attente ()
{
	char tampon [256] ;
    
	printf ("\nTaper sur Entree pour continuer:\n") ;
    fgets (tampon, 256, stdin) ;
}

void saisirChaineC (char * tampon)
{
	int dernier ; 
	printf ("Entrer une chaine:\n") ;
    fgets (tampon, 256, stdin) ;
    dernier = strlen (tampon) - 1 ;
    if (tampon[dernier] == '\n')
    {
        tampon[dernier] = '\0' ;
    }
}

void afficherChaine (const ChaineDyn ch)
{
	int i ;
    
    printf ("nbCar= %d   ptrCar= %X\n",ch.nbCar,ch.ptrCar) ;
    printf ("contenu= ") ;
    for (i = 0 ; i < ch.nbCar ; i++)
    {
    	putchar (ch.ptrCar[i]) ;
    }
    putchar ('\n') ;   
}

void saisirEntier (int * nbre)
{
    char tampon [256] ;
    int err ;
    
	printf ("Entrer un nombre entier: ") ;
    fgets (tampon, 256, stdin) ;
    err = sscanf (tampon,"%d", nbre) ;
    if (err == 0) 
    {
        * nbre = 0 ;
    }       
}

/* Convertir une chaine C en type ChaineDyn */    
void convertir ()
{
	int ret ;
	jmp_buf ptRep ;
	char chaineC [256] ;
    ChaineDyn ch ;
    
    printf ("Choix 1- Convertir une chaine C en type ChaineDyn\n") ;
    creerChaineVide (&ch) ;
    afficherChaine (ch) ;
    saisirChaineC (chaineC) ;
    
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
    	convertirChaine (&ch, chaineC, ptRep) ;
    } 
    else
    {
    	printf ("\n*** %s\n", ret) ;
    }
        	
    afficherChaine (ch) ;
    libererChaine (&ch) ;  
}

/* Afficher la longueur d'une chaine du type ChaineDyn */
void longueur ()
{
	int ret ;
	jmp_buf ptRep ;
	char chaineC [256] ;
    ChaineDyn ch ;
    
    printf("Choix 2- Afficher la longueur d'une chaine du type ChaineDyn\n") ;
    creerChaineVide (&ch) ;
    saisirChaineC (chaineC) ;
    
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
    	convertirChaine (&ch, chaineC, ptRep) ;
    } 
    else
    {
    	printf ("\n*** %s\n", ret) ;
    }
        
    printf ("longueur= %d\n", longueurChaine (ch)) ;        
    afficherChaine (ch) ;
    libererChaine (&ch) ; 
}

/*Copier une chaine du type ChaineDyn dans une autre */
void copier ()
{
	int ret ;
	jmp_buf ptRep ;
	char chaineC [256] ;
    ChaineDyn ch1, ch2 ;

	printf ("Choix 3- Copier une chaine du type ChaineDyn dans une autre\n") ;
    
   	creerChaineVide (&ch1) ;
    creerChaineVide (&ch2) ;
    
    saisirChaineC (chaineC) ;    
	ret = setjmp (ptRep) ;
    if (ret == 0)
    {
    	convertirChaine (&ch1, chaineC, ptRep) ;
    } 
    else
    {
    	printf ("\n*** %s\n", ret) ;
    }       	
    afficherChaine (ch1) ; 	
    	
    saisirChaineC (chaineC) ;		
	ret = setjmp (ptRep) ;
    if (ret == 0)
    {
    	convertirChaine (&ch2, chaineC, ptRep) ;
    } 
    else
    {
    	printf ("\n*** %s\n", ret) ;
    }       	
    afficherChaine (ch2) ; 	
    
	ret = setjmp (ptRep) ;
    if (ret == 0)
    {
    	copierChaine (&ch1, ch2, ptRep) ;
    } 
    else
    {
    	printf ("\n*** %s\n", ret) ;
    }        
    afficherChaine (ch1) ;
    
    libererChaine (&ch1) ;
    libererChaine (&ch2) ;	
}

void comparer()
{
	int resultat;
	ChaineDyn ch1, ch2;

	creerChaineVide(&ch1);
	creerChaineVide(&ch2);

    saisirChaineC (&ch1) ;    
    saisirChaineC (&ch2) ;    
		
	resultat = comparerChaine(ch1, ch2);
		
	if(resultat == 0)
		printf("Les chaines sont égales");
	else if(resultat == 1)
		printf("La chaine 1 est avant la chaine 2");
	else
		printf("La chaine 2 est avant la chaine 1");
			
}
