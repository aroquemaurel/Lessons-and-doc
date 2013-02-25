#include "dialogconnexion.h"

DialogConnexion::DialogConnexion(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

QString DialogConnexion::getLogin() const {
    return login->text();
}
QString DialogConnexion::getMdp() const {
    return pass->text();
}
