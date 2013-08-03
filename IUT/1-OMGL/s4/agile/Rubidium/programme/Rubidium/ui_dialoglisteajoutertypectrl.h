/********************************************************************************
** Form generated from reading UI file 'dialoglisteajoutertypectrl.ui'
**
** Created: Sat Aug 3 00:47:20 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLISTEAJOUTERTYPECTRL_H
#define UI_DIALOGLISTEAJOUTERTYPECTRL_H

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

class Ui_DialogListeAjouterTypeCtrl
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *typeCtrl;
    QHBoxLayout *ajouterSupprimer;
    QPushButton *ajouter;
    QPushButton *supprimer;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *boutons;

    void setupUi(QDialog *DialogListeAjouterTypeCtrl)
    {
        if (DialogListeAjouterTypeCtrl->objectName().isEmpty())
            DialogListeAjouterTypeCtrl->setObjectName(QString::fromUtf8("DialogListeAjouterTypeCtrl"));
        DialogListeAjouterTypeCtrl->resize(274, 285);
        verticalLayout = new QVBoxLayout(DialogListeAjouterTypeCtrl);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        typeCtrl = new QTableView(DialogListeAjouterTypeCtrl);
        typeCtrl->setObjectName(QString::fromUtf8("typeCtrl"));

        verticalLayout->addWidget(typeCtrl);

        ajouterSupprimer = new QHBoxLayout();
        ajouterSupprimer->setObjectName(QString::fromUtf8("ajouterSupprimer"));
        ajouter = new QPushButton(DialogListeAjouterTypeCtrl);
        ajouter->setObjectName(QString::fromUtf8("ajouter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icones/ajouter"), QSize(), QIcon::Normal, QIcon::Off);
        ajouter->setIcon(icon);

        ajouterSupprimer->addWidget(ajouter);

        supprimer = new QPushButton(DialogListeAjouterTypeCtrl);
        supprimer->setObjectName(QString::fromUtf8("supprimer"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icones/supprimer"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer->setIcon(icon1);

        ajouterSupprimer->addWidget(supprimer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ajouterSupprimer->addItem(horizontalSpacer);


        verticalLayout->addLayout(ajouterSupprimer);

        boutons = new QDialogButtonBox(DialogListeAjouterTypeCtrl);
        boutons->setObjectName(QString::fromUtf8("boutons"));
        boutons->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(boutons);


        retranslateUi(DialogListeAjouterTypeCtrl);
        QObject::connect(boutons, SIGNAL(clicked(QAbstractButton*)), DialogListeAjouterTypeCtrl, SLOT(accept()));
        QObject::connect(ajouter, SIGNAL(pressed()), DialogListeAjouterTypeCtrl, SLOT(ajouter()));
        QObject::connect(supprimer, SIGNAL(pressed()), DialogListeAjouterTypeCtrl, SLOT(supprimer()));

        QMetaObject::connectSlotsByName(DialogListeAjouterTypeCtrl);
    } // setupUi

    void retranslateUi(QDialog *DialogListeAjouterTypeCtrl)
    {
        DialogListeAjouterTypeCtrl->setWindowTitle(QApplication::translate("DialogListeAjouterTypeCtrl", "Gestion des types de contr\303\264les", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogListeAjouterTypeCtrl: public Ui_DialogListeAjouterTypeCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLISTEAJOUTERTYPECTRL_H
