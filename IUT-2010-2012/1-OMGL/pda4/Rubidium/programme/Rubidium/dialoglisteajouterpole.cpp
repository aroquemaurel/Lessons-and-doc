#include "dialoglisteajouterpole.h"

#include "comboboxdelegateforue.h"
#include <QMessageBox>

DialogListeAjouterPole::DialogListeAjouterPole(QWidget *parent) :
    QDialog(parent) {
    setupUi(this);

    mModele = new QSqlTableModel();

    mModele = Bdd::getInstance()->getTablePoles();

    pole->setModel(mModele);
    pole->setItemDelegateForColumn(2, new ComboBoxDelegateForUe());
    pole->hideColumn(0);
}

DialogListeAjouterPole::~DialogListeAjouterPole() {
    delete mModele;
}

void DialogListeAjouterPole::ajouter() {
    mModele->insertRow(mModele->rowCount());
}

void DialogListeAjouterPole::supprimer() {
    if(!pole->currentIndex().isValid()) {
        return;
    }

    int retour = QMessageBox::question(this,
                                       "Supprimer", "Êtes vous sûr de vouloir supprimer ce pôle ?",
                                       QMessageBox::Yes | QMessageBox::No);

    if(retour == QMessageBox::No) {
        return;
    }

    mModele->removeRow(pole->currentIndex().row());
}
