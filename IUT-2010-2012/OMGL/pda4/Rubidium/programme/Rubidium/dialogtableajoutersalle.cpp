#include "dialogtableajoutersalle.h"
#include "ui_dialogtableajoutersalle.h"

#include "spinboxdelegate.h"
#include <QMessageBox>

DialogTableAjouterSalle::DialogTableAjouterSalle(QWidget *parent) :
    QDialog(parent) {
    setupUi(this);

    mModele = new QSqlTableModel();

    mModele = Bdd::getInstance()->getTableSalles();

    salles->setModel(mModele);
    salles->setItemDelegateForColumn(2, new SpinBoxDelegate());
    salles->setItemDelegateForColumn(3, new SpinBoxDelegate());
    salles->hideColumn(0);
}

DialogTableAjouterSalle::~DialogTableAjouterSalle() {
    delete mModele;
}

void DialogTableAjouterSalle::ajouter() {
    mModele->insertRow(mModele->rowCount());
}

void DialogTableAjouterSalle::supprimer() {
    if(!salles->currentIndex().isValid()) {
        return;
    }

    int retour = QMessageBox::question(this,
                                       "Supprimer",
                                       "Êtes vous sûr de vouloir supprimer cette salle ?",
                                       QMessageBox::Yes | QMessageBox::No);

    if(retour == QMessageBox::No) {
        return;
    }

    mModele->removeRow(salles->currentIndex().row());
}
