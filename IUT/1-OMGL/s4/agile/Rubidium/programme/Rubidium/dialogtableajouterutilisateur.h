#ifndef DIALOGTABLEAJOUTERUTILISATEUR_H
#define DIALOGTABLEAJOUTERUTILISATEUR_H

#include <QDialog>

#include <ui_dialogtableajouterutilisateur.h>

class DialogTableAjouterUtilisateur : public QDialog, private Ui::DialogTableAjouterUtilisateur {
    Q_OBJECT

public:
    explicit DialogTableAjouterUtilisateur(QWidget *parent = 0);
};

#endif // DIALOGTABLEAJOUTERUTILISATEUR_H
