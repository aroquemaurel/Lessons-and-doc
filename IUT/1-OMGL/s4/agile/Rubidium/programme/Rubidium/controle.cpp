#include "controle.h"

Controle::Controle() {
    mDuree = .0;
    mCoefficient = .0;
    mDate.currentDate();
    mHeure.currentTime();
    mCalculatrice = false;
    mDocuments = false;
    mSalles.clear();
}

Controle::Controle(const Controle &pControle){
    mDuree = pControle.getDuree();
    mCoefficient = pControle.getCoefficient();
	mDate = pControle.getDate();
    mCalculatrice = pControle.estAutoriseCalculatrice();
    mDocuments = pControle.estAutoriseDocuments();
}

Controle::~Controle(){

}

double Controle::getDuree() const {
    return mDuree;
}

void Controle::setDuree(double pDuree) {
    mDuree = pDuree;
}

double Controle::getCoefficient() const {
    return mCoefficient;
}

void Controle::setCoefficient(double pCoefficient) {
    mCoefficient = pCoefficient;
}

QDate Controle::getDate() const {
    return mDate;
}

void Controle::setDate(QDate pDate) {
    mDate = pDate;
}

QTime Controle::getHeure() const {
    return mHeure;
}

void Controle::setHeure(QTime pHeure) {
    mHeure = pHeure;
}

bool Controle::estAutoriseCalculatrice() const {
    return mCalculatrice;
}

void Controle::setAutorisationCalculatrice(bool pCalculatrice) {
    mCalculatrice = pCalculatrice;
}

bool Controle::estAutoriseDocuments() const {
    return mDocuments;
}

void Controle::setAutorisationDocuments(bool pDocuments) {
    mDocuments = pDocuments;
}

int Controle::getIdMatiere() const {
    return mIdMatiere;
}

void Controle::setIdMatiere(int pIdMatiere) {
    mIdMatiere = pIdMatiere;
}

int Controle::getIdType() const {
    return mIdTypeControle;
}
void Controle::setIdType(int pIdType) {
    mIdTypeControle = pIdType;
}

QStringList Controle::getSalles() {
    return mSalles;
}

void Controle::ajouterSalle(QString pSalle) {
    mSalles << pSalle;
    mSalles.removeDuplicates();
}

void Controle::supprimerSalle(QString pSalle) {
    mSalles.removeAll(pSalle);
}
