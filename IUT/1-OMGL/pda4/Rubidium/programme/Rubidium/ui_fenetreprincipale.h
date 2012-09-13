/********************************************************************************
** Form generated from reading UI file 'fenetreprincipale.ui'
**
** Created: Sat Mar 31 16:04:39 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETREPRINCIPALE_H
#define UI_FENETREPRINCIPALE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenetrePrincipale
{
public:
    QAction *actionConnexion;
    QAction *actionDeconnexion;
    QAction *actionQuitter;
    QAction *actionAdminPoles;
    QAction *actionAdminMatieres;
    QAction *actionAdminTypesControle;
    QAction *actionAdminSalles;
    QAction *actionAdminUtilisateurs;
    QAction *actionNouveau_controle;
    QAction *actionNouveaux_controles;
    QAction *actionJeuEssai;
    QAction *actionViderBd;
    QAction *actionEditer;
    QAction *actionSurveiller;
    QAction *actionToutImprimer;
    QAction *actionImprimerDetailsHeuresdesurveillance;
    QAction *actionImprimerControlesSurveilles;
    QAction *actionImprimerDetailsHeuresdesurveillanceTrieParQuota;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableView *listeControles;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuImprimer;
    QMenu *menuAdministration;
    QMenu *menuControle;
    QMenu *menuDebug;
    QToolBar *fichierToolBar;
    QStatusBar *statusBar;
    QToolBar *controleToolBar;
    QToolBar *toolBarActions;

    void setupUi(QMainWindow *FenetrePrincipale)
    {
        if (FenetrePrincipale->objectName().isEmpty())
            FenetrePrincipale->setObjectName(QString::fromUtf8("FenetrePrincipale"));
        FenetrePrincipale->resize(829, 537);
        actionConnexion = new QAction(FenetrePrincipale);
        actionConnexion->setObjectName(QString::fromUtf8("actionConnexion"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icones/connexion"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnexion->setIcon(icon);
        actionDeconnexion = new QAction(FenetrePrincipale);
        actionDeconnexion->setObjectName(QString::fromUtf8("actionDeconnexion"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icones/deconnexion"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeconnexion->setIcon(icon1);
        actionQuitter = new QAction(FenetrePrincipale);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icones/quitter"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuitter->setIcon(icon2);
        actionAdminPoles = new QAction(FenetrePrincipale);
        actionAdminPoles->setObjectName(QString::fromUtf8("actionAdminPoles"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icones/options"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdminPoles->setIcon(icon3);
        actionAdminMatieres = new QAction(FenetrePrincipale);
        actionAdminMatieres->setObjectName(QString::fromUtf8("actionAdminMatieres"));
        actionAdminMatieres->setIcon(icon3);
        actionAdminTypesControle = new QAction(FenetrePrincipale);
        actionAdminTypesControle->setObjectName(QString::fromUtf8("actionAdminTypesControle"));
        actionAdminTypesControle->setIcon(icon3);
        actionAdminSalles = new QAction(FenetrePrincipale);
        actionAdminSalles->setObjectName(QString::fromUtf8("actionAdminSalles"));
        actionAdminSalles->setIcon(icon3);
        actionAdminUtilisateurs = new QAction(FenetrePrincipale);
        actionAdminUtilisateurs->setObjectName(QString::fromUtf8("actionAdminUtilisateurs"));
        actionAdminUtilisateurs->setIcon(icon3);
        actionNouveau_controle = new QAction(FenetrePrincipale);
        actionNouveau_controle->setObjectName(QString::fromUtf8("actionNouveau_controle"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icones/ajouter"), QSize(), QIcon::Normal, QIcon::Off);
        actionNouveau_controle->setIcon(icon4);
        actionNouveaux_controles = new QAction(FenetrePrincipale);
        actionNouveaux_controles->setObjectName(QString::fromUtf8("actionNouveaux_controles"));
        actionNouveaux_controles->setEnabled(true);
        actionJeuEssai = new QAction(FenetrePrincipale);
        actionJeuEssai->setObjectName(QString::fromUtf8("actionJeuEssai"));
        actionJeuEssai->setIcon(icon3);
        actionViderBd = new QAction(FenetrePrincipale);
        actionViderBd->setObjectName(QString::fromUtf8("actionViderBd"));
        actionViderBd->setIcon(icon3);
        actionEditer = new QAction(FenetrePrincipale);
        actionEditer->setObjectName(QString::fromUtf8("actionEditer"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icones/editer"), QSize(), QIcon::Normal, QIcon::Off);
        actionEditer->setIcon(icon5);
        actionSurveiller = new QAction(FenetrePrincipale);
        actionSurveiller->setObjectName(QString::fromUtf8("actionSurveiller"));
        actionSurveiller->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icones/surveiller"), QSize(), QIcon::Normal, QIcon::Off);
        actionSurveiller->setIcon(icon6);
        actionToutImprimer = new QAction(FenetrePrincipale);
        actionToutImprimer->setObjectName(QString::fromUtf8("actionToutImprimer"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icones/imprimer"), QSize(), QIcon::Normal, QIcon::Off);
        actionToutImprimer->setIcon(icon7);
        actionImprimerDetailsHeuresdesurveillance = new QAction(FenetrePrincipale);
        actionImprimerDetailsHeuresdesurveillance->setObjectName(QString::fromUtf8("actionImprimerDetailsHeuresdesurveillance"));
        actionImprimerDetailsHeuresdesurveillance->setIcon(icon7);
        actionImprimerControlesSurveilles = new QAction(FenetrePrincipale);
        actionImprimerControlesSurveilles->setObjectName(QString::fromUtf8("actionImprimerControlesSurveilles"));
        actionImprimerControlesSurveilles->setIcon(icon7);
        actionImprimerDetailsHeuresdesurveillanceTrieParQuota = new QAction(FenetrePrincipale);
        actionImprimerDetailsHeuresdesurveillanceTrieParQuota->setObjectName(QString::fromUtf8("actionImprimerDetailsHeuresdesurveillanceTrieParQuota"));
        actionImprimerDetailsHeuresdesurveillanceTrieParQuota->setIcon(icon7);
        centralWidget = new QWidget(FenetrePrincipale);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listeControles = new QTableView(centralWidget);
        listeControles->setObjectName(QString::fromUtf8("listeControles"));
        listeControles->setContextMenuPolicy(Qt::CustomContextMenu);

        verticalLayout->addWidget(listeControles);

        FenetrePrincipale->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FenetrePrincipale);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 829, 23));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuImprimer = new QMenu(menuFichier);
        menuImprimer->setObjectName(QString::fromUtf8("menuImprimer"));
        menuAdministration = new QMenu(menuBar);
        menuAdministration->setObjectName(QString::fromUtf8("menuAdministration"));
        menuControle = new QMenu(menuBar);
        menuControle->setObjectName(QString::fromUtf8("menuControle"));
        menuDebug = new QMenu(menuBar);
        menuDebug->setObjectName(QString::fromUtf8("menuDebug"));
        FenetrePrincipale->setMenuBar(menuBar);
        fichierToolBar = new QToolBar(FenetrePrincipale);
        fichierToolBar->setObjectName(QString::fromUtf8("fichierToolBar"));
        FenetrePrincipale->addToolBar(Qt::TopToolBarArea, fichierToolBar);
        statusBar = new QStatusBar(FenetrePrincipale);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FenetrePrincipale->setStatusBar(statusBar);
        controleToolBar = new QToolBar(FenetrePrincipale);
        controleToolBar->setObjectName(QString::fromUtf8("controleToolBar"));
        FenetrePrincipale->addToolBar(Qt::TopToolBarArea, controleToolBar);
        toolBarActions = new QToolBar(FenetrePrincipale);
        toolBarActions->setObjectName(QString::fromUtf8("toolBarActions"));
        FenetrePrincipale->addToolBar(Qt::TopToolBarArea, toolBarActions);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuAdministration->menuAction());
        menuBar->addAction(menuControle->menuAction());
        menuBar->addAction(menuDebug->menuAction());
        menuFichier->addAction(actionConnexion);
        menuFichier->addAction(actionDeconnexion);
        menuFichier->addSeparator();
        menuFichier->addAction(menuImprimer->menuAction());
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuImprimer->addAction(actionImprimerControlesSurveilles);
        menuImprimer->addAction(actionToutImprimer);
        menuImprimer->addAction(actionImprimerDetailsHeuresdesurveillance);
        menuImprimer->addAction(actionImprimerDetailsHeuresdesurveillanceTrieParQuota);
        menuAdministration->addAction(actionAdminPoles);
        menuAdministration->addAction(actionAdminMatieres);
        menuAdministration->addAction(actionAdminTypesControle);
        menuAdministration->addAction(actionAdminUtilisateurs);
        menuAdministration->addSeparator();
        menuAdministration->addAction(actionAdminSalles);
        menuAdministration->addSeparator();
        menuControle->addAction(actionNouveau_controle);
        menuControle->addAction(actionNouveaux_controles);
        menuDebug->addAction(actionJeuEssai);
        menuDebug->addAction(actionViderBd);
        fichierToolBar->addAction(actionConnexion);
        fichierToolBar->addAction(actionDeconnexion);
        fichierToolBar->addSeparator();
        fichierToolBar->addSeparator();
        fichierToolBar->addAction(actionQuitter);
        controleToolBar->addAction(actionNouveau_controle);
        controleToolBar->addAction(actionNouveaux_controles);
        toolBarActions->addAction(actionSurveiller);
        toolBarActions->addAction(actionEditer);

        retranslateUi(FenetrePrincipale);
        QObject::connect(actionQuitter, SIGNAL(triggered()), FenetrePrincipale, SLOT(quitter()));
        QObject::connect(actionAdminMatieres, SIGNAL(triggered()), FenetrePrincipale, SLOT(adminMatiere()));
        QObject::connect(actionAdminPoles, SIGNAL(triggered()), FenetrePrincipale, SLOT(adminPole()));
        QObject::connect(actionAdminSalles, SIGNAL(triggered()), FenetrePrincipale, SLOT(adminSalles()));
        QObject::connect(actionAdminTypesControle, SIGNAL(triggered()), FenetrePrincipale, SLOT(adminTypeControle()));
        QObject::connect(actionAdminUtilisateurs, SIGNAL(triggered()), FenetrePrincipale, SLOT(adminUtilisateurs()));
        QObject::connect(actionConnexion, SIGNAL(triggered()), FenetrePrincipale, SLOT(seConnecter()));
        QObject::connect(actionDeconnexion, SIGNAL(triggered()), FenetrePrincipale, SLOT(seDeconnecter()));
        QObject::connect(actionNouveau_controle, SIGNAL(triggered()), FenetrePrincipale, SLOT(ajouterControle()));
        QObject::connect(actionNouveaux_controles, SIGNAL(triggered()), FenetrePrincipale, SLOT(initialiserControles()));
        QObject::connect(actionJeuEssai, SIGNAL(triggered()), FenetrePrincipale, SLOT(remplirJeuEssai()));
        QObject::connect(actionViderBd, SIGNAL(triggered()), FenetrePrincipale, SLOT(viderBd()));
        QObject::connect(listeControles, SIGNAL(customContextMenuRequested(QPoint)), FenetrePrincipale, SLOT(menu()));
        QObject::connect(actionEditer, SIGNAL(triggered()), FenetrePrincipale, SLOT(editer()));
        QObject::connect(actionSurveiller, SIGNAL(triggered()), FenetrePrincipale, SLOT(surveiller()));
        QObject::connect(listeControles, SIGNAL(clicked(QModelIndex)), FenetrePrincipale, SLOT(majActionsControles()));
        QObject::connect(actionImprimerControlesSurveilles, SIGNAL(triggered()), FenetrePrincipale, SLOT(imprimerListeControlesSurveilles()));
        QObject::connect(actionToutImprimer, SIGNAL(triggered()), FenetrePrincipale, SLOT(imprimerListeTousControles()));
        QObject::connect(actionImprimerDetailsHeuresdesurveillance, SIGNAL(triggered()), FenetrePrincipale, SLOT(imprimerListeDetailsHeuresSurveillances()));
        QObject::connect(actionImprimerDetailsHeuresdesurveillanceTrieParQuota, SIGNAL(triggered()), FenetrePrincipale, SLOT(imprimerListeDetailsHeuresSurveillancesTrieParQuota()));

        QMetaObject::connectSlotsByName(FenetrePrincipale);
    } // setupUi

    void retranslateUi(QMainWindow *FenetrePrincipale)
    {
        FenetrePrincipale->setWindowTitle(QApplication::translate("FenetrePrincipale", "Rubidium", 0, QApplication::UnicodeUTF8));
        actionConnexion->setText(QApplication::translate("FenetrePrincipale", "Connexion...", 0, QApplication::UnicodeUTF8));
        actionDeconnexion->setText(QApplication::translate("FenetrePrincipale", "D\303\251connexion", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("FenetrePrincipale", "Quitter", 0, QApplication::UnicodeUTF8));
        actionAdminPoles->setText(QApplication::translate("FenetrePrincipale", "P\303\264les...", 0, QApplication::UnicodeUTF8));
        actionAdminMatieres->setText(QApplication::translate("FenetrePrincipale", "Mati\303\250res...", 0, QApplication::UnicodeUTF8));
        actionAdminTypesControle->setText(QApplication::translate("FenetrePrincipale", "Types de contr\303\264le...", 0, QApplication::UnicodeUTF8));
        actionAdminSalles->setText(QApplication::translate("FenetrePrincipale", "Salles...", 0, QApplication::UnicodeUTF8));
        actionAdminUtilisateurs->setText(QApplication::translate("FenetrePrincipale", "Utilisateurs...", 0, QApplication::UnicodeUTF8));
        actionNouveau_controle->setText(QApplication::translate("FenetrePrincipale", "Nouveau contr\303\264le...", 0, QApplication::UnicodeUTF8));
        actionNouveaux_controles->setText(QApplication::translate("FenetrePrincipale", "Initialisation des contr\303\264les...", 0, QApplication::UnicodeUTF8));
        actionJeuEssai->setText(QApplication::translate("FenetrePrincipale", "Remplir la base avec un jeu d'essai", 0, QApplication::UnicodeUTF8));
        actionViderBd->setText(QApplication::translate("FenetrePrincipale", "Vider la base de donn\303\251es", 0, QApplication::UnicodeUTF8));
        actionEditer->setText(QApplication::translate("FenetrePrincipale", "\303\211diter", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEditer->setToolTip(QApplication::translate("FenetrePrincipale", "\303\211dite le controle s\303\251lectionn\303\251", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSurveiller->setText(QApplication::translate("FenetrePrincipale", "Surveiller", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSurveiller->setToolTip(QApplication::translate("FenetrePrincipale", "Surveiller ou non le contr\303\264le courant", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionToutImprimer->setText(QApplication::translate("FenetrePrincipale", "Tous les contr\303\264les", 0, QApplication::UnicodeUTF8));
        actionImprimerDetailsHeuresdesurveillance->setText(QApplication::translate("FenetrePrincipale", "D\303\251tails des heures de surveillance de tous les professeurs", 0, QApplication::UnicodeUTF8));
        actionImprimerControlesSurveilles->setText(QApplication::translate("FenetrePrincipale", "Contr\303\264les surveill\303\251s", 0, QApplication::UnicodeUTF8));
        actionImprimerDetailsHeuresdesurveillanceTrieParQuota->setText(QApplication::translate("FenetrePrincipale", "D\303\251tails des heures de surveillance de tous les professeurs -- tri\303\251 par quota", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("FenetrePrincipale", "Fichier", 0, QApplication::UnicodeUTF8));
        menuImprimer->setTitle(QApplication::translate("FenetrePrincipale", "Imprimer", 0, QApplication::UnicodeUTF8));
        menuAdministration->setTitle(QApplication::translate("FenetrePrincipale", "Administration", 0, QApplication::UnicodeUTF8));
        menuControle->setTitle(QApplication::translate("FenetrePrincipale", "Contr\303\264les", 0, QApplication::UnicodeUTF8));
        menuDebug->setTitle(QApplication::translate("FenetrePrincipale", "Debug", 0, QApplication::UnicodeUTF8));
        fichierToolBar->setWindowTitle(QApplication::translate("FenetrePrincipale", "Fichier", 0, QApplication::UnicodeUTF8));
        controleToolBar->setWindowTitle(QApplication::translate("FenetrePrincipale", "Contr\303\264les", 0, QApplication::UnicodeUTF8));
        toolBarActions->setWindowTitle(QApplication::translate("FenetrePrincipale", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FenetrePrincipale: public Ui_FenetrePrincipale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETREPRINCIPALE_H
