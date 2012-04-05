#ifndef DIALOGAJOUTERUTILISATEUR_H
#define DIALOGAJOUTERUTILISATEUR_H

#include "ui_dialogajouterutilisateur.h"

class DialogAjouterUtilisateur : public QDialog, private Ui::DialogAjouterUtilisateur
{
    Q_OBJECT
    
public:
    explicit DialogAjouterUtilisateur(QWidget *parent = 0);
};

#endif // DIALOGAJOUTERUTILISATEUR_H
