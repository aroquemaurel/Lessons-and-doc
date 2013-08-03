/********************************************************************************
** Form generated from reading UI file 'dialogconnexion.ui'
**
** Created: Sat Aug 3 00:47:19 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONNEXION_H
#define UI_DIALOGCONNEXION_H

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

QT_BEGIN_NAMESPACE

class Ui_DialogConnexion
{
public:
    QFormLayout *formLayout;
    QLabel *labelLogin;
    QLineEdit *login;
    QLabel *labelPass;
    QLineEdit *pass;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogConnexion)
    {
        if (DialogConnexion->objectName().isEmpty())
            DialogConnexion->setObjectName(QString::fromUtf8("DialogConnexion"));
        DialogConnexion->resize(239, 111);
        formLayout = new QFormLayout(DialogConnexion);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelLogin = new QLabel(DialogConnexion);
        labelLogin->setObjectName(QString::fromUtf8("labelLogin"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelLogin);

        login = new QLineEdit(DialogConnexion);
        login->setObjectName(QString::fromUtf8("login"));

        formLayout->setWidget(0, QFormLayout::FieldRole, login);

        labelPass = new QLabel(DialogConnexion);
        labelPass->setObjectName(QString::fromUtf8("labelPass"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPass);

        pass = new QLineEdit(DialogConnexion);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, pass);

        buttonBox = new QDialogButtonBox(DialogConnexion);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(2, QFormLayout::SpanningRole, buttonBox);

        QWidget::setTabOrder(login, pass);
        QWidget::setTabOrder(pass, buttonBox);

        retranslateUi(DialogConnexion);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogConnexion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogConnexion, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogConnexion);
    } // setupUi

    void retranslateUi(QDialog *DialogConnexion)
    {
        DialogConnexion->setWindowTitle(QApplication::translate("DialogConnexion", "Connexion...", 0, QApplication::UnicodeUTF8));
        labelLogin->setText(QApplication::translate("DialogConnexion", "Login", 0, QApplication::UnicodeUTF8));
        login->setText(QString());
        labelPass->setText(QApplication::translate("DialogConnexion", "Mot de passe", 0, QApplication::UnicodeUTF8));
        pass->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogConnexion: public Ui_DialogConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONNEXION_H
