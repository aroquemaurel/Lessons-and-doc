/********************************************************************************
** Form generated from reading UI file 'dialogtableajoutermatiere.ui'
**
** Created: Sat Mar 31 16:04:39 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTABLEAJOUTERMATIERE_H
#define UI_DIALOGTABLEAJOUTERMATIERE_H

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

class Ui_DialogTableAjouterMatiere
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *matiere;
    QHBoxLayout *ajouterSupprimer;
    QPushButton *ajouter;
    QPushButton *supprimer;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *boutons;

    void setupUi(QDialog *DialogTableAjouterMatiere)
    {
        if (DialogTableAjouterMatiere->objectName().isEmpty())
            DialogTableAjouterMatiere->setObjectName(QString::fromUtf8("DialogTableAjouterMatiere"));
        DialogTableAjouterMatiere->resize(274, 285);
        verticalLayout = new QVBoxLayout(DialogTableAjouterMatiere);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        matiere = new QTableView(DialogTableAjouterMatiere);
        matiere->setObjectName(QString::fromUtf8("matiere"));

        verticalLayout->addWidget(matiere);

        ajouterSupprimer = new QHBoxLayout();
        ajouterSupprimer->setObjectName(QString::fromUtf8("ajouterSupprimer"));
        ajouter = new QPushButton(DialogTableAjouterMatiere);
        ajouter->setObjectName(QString::fromUtf8("ajouter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icones/ajouter"), QSize(), QIcon::Normal, QIcon::Off);
        ajouter->setIcon(icon);

        ajouterSupprimer->addWidget(ajouter);

        supprimer = new QPushButton(DialogTableAjouterMatiere);
        supprimer->setObjectName(QString::fromUtf8("supprimer"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icones/supprimer"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer->setIcon(icon1);

        ajouterSupprimer->addWidget(supprimer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ajouterSupprimer->addItem(horizontalSpacer);


        verticalLayout->addLayout(ajouterSupprimer);

        boutons = new QDialogButtonBox(DialogTableAjouterMatiere);
        boutons->setObjectName(QString::fromUtf8("boutons"));
        boutons->setOrientation(Qt::Horizontal);
        boutons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(boutons);


        retranslateUi(DialogTableAjouterMatiere);
        QObject::connect(boutons, SIGNAL(accepted()), DialogTableAjouterMatiere, SLOT(accept()));
        QObject::connect(boutons, SIGNAL(rejected()), DialogTableAjouterMatiere, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogTableAjouterMatiere);
    } // setupUi

    void retranslateUi(QDialog *DialogTableAjouterMatiere)
    {
        DialogTableAjouterMatiere->setWindowTitle(QApplication::translate("DialogTableAjouterMatiere", "Gestion des mati\303\250res", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogTableAjouterMatiere: public Ui_DialogTableAjouterMatiere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTABLEAJOUTERMATIERE_H
