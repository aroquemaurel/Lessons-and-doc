#ifndef DIALOGTABLEAJOUTERMATIERE_H
#define DIALOGTABLEAJOUTERMATIERE_H

#include "ui_dialogtableajoutermatiere.h"

class DialogTableAjouterMatiere : public QDialog, private Ui::DialogTableAjouterMatiere {
    Q_OBJECT

public:
    explicit DialogTableAjouterMatiere(QWidget *parent = 0);
};

#endif // DIALOGTABLEAJOUTERMATIERE_H
