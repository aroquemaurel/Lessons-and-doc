#include "dockprofil.h"
#include "ui_dockprofil.h"

#include "bdd.h"

DockProfil::DockProfil(const Personne& pInfos, QWidget *parent)
    : QWidget(parent) {
    setupUi(this);

    nom->setText("<b>" +
                 pInfos.getPrenom() +
                 " " +
                 pInfos.getNom() +
                 "</b>");

    if(pInfos.estAdministrateur()) {
        admin->show();
    }
    else {
        admin->hide();
    }

    if(pInfos.estReponsablePlanning()) {
        planning->show();
    }
    else {
        planning->hide();
    }

    QStringListIterator i(Bdd::getInstance()->getResponsableMatieres(pInfos));
    while(i.hasNext()) {
        QLabel* matiere = new QLabel("Responsable de " + i.next());
        roles->layout()->addWidget(matiere);
    }

    QStringListIterator ii(Bdd::getInstance()->getMatieres(pInfos));
    while(ii.hasNext()) {
        QLabel* matiere = new QLabel(ii.next());
        matieres->layout()->addWidget(matiere);
    }

    // QUOTAS
    aEff->setText(QVariant(pInfos.getQuota()).toString());
    eff->setText(QVariant(pInfos.getNbHeuresEffectuees()).toString());
    prog->setText("TODO");
    restantes->setText(QVariant(pInfos.getQuota() - pInfos.getNbHeuresEffectuees()).toString());
}
