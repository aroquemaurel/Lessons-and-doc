#ifndef DIALOGAJOUTERTYPECTRL_H
#define DIALOGAJOUTERTYPECTRL_H

#include "bdd.h"

#include "ui_dialoglisteajoutertypectrl.h"

class DialogListeAjouterTypeCtrl : public QDialog, private Ui::DialogListeAjouterTypeCtrl {
    Q_OBJECT
    
public:
    explicit DialogListeAjouterTypeCtrl(QWidget *parent = 0);
    ~DialogListeAjouterTypeCtrl();

private slots:
    void ajouter();
    void supprimer();

private:
    QSqlTableModel* mModele;
};

#endif // DIALOGAJOUTERTYPECTRL_H
