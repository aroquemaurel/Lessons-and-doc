/********************************************************************************
** Form generated from reading UI file 'dialogajoutertypectrl.ui'
**
** Created: Thu Mar 1 10:58:35 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTERTYPECTRL_H
#define UI_DIALOGAJOUTERTYPECTRL_H

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

class Ui_DialogAjouterTypeCtrl
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lbType;
    QLineEdit *type;
    QDialogButtonBox *boutons;

    void setupUi(QDialog *DialogAjouterTypeCtrl)
    {
        if (DialogAjouterTypeCtrl->objectName().isEmpty())
            DialogAjouterTypeCtrl->setObjectName(QString::fromUtf8("DialogAjouterTypeCtrl"));
        DialogAjouterTypeCtrl->resize(194, 80);
        verticalLayout = new QVBoxLayout(DialogAjouterTypeCtrl);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lbType = new QLabel(DialogAjouterTypeCtrl);
        lbType->setObjectName(QString::fromUtf8("lbType"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lbType);

        type = new QLineEdit(DialogAjouterTypeCtrl);
        type->setObjectName(QString::fromUtf8("type"));

        formLayout->setWidget(0, QFormLayout::FieldRole, type);


        verticalLayout->addLayout(formLayout);

        boutons = new QDialogButtonBox(DialogAjouterTypeCtrl);
        boutons->setObjectName(QString::fromUtf8("boutons"));
        boutons->setOrientation(Qt::Horizontal);
        boutons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(boutons);

        QWidget::setTabOrder(type, boutons);

        retranslateUi(DialogAjouterTypeCtrl);
        QObject::connect(boutons, SIGNAL(accepted()), DialogAjouterTypeCtrl, SLOT(accept()));
        QObject::connect(boutons, SIGNAL(rejected()), DialogAjouterTypeCtrl, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAjouterTypeCtrl);
    } // setupUi

    void retranslateUi(QDialog *DialogAjouterTypeCtrl)
    {
        DialogAjouterTypeCtrl->setWindowTitle(QApplication::translate("DialogAjouterTypeCtrl", "Ajouter un type de contr\303\264le", 0, QApplication::UnicodeUTF8));
        lbType->setText(QApplication::translate("DialogAjouterTypeCtrl", "Type", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogAjouterTypeCtrl: public Ui_DialogAjouterTypeCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTERTYPECTRL_H
