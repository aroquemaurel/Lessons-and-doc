#ifndef ELEMENTPILE
#define ELEMENTPILE

/* ----------------------------------
        D�claration des types
   --------------------------------*/

/* D�claration du type des �l�ments d'une pile */

typedef int T_element;

/* ----------------------------------
            Constructeurs
   --------------------------------*/
/*
 * Donn�es:
 * Objet: Saisir un T_element  
 * R�sultats: un T_element saisi  
*/
void saisir_element(T_element *el);

/*
 * Donn�es: la valeur du T_element � copier :de , le nom du T_element
 *      	o� se fait la copie: vers  
 * Objet: Copie d'un T_element dans un autre T_element  
 * R�sultats: le T_element vers modifi�  
*/
void affecter_element(T_element *vers, T_element de);


/* ----------------------------------
            Accesseurs
   --------------------------------*/

/*
 * Donn�es: la valeur d'un T_element 
 * Objet: Afficher un T_element  
 * R�sultats: 
*/
void afficher_element(T_element el);


#endif
