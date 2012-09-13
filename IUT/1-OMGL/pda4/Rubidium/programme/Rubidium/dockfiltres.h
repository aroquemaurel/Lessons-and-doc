#ifndef DOCKFILTRES_H
#define DOCKFILTRES_H

#include <QWidget>

#include "ui_dockfiltres.h"

#include "fenetreprincipale.h"

class FenetrePrincipale;

class DockFiltres : public QWidget, private Ui::DockFiltres {
    Q_OBJECT
public:
    explicit DockFiltres(FenetrePrincipale *f,
                         QWidget *parent=0);

    void afficherFiltreProfil(bool visible);

signals:
    void nouveauFiltre();

public slots:
    void maj(void);

private slots:
    void semestreSelectionne(bool activer);
    void matiereSelectionne(bool activer);
    void surveillanceSelectionne(bool activer);
    void voirMesMatieresSelectionne(bool activer) ;
    void voirMatieresResponsableSelectionne(bool activer) ;
private:
    void changerFiltre(QString pAncien, QString pNouveau);
    void filtrer(QString pFiltre, bool activer);


    FenetrePrincipale* mFenetre;

};

#endif // DOCKFILTRES_H
