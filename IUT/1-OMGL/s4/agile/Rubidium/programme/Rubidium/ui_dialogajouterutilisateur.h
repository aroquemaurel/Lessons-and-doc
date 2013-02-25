/********************************************************************************
** Form generated from reading UI file 'dialogajouterutilisateur.ui'
**
** Created: Sat Mar 31 16:04:39 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTERUTILISATEUR_H
#define UI_DIALOGAJOUTERUTILISATEUR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogAjouterUtilisateur
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lbNom;
    QLineEdit *nom;
    QLabel *lbPrenom;
    QLineEdit *prenom;
    QLabel *lbPass1;
    QLineEdit *pass1;
    QLabel *lbPass2;
    QLineEdit *pass2;
    QLabel *lbQuota;
    QSpinBox *quota;
    QCheckBox *responsablePlanning;
    QCheckBox *administrateur;
    QDialogButtonBox *boutons;

    void setupUi(QDialog *DialogAjouterUtilisateur)
    {
        if (DialogAjouterUtilisateur->objectName().isEmpty())
            DialogAjouterUtilisateur->setObjectName(QString::fromUtf8("DialogAjouterUtilisateur"));
        DialogAjouterUtilisateur->resize(278, 268);
        verticalLayout = new QVBoxLayout(DialogAjouterUtilisateur);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lbNom = new QLabel(DialogAjouterUtilisateur);
        lbNom->setObjectName(QString::fromUtf8("lbNom"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lbNom);

        nom = new QLineEdit(DialogAjouterUtilisateur);
        nom->setObjectName(QString::fromUtf8("nom"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nom);

        lbPrenom = new QLabel(DialogAjouterUtilisateur);
        lbPrenom->setObjectName(QString::fromUtf8("lbPrenom"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lbPrenom);

        prenom = new QLineEdit(DialogAjouterUtilisateur);
        prenom->setObjectName(QString::fromUtf8("prenom"));

        formLayout->setWidget(1, QFormLayout::FieldRole, prenom);

        lbPass1 = new QLabel(DialogAjouterUtilisateur);
        lbPass1->setObjectName(QString::fromUtf8("lbPass1"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lbPass1);

        pass1 = new QLineEdit(DialogAjouterUtilisateur);
        pass1->setObjectName(QString::fromUtf8("pass1"));
        pass1->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, pass1);

        lbPass2 = new QLabel(DialogAjouterUtilisateur);
        lbPass2->setObjectName(QString::fromUtf8("lbPass2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lbPass2);

        pass2 = new QLineEdit(DialogAjouterUtilisateur);
        pass2->setObjectName(QString::fromUtf8("pass2"));
        pass2->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, pass2);

        lbQuota = new QLabel(DialogAjouterUtilisateur);
        lbQuota->setObjectName(QString::fromUtf8("lbQuota"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lbQuota);

        quota = new QSpinBox(DialogAjouterUtilisateur);
        quota->setObjectName(QString::fromUtf8("quota"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(quota->sizePolicy().hasHeightForWidth());
        quota->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::FieldRole, quota);

        responsablePlanning = new QCheckBox(DialogAjouterUtilisateur);
        responsablePlanning->setObjectName(QString::fromUtf8("responsablePlanning"));

        formLayout->setWidget(5, QFormLayout::FieldRole, responsablePlanning);

        administrateur = new QCheckBox(DialogAjouterUtilisateur);
        administrateur->setObjectName(QString::fromUtf8("administrateur"));

        formLayout->setWidget(6, QFormLayout::FieldRole, administrateur);


        verticalLayout->addLayout(formLayout);

        boutons = new QDialogButtonBox(DialogAjouterUtilisateur);
        boutons->setObjectName(QString::fromUtf8("boutons"));
        boutons->setOrientation(Qt::Horizontal);
        boutons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(boutons);

        QWidget::setTabOrder(nom, prenom);
        QWidget::setTabOrder(prenom, pass1);
        QWidget::setTabOrder(pass1, pass2);
        QWidget::setTabOrder(pass2, quota);
        QWidget::setTabOrder(quota, responsablePlanning);
        QWidget::setTabOrder(responsablePlanning, administrateur);
        QWidget::setTabOrder(administrateur, boutons);

        retranslateUi(DialogAjouterUtilisateur);
        QObject::connect(boutons, SIGNAL(accepted()), DialogAjouterUtilisateur, SLOT(accept()));
        QObject::connect(boutons, SIGNAL(rejected()), DialogAjouterUtilisateur, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAjouterUtilisateur);
    } // setupUi

    void retranslateUi(QDialog *DialogAjouterUtilisateur)
    {
        DialogAjouterUtilisateur->setWindowTitle(QApplication::translate("DialogAjouterUtilisateur", "Ajouter un utilisateur", 0, QApplication::UnicodeUTF8));
        lbNom->setText(QApplication::translate("DialogAjouterUtilisateur", "Nom", 0, QApplication::UnicodeUTF8));
        lbPrenom->setText(QApplication::translate("DialogAjouterUtilisateur", "Pr\303\251nom", 0, QApplication::UnicodeUTF8));
        lbPass1->setText(QApplication::translate("DialogAjouterUtilisateur", "Mot de passe", 0, QApplication::UnicodeUTF8));
        lbPass2->setText(QApplication::translate("DialogAjouterUtilisateur", "Mot de passe", 0, QApplication::UnicodeUTF8));
        lbQuota->setText(QApplication::translate("DialogAjouterUtilisateur", "Quota", 0, QApplication::UnicodeUTF8));
        quota->setSuffix(QApplication::translate("DialogAjouterUtilisateur", "h", 0, QApplication::UnicodeUTF8));
        responsablePlanning->setText(QApplication::translate("DialogAjouterUtilisateur", "Responsable Planning", 0, QApplication::UnicodeUTF8));
        administrateur->setText(QApplication::translate("DialogAjouterUtilisateur", "Administrateur", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogAjouterUtilisateur: public Ui_DialogAjouterUtilisateur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTERUTILISATEUR_H
