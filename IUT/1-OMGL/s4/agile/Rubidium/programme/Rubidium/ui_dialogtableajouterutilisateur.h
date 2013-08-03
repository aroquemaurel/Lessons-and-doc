/********************************************************************************
** Form generated from reading UI file 'dialogtableajouterutilisateur.ui'
**
** Created: Sat Aug 3 00:47:20 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTABLEAJOUTERUTILISATEUR_H
#define UI_DIALOGTABLEAJOUTERUTILISATEUR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogTableAjouterUtilisateur
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *utilisateur;
    QHBoxLayout *ajouterSupprimer;
    QPushButton *ajouter;
    QPushButton *supprimer;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *boutons;

    void setupUi(QDialog *DialogTableAjouterUtilisateur)
    {
        if (DialogTableAjouterUtilisateur->objectName().isEmpty())
            DialogTableAjouterUtilisateur->setObjectName(QString::fromUtf8("DialogTableAjouterUtilisateur"));
        DialogTableAjouterUtilisateur->resize(274, 285);
        verticalLayout = new QVBoxLayout(DialogTableAjouterUtilisateur);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        utilisateur = new QTableView(DialogTableAjouterUtilisateur);
        utilisateur->setObjectName(QString::fromUtf8("utilisateur"));

        verticalLayout->addWidget(utilisateur);

        ajouterSupprimer = new QHBoxLayout();
        ajouterSupprimer->setObjectName(QString::fromUtf8("ajouterSupprimer"));
        ajouter = new QPushButton(DialogTableAjouterUtilisateur);
        ajouter->setObjectName(QString::fromUtf8("ajouter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icones/ajouter"), QSize(), QIcon::Normal, QIcon::Off);
        ajouter->setIcon(icon);

        ajouterSupprimer->addWidget(ajouter);

        supprimer = new QPushButton(DialogTableAjouterUtilisateur);
        supprimer->setObjectName(QString::fromUtf8("supprimer"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icones/supprimer"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer->setIcon(icon1);

        ajouterSupprimer->addWidget(supprimer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ajouterSupprimer->addItem(horizontalSpacer);


        verticalLayout->addLayout(ajouterSupprimer);

        boutons = new QDialogButtonBox(DialogTableAjouterUtilisateur);
        boutons->setObjectName(QString::fromUtf8("boutons"));
        boutons->setOrientation(Qt::Horizontal);
        boutons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(boutons);


        retranslateUi(DialogTableAjouterUtilisateur);
        QObject::connect(boutons, SIGNAL(accepted()), DialogTableAjouterUtilisateur, SLOT(accept()));
        QObject::connect(boutons, SIGNAL(rejected()), DialogTableAjouterUtilisateur, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogTableAjouterUtilisateur);
    } // setupUi

    void retranslateUi(QDialog *DialogTableAjouterUtilisateur)
    {
        DialogTableAjouterUtilisateur->setWindowTitle(QApplication::translate("DialogTableAjouterUtilisateur", "Gestion des utilisateurs", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogTableAjouterUtilisateur: public Ui_DialogTableAjouterUtilisateur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTABLEAJOUTERUTILISATEUR_H
