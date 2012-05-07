#include "dialoglisteajoutertypectrl.h"

#include "fenetreprincipale.h"
#include <QMessageBox>

DialogListeAjouterTypeCtrl::DialogListeAjouterTypeCtrl(QWidget *parent) :
    QDialog(parent) {
    setupUi(this);

    mModele = new QSqlTableModel();

    mModele = Bdd::getInstance()->getTableTypeCtrl();

    typeCtrl->setModel(mModele);
    typeCtrl->hideColumn(0);
}

DialogListeAjouterTypeCtrl::~DialogListeAjouterTypeCtrl() {
    delete mModele;
}

void DialogListeAjouterTypeCtrl::ajouter() {
    mModele->insertRow(mModele->rowCount());
}

void DialogListeAjouterTypeCtrl::supprimer() {
    if(!typeCtrl->currentIndex().isValid()) {
        return;
    }

    int retour = QMessageBox::question(this,
                                       "Supprimer",
                                       "Êtes vous sûr de vouloir supprimer ce type de contrôle ?",
                                       QMessageBox::Yes | QMessageBox::No);

    if(retour == QMessageBox::No) {
        return;
    }

    mModele->removeRow(typeCtrl->currentIndex().row());
}
