/********************************************************************************
** Form generated from reading UI file 'dialogchangerpass.ui'
**
** Created: Sat Mar 31 16:04:39 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHANGERPASS_H
#define UI_DIALOGCHANGERPASS_H

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
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogChangerPass
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lbAncienPass;
    QLineEdit *ancienPass;
    QLabel *lbNouveauPass1;
    QLineEdit *nouveauPass1;
    QLabel *lbNouveauPass2;
    QLineEdit *nouveauPass2;
    QDialogButtonBox *boutons;

    void setupUi(QDialog *DialogChangerPass)
    {
        if (DialogChangerPass->objectName().isEmpty())
            DialogChangerPass->setObjectName(QString::fromUtf8("DialogChangerPass"));
        DialogChangerPass->resize(325, 146);
        verticalLayout = new QVBoxLayout(DialogChangerPass);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lbAncienPass = new QLabel(DialogChangerPass);
        lbAncienPass->setObjectName(QString::fromUtf8("lbAncienPass"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lbAncienPass);

        ancienPass = new QLineEdit(DialogChangerPass);
        ancienPass->setObjectName(QString::fromUtf8("ancienPass"));
        ancienPass->setMinimumSize(QSize(150, 0));
        ancienPass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(0, QFormLayout::FieldRole, ancienPass);

        lbNouveauPass1 = new QLabel(DialogChangerPass);
        lbNouveauPass1->setObjectName(QString::fromUtf8("lbNouveauPass1"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lbNouveauPass1);

        nouveauPass1 = new QLineEdit(DialogChangerPass);
        nouveauPass1->setObjectName(QString::fromUtf8("nouveauPass1"));
        nouveauPass1->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, nouveauPass1);

        lbNouveauPass2 = new QLabel(DialogChangerPass);
        lbNouveauPass2->setObjectName(QString::fromUtf8("lbNouveauPass2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lbNouveauPass2);

        nouveauPass2 = new QLineEdit(DialogChangerPass);
        nouveauPass2->setObjectName(QString::fromUtf8("nouveauPass2"));
        nouveauPass2->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, nouveauPass2);


        verticalLayout->addLayout(formLayout);

        boutons = new QDialogButtonBox(DialogChangerPass);
        boutons->setObjectName(QString::fromUtf8("boutons"));
        boutons->setOrientation(Qt::Horizontal);
        boutons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(boutons);

        QWidget::setTabOrder(ancienPass, nouveauPass1);
        QWidget::setTabOrder(nouveauPass1, nouveauPass2);
        QWidget::setTabOrder(nouveauPass2, boutons);

        retranslateUi(DialogChangerPass);
        QObject::connect(boutons, SIGNAL(accepted()), DialogChangerPass, SLOT(accept()));
        QObject::connect(boutons, SIGNAL(rejected()), DialogChangerPass, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogChangerPass);
    } // setupUi

    void retranslateUi(QDialog *DialogChangerPass)
    {
        DialogChangerPass->setWindowTitle(QApplication::translate("DialogChangerPass", "Changer le mot de passe", 0, QApplication::UnicodeUTF8));
        lbAncienPass->setText(QApplication::translate("DialogChangerPass", "Ancien mot de passe", 0, QApplication::UnicodeUTF8));
        lbNouveauPass1->setText(QApplication::translate("DialogChangerPass", "Nouveau mot de passe", 0, QApplication::UnicodeUTF8));
        lbNouveauPass2->setText(QApplication::translate("DialogChangerPass", "Nouveau mot de passe", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogChangerPass: public Ui_DialogChangerPass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHANGERPASS_H
