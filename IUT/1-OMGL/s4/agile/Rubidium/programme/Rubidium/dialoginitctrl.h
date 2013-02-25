#ifndef DIALOGINITCTRL_H
#define DIALOGINITCTRL_H

#include "ui_dialoginitctrl.h"
#include "bdd.h"

class DialogInitCtrl : public QDialog, private Ui::DialogInitCtrl
{
    Q_OBJECT

public:
    explicit DialogInitCtrl(QWidget *parent = 0);
    ~DialogInitCtrl();

private slots:
    void ajouter();
    void supprimer();

private:
    QSqlTableModel* mModele;

};

#endif // DIALOGINITCTRL_H
