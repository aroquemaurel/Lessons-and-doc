/********************************************************************************
** Form generated from reading UI file 'dialogajoutermatiere.ui'
**
** Created: Sat Mar 31 16:04:39 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTERMATIERE_H
#define UI_DIALOGAJOUTERMATIERE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogAjoutermatiere
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *layoutGeneral;
    QGridLayout *layoutSousGeneral;
    QLabel *lbMatiere;
    QLineEdit *matiere;
    QLabel *lbPole;
    QComboBox *pole;
    QDialogButtonBox *boutons;

    void setupUi(QDialog *DialogAjoutermatiere)
    {
        if (DialogAjoutermatiere->objectName().isEmpty())
            DialogAjoutermatiere->setObjectName(QString::fromUtf8("DialogAjoutermatiere"));
        DialogAjoutermatiere->resize(198, 115);
        layoutWidget = new QWidget(DialogAjoutermatiere);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 178, 97));
        layoutGeneral = new QVBoxLayout(layoutWidget);
        layoutGeneral->setObjectName(QString::fromUtf8("layoutGeneral"));
        layoutGeneral->setContentsMargins(0, 0, 0, 0);
        layoutSousGeneral = new QGridLayout();
        layoutSousGeneral->setObjectName(QString::fromUtf8("layoutSousGeneral"));
        lbMatiere = new QLabel(layoutWidget);
        lbMatiere->setObjectName(QString::fromUtf8("lbMatiere"));

        layoutSousGeneral->addWidget(lbMatiere, 0, 0, 1, 1);

        matiere = new QLineEdit(layoutWidget);
        matiere->setObjectName(QString::fromUtf8("matiere"));

        layoutSousGeneral->addWidget(matiere, 0, 1, 1, 1);

        lbPole = new QLabel(layoutWidget);
        lbPole->setObjectName(QString::fromUtf8("lbPole"));

        layoutSousGeneral->addWidget(lbPole, 1, 0, 1, 1);

        pole = new QComboBox(layoutWidget);
        pole->setObjectName(QString::fromUtf8("pole"));

        layoutSousGeneral->addWidget(pole, 1, 1, 1, 1);


        layoutGeneral->addLayout(layoutSousGeneral);

        boutons = new QDialogButtonBox(layoutWidget);
        boutons->setObjectName(QString::fromUtf8("boutons"));
        boutons->setOrientation(Qt::Horizontal);
        boutons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        layoutGeneral->addWidget(boutons);

        QWidget::setTabOrder(matiere, pole);
        QWidget::setTabOrder(pole, boutons);

        retranslateUi(DialogAjoutermatiere);
        QObject::connect(boutons, SIGNAL(accepted()), DialogAjoutermatiere, SLOT(accept()));
        QObject::connect(boutons, SIGNAL(rejected()), DialogAjoutermatiere, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAjoutermatiere);
    } // setupUi

    void retranslateUi(QDialog *DialogAjoutermatiere)
    {
        DialogAjoutermatiere->setWindowTitle(QApplication::translate("DialogAjoutermatiere", "Ajouter une mati\303\250re", 0, QApplication::UnicodeUTF8));
        lbMatiere->setText(QApplication::translate("DialogAjoutermatiere", "Mati\303\250re", 0, QApplication::UnicodeUTF8));
        lbPole->setText(QApplication::translate("DialogAjoutermatiere", "P\303\264le", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogAjoutermatiere: public Ui_DialogAjoutermatiere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTERMATIERE_H
