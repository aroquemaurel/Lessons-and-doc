#include "dialogajoutctrl.h"

#include "bdd.h"

DialogAjoutCtrl::DialogAjoutCtrl(Controle& pAncien, QWidget *parent)
    : QDialog(parent) {
    setupUi(this);

    matiere->addItems(Bdd::getInstance()->getListeMatieres());
    type->addItems(Bdd::getInstance()->getListeTypeCtrl());

    QStringListIterator i(Bdd::getInstance()->getListeSalles());
    while(i.hasNext()) {
        QString salle = i.next();

        QCheckBox* checkBoxSalle = new QCheckBox(salle);
        groupBoxSalles->layout()->addWidget(checkBoxSalle);
        mSalles << checkBoxSalle;
    }

    lbNom->hide();
    nom->hide();

    setDuree(pAncien.getDuree());
    setCoefficient(pAncien.getCoefficient());
    setDate(pAncien.getDate());
    setHeure(pAncien.getHeure());
    setAutorisationCalculatrice(pAncien.estAutoriseCalculatrice());
    setAutorisationDocuments(pAncien.estAutoriseDocuments());
    setIdMatiere(pAncien.getIdMatiere());
    setIdType(pAncien.getIdType());
    QString nomSalle;
    QStringListIterator ii(pAncien.getSalles());
    while(ii.hasNext()) {
        nomSalle = ii.next();
        ajouterSalle(nomSalle);
    }

}

DialogAjoutCtrl::~DialogAjoutCtrl() {

}

double DialogAjoutCtrl::getDuree() const {
    return duree->time().hour()
            + (double)(duree->time().minute())/60;
}

void DialogAjoutCtrl::setDuree(double pDuree) {
    int heures = pDuree;
    int minutes = (pDuree-heures) * 60;

    duree->setTime(QTime(heures, minutes, 0));
}

double DialogAjoutCtrl::getCoefficient() const {
    return coeff->value();
}

void DialogAjoutCtrl::setCoefficient(double pCoefficient) {
    coeff->setValue(pCoefficient);
}

QDate DialogAjoutCtrl::getDate() const {
    return QDate(calendarWidget->selectedDate());
}

QTime DialogAjoutCtrl::getHeure() const {
    return QTime(heureDebut->time());
}

void DialogAjoutCtrl::setDate(QDate pDate) {
    calendarWidget->setSelectedDate(pDate);

}
void DialogAjoutCtrl::setHeure(QTime pHeure){
    heureDebut->setTime(pHeure);
}

bool DialogAjoutCtrl::estAutoriseCalculatrice() const {
    return calc->isChecked();
}

void DialogAjoutCtrl::setAutorisationCalculatrice(bool pCalculatrice) {
    calc->setChecked(pCalculatrice);
}

bool DialogAjoutCtrl::estAutoriseDocuments() const {
    return docs->isChecked();
}

void DialogAjoutCtrl::setAutorisationDocuments(bool pDocuments) {
    docs->setChecked(pDocuments);
}

int DialogAjoutCtrl::getIdMatiere() const {
    return matiere->currentIndex()+1;
}

void DialogAjoutCtrl::setIdMatiere(int pIdMatiere) {
    matiere->setCurrentIndex(pIdMatiere-1);
}

int DialogAjoutCtrl::getIdType() const {
    return type->currentIndex()+1;
}

void DialogAjoutCtrl::setIdType(int pIdType) {
    type->setCurrentIndex(pIdType-1);
}

QStringList DialogAjoutCtrl::getSalles() {
    QStringList retour;
    QListIterator<QCheckBox*> i(mSalles);
    while(i.hasNext()) {
        QCheckBox* nomSalle = i.next();
        if(nomSalle->isChecked()) {
            retour << nomSalle->text();
        }
    }
    return retour;
}

void DialogAjoutCtrl::ajouterSalle(QString pSalle) {
    QListIterator<QCheckBox*> i(mSalles);
    while(i.hasNext()) {
        QCheckBox* nomSalle = i.next();
        if(nomSalle->text() == pSalle) {
            nomSalle->setChecked(true);
        }
    }
}

void DialogAjoutCtrl::supprimerSalle(QString pSalle) {
    QListIterator<QCheckBox*> i(mSalles);
    while(i.hasNext()) {
        QCheckBox* nomSalle = i.next();
        if(nomSalle->text() == pSalle) {
            nomSalle->setChecked(false);
        }
    }
}
