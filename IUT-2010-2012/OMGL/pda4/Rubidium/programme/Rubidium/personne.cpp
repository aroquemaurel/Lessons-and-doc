#include "personne.h"

Personne::Personne() {
    mNom.clear();
    mPrenom.clear();
    mMdp.clear();

    mResponsablePlanning=false;
    mAdministrateur=false;
}

Personne::Personne(const Personne &pPersonne) {
    mNom = pPersonne.getNom();
    mPrenom = pPersonne.getPrenom();
    mMdp = pPersonne.getMdp();
    mQuota = pPersonne.getQuota();
    mHeuresEffectuees = pPersonne.getNbHeuresEffectuees();
    mResponsablePlanning = pPersonne.estReponsablePlanning();
    mAdministrateur = pPersonne.estAdministrateur();
}

Personne::~Personne() {

}

QString Personne::getNom() const {
    return mNom;
}
void Personne::setNom(QString pNom) {
    mNom = pNom;
}
QString Personne::getPrenom() const {
    return mPrenom;
}
void Personne::setPrenom(QString pPrenom) {
    mPrenom = pPrenom;
}
QString Personne::getMdp() const {
    return mMdp;
}
void Personne::setMdp(QString pMdp) {
    mMdp = pMdp;
}
QTime Personne::getQuota() const {
    return mQuota;
}
void Personne::setQuota(QTime pQuota) {
    mQuota = pQuota;
}
QTime Personne::getNbHeuresEffectuees() const {
    return mHeuresEffectuees;
}
QTime Personne::getNbHeuresProgrammes() const {
    return mHeuresProgrammes;
}
void Personne::setNbHeuresEffectuees(QTime pNbHeuresEffectuees) {
    mHeuresEffectuees = pNbHeuresEffectuees;
}
void Personne::setNbHeuresProgrammes(QTime pNbHeuresProgrammes) {
    mHeuresProgrammes = pNbHeuresProgrammes;
}
bool Personne::estReponsablePlanning() const {
    return mResponsablePlanning;
}
void Personne::setResponsable(bool pResponsable) {
    mResponsablePlanning = pResponsable;
}
bool Personne::estAdministrateur() const {
    return mAdministrateur;
}
void Personne::setAdministrateur(bool pAdministrateur) {
    mAdministrateur = pAdministrateur;
}
