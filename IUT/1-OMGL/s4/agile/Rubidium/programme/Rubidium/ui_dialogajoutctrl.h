/********************************************************************************
** Form generated from reading UI file 'dialogajoutctrl.ui'
**
** Created: Sat Aug 3 00:47:20 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGAJOUTCTRL_H
#define UI_DIALOGAJOUTCTRL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogAjoutCtrl
{
public:
    QVBoxLayout *verticalLayout_3;
    QGridLayout *layoutNom;
    QLabel *lbNom;
    QLineEdit *nom;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBoxDate;
    QVBoxLayout *verticalLayout_2;
    QCalendarWidget *calendarWidget;
    QFormLayout *formLayout;
    QLabel *lbHeureDebut;
    QTimeEdit *heureDebut;
    QLabel *lbDuree;
    QTimeEdit *duree;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QLabel *lbMatiere;
    QComboBox *matiere;
    QLabel *lbType;
    QComboBox *type;
    QLabel *lbCoeff;
    QDoubleSpinBox *coeff;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBoxSalles;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBoxAutorisations;
    QGridLayout *gridLayout_2;
    QCheckBox *calc;
    QCheckBox *docs;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogAjoutCtrl)
    {
        if (DialogAjoutCtrl->objectName().isEmpty())
            DialogAjoutCtrl->setObjectName(QString::fromUtf8("DialogAjoutCtrl"));
        DialogAjoutCtrl->resize(350, 618);
        verticalLayout_3 = new QVBoxLayout(DialogAjoutCtrl);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        layoutNom = new QGridLayout();
        layoutNom->setObjectName(QString::fromUtf8("layoutNom"));
        lbNom = new QLabel(DialogAjoutCtrl);
        lbNom->setObjectName(QString::fromUtf8("lbNom"));

        layoutNom->addWidget(lbNom, 0, 0, 1, 1);

        nom = new QLineEdit(DialogAjoutCtrl);
        nom->setObjectName(QString::fromUtf8("nom"));

        layoutNom->addWidget(nom, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutNom->addItem(horizontalSpacer, 0, 2, 1, 1);


        verticalLayout_3->addLayout(layoutNom);

        groupBoxDate = new QGroupBox(DialogAjoutCtrl);
        groupBoxDate->setObjectName(QString::fromUtf8("groupBoxDate"));
        verticalLayout_2 = new QVBoxLayout(groupBoxDate);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        calendarWidget = new QCalendarWidget(groupBoxDate);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGridVisible(true);

        verticalLayout_2->addWidget(calendarWidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lbHeureDebut = new QLabel(groupBoxDate);
        lbHeureDebut->setObjectName(QString::fromUtf8("lbHeureDebut"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lbHeureDebut);

        heureDebut = new QTimeEdit(groupBoxDate);
        heureDebut->setObjectName(QString::fromUtf8("heureDebut"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(heureDebut->sizePolicy().hasHeightForWidth());
        heureDebut->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, heureDebut);

        lbDuree = new QLabel(groupBoxDate);
        lbDuree->setObjectName(QString::fromUtf8("lbDuree"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lbDuree);

        duree = new QTimeEdit(groupBoxDate);
        duree->setObjectName(QString::fromUtf8("duree"));
        sizePolicy.setHeightForWidth(duree->sizePolicy().hasHeightForWidth());
        duree->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, duree);


        verticalLayout_2->addLayout(formLayout);


        verticalLayout_3->addWidget(groupBoxDate);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox = new QGroupBox(DialogAjoutCtrl);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        lbMatiere = new QLabel(groupBox);
        lbMatiere->setObjectName(QString::fromUtf8("lbMatiere"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lbMatiere);

        matiere = new QComboBox(groupBox);
        matiere->setObjectName(QString::fromUtf8("matiere"));
        sizePolicy.setHeightForWidth(matiere->sizePolicy().hasHeightForWidth());
        matiere->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, matiere);

        lbType = new QLabel(groupBox);
        lbType->setObjectName(QString::fromUtf8("lbType"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lbType);

        type = new QComboBox(groupBox);
        type->setObjectName(QString::fromUtf8("type"));
        sizePolicy.setHeightForWidth(type->sizePolicy().hasHeightForWidth());
        type->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, type);

        lbCoeff = new QLabel(groupBox);
        lbCoeff->setObjectName(QString::fromUtf8("lbCoeff"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, lbCoeff);

        coeff = new QDoubleSpinBox(groupBox);
        coeff->setObjectName(QString::fromUtf8("coeff"));
        sizePolicy.setHeightForWidth(coeff->sizePolicy().hasHeightForWidth());
        coeff->setSizePolicy(sizePolicy);
        coeff->setDecimals(3);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, coeff);


        horizontalLayout_2->addWidget(groupBox);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBoxSalles = new QGroupBox(DialogAjoutCtrl);
        groupBoxSalles->setObjectName(QString::fromUtf8("groupBoxSalles"));
        verticalLayout = new QVBoxLayout(groupBoxSalles);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        horizontalLayout_3->addWidget(groupBoxSalles);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBoxAutorisations = new QGroupBox(DialogAjoutCtrl);
        groupBoxAutorisations->setObjectName(QString::fromUtf8("groupBoxAutorisations"));
        gridLayout_2 = new QGridLayout(groupBoxAutorisations);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        calc = new QCheckBox(groupBoxAutorisations);
        calc->setObjectName(QString::fromUtf8("calc"));

        gridLayout_2->addWidget(calc, 0, 0, 1, 1);

        docs = new QCheckBox(groupBoxAutorisations);
        docs->setObjectName(QString::fromUtf8("docs"));

        gridLayout_2->addWidget(docs, 1, 0, 1, 1);


        horizontalLayout_4->addWidget(groupBoxAutorisations);


        verticalLayout_3->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(DialogAjoutCtrl);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);

        QWidget::setTabOrder(nom, calendarWidget);
        QWidget::setTabOrder(calendarWidget, heureDebut);
        QWidget::setTabOrder(heureDebut, duree);
        QWidget::setTabOrder(duree, matiere);
        QWidget::setTabOrder(matiere, type);
        QWidget::setTabOrder(type, calc);
        QWidget::setTabOrder(calc, docs);
        QWidget::setTabOrder(docs, buttonBox);

        retranslateUi(DialogAjoutCtrl);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogAjoutCtrl, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogAjoutCtrl, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAjoutCtrl);
    } // setupUi

    void retranslateUi(QDialog *DialogAjoutCtrl)
    {
        DialogAjoutCtrl->setWindowTitle(QApplication::translate("DialogAjoutCtrl", "Ajouter un contr\303\264le", 0, QApplication::UnicodeUTF8));
        lbNom->setText(QApplication::translate("DialogAjoutCtrl", "<b>Nom</b>", 0, QApplication::UnicodeUTF8));
        groupBoxDate->setTitle(QApplication::translate("DialogAjoutCtrl", "Date", 0, QApplication::UnicodeUTF8));
        lbHeureDebut->setText(QApplication::translate("DialogAjoutCtrl", "Heure de d\303\251but", 0, QApplication::UnicodeUTF8));
        lbDuree->setText(QApplication::translate("DialogAjoutCtrl", "Dur\303\251e", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DialogAjoutCtrl", "Informations", 0, QApplication::UnicodeUTF8));
        lbMatiere->setText(QApplication::translate("DialogAjoutCtrl", "Mati\303\250re", 0, QApplication::UnicodeUTF8));
        lbType->setText(QApplication::translate("DialogAjoutCtrl", "Type", 0, QApplication::UnicodeUTF8));
        lbCoeff->setText(QApplication::translate("DialogAjoutCtrl", "Coefficient", 0, QApplication::UnicodeUTF8));
        groupBoxSalles->setTitle(QApplication::translate("DialogAjoutCtrl", "Salles", 0, QApplication::UnicodeUTF8));
        groupBoxAutorisations->setTitle(QApplication::translate("DialogAjoutCtrl", "Autorisations", 0, QApplication::UnicodeUTF8));
        calc->setText(QApplication::translate("DialogAjoutCtrl", "Calculatrice", 0, QApplication::UnicodeUTF8));
        docs->setText(QApplication::translate("DialogAjoutCtrl", "Documents", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogAjoutCtrl: public Ui_DialogAjoutCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGAJOUTCTRL_H
