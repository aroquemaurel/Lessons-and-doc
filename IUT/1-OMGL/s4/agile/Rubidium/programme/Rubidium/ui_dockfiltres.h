/********************************************************************************
** Form generated from reading UI file 'dockfiltres.ui'
**
** Created: Sat Aug 3 00:47:19 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCKFILTRES_H
#define UI_DOCKFILTRES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DockFiltres
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *matiere;
    QVBoxLayout *verticalLayout;
    QGroupBox *semestre;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *s1;
    QCheckBox *s2;
    QCheckBox *s3;
    QCheckBox *s4;
    QCheckBox *controleSurveilles;
    QCheckBox *voirMesMatieres;
    QCheckBox *voirMatiereResponsable;
    QSpacerItem *spacerBas;

    void setupUi(QWidget *DockFiltres)
    {
        if (DockFiltres->objectName().isEmpty())
            DockFiltres->setObjectName(QString::fromUtf8("DockFiltres"));
        DockFiltres->resize(246, 278);
        verticalLayout_3 = new QVBoxLayout(DockFiltres);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        matiere = new QGroupBox(DockFiltres);
        matiere->setObjectName(QString::fromUtf8("matiere"));
        verticalLayout = new QVBoxLayout(matiere);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        verticalLayout_3->addWidget(matiere);

        semestre = new QGroupBox(DockFiltres);
        semestre->setObjectName(QString::fromUtf8("semestre"));
        verticalLayout_2 = new QVBoxLayout(semestre);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        s1 = new QCheckBox(semestre);
        s1->setObjectName(QString::fromUtf8("s1"));

        verticalLayout_2->addWidget(s1);

        s2 = new QCheckBox(semestre);
        s2->setObjectName(QString::fromUtf8("s2"));

        verticalLayout_2->addWidget(s2);

        s3 = new QCheckBox(semestre);
        s3->setObjectName(QString::fromUtf8("s3"));

        verticalLayout_2->addWidget(s3);

        s4 = new QCheckBox(semestre);
        s4->setObjectName(QString::fromUtf8("s4"));

        verticalLayout_2->addWidget(s4);


        verticalLayout_3->addWidget(semestre);

        controleSurveilles = new QCheckBox(DockFiltres);
        controleSurveilles->setObjectName(QString::fromUtf8("controleSurveilles"));

        verticalLayout_3->addWidget(controleSurveilles);

        voirMesMatieres = new QCheckBox(DockFiltres);
        voirMesMatieres->setObjectName(QString::fromUtf8("voirMesMatieres"));

        verticalLayout_3->addWidget(voirMesMatieres);

        voirMatiereResponsable = new QCheckBox(DockFiltres);
        voirMatiereResponsable->setObjectName(QString::fromUtf8("voirMatiereResponsable"));

        verticalLayout_3->addWidget(voirMatiereResponsable);

        spacerBas = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(spacerBas);

        QWidget::setTabOrder(matiere, semestre);
        QWidget::setTabOrder(semestre, s1);
        QWidget::setTabOrder(s1, s2);
        QWidget::setTabOrder(s2, s3);
        QWidget::setTabOrder(s3, s4);
        QWidget::setTabOrder(s4, controleSurveilles);

        retranslateUi(DockFiltres);
        QObject::connect(s1, SIGNAL(toggled(bool)), DockFiltres, SLOT(semestreSelectionne(bool)));
        QObject::connect(s2, SIGNAL(toggled(bool)), DockFiltres, SLOT(semestreSelectionne(bool)));
        QObject::connect(s3, SIGNAL(toggled(bool)), DockFiltres, SLOT(semestreSelectionne(bool)));
        QObject::connect(s4, SIGNAL(toggled(bool)), DockFiltres, SLOT(semestreSelectionne(bool)));
        QObject::connect(controleSurveilles, SIGNAL(toggled(bool)), DockFiltres, SLOT(surveillanceSelectionne(bool)));
        QObject::connect(voirMesMatieres, SIGNAL(toggled(bool)), DockFiltres, SLOT(voirMesMatieresSelectionne(bool)));
        QObject::connect(voirMatiereResponsable, SIGNAL(toggled(bool)), DockFiltres, SLOT(voirMatieresResponsableSelectionne(bool)));

        QMetaObject::connectSlotsByName(DockFiltres);
    } // setupUi

    void retranslateUi(QWidget *DockFiltres)
    {
        DockFiltres->setWindowTitle(QApplication::translate("DockFiltres", "Filtres", 0, QApplication::UnicodeUTF8));
        matiere->setTitle(QApplication::translate("DockFiltres", "Mati\303\250re", 0, QApplication::UnicodeUTF8));
        semestre->setTitle(QApplication::translate("DockFiltres", "Semestre", 0, QApplication::UnicodeUTF8));
        s1->setText(QApplication::translate("DockFiltres", "S1", 0, QApplication::UnicodeUTF8));
        s2->setText(QApplication::translate("DockFiltres", "S2", 0, QApplication::UnicodeUTF8));
        s3->setText(QApplication::translate("DockFiltres", "S3", 0, QApplication::UnicodeUTF8));
        s4->setText(QApplication::translate("DockFiltres", "S4", 0, QApplication::UnicodeUTF8));
        controleSurveilles->setText(QApplication::translate("DockFiltres", "Les contr\303\264les que je surveille", 0, QApplication::UnicodeUTF8));
        voirMesMatieres->setText(QApplication::translate("DockFiltres", "Mes mati\303\250res", 0, QApplication::UnicodeUTF8));
        voirMatiereResponsable->setText(QApplication::translate("DockFiltres", "Mati\303\250res ou je suis responsable", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DockFiltres: public Ui_DockFiltres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCKFILTRES_H
