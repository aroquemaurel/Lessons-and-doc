#include "dialoginitctrl.h"

#include "comboboxdelegatefortypectrl.h"
#include "comboboxdelegateformatieres.h"
#include "timedelegateforduree.h"
#include "calendardelegate.h"
#include "checkboxdelegate.h"
#include "timedelegate.h"
#include "spinboxdelegateforcoeff.h"
#include <QMessageBox>

DialogInitCtrl::DialogInitCtrl(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    mModele = new QSqlTableModel();

    mModele = Bdd::getInstance()->getTableControles();
    controles->setModel(mModele);

    controles->setItemDelegateForColumn(1, new ComboBoxDelegateForTypeCtrl());
    controles->setItemDelegateForColumn(2, new ComboBoxDelegateForMatieres());
    controles->setItemDelegateForColumn(3, new CalendarDelegate());
    controles->setItemDelegateForColumn(4, new TimeDelegate());
    controles->setItemDelegateForColumn(5, new TimeDelegateForDuree());
    controles->setItemDelegateForColumn(6, new SpinBoxDelegateForCoeff());
    controles->setItemDelegateForColumn(7, new CheckboxDelegate());
    controles->setItemDelegateForColumn(8, new CheckboxDelegate());
    controles->hideColumn(0);
}

DialogInitCtrl::~DialogInitCtrl() {
    delete mModele;
}

void DialogInitCtrl::ajouter() {
    mModele->insertRow(mModele->rowCount());
}

void DialogInitCtrl::supprimer() {
    if(!controles->currentIndex().isValid()) {
        return;
    }

    int retour = QMessageBox::question(this,
                                       "Supprimer", "Êtes vous sûr de vouloir supprimer ce contrôle ?",
                                       QMessageBox::Yes | QMessageBox::No);

    if(retour == QMessageBox::No) {
        return;
    }

    mModele->removeRow(controles->currentIndex().row());
}
