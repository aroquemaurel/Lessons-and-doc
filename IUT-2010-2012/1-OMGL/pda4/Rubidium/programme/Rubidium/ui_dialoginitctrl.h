/********************************************************************************
** Form generated from reading UI file 'dialoginitctrl.ui'
**
** Created: Sat Mar 31 16:04:39 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGINITCTRL_H
#define UI_DIALOGINITCTRL_H

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

class Ui_DialogInitCtrl
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *controles;
    QHBoxLayout *layoutPlusMoin;
    QPushButton *ajouter;
    QPushButton *supprimer;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *boutons;

    void setupUi(QDialog *DialogInitCtrl)
    {
        if (DialogInitCtrl->objectName().isEmpty())
            DialogInitCtrl->setObjectName(QString::fromUtf8("DialogInitCtrl"));
        DialogInitCtrl->resize(845, 365);
        verticalLayout = new QVBoxLayout(DialogInitCtrl);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        controles = new QTableView(DialogInitCtrl);
        controles->setObjectName(QString::fromUtf8("controles"));

        verticalLayout->addWidget(controles);

        layoutPlusMoin = new QHBoxLayout();
        layoutPlusMoin->setObjectName(QString::fromUtf8("layoutPlusMoin"));
        ajouter = new QPushButton(DialogInitCtrl);
        ajouter->setObjectName(QString::fromUtf8("ajouter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icones/ajouter"), QSize(), QIcon::Normal, QIcon::Off);
        ajouter->setIcon(icon);

        layoutPlusMoin->addWidget(ajouter);

        supprimer = new QPushButton(DialogInitCtrl);
        supprimer->setObjectName(QString::fromUtf8("supprimer"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icones/supprimer"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer->setIcon(icon1);

        layoutPlusMoin->addWidget(supprimer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutPlusMoin->addItem(horizontalSpacer);


        verticalLayout->addLayout(layoutPlusMoin);

        boutons = new QDialogButtonBox(DialogInitCtrl);
        boutons->setObjectName(QString::fromUtf8("boutons"));
        boutons->setOrientation(Qt::Horizontal);
        boutons->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(boutons);

        QWidget::setTabOrder(controles, ajouter);
        QWidget::setTabOrder(ajouter, supprimer);
        QWidget::setTabOrder(supprimer, boutons);

        retranslateUi(DialogInitCtrl);
        QObject::connect(ajouter, SIGNAL(pressed()), DialogInitCtrl, SLOT(ajouter()));
        QObject::connect(supprimer, SIGNAL(pressed()), DialogInitCtrl, SLOT(supprimer()));
        QObject::connect(boutons, SIGNAL(clicked(QAbstractButton*)), DialogInitCtrl, SLOT(accept()));

        QMetaObject::connectSlotsByName(DialogInitCtrl);
    } // setupUi

    void retranslateUi(QDialog *DialogInitCtrl)
    {
        DialogInitCtrl->setWindowTitle(QApplication::translate("DialogInitCtrl", "Initialiser les contr\303\264les", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogInitCtrl: public Ui_DialogInitCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGINITCTRL_H
