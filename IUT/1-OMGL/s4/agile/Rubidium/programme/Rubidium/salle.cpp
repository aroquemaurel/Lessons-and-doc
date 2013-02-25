#include "salle.h"

Salle::Salle() {

}

Salle::Salle(const Salle &pSalle){
    mNom = pSalle.getNom();
    mNbSurveillants = pSalle.getNbSurveillants();
    mCapacite = pSalle.getCapacite();
}

Salle::~Salle(){
    
}

QString Salle::getNom() const {
    return mNom;
}
void Salle::setNom(QString pNom){
    mNom = pNom;
}
int Salle::getNbSurveillants() const {
    return mNbSurveillants;
}
void Salle::setNbSurveillants(int pNbSurveillants){
    mNbSurveillants = pNbSurveillants;
}
int Salle::getCapacite() const {
    return mCapacite;
}
void Salle::setCapacite(int pCapacite){
    mCapacite = pCapacite;
}
