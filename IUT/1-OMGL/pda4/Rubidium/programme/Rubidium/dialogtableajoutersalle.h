#ifndef DIALOGTABLEAJOUTERSALLE_H
#define DIALOGTABLEAJOUTERSALLE_H

#include "bdd.h"

#include <ui_dialogtableajoutersalle.h>

class DialogTableAjouterSalle : public QDialog, private Ui::DialogTableAjouterSalle {
    Q_OBJECT

public:
    explicit DialogTableAjouterSalle(QWidget *parent = 0);
    ~DialogTableAjouterSalle();

private slots:
//    void actionBouton(QAbstractButton* pBouton);
    void ajouter();
    void supprimer();

private:
    QSqlTableModel* mModele;
};

#endif // DIALOGTABLEAJOUTERSALLE_H
