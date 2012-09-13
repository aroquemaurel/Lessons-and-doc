/********************************************************************************
** Form generated from reading UI file 'dialoglisteajouterpole.ui'
**
** Created: Sat Mar 31 16:04:39 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLISTEAJOUTERPOLE_H
#define UI_DIALOGLISTEAJOUTERPOLE_H

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

class Ui_DialogListeAjouterPole
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *pole;
    QHBoxLayout *ajouterSupprimer;
    QPushButton *ajouter;
    QPushButton *supprimer;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *boutons;

    void setupUi(QDialog *DialogListeAjouterPole)
    {
        if (DialogListeAjouterPole->objectName().isEmpty())
            DialogListeAjouterPole->setObjectName(QString::fromUtf8("DialogListeAjouterPole"));
        DialogListeAjouterPole->resize(274, 285);
        verticalLayout = new QVBoxLayout(DialogListeAjouterPole);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pole = new QTableView(DialogListeAjouterPole);
        pole->setObjectName(QString::fromUtf8("pole"));

        verticalLayout->addWidget(pole);

        ajouterSupprimer = new QHBoxLayout();
        ajouterSupprimer->setObjectName(QString::fromUtf8("ajouterSupprimer"));
        ajouter = new QPushButton(DialogListeAjouterPole);
        ajouter->setObjectName(QString::fromUtf8("ajouter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icones/ajouter"), QSize(), QIcon::Normal, QIcon::Off);
        ajouter->setIcon(icon);

        ajouterSupprimer->addWidget(ajouter);

        supprimer = new QPushButton(DialogListeAjouterPole);
        supprimer->setObjectName(QString::fromUtf8("supprimer"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icones/supprimer"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer->setIcon(icon1);

        ajouterSupprimer->addWidget(supprimer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ajouterSupprimer->addItem(horizontalSpacer);


        verticalLayout->addLayout(ajouterSupprimer);

        boutons = new QDialogButtonBox(DialogListeAjouterPole);
        boutons->setObjectName(QString::fromUtf8("boutons"));
        boutons->setOrientation(Qt::Horizontal);
        boutons->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(boutons);


        retranslateUi(DialogListeAjouterPole);
        QObject::connect(boutons, SIGNAL(clicked(QAbstractButton*)), DialogListeAjouterPole, SLOT(accept()));
        QObject::connect(ajouter, SIGNAL(pressed()), DialogListeAjouterPole, SLOT(ajouter()));
        QObject::connect(supprimer, SIGNAL(pressed()), DialogListeAjouterPole, SLOT(supprimer()));

        QMetaObject::connectSlotsByName(DialogListeAjouterPole);
    } // setupUi

    void retranslateUi(QDialog *DialogListeAjouterPole)
    {
        DialogListeAjouterPole->setWindowTitle(QApplication::translate("DialogListeAjouterPole", "Gestion des p\303\264les", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogListeAjouterPole: public Ui_DialogListeAjouterPole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLISTEAJOUTERPOLE_H
