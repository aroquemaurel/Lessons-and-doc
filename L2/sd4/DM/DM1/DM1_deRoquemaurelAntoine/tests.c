#include <stdio.h>
#include <stdlib.h>
#include "pileStatique.h"
#include "element.h"
#include "pileMixte.h"
#include "pileDynamique.h"
char* gModule;
void afficherResultatTest(int pReussite, char* message);
void testPileStatique(void);
void testPileMixte(void);
void testPileDynamique(void);
int main(void) {
	testPileStatique();
	printf("\n");
	testPileDynamique();
	printf("\n");
	testPileMixte();

	return 0;
}
void testPileStatique(void) {
	int i;
	int elt;
	gModule = "PileStatique";
	PileStatique p = pileStatiqueCreer();
	afficherResultatTest(pileStatiqueEstVide(p), "Création de la pile");

	pileStatiqueEmpiler(&p, 13);
	afficherResultatTest(pileStatiqueSommet(p) == 13, "Sommet");
	pileStatiqueEmpiler(&p, 42);
	afficherResultatTest(!pileStatiqueEstVide(p) && pileStatiqueSommet(p) == 42, "Empiler un élément");
	
	pileStatiqueDepiler(&p);
	afficherResultatTest(!pileStatiqueEstVide(p) && pileStatiqueSommet(p) == 13, "Depiler un élément");
	pileStatiqueDepiler(&p);
	afficherResultatTest(pileStatiqueEstVide(p), "La pile est vide");

	for(i=0 ; i < TAILLE_MAX ; ++i) {
		pileStatiqueEmpiler(&p, i);
	}
	afficherResultatTest(pileStatiqueEstPleine(p), "La pile est pleine");
//	pileStatiqueEmpiler(p, i);  //Ce test effectue un assert car la pile est pleine
	elt = pileStatiqueSommet(p);
	afficherResultatTest(pileStatiqueEstPleine(p) && pileStatiqueSommet(p) == elt, "On n'empile pas si la pile est pleine");
	
	for(i=0 ; i < TAILLE_MAX ; ++i) {
		pileStatiqueDepiler(&p);
	}
	afficherResultatTest(pileStatiqueEstVide(p), "La pile est vide");
//	pileStatiqueDepiler(p); // Ce test effectue un assert comme prévu
//	afficherResultatTest(pileStatiqueEstVide(p), "On ne dépile pas si la pile est vide");


}
void testPileDynamique(void) {
	int i;
	int elt;
	gModule = "PileDynamique";
	PileDynamique p = pileDynamiqueCreer();
	afficherResultatTest(pileDynamiqueEstVide(p), "Création de la pile");

	pileDynamiqueEmpiler(&p, (Element) 13);
	afficherResultatTest(pileDynamiqueSommet(p) == (Element) 13, "Sommet");
 	pileDynamiqueEmpiler(&p, (Element) 42);
	afficherResultatTest(!pileDynamiqueEstVide(p) && pileDynamiqueSommet(p) == (Element) 42, "Empiler un élément");
	
	pileDynamiqueDepiler(&p);
	afficherResultatTest(!pileDynamiqueEstVide(p) && pileDynamiqueSommet(p) == (Element) 13, "Depiler un élément");
	pileDynamiqueDepiler(&p);
	pileDynamiqueDepiler(&p);
	afficherResultatTest(pileDynamiqueEstVide(p), "La pile est vide");

	for(i=0 ; i < 2500; ++i) {
		pileDynamiqueEmpiler(&p, i);
	}
	afficherResultatTest(!pileDynamiqueEstPleine(p), "Pile est pleine"); // la pile ne peut être pleine
	pileDynamiqueEmpiler(&p, (Element) 1337);  
	elt = pileDynamiqueSommet(p);
	afficherResultatTest(!pileDynamiqueEstPleine(p) && pileDynamiqueSommet(p) == elt, "On n'empile pas si la pile est pleine");
	pileDynamiqueDepiler(&p);
	
	for(i=0 ; i < 2500; ++i) {
		pileDynamiqueDepiler(&p);
	}
	afficherResultatTest(pileDynamiqueEstVide(p), "La pile est vide");
	pileDynamiqueDepiler(&p); 
	afficherResultatTest(pileDynamiqueEstVide(p), "On ne dépile pas si la pile est vide");
}
void testPileMixte(void) {
	int i;
	int elt;
	gModule = "PileMixte";
	PileMixte p = pileMixteCreer();
	afficherResultatTest(pileMixteEstVide(p), "Création de la pile");

	pileMixteEmpiler(&p, 13);
	afficherResultatTest(pileMixteSommet(p) == 13, "Sommet");
 	pileMixteEmpiler(&p, 42);
	afficherResultatTest(!pileMixteEstVide(p) && pileMixteSommet(p) == 42, "Empiler un élément");
  
	pileMixteDepiler(&p);
	afficherResultatTest(!pileMixteEstVide(p) && pileMixteSommet(p) == 13, "Depiler un élément");
	pileDynamiqueDepiler(&p);
	pileDynamiqueDepiler(&p);
	afficherResultatTest(pileDynamiqueEstVide(p), "La pile est vide");
 
	for(i=0 ; i < 1500; ++i) {
		pileMixteEmpiler(&p, i);
	}
	afficherResultatTest(!pileMixteEstPleine(p), "Pile est pleine"); // la pile ne peut être pleine
	pileMixteEmpiler(&p, i);  
	elt = pileMixteSommet(p);
	afficherResultatTest(!pileMixteEstPleine(p) && pileMixteSommet(p) == elt, "On n'empile pas si la pile est pleine");
	pileMixteDepiler(&p);
	
	for(i=0 ; i < 1500; ++i) {
		pileMixteDepiler(&p);
	}
	afficherResultatTest(pileMixteEstVide(p), "La pile est vide");
//	pileMixteDepiler(&p); // assert, donc c'est ok.
	afficherResultatTest(pileMixteEstVide(p), "On ne dépile pas si la pile est vide");


}
void afficherResultatTest(int pReussite, char* pMessage) {
	if(pReussite) {
		printf("\033[32;01m");
		printf("[Passed]");
	} else {
		printf("\033[31;01m");
		printf("[Failed]");
	}
	printf("\033[00;36m");
	printf(" %s ", gModule);
	printf("\033[00;00m");
	printf(" %s\n", pMessage); 
}
