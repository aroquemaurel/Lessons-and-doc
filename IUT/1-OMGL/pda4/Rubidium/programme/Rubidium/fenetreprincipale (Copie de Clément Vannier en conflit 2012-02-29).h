#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QMainWindow>

#include "ui_fenetreprincipale.h"

#include "dockprofil.h"
#include "dockfiltres.h"

#include "personne.h"

class FenetrePrincipale : public QMainWindow, private Ui::FenetrePrincipale {
    Q_OBJECT

public:
    explicit FenetrePrincipale(QWidget *parent = 0);
    ~FenetrePrincipale();

public slots:
    void quitter();

    void seConnecter();
    void seDeconnecter();
    void imprimer();

    void adminMatiere();
    void adminPole();
    void adminSalles();
    void adminTypeControle();
    void adminUtilisateurs();
    void remplirJeuEssai();
    void viderBd();

    void ajouterControle();
    void initialiserControles();

    static void pasImplemente(QString pFonction);

signals:
    void miseAJour();

private slots:
    void majListecontroles();

private:
    void setRaccourcisActions();

    DockProfil* mWidgetProfil;
    QDockWidget* mDockProfil;
    DockFiltres* mFiltres;

    Personne* mUtilisateur;
};

#endif // FENETREPRINCIPALE_H
