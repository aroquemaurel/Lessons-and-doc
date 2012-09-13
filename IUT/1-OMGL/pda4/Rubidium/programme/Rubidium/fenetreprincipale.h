#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H
#include "dockfiltres.h"
#include <QMainWindow>

#include "ui_fenetreprincipale.h"

#include "dockprofil.h"


#include "personne.h"

class FenetrePrincipale : public QMainWindow, private Ui::FenetrePrincipale {
	Q_OBJECT

public:
	explicit FenetrePrincipale(QWidget *parent = 0);
	~FenetrePrincipale();

    static void pasImplemente(QString pFonction);

    Personne* getUtilisateur();

signals:
    void miseAJour();

public slots:
	void quitter();

	void seConnecter();
	void seDeconnecter();

    void imprimerListeControlesSurveilles();
    void imprimerListeTousControles();
    void imprimerListeDetailsHeuresSurveillances();
    void imprimerListeDetailsHeuresSurveillancesTrieParQuota() ;

	void adminMatiere();
	void adminPole();
	void adminSalles();
	void adminTypeControle();
	void adminUtilisateurs();
	void remplirJeuEssai();
    void viderBd();

	void ajouterControle();
	void initialiserControles();

    void majListeControles();
    void majActionsControles();

    void menu();
    void editer();
    void surveiller();

private:
    void setRaccourcisActions();

    DockProfil*  mWidgetProfil;
	QDockWidget* mDockProfil;
	QDockWidget* mDockFiltres;

	Personne* mUtilisateur;

    QString mFiltre;

    QModelIndex* mListeDernierIndex;
};

#endif // FENETREPRINCIPALE_H
