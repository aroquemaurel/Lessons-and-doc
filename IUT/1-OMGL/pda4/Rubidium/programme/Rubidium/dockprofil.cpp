#include "dockprofil.h"
#include "ui_dockprofil.h"

#include "bdd.h"

DockProfil::DockProfil(const Personne& pPersonne,
                       QWidget *parent)
    : QWidget(parent) {
    int nbMinutesRestantes = 0;

    setupUi(this);
    boutonMotDePasse->setVisible(false);
    nom->setText("<b>" +
                 pPersonne.getPrenom() +
                 " " +
                 pPersonne.getNom() +
                 "</b>");

    if(pPersonne.estAdministrateur()) {
        admin->show();
    }
    else {
        admin->hide();
    }

    if(pPersonne.estReponsablePlanning()) {
        planning->show();
    }
    else {
        planning->hide();
    }

    QStringListIterator i(Bdd::getInstance()->getResponsableMatieres(pPersonne));
    while(i.hasNext()) {
        QLabel* matiere = new QLabel("Responsable de " + i.next());
        roles->layout()->addWidget(matiere);
    }

    QStringListIterator ii(Bdd::getInstance()->getMatieres(pPersonne));
    while(ii.hasNext()) {
        QLabel* matiere = new QLabel(ii.next());
        matieres->layout()->addWidget(matiere);
    }

    // QUOTAS
    aEff->setText(pPersonne.getQuota().toString("h'h'mm"));
    eff->setText(pPersonne.getNbHeuresEffectuees().toString("h'h'mm"));
    prog->setText(pPersonne.getNbHeuresProgrammes().toString("h'h'mm"));
    prog->hide();
    labelProgrammees->hide();

    nbMinutesRestantes = pPersonne.getQuota().hour() * 60 +
                         pPersonne.getQuota().minute() -
                         pPersonne.getNbHeuresEffectuees().hour() * 60 +
                         pPersonne.getNbHeuresEffectuees().minute();
    restantes->setText("<b>"+ QTime(nbMinutesRestantes/60, nbMinutesRestantes%60).toString("h'h'mm")
                       +"</b>");

}

DockProfil::~DockProfil() {
}
