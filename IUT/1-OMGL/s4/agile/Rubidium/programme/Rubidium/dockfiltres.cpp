#include "dockfiltres.h"

#include "bdd.h"

DockFiltres::DockFiltres(FenetrePrincipale* f,
                         QWidget *parent) :
    QWidget(parent) {
    setupUi(this);

    mFenetre = f;

    QStringListIterator i(Bdd::getInstance()->getListeMatieres());
    while(i.hasNext()) {
        QString nomMatiere = i.next();

        QCheckBox* checkBoxMatiere = new QCheckBox(nomMatiere);
        checkBoxMatiere->setObjectName(nomMatiere);
        connect(checkBoxMatiere, SIGNAL(toggled(bool)),
                this, SLOT(matiereSelectionne(bool)));
        matiere->layout()->addWidget(checkBoxMatiere);
    }
    maj();
}

void DockFiltres::semestreSelectionne(bool activer) {
    QStringList filtreAncien;
    QStringList filtre;

    QListIterator<QCheckBox*> i(semestre->findChildren<QCheckBox*>());
    while(i.hasNext()) {
        QCheckBox* sem = i.next();
        QString nom = sem->objectName().remove("s");

        if(sem->isChecked()) {
            filtre << QString("Semestre_M='"+nom+"'");
            if(sem->objectName() != sender()->objectName()) {
                filtreAncien << QString("Semestre_M='"+nom+"'");
            }
        }
        if(!sem->isChecked() && sem->objectName() == sender()->objectName()) {
            filtreAncien << QString("Semestre_M='"+nom+"'");
        }
    }

    QString strFiltre ="AND(";

    for(int i=0; i < filtre.size(); ++i) {
        if(i !=0) {
            strFiltre += " OR ";
        }
        strFiltre += filtre.at(i);
    }
    strFiltre += ") ";

    QString strFiltreAncien ="AND(";
    for(int i=0; i< filtreAncien.size(); ++i) {
        if(i !=0) {
            strFiltreAncien += " OR ";
        }
        strFiltreAncien += filtreAncien.at(i);
    }
    strFiltreAncien += ") ";

    changerFiltre(strFiltreAncien, strFiltre);

}

void DockFiltres::matiereSelectionne(bool activer) {
    QStringList filtreAncien;
    QStringList filtre;

    QListIterator<QCheckBox*> i(matiere->findChildren<QCheckBox*>());
    while(i.hasNext()) {
        QCheckBox* matiere = i.next();
        QStringList nomTemp = matiere->objectName().split(" ");
        QString nom;
        for(int i=0; i<nomTemp.size()-1; ++i) {
            nom += nomTemp.at(i);
            nom += " ";
        }
        nom.resize(nom.size()-1);
        if(matiere->isChecked()) {
            filtre << QString("Nom_M='"+nom+"'");
            if(matiere->objectName() != sender()->objectName()) {
                filtreAncien << QString("Nom_M='"+nom+"'");
            }
        }
        if(!matiere->isChecked() && matiere->objectName() == sender()->objectName()) {
            filtreAncien << QString("Nom_M='"+nom+"'");
        }
    }

    QString strFiltre ="AND(";

    for(int i=0; i < filtre.size(); ++i) {
        if(i !=0) {
            strFiltre += " OR ";
        }
        strFiltre += filtre.at(i);
    }
    strFiltre += ") ";

    QString strFiltreAncien ="AND(";
    for(int i=0; i< filtreAncien.size(); ++i) {
        if(i !=0) {
            strFiltreAncien += " OR ";
        }
        strFiltreAncien += filtreAncien.at(i);
    }
    strFiltreAncien += ") ";


    changerFiltre(strFiltreAncien, strFiltre);

}

void DockFiltres::surveillanceSelectionne(bool activer) {
    QString requete = " AND ID_C in (select ID_C "
            "from surveiller, Personne "
            "where Surveiller.id_P = (select Id_P from Personne where upper(Nom_P) = upper('"+mFenetre->getUtilisateur()->getNom()+"')))";


    filtrer(requete,
            controleSurveilles->isChecked());
}

void DockFiltres::voirMesMatieresSelectionne(bool activer) {
    QString requete = "AND enseigner.id_p = (select Id_P from Personne where upper(Nom_P) = upper('"+mFenetre->getUtilisateur()->getNom()+"')) ";


    filtrer(requete,
            voirMesMatieres->isChecked());
}
void DockFiltres::voirMatieresResponsableSelectionne(bool activer) {
    QString requete = "AND enseigner.id_p = "
                "(select Id_P from Personne where upper(Nom_P) = upper('"+mFenetre->getUtilisateur()->getNom()+"'))"
            "AND enseigner.responsable_matiere = 'True'";


    filtrer(requete,
            voirMatiereResponsable->isChecked());
}

void DockFiltres::changerFiltre(QString pAncien, QString pNouveau) {
    filtrer(pAncien, false);
    filtrer(pNouveau, true);
}

void DockFiltres::filtrer(QString pFiltre, bool activer) {
    pFiltre.remove("AND() ");
    if(activer) {
        Bdd::getInstance()->setFiltre(QString(Bdd::getInstance()->getFiltre() + " " + pFiltre));
    }
    else {
        QString filtreActuel = Bdd::getInstance()->getFiltre();
        filtreActuel.remove(pFiltre);
        Bdd::getInstance()->setFiltre(filtreActuel);
    }

    emit nouveauFiltre();
}

void DockFiltres::maj(void) {
    controleSurveilles->setVisible(mFenetre->getUtilisateur() != NULL);
    voirMesMatieres->setVisible(mFenetre->getUtilisateur() != NULL);
    voirMatiereResponsable->setVisible(mFenetre->getUtilisateur() != NULL);
}
