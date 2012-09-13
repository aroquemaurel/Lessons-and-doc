#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "couleur.h"

using namespace std;

/*------------------------------------------------------------------------------
|  Ecriture des fonctions de tests                                             |
------------------------------------------------------------------------------*/

// test P1 
bool testNuanceRougeCouleur()
{
     Couleur c(1,2,3);
     if (c.getRouge()==1)
        return true;
     else
        return false;
}

// test P2
bool testNuanceVertCouleur()
{
     Couleur c(1,2,3);
     if (c.getVert()==2)
        return true;
     else
        return false;
}

// test P3
bool testNuanceBleuCouleur()
{
     Couleur c(1,2,3);
     if (c.getBleu()==3)
        return true;
     else
        return false;
}

// test P4
bool testNuanceRougeCouleurRouge()
{
     if (Couleur::ROUGE.getRouge()==255)
        return true;
     else
        return false;
}

// test P5
bool testNuanceVertCouleurRouge()
{
     if (Couleur::ROUGE.getVert()==0)
        return true;
     else
        return false;
}

// test P6
bool testNuanceBleuCouleurRouge()
{
     if (Couleur::ROUGE.getBleu()==0)
        return true;
     else
        return false;
}

// test P7
bool testNuanceRougeCouleurVerte()
{
     if (Couleur::VERT.getRouge()==0)
        return true;
     else
        return false;
}

// test P8
bool testNuanceVertCouleurVerte()
{
     if (Couleur::VERT.getVert()==255)
        return true;
     else
        return false;
}

// test P9
bool testNuanceBleuCouleurVerte()
{
     if (Couleur::VERT.getBleu()==0)
        return true;
     else
        return false;
}

// test P10
bool testNuanceRougeCouleurBleu()
{
     if (Couleur::BLEU.getRouge()==0)
        return true;
     else
        return false;
}

// test P11
bool testNuanceVertCouleurBleu()
{
     if (Couleur::BLEU.getVert()==0)
        return true;
     else
        return false;
}

// test P12
bool testNuanceBleuCouleurBleu()
{
     if (Couleur::BLEU.getBleu()==255)
        return true;
     else
        return false;
}

// plusieurs tests pour une même propriété
// tests P13
bool testValeurRVBRouge()
{
     if (Couleur::ROUGE.getValeurRVB()==255*256*256)
        return true;
     else
        return false; 
}

bool testValeurRVBVert()
{
     if (Couleur::VERT.getValeurRVB()==255*256)
        return true;
     else
        return false; 
}

bool testValeurRVBBleu()
{
     if (Couleur::BLEU.getValeurRVB()==255)
        return true;
     else
        return false; 
}

bool testValeurRVBCouleur111()
{
     Couleur c(1,1,1);
     if (c.getValeurRVB() == 256*256 + 256 + 1)
        return true;
     else
        return false;
}

bool testValeurRVBCouleur123()
{
     Couleur c(1,2,3);
     if (c.getValeurRVB() == 256*256 + 2 * 256 + 3)
        return true;
     else
        return false;
}

// test P14
bool testModificateurRougeComposanteRouge()
{
     Couleur c (1,2,3);
     c.setRouge(11);
     if (c.getRouge()==11)
        return true;
     else
        return false;
}

// test P15
bool testModificateurRougeComposanteVerte()
{
     Couleur c (1,2,3);
     c.setRouge(11);
     if (c.getVert()==2)
        return true;
     else
        return false;
}

// test P16
bool testModificateurRougeComposanteBleu()
{
     Couleur c (1,2,3);
     c.setRouge(11);
     if (c.getBleu()==3)
        return true;
     else
        return false;
}

// testP17
bool testModificateurVertComposanteRouge()
{
     Couleur c (1,2,3);
     c.setVert(22);
     if (c.getRouge()==1)
        return true;
     else
        return false;
}

// testP18
bool testModificateurVertComposanteVerte()
{
     Couleur c (1,2,3);
     c.setVert(22);
     if (c.getVert()==22)
        return true;
     else
        return false;
}

// testP19
bool testModificateurVertComposanteBleu()
{
     Couleur c (1,2,3);
     c.setVert(22);
     if (c.getBleu()==3)
        return true;
     else
        return false;
}

// testP20
bool testModificateurBleuComposanteRouge()
{
     Couleur c (1,2,3);
     c.setBleu(33);
     if (c.getRouge()==1)
        return true;
     else
        return false;
}

// testP21
bool testModificateurBleuComposanteVerte()
{
     Couleur c (1,2,3);
     c.setBleu(33);
     if (c.getVert()==2)
        return true;
     else
        return false;
}

// testP22
bool testModificateurBleuComposanteBleu()
{
     Couleur c (1,2,3);
     c.setBleu(33);
     if (c.getBleu()==33)
        return true;
     else
        return false;
}

// test sur domaine de définition des générateurs
bool testExceptionComposanteRougeConstructeurCouleurValeurNegative()
{
     try
     {
        Couleur c (-1,0,0);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionComposanteRougeConstructeurCouleurValeurSuperieure()
{
     try
     {
        Couleur c (257,0,0);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionComposanteVerteConstructeurCouleurValeurNegative()
{
     try
     {
        Couleur c (0,-1,0);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionComposanteVerteConstructeurCouleurValeurSuperieure()
{
     try
     {
        Couleur c (0,257,0);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionComposanteBleuConstructeurCouleurValeurNegative()
{
     try
     {
        Couleur c (0,0,-1);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionComposanteBleuConstructeurCouleurValeurSuperieure()
{
     try
     {
        Couleur c (0,0,257);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionComposanteRougeModifieurCouleurValeurNegative()
{
     Couleur c (0,0,0);
     try
     {
        c.setRouge(-1);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionComposanteRougeModifieurCouleurValeurSuperieure()
{
     Couleur c (0,0,0);
     try
     {
        c.setRouge(257);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionComposanteVerteModifieurCouleurValeurNegative()
{
     Couleur c (0,0,0);
     try
     {
        c.setVert(-1);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionComposanteVerteModifieurCouleurValeurSuperieure()
{
     Couleur c (0,0,0);
     try
     {
        c.setVert(257);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionComposanteBleuModifieurCouleurValeurNegative()
{
     Couleur c (0,0,0);
     try
     {
        c.setBleu(-1);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

bool testExceptionComposanteBleuModifieurCouleurValeurSuperieure()
{
     Couleur c (0,0,0);
     try
     {
        c.setBleu(257);
     }
     catch (const logic_error & ex)
     {
           return true;
     }
     return false;
}

/*------------------------------------------------------------------------------
|  Déclaration des structures de données necessaire aux tests                  |
------------------------------------------------------------------------------*/
     
// un test se compose d'un pointeur de fonction et d'un message d'erreur explicite si le test échoue
class TestUnitaire{
   private :  
      // déclaration d'un pointeur de fonction
      // la fonction ne prend pas de paramètres et renvoie un booléen
      typedef bool (*test)();  
      test functionOfTest;
      string errorTest;
   
   public :
      // constructeur de test
      TestUnitaire(test ptrFunction, string message) 
      {
         this->functionOfTest = ptrFunction;
         this->errorTest = message;
      }
      // les accesseurs en lecture
      test getFunctionOfTest() const { return this->functionOfTest; }
      string getErrorTest() const { return this->errorTest; }
};

/*------------------------------------------------------------------------------
|  Fonctions d'automatisation des tests                                        |
------------------------------------------------------------------------------*/

// initialisation des tests 
void initializeAllTests(vector<TestUnitaire> & lesTests)
{
   lesTests.push_back(TestUnitaire(&testNuanceRougeCouleur, string("test composante rouge failed")));
   lesTests.push_back(TestUnitaire(&testNuanceVertCouleur, string("test composante verte failed")));
   lesTests.push_back(TestUnitaire(&testNuanceBleuCouleur, string("test composante bleu failed")));
   lesTests.push_back(TestUnitaire(&testNuanceRougeCouleurRouge, string("test composante rouge de la couleur rouge failed")));
   lesTests.push_back(TestUnitaire(&testNuanceVertCouleurRouge, string("test composante verte de la couleur rouge failed")));
   lesTests.push_back(TestUnitaire(&testNuanceBleuCouleurRouge, string("test composante bleu de la couleur rouge failed")));
   lesTests.push_back(TestUnitaire(&testNuanceRougeCouleurVerte, string("test composante rouge de la couleur verte failed")));
   lesTests.push_back(TestUnitaire(&testNuanceVertCouleurVerte, string("test composante verte de la couleur verte failed")));
   lesTests.push_back(TestUnitaire(&testNuanceBleuCouleurVerte, string("test composante bleu de la couleur verte failed")));   
   lesTests.push_back(TestUnitaire(&testNuanceRougeCouleurBleu, string("test composante rouge de la couleur bleu failed")));
   lesTests.push_back(TestUnitaire(&testNuanceVertCouleurBleu, string("test composante verte de la couleur bleu failed")));
   lesTests.push_back(TestUnitaire(&testNuanceBleuCouleurBleu, string("test composante bleu de la couleur bleu failed")));
   lesTests.push_back(TestUnitaire(&testModificateurRougeComposanteRouge, string("test modifieur composante rouge sur composante rouge failed")));
   lesTests.push_back(TestUnitaire(&testModificateurRougeComposanteVerte, string("test modifieur composante rouge sur composante verte failed")));
   lesTests.push_back(TestUnitaire(&testModificateurRougeComposanteBleu, string("test modifieur composante rouge sur composante bleu failed")));
   lesTests.push_back(TestUnitaire(&testModificateurVertComposanteRouge, string("test modifieur composante verte sur composante rouge failed")));
   lesTests.push_back(TestUnitaire(&testModificateurVertComposanteVerte, string("test modifieur composante verte sur composante verte failed")));
   lesTests.push_back(TestUnitaire(&testModificateurVertComposanteBleu, string("test modifieur composante verte sur composante bleu failed")));
   lesTests.push_back(TestUnitaire(&testModificateurBleuComposanteRouge, string("test modifieur composante bleu sur composante rouge failed")));
   lesTests.push_back(TestUnitaire(&testModificateurBleuComposanteVerte, string("test modifieur composante bleu sur composante verte failed")));
   lesTests.push_back(TestUnitaire(&testModificateurBleuComposanteBleu, string("test modifieur composante bleu sur composante bleu failed")));
   lesTests.push_back(TestUnitaire(&testValeurRVBRouge, string("test valeurRVB sur Couleur Rouge failed")));
   lesTests.push_back(TestUnitaire(&testValeurRVBVert, string("test valeurRVB sur Couleur Verte failed")));
   lesTests.push_back(TestUnitaire(&testValeurRVBBleu, string("test valeurRVB sur Couleur Bleu failed")));
   lesTests.push_back(TestUnitaire(&testValeurRVBCouleur111, string("test valeurRVB sur Couleur (1,1,1) failed")));
   lesTests.push_back(TestUnitaire(&testValeurRVBCouleur123, string("test valeurRVB sur Couleur (1,2,3) failed")));
   lesTests.push_back(TestUnitaire(&testExceptionComposanteRougeConstructeurCouleurValeurNegative, string ("test valeur negative composante rouge constructeur failed")));
   lesTests.push_back(TestUnitaire(&testExceptionComposanteRougeConstructeurCouleurValeurSuperieure, string ("test valeur superieure a 255 composante rouge constructeur failed"))); 
   lesTests.push_back(TestUnitaire(&testExceptionComposanteVerteConstructeurCouleurValeurNegative, string ("test valeur negative composante verte constructeur failed")));
   lesTests.push_back(TestUnitaire(&testExceptionComposanteVerteConstructeurCouleurValeurSuperieure, string ("test valeur superieure a 255 composante verte constructeur failed")));
   lesTests.push_back(TestUnitaire(&testExceptionComposanteBleuConstructeurCouleurValeurNegative, string ("test valeur negative composante bleu constructeur failed")));
   lesTests.push_back(TestUnitaire(&testExceptionComposanteBleuConstructeurCouleurValeurSuperieure, string ("test valeur superieure a 255 composante bleu constructeur failed")));
   lesTests.push_back(TestUnitaire(&testExceptionComposanteRougeModifieurCouleurValeurNegative, string ("test valeur negative composante rouge modifieur rouge failed")));
   lesTests.push_back(TestUnitaire(&testExceptionComposanteRougeModifieurCouleurValeurSuperieure, string ("test valeur superieure composante rouge modifieur rouge failed"))); 
   lesTests.push_back(TestUnitaire(&testExceptionComposanteVerteModifieurCouleurValeurNegative, string ("test valeur negative composante verte modifieur vert failed")));
   lesTests.push_back(TestUnitaire(&testExceptionComposanteVerteModifieurCouleurValeurSuperieure, string ("test valeur superieure composante verte modifieur vert failed")));
   lesTests.push_back(TestUnitaire(&testExceptionComposanteBleuModifieurCouleurValeurNegative, string ("test valeur negative composante bleu modifieur bleu failed")));
   lesTests.push_back(TestUnitaire(&testExceptionComposanteBleuModifieurCouleurValeurSuperieure, string ("test valeur superieure composante bleu modifieur bleu failed")));
}

// test si tous les tests sont ok
bool testsAllOkay(vector<bool> &resultats)
{
     int i;
     for (i = 0; i < resultats.size() && resultats[i]; i++) {}
     return (i == resultats.size());
}

// execution des tests
void runAllTests()
{
     vector<TestUnitaire> lesTests;
     initializeAllTests(lesTests);                          
     vector<bool> resultats(lesTests.size(),false);  
     
     // Exécution automatique des tests          
     for (int i = 0; i < resultats.size(); i++)
     {
         resultats[i]= (*lesTests[i].getFunctionOfTest())();
     }
     
     // Affichage des résultats
     if (testsAllOkay(resultats))
     {
        cout << "Tous les tests sont Okay" << endl;
     }
     else 
     {
        cout << "*** ATTENTION ***" << endl;
        for (int i = 0; i < resultats.size(); i++)
        {
            if (!resultats[i])
               cout << lesTests[i].getErrorTest() << endl;
        }
     }
}

int main(int argc, char *argv[])
{
    runAllTests();
    system("PAUSE");
    return EXIT_SUCCESS;
}


