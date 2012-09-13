/********************************************************************************
** Form generated from reading UI file 'dialogajoutersalle.ui'
**
** Created: Thu Mar 1 10:58:35 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTERSALLE_H
#define UI_DIALOGAJOUTERSALLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogAjouterSalle
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lbNom;
    QLineEdit *nom;
    QLabel *lbCapacite;
    QSpinBox *capacite;
    QLabel *lbSurveillants;
    QSpinBox *surveillants;
    QDialogButtonBox *boutons;

    void setupUi(QDialog *DialogAjouterSalle)
    {
        if (DialogAjouterSalle->objectName().isEmpty())
            DialogAjouterSalle->setObjectName(QString::fromUtf8("DialogAjouterSalle"));
        DialogAjouterSalle->resize(309, 146);
        verticalLayout = new QVBoxLayout(DialogAjouterSalle);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lbNom = new QLabel(DialogAjouterSalle);
        lbNom->setObjectName(QString::fromUtf8("lbNom"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lbNom);

        nom = new QLineEdit(DialogAjouterSalle);
        nom->setObjectName(QString::fromUtf8("nom"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nom);

        lbCapacite = new QLabel(DialogAjouterSalle);
        lbCapacite->setObjectName(QString::fromUtf8("lbCapacite"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lbCapacite);

        capacite = new QSpinBox(DialogAjouterSalle);
        capacite->setObjectName(QString::fromUtf8("capacite"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(capacite->sizePolicy().hasHeightForWidth());
        capacite->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, capacite);

        lbSurveillants = new QLabel(DialogAjouterSalle);
        lbSurveillants->setObjectName(QString::fromUtf8("lbSurveillants"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lbSurveillants);

        surveillants = new QSpinBox(DialogAjouterSalle);
        surveillants->setObjectName(QString::fromUtf8("surveillants"));
        sizePolicy.setHeightForWidth(surveillants->sizePolicy().hasHeightForWidth());
        surveillants->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, surveillants);


        verticalLayout->addLayout(formLayout);

        boutons = new QDialogButtonBox(DialogAjouterSalle);
        boutons->setObjectName(QString::fromUtf8("boutons"));
        boutons->setOrientation(Qt::Horizontal);
        boutons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(boutons);

        QWidget::setTabOrder(nom, capacite);
        QWidget::setTabOrder(capacite, surveillants);
        QWidget::setTabOrder(surveillants, boutons);

        retranslateUi(DialogAjouterSalle);
        QObject::connect(boutons, SIGNAL(accepted()), DialogAjouterSalle, SLOT(accept()));
        QObject::connect(boutons, SIGNAL(rejected()), DialogAjouterSalle, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAjouterSalle);
    } // setupUi

    void retranslateUi(QDialog *DialogAjouterSalle)
    {
        DialogAjouterSalle->setWindowTitle(QApplication::translate("DialogAjouterSalle", "Ajouter une salle", 0, QApplication::UnicodeUTF8));
        lbNom->setText(QApplication::translate("DialogAjouterSalle", "Nom", 0, QApplication::UnicodeUTF8));
        lbCapacite->setText(QApplication::translate("DialogAjouterSalle", "Capacit\303\251", 0, QApplication::UnicodeUTF8));
        lbSurveillants->setText(QApplication::translate("DialogAjouterSalle", "Surveillants n\303\251cessaires", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogAjouterSalle: public Ui_DialogAjouterSalle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTERSALLE_H
