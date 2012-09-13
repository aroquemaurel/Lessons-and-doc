#ifndef DIALOGAJOUTERMATIERE_H
#define DIALOGAJOUTERMATIERE_H

#include "ui_dialogajoutermatiere.h"

class DialogAjoutermatiere : public QDialog, private Ui::DialogAjoutermatiere
{
    Q_OBJECT
    
public:
    explicit DialogAjoutermatiere(QWidget *parent = 0);
};

#endif // DIALOGAJOUTERMATIERE_H
