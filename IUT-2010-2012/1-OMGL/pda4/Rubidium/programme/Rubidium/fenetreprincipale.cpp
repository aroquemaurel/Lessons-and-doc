
#include "fenetreprincipale.h"

#include "bdd.h"
#include "dialogconnexion.h"
#include "dialogajoutctrl.h"
#include "dialoginitctrl.h"
#include "dialoglisteajouterpole.h"
#include "dialoglisteajoutertypectrl.h"
#include "dialogtableajoutermatiere.h"
#include "dialogtableajoutersalle.h"
#include "dialogtableajouterutilisateur.h"

#include <QMessageBox>
#include <QDockWidget>
#include <QPrintDialog>

#include <QPrinter>
#include <QTextDocument>

FenetrePrincipale::FenetrePrincipale(QWidget *parent)
    : QMainWindow(parent) {
    setupUi(this);

    /*/DÉMO
    actionImprimer->setVisible(false);
    actionAdminPoles->setVisible(false);
    actionAdminMatieres->setVisible(false);
    actionAdminUtilisateurs->setVisible(false);
    actionJeuEssai->setVisible(false);
    menuDebug->setEnabled(false);
    QMainWindow::menuBar()->removeAction(menuDebug->menuAction());
   //*/
    mFiltre.clear();

    mUtilisateur = NULL;

    mWidgetProfil = NULL;
    mDockProfil = NULL;

    DockFiltres* mFiltres = new DockFiltres(this);
    mDockFiltres = new QDockWidget(tr("Filtres"), this);
    mDockFiltres->setWidget(mFiltres);
    addDockWidget(Qt::RightDockWidgetArea, mDockFiltres);

    actionConnexion->setVisible(true);
    actionDeconnexion->setVisible(false);
    actionImprimerControlesSurveilles->setVisible(false);
    actionImprimerDetailsHeuresdesurveillance->setVisible(false);
    actionImprimerDetailsHeuresdesurveillanceTrieParQuota->setVisible(false);
    actionAdminMatieres->setVisible(false);
    actionAdminUtilisateurs->setVisible(false);
actionNouveaux_controles->setVisible(false);
    actionSurveiller->setVisible(false);

    actionJeuEssai->setVisible(false);
    actionViderBd->setVisible(false);
    menuDebug->setEnabled(false);
    QMainWindow::menuBar()->removeAction(menuDebug->menuAction());

    QMainWindow::menuBar()->removeAction(menuAdministration->menuAction());
    QMainWindow::menuBar()->removeAction(menuControle->menuAction());
    QMainWindow::removeToolBar(controleToolBar);

    connect(mFiltres, SIGNAL(nouveauFiltre()),
            this, SLOT(majListeControles()));

    connect(this, SIGNAL(miseAJour()),
            this, SLOT(majListeControles()));
    connect(this, SIGNAL(miseAJour()),
            mFiltres, SLOT(maj()));
    connect(this, SIGNAL(miseAJour()),
            this, SLOT(majActionsControles()));

    majListeControles();
    majActionsControles();

    setRaccourcisActions();
    listeControles->setEditTriggers(QAbstractItemView::NoEditTriggers);
    listeControles->setSelectionMode(QAbstractItemView::NoSelection);
}

FenetrePrincipale::~FenetrePrincipale() {
}

Personne* FenetrePrincipale::getUtilisateur() {
    return mUtilisateur;
}

void FenetrePrincipale::quitter() {
    Bdd::detruire();
    close();
}

void FenetrePrincipale::seConnecter() {
    DialogConnexion fenetre;

    int retour = fenetre.exec();

    if(retour == QDialog::Rejected) {
        return;
    }

    if(Bdd::getInstance()->validerPersonne(fenetre.getLogin(), fenetre.getMdp())) {
        // On se connecte
        mUtilisateur = Bdd::getInstance()->getPersonne(fenetre.getLogin());

        mWidgetProfil = new DockProfil(*mUtilisateur);
        mDockProfil = new QDockWidget(tr("Profil"), this);
        mDockProfil->setWidget(mWidgetProfil);
        addDockWidget(Qt::LeftDockWidgetArea, mDockProfil);

        actionConnexion->setVisible(false);
        actionDeconnexion->setVisible(true);
        actionImprimerControlesSurveilles->setVisible(true);
        actionImprimerDetailsHeuresdesurveillance->setVisible(true);
        actionImprimerDetailsHeuresdesurveillanceTrieParQuota->setVisible(true);

        if(mUtilisateur->estAdministrateur()) {
            QMainWindow::menuBar()->addMenu(menuAdministration);
        }

        if(mUtilisateur->estReponsablePlanning()
                || !Bdd::getInstance()->getResponsableMatieres(*mUtilisateur).isEmpty()
                || mUtilisateur->estAdministrateur()){
            QMainWindow::menuBar()->addMenu(menuControle);
            QMainWindow::addToolBar(controleToolBar);
            controleToolBar->show();

        }

        listeControles->setSelectionMode(QAbstractItemView::SingleSelection);
        listeControles->setSelectionBehavior(QAbstractItemView::SelectRows);

        emit miseAJour();
    }
    else {
        QMessageBox::critical(this,
                              tr("Erreur"),
                              tr("Couple Login/Mot de passe incorrect"));
    }
}

void FenetrePrincipale::seDeconnecter() {
    mUtilisateur = NULL;

    actionConnexion->setVisible(true);
    actionDeconnexion->setVisible(false);
    actionImprimerControlesSurveilles->setVisible(false);
    actionImprimerDetailsHeuresdesurveillance->setVisible(false);
    actionImprimerDetailsHeuresdesurveillanceTrieParQuota->setVisible(false);

    removeDockWidget(mDockProfil);
    delete mWidgetProfil;
    delete mDockProfil;

    QMainWindow::menuBar()->removeAction(menuAdministration->menuAction());
    QMainWindow::menuBar()->removeAction(menuControle->menuAction());
    QMainWindow::removeToolBar(controleToolBar);

    listeControles->setSelectionMode(QAbstractItemView::NoSelection);

    emit miseAJour();
}

void FenetrePrincipale::imprimerListeControlesSurveilles() {
    QPrinter printer;
    QTextDocument doc;

    /* Texte au format HTML */
    QString texte = Bdd::getInstance()->getListeControlesSurveillesFormatHTML(*mUtilisateur);
    doc.setHtml(texte);

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle(tr("Imprimer un document"));

    dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);

    if (dialog->exec() == QDialog::Accepted)
        doc.print(&printer);
    return;
}

void FenetrePrincipale::imprimerListeTousControles() {
    QPrinter printer;
    QTextDocument doc;

    /* Texte au format HTML */
    QString texte = Bdd::getInstance()->getListeTousControleHTML();
    doc.setHtml(texte);

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle(tr("Imprimer un document"));

    dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);

    if (dialog->exec() == QDialog::Accepted)
        doc.print(&printer);
    return;
}

void FenetrePrincipale::imprimerListeDetailsHeuresSurveillances() {
    QPrinter printer;
    QTextDocument doc;

    /* Texte au format HTML */
    QString texte = Bdd::getInstance()->getListeControlesParEnseignantHTML();
    doc.setHtml(texte);

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle(tr("Imprimer un document"));

    dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);

    if (dialog->exec() == QDialog::Accepted)
        doc.print(&printer);
    return;
}

void FenetrePrincipale::imprimerListeDetailsHeuresSurveillancesTrieParQuota() {
    QPrinter printer;
    QTextDocument doc;

    /* Texte au format HTML */
    QString texte = Bdd::getInstance()->getListeControlesParEnseignantTrieParQuotaHTML();
    doc.setHtml(texte);

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle(tr("Imprimer un document"));

    dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);

    if (dialog->exec() == QDialog::Accepted)
        doc.print(&printer);
    return;
}

void FenetrePrincipale::adminMatiere() {
    DialogTableAjouterMatiere fenetre;

    int retour = fenetre.exec();

    if(retour == QDialog::Rejected) {
        return;
    }

    // TODO
    pasImplemente("Ajouter un contrôle");
    emit miseAJour();
}

void FenetrePrincipale::adminPole() {
    DialogListeAjouterPole fenetre;

    fenetre.exec();

    emit miseAJour();
}

void FenetrePrincipale::adminSalles() {
    DialogTableAjouterSalle fenetre;

    fenetre.exec();

    emit miseAJour();
}

void FenetrePrincipale::adminTypeControle() {
    DialogListeAjouterTypeCtrl fenetre;

    fenetre.exec();

    emit miseAJour();
}

void FenetrePrincipale::adminUtilisateurs() {
    DialogTableAjouterUtilisateur fenetre;

    int retour = fenetre.exec();

    if(retour == QDialog::Rejected) {
        return;
    }

    // TODO
    pasImplemente("Ajouter un contrôle");
    emit miseAJour();
}

void FenetrePrincipale::remplirJeuEssai() {
    Bdd::getInstance()->jeuDEssai();
    emit miseAJour();
}

void FenetrePrincipale::viderBd() {
    Bdd::getInstance()->viderBdd();
    emit miseAJour();
}

void FenetrePrincipale::ajouterControle() {
    Controle test;
    DialogAjoutCtrl fenetre((Controle&)test, (QWidget*)(0));

    int retour = fenetre.exec();

    if(retour == QDialog::Rejected) {
        return;
    }

    Bdd::getInstance()->ajouterControle(fenetre);

    emit miseAJour();
}

void FenetrePrincipale::initialiserControles() {
    DialogInitCtrl fenetre;

    fenetre.exec();

    emit miseAJour();
}

void FenetrePrincipale::pasImplemente(QString pFonction) {
    QMessageBox::information(0,
                             "Pas implémenté",
                             "Désolé, mais la fonction " + pFonction + " n'est pas implémentée !");
}

void FenetrePrincipale::majListeControles() {
    listeControles->setModel(Bdd::getInstance()->getTableauControles(*mUtilisateur));
}

void FenetrePrincipale::majActionsControles() {
    if(mUtilisateur == NULL || !listeControles->currentIndex().isValid()) {
        actionSurveiller->setVisible(false);
        actionEditer->setVisible(false);
    }
    else {
        int idCtrl = listeControles->currentIndex().row();
        actionSurveiller->setVisible(true);
        qDebug() << listeControles->model()->index(idCtrl,8).data().toString();
        actionSurveiller->setChecked(listeControles->model()->index(idCtrl,8).data().toString() != "Surveillé");
        actionEditer->setVisible(!listeControles->model()->index(idCtrl,9).data().toString().isNull());
    }
}

void FenetrePrincipale::menu() {
    QMenu*	menu = new QMenu;
    if(!listeControles->currentIndex().isValid()) {
        return;
    }

    int idCtrl=  listeControles->currentIndex().row();
    if(!listeControles->model()->index(idCtrl,8).data().toString().isNull()) {
        menu->addAction(actionSurveiller);
        actionSurveiller->setChecked(listeControles->model()->index(idCtrl,8).data().toString() != "Surveillé");
    }
    if(!listeControles->model()->index(idCtrl,9).data().toString().isNull()) {
        menu->addAction(actionEditer);
    }
    menu->exec(QCursor::pos());
}

void FenetrePrincipale::editer() {
    QString nomMatiereCourant = listeControles->model()->index(listeControles->currentIndex().row(),1).data().toString();
    nomMatiereCourant = nomMatiereCourant.split(" ").first();
    QStringList dateTxt = listeControles->model()->index(listeControles->currentIndex().row(),0).data().toString().split("/");
    QDate dateCourant = QDate(dateTxt.last().toInt(), dateTxt.at(1).toInt(), dateTxt.first().toInt());

    QStringList heureTxt= listeControles->model()->index(listeControles->currentIndex().row(),3).data().toString().split("h");
    QTime heureCourant = QTime(heureTxt.first().toInt(), heureTxt.last().toInt());

    Controle ancien = Bdd::getInstance()->getControle(nomMatiereCourant, dateCourant, heureCourant);

    DialogAjoutCtrl fenetre(ancien);

    int retour = fenetre.exec();

    if(retour == QDialog::Rejected) {
        return;
    }
    Bdd::getInstance()->editerControle(ancien, fenetre);

    emit miseAJour();
}

void FenetrePrincipale::surveiller() {
    QString nomMatiereCourant = listeControles->model()->index(listeControles->currentIndex().row(),1).data().toString();
    nomMatiereCourant = nomMatiereCourant.split(" ").first();
    QStringList dateTxt = listeControles->model()->index(listeControles->currentIndex().row(),0).data().toString().split("/");
    QDate dateCourant = QDate(dateTxt.last().toInt(), dateTxt.at(1).toInt(), dateTxt.first().toInt());

    QStringList heureTxt= listeControles->model()->index(listeControles->currentIndex().row(),3).data().toString().split("h");
    QTime heureCourant = QTime(heureTxt.first().toInt(), heureTxt.last().toInt());


    Bdd::getInstance()->surveiller(*mUtilisateur,
                                   Bdd::getInstance()->getControle(nomMatiereCourant, dateCourant, heureCourant),
                                   listeControles->model()->index(listeControles->currentIndex().row(),8)
                                   .data().toString() != "Surveillé");

    majActionsControles();
    actionSurveiller->setChecked(!actionSurveiller->isChecked());
    miseAJour();
    listeControles->setFocus();

}

void FenetrePrincipale::setRaccourcisActions() {
    QList<QKeySequence> raccourcisConnexion;
    raccourcisConnexion << QKeySequence(Qt::CTRL + Qt::Key_Return);
    raccourcisConnexion << QKeySequence(Qt::CTRL + Qt::Key_Enter);
    actionConnexion->setShortcuts(raccourcisConnexion);
    actionDeconnexion->setShortcuts(raccourcisConnexion);
    //actionImprimerControlesSurveilles->setShortcut(QKeySequence::Print);
    actionQuitter->setShortcut(QKeySequence::Quit);
}

