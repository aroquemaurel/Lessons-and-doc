#ifndef DIALOGAJOUTERPOLE_H
#define DIALOGAJOUTERPOLE_H

#include "bdd.h"

#include "ui_dialoglisteajouterpole.h"

class DialogListeAjouterPole : public QDialog, private Ui::DialogListeAjouterPole {
    Q_OBJECT
    
public:
    explicit DialogListeAjouterPole(QWidget *parent = 0);
    ~DialogListeAjouterPole();

private slots:
    void ajouter();
    void supprimer();

private:
    QSqlTableModel* mModele;
};

#endif // DIALOGAJOUTERPOLE_H
