/********************************************************************************
** Form generated from reading UI file 'dockprofil.ui'
**
** Created: Sat Aug 3 00:47:19 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCKPROFIL_H
#define UI_DOCKPROFIL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DockProfil
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *layoutNom;
    QLabel *nom;
    QSpacerItem *spacerNom;
    QHBoxLayout *layoutGeneral;
    QVBoxLayout *layoutGrouBoxes;
    QGroupBox *roles;
    QVBoxLayout *verticalLayout_2;
    QLabel *admin;
    QLabel *planning;
    QGroupBox *matieres;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *quotas;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *layoutQuotas;
    QLabel *labelAEffectuer;
    QLabel *aEff;
    QLabel *labelEffectuees;
    QLabel *eff;
    QLabel *labelProgrammees;
    QLabel *prog;
    QFrame *line;
    QLabel *labelRestantes;
    QLabel *restantes;
    QSpacerItem *spacerDock;
    QFrame *line_2;
    QPushButton *boutonMotDePasse;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DockProfil)
    {
        if (DockProfil->objectName().isEmpty())
            DockProfil->setObjectName(QString::fromUtf8("DockProfil"));
        DockProfil->resize(246, 404);
        verticalLayout_3 = new QVBoxLayout(DockProfil);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        layoutNom = new QHBoxLayout();
        layoutNom->setObjectName(QString::fromUtf8("layoutNom"));
        nom = new QLabel(DockProfil);
        nom->setObjectName(QString::fromUtf8("nom"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nom->sizePolicy().hasHeightForWidth());
        nom->setSizePolicy(sizePolicy);

        layoutNom->addWidget(nom);

        spacerNom = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutNom->addItem(spacerNom);


        verticalLayout_3->addLayout(layoutNom);

        layoutGeneral = new QHBoxLayout();
        layoutGeneral->setObjectName(QString::fromUtf8("layoutGeneral"));
        layoutGrouBoxes = new QVBoxLayout();
        layoutGrouBoxes->setObjectName(QString::fromUtf8("layoutGrouBoxes"));
        roles = new QGroupBox(DockProfil);
        roles->setObjectName(QString::fromUtf8("roles"));
        verticalLayout_2 = new QVBoxLayout(roles);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        admin = new QLabel(roles);
        admin->setObjectName(QString::fromUtf8("admin"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(118, 118, 117, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        admin->setPalette(palette);

        verticalLayout_2->addWidget(admin);

        planning = new QLabel(roles);
        planning->setObjectName(QString::fromUtf8("planning"));

        verticalLayout_2->addWidget(planning);


        layoutGrouBoxes->addWidget(roles);

        matieres = new QGroupBox(DockProfil);
        matieres->setObjectName(QString::fromUtf8("matieres"));
        verticalLayout_4 = new QVBoxLayout(matieres);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));

        layoutGrouBoxes->addWidget(matieres);

        quotas = new QGroupBox(DockProfil);
        quotas->setObjectName(QString::fromUtf8("quotas"));
        verticalLayout_5 = new QVBoxLayout(quotas);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        layoutQuotas = new QFormLayout();
        layoutQuotas->setObjectName(QString::fromUtf8("layoutQuotas"));
        labelAEffectuer = new QLabel(quotas);
        labelAEffectuer->setObjectName(QString::fromUtf8("labelAEffectuer"));

        layoutQuotas->setWidget(0, QFormLayout::LabelRole, labelAEffectuer);

        aEff = new QLabel(quotas);
        aEff->setObjectName(QString::fromUtf8("aEff"));

        layoutQuotas->setWidget(0, QFormLayout::FieldRole, aEff);

        labelEffectuees = new QLabel(quotas);
        labelEffectuees->setObjectName(QString::fromUtf8("labelEffectuees"));

        layoutQuotas->setWidget(1, QFormLayout::LabelRole, labelEffectuees);

        eff = new QLabel(quotas);
        eff->setObjectName(QString::fromUtf8("eff"));

        layoutQuotas->setWidget(1, QFormLayout::FieldRole, eff);

        labelProgrammees = new QLabel(quotas);
        labelProgrammees->setObjectName(QString::fromUtf8("labelProgrammees"));

        layoutQuotas->setWidget(2, QFormLayout::LabelRole, labelProgrammees);

        prog = new QLabel(quotas);
        prog->setObjectName(QString::fromUtf8("prog"));

        layoutQuotas->setWidget(2, QFormLayout::FieldRole, prog);

        line = new QFrame(quotas);
        line->setObjectName(QString::fromUtf8("line"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setMinimumSize(QSize(25, 0));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        layoutQuotas->setWidget(3, QFormLayout::FieldRole, line);

        labelRestantes = new QLabel(quotas);
        labelRestantes->setObjectName(QString::fromUtf8("labelRestantes"));

        layoutQuotas->setWidget(4, QFormLayout::LabelRole, labelRestantes);

        restantes = new QLabel(quotas);
        restantes->setObjectName(QString::fromUtf8("restantes"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        restantes->setPalette(palette1);

        layoutQuotas->setWidget(4, QFormLayout::FieldRole, restantes);


        verticalLayout_5->addLayout(layoutQuotas);


        layoutGrouBoxes->addWidget(quotas);


        layoutGeneral->addLayout(layoutGrouBoxes);

        spacerDock = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layoutGeneral->addItem(spacerDock);


        verticalLayout_3->addLayout(layoutGeneral);

        line_2 = new QFrame(DockProfil);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        boutonMotDePasse = new QPushButton(DockProfil);
        boutonMotDePasse->setObjectName(QString::fromUtf8("boutonMotDePasse"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(boutonMotDePasse->sizePolicy().hasHeightForWidth());
        boutonMotDePasse->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(boutonMotDePasse);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(DockProfil);

        QMetaObject::connectSlotsByName(DockProfil);
    } // setupUi

    void retranslateUi(QWidget *DockProfil)
    {
        DockProfil->setWindowTitle(QApplication::translate("DockProfil", "Profil", 0, QApplication::UnicodeUTF8));
        nom->setText(QString());
        roles->setTitle(QApplication::translate("DockProfil", "Roles", 0, QApplication::UnicodeUTF8));
        admin->setText(QApplication::translate("DockProfil", "Administrateur", 0, QApplication::UnicodeUTF8));
        planning->setText(QApplication::translate("DockProfil", "Responsable des plannings", 0, QApplication::UnicodeUTF8));
        matieres->setTitle(QApplication::translate("DockProfil", "Mati\303\250res", 0, QApplication::UnicodeUTF8));
        quotas->setTitle(QApplication::translate("DockProfil", "Quotas", 0, QApplication::UnicodeUTF8));
        labelAEffectuer->setText(QApplication::translate("DockProfil", "\303\200 effectuer", 0, QApplication::UnicodeUTF8));
        aEff->setText(QString());
        labelEffectuees->setText(QApplication::translate("DockProfil", "Effectu\303\251es", 0, QApplication::UnicodeUTF8));
        eff->setText(QString());
        labelProgrammees->setText(QApplication::translate("DockProfil", "Programm\303\251es", 0, QApplication::UnicodeUTF8));
        prog->setText(QString());
        labelRestantes->setText(QApplication::translate("DockProfil", "Restantes", 0, QApplication::UnicodeUTF8));
        restantes->setText(QString());
        boutonMotDePasse->setText(QApplication::translate("DockProfil", "Changer le mot de passe...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DockProfil: public Ui_DockProfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCKPROFIL_H
