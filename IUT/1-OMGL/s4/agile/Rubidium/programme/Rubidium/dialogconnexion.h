#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include "ui_dialogconnexion.h"

class DialogConnexion : public QDialog, private Ui::DialogConnexion
{
    Q_OBJECT
    
public:
    explicit DialogConnexion(QWidget *parent = 0);

    QString getLogin() const;
    QString getMdp() const;

};

#endif // DIALOGCONNEXION_H
