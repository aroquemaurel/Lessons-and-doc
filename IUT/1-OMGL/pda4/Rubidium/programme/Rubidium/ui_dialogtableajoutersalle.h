/********************************************************************************
** Form generated from reading UI file 'dialogtableajoutersalle.ui'
**
** Created: Sat Mar 31 16:04:39 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTABLEAJOUTERSALLE_H
#define UI_DIALOGTABLEAJOUTERSALLE_H

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

class Ui_DialogTableAjouterSalle
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *salles;
    QHBoxLayout *ajouterSupprimer;
    QPushButton *boutonAjouter;
    QPushButton *boutonSupprimer;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *boutons;

    void setupUi(QDialog *DialogTableAjouterSalle)
    {
        if (DialogTableAjouterSalle->objectName().isEmpty())
            DialogTableAjouterSalle->setObjectName(QString::fromUtf8("DialogTableAjouterSalle"));
        DialogTableAjouterSalle->resize(289, 285);
        verticalLayout = new QVBoxLayout(DialogTableAjouterSalle);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        salles = new QTableView(DialogTableAjouterSalle);
        salles->setObjectName(QString::fromUtf8("salles"));

        verticalLayout->addWidget(salles);

        ajouterSupprimer = new QHBoxLayout();
        ajouterSupprimer->setObjectName(QString::fromUtf8("ajouterSupprimer"));
        boutonAjouter = new QPushButton(DialogTableAjouterSalle);
        boutonAjouter->setObjectName(QString::fromUtf8("boutonAjouter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icones/ajouter"), QSize(), QIcon::Normal, QIcon::Off);
        boutonAjouter->setIcon(icon);

        ajouterSupprimer->addWidget(boutonAjouter);

        boutonSupprimer = new QPushButton(DialogTableAjouterSalle);
        boutonSupprimer->setObjectName(QString::fromUtf8("boutonSupprimer"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icones/supprimer"), QSize(), QIcon::Normal, QIcon::Off);
        boutonSupprimer->setIcon(icon1);

        ajouterSupprimer->addWidget(boutonSupprimer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ajouterSupprimer->addItem(horizontalSpacer);


        verticalLayout->addLayout(ajouterSupprimer);

        boutons = new QDialogButtonBox(DialogTableAjouterSalle);
        boutons->setObjectName(QString::fromUtf8("boutons"));
        boutons->setOrientation(Qt::Horizontal);
        boutons->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(boutons);


        retranslateUi(DialogTableAjouterSalle);
        QObject::connect(boutons, SIGNAL(clicked(QAbstractButton*)), DialogTableAjouterSalle, SLOT(accept()));
        QObject::connect(boutonAjouter, SIGNAL(pressed()), DialogTableAjouterSalle, SLOT(ajouter()));
        QObject::connect(boutonSupprimer, SIGNAL(pressed()), DialogTableAjouterSalle, SLOT(supprimer()));

        QMetaObject::connectSlotsByName(DialogTableAjouterSalle);
    } // setupUi

    void retranslateUi(QDialog *DialogTableAjouterSalle)
    {
        DialogTableAjouterSalle->setWindowTitle(QApplication::translate("DialogTableAjouterSalle", "Gestion des salles", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogTableAjouterSalle: public Ui_DialogTableAjouterSalle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTABLEAJOUTERSALLE_H
