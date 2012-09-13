#include "couleur.h"
#include <iostream>

const Couleur Couleur::ROUGE = Couleur(255, 0, 0);

const Couleur Couleur::VERT = Couleur(0, 255, 0);

const Couleur Couleur::BLEU = Couleur(0, 0, 255);

Couleur::Couleur(const int r, const int v, const int b) throw (domain_error)
{
 if (r < 0 || r > 255)
 {
  throw domain_error("ERREUR NUANCE DE ROUGE");
 }
 if (v < 0 || v > 255)
 {
  throw domain_error("ERREUR NUANCE DE VERT");
 }
 if (b < 0 || b > 255)
 {
  throw domain_error("ERREUR NUANCE DE BLEU");
 }
 this->rouge = r;
 this->vert = v;
 this->bleu = b;
}

int Couleur::getRouge() const
{
 return (this->rouge);
}

int Couleur::getVert() const
{
 return (this->vert);
}

int Couleur::getBleu () const
{
 return (this->bleu);
}

long Couleur::getValeurRVB () const
{
 return(long (this->rouge * 256 * 256) + long (this->vert * 256) + long (this->bleu)) ;
}

void Couleur::setRouge(const int r) throw (domain_error)
{
 if (r < 0 || r > 255)
 {
  throw domain_error("ERREUR NUANCE DE ROUGE");
 }
  this->rouge = r;
}

void Couleur::setVert (const int v) throw (domain_error)
{
 if (v < 0 || v > 255)
 {
  throw domain_error("ERREUR NUANCE DE ROUGE");
 }
 this->vert = v;
}

void Couleur::setBleu (const int b) throw (domain_error)
{
 if (b < 0 || b > 255)
 {
  throw domain_error("ERREUR NUANCE DE BLEU");
 }
 this->bleu = b;
}
