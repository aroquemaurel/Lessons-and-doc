#include "bdd.h"

#include <QStandardItem>
#include <QDate>

// SINGLETON
Bdd* Bdd::mInstance = 0;

Bdd* Bdd::getInstance() {
    if (mInstance==0) {
        mInstance = new Bdd();
    }
    return mInstance;
}

void Bdd::detruire() {
    delete mInstance;
}

//*/

Bdd::Bdd() {
    bool creerStructure = false;

    mBdd = QSqlDatabase::addDatabase("QSQLITE");
    mFiltre = " ";

    if(!QFile::exists("./Rubidium.db")) {
        creerStructure = true;
    }

    mBdd.setDatabaseName("./Rubidium.db");

    if(!mBdd.open()) {
        throw std::exception();
    }

    if(creerStructure) {
        creerBdd();
    }
}

Bdd::~Bdd() {
    mBdd.close();
}

void Bdd::jeuDEssai() {
    executerFichier("./jeuDEssai.sql");
}

void Bdd::viderBdd() {
    executerFichier("./viderBdd.sql");
}

bool Bdd::validerPersonne(QString pLogin, QString pMotDePasse) {
    QSqlQuery q;

    // login "Max.Chevalier" => ["Max, "Chevalier"]
    QStringList nom = pLogin.split(".");

    q.prepare("SELECT * FROM PERSONNE "
              "WHERE upper(Nom_P)=:nom"
              "  AND upper(Prenom_P)=:prenom "
              "  AND MDP_P=:mdp");

    q.bindValue(":nom", nom.last().toUpper());
    q.bindValue(":prenom", nom.first().toUpper());
    q.bindValue(":mdp", pMotDePasse);

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    while(q.next()) {
        return true;
    }
    return false;
}

Personne* Bdd::getPersonne(QString pLogin) {
    Personne* retour = new Personne();
    QSqlQuery q, qHeuresEffectues;
    int nbMinutesProgrammes = 0;

    // login "Max.Chevalier" => ["Max, "Chevalier"]
    QStringList nom = pLogin.split(".");

    q.prepare("SELECT * FROM PERSONNE "
              "WHERE upper(Nom_P)=:nom"
              "  AND upper(Prenom_P)=:prenom");

    q.bindValue(":nom", nom.last().toUpper());
    q.bindValue(":prenom", nom.first().toUpper());
    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }


    while(q.next()) {
        qHeuresEffectues.prepare("SELECT * FROM SURVEILLER, CONTROLE "
                                 "WHERE id_P=:id "
                                 "     AND controle.id_C=surveiller.id_C "
                                 "AND Date_C<date('now')"
                                 );


        qHeuresEffectues.bindValue(":id", valeur(q, "id_P"));
        if(!qHeuresEffectues.exec()) {
            qDebug() << derniereErreur(qHeuresEffectues);
            throw std::exception();
        }
        while(qHeuresEffectues.next()){
            nbMinutesProgrammes += valeur(qHeuresEffectues, "Duree_C").toInt();
        }
        retour->setNom(valeur(q, "Nom_P").toString());
        retour->setPrenom(valeur(q, "Prenom_P").toString());
        retour->setMdp(valeur(q, "MDP_P").toString());
        retour->setNbHeuresEffectuees(v2time(valeur(q, "Heures_effectues_P")));
        retour->setQuota(v2time(valeur(q, "Quota_P")));
        retour->setNbHeuresProgrammes(v2time(nbMinutesProgrammes));
        retour->setAdministrateur(v2b(valeur(q, "Administrateur_P")));
        retour->setResponsable(v2b(valeur(q, "Responsable_Planning_P")));
    }
    return retour;
}

void Bdd::ajouterPersonne(const Personne& pPersonne) {
    QSqlQuery q;

    q.prepare("insert into PERSONNE "
              "(Nom_P, Prenom_P, MDP_P, "
              "Quota_P, Responsable_Planning_P, "
              "Administrateur_P, Heures_Effectuees_P) "
              "values (:nom, :prenom, "
              ":mdp, :quota, :respPlanning, "
              ":admin, 0)");

    q.bindValue(":nom", pPersonne.getNom());
    q.bindValue(":prenom", pPersonne.getPrenom());
    q.bindValue(":mdp", pPersonne.getMdp());
    q.bindValue(":quota", pPersonne.getQuota());
    q.bindValue(":respPlanning", b2s(pPersonne.estReponsablePlanning()));
    q.bindValue(":admin", b2s(pPersonne.estAdministrateur()));

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }
}

void Bdd::editerPersonne(QString pLogin, const Personne& pPersonne) {
    QSqlQuery q;

    QStringList nom = pLogin.split(".");

    q.prepare("UPDATE PERSONNE "
              "SET Nom_P = :nom, Prenom_P = :prenom, MDP_P = :mdp, "
              "  Quota_P = :quota, Responsable_Planning_P = :respPlanning, "
              "  Administrateur_P = :admin, Heures_Effectuees_P = :heuresEffectuees) "
              "WHERE upper(Nom_P)=:nomA "
              "  AND upper (Prenom_P)=:prenomA;" );

    q.bindValue(":nomA", nom.last().toUpper());
    q.bindValue(":prenomA", nom.first().toUpper());

    q.bindValue(":nom", pPersonne.getNom());
    q.bindValue(":prenom", pPersonne.getPrenom());
    q.bindValue(":mdp", pPersonne.getMdp());
    q.bindValue(":quota", pPersonne.getQuota());
    q.bindValue(":respPlanning", b2s(pPersonne.estReponsablePlanning()));
    q.bindValue(":admin", b2s(pPersonne.estAdministrateur()));
    q.bindValue(":heuresEffectuees", pPersonne.getNbHeuresEffectuees());

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }
}

void Bdd::supprimerPersonne(QString pLogin) {
    QSqlQuery q;

    QStringList nom = pLogin.split(".");

    q.prepare("DELETE FROM PERSONNE "
              "WHERE upper(Nom_P)=:nom "
              "AND upper (Prenom_P)=:prenom;" );

    q.bindValue(":nom", nom.last().toUpper());
    q.bindValue(":prenom", nom.first().toUpper());

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }
}

void Bdd::surveiller(const Personne& pPersonne,
                     const Controle& pControle,
                     bool pValeur) {
    QSqlQuery q;

    if(pValeur) {
        q.prepare("insert into surveiller(id_p, id_c) "
                  "values ((select id_p from personne where nom_p=:nom and prenom_p=:prenom), "
                  "        (select id_c from controle where date_c=:date and heure_c=:heure and id_m=:idMatiere))");
    }
    else {
        q.prepare("delete from surveiller "
                  "where id_p=(select id_p from personne where nom_p=:nom and prenom_p=:prenom) "
                  "  and id_c=(select id_c from controle where date_c=:date and heure_c=:heure and id_m=:idMatiere)");
    }
    q.bindValue(":nom", pPersonne.getNom());
    q.bindValue(":prenom", pPersonne.getPrenom());
    q.bindValue(":date", pControle.getDate().toString("yyyy-MM-dd"));
    q.bindValue(":heure", pControle.getHeure().toString("hh':'mm"));
    q.bindValue(":idMatiere", pControle.getIdMatiere());

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }
}

QStringList Bdd::getResponsableMatieres(const Personne& pPersonne) {
    QStringList retour;
    QSqlQuery q;

    q.prepare("SELECT Nom_M, Semestre_M "
              "FROM PERSONNE, ENSEIGNER, MATIERE "
              "WHERE PERSONNE.Id_P = ENSEIGNER.Id_P "
              "  AND ENSEIGNER.Id_M = MATIERE.Id_M "
              "  AND upper(Nom_P)=:nom "
              "  AND upper(Prenom_P)=:prenom "
              "  AND Responsable_Matiere = 'True' ");

    q.bindValue(":nom", pPersonne.getNom().toUpper());
    q.bindValue(":prenom", pPersonne.getPrenom().toUpper());
    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    while(q.next()) {
        retour << QString(valeur(q, "Nom_M").toString() + " " + valeur(q, "Semestre_M").toString());
    }

    return retour;
}

QStringList Bdd::getMatieres(const Personne& pPersonne) {
    QStringList retour;
    QSqlQuery q;

    q.prepare("SELECT Nom_M, Semestre_M "
              "FROM PERSONNE, ENSEIGNER, MATIERE "
              "WHERE PERSONNE.Id_P = ENSEIGNER.Id_P"
              "  AND ENSEIGNER.Id_M = MATIERE.Id_M"
              "  AND upper(Nom_P)=:nom"
              "  AND upper(Prenom_P)=:prenom");

    q.bindValue(":nom", pPersonne.getNom().toUpper());
    q.bindValue(":prenom", pPersonne.getPrenom().toUpper());
    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    while(q.next()) {
        retour << QString(valeur(q, "Nom_M").toString() + " " + valeur(q, "Semestre_M").toString());
    }

    return retour;
}

QStandardItemModel* Bdd::getTableauControles(const Personne& pPersonne) {
    QStandardItemModel* retour = new QStandardItemModel();
    QList<int> controlesSurveilles;
    QStringList controlesResponsable;

    if(&pPersonne != NULL) {
        retour->setColumnCount(10);
        retour->setHorizontalHeaderLabels(
                    QStringList()
                    << qApp->tr("Date")
                    << qApp->tr("Matière")
                    << qApp->tr("Type")
                    << qApp->tr("Heure")
                    << qApp->tr("Durée")
                    << qApp->tr("Coefficient")
                    << qApp->tr("Calculatrice")
                    << qApp->tr("Documents")
                    << qApp->tr("Surveiller")
                    << qApp->tr("Modifier")
                    );
    }
    else {
        retour->setColumnCount(8);
        retour->setHorizontalHeaderLabels(
                    QStringList()
                    << qApp->tr("Date")
                    << qApp->tr("Matière")
                    << qApp->tr("Type")
                    << qApp->tr("Heure")
                    << qApp->tr("Durée")
                    << qApp->tr("Coefficient")
                    << qApp->tr("Calculatrice")
                    << qApp->tr("Documents")
//                    << qApp->tr("Surveiller")
    //                << qApp->tr("Modifier")
                    );    }


    QSqlQuery q;

    q.prepare("SELECT DISTINCT Id_C, Date_C, Heure_C, Nom_M, Semestre_M, Nom_TC, Duree_C, Coefficient_C, Calculatrice_OK, Documents_OK "
              "FROM CONTROLE, MATIERE, TYPE_CONTROLE, ENSEIGNER "
              "WHERE CONTROLE.Id_M = MATIERE.Id_M "
              "  AND CONTROLE.Id_TC = TYPE_CONTROLE.Id_TC "
              "  AND enseigner.id_M = controle.id_M "
              + mFiltre);

    if(!q.exec()) {
        qDebug() << "getTableCtrl";
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    if(&pPersonne != NULL) {
        controlesSurveilles = getListeControlesSurveilles(pPersonne);
        controlesResponsable = getResponsableMatieres(pPersonne);
    }

    while(q.next()) {
        QList<QStandardItem*> ligne;

        // Date
        ligne << new QStandardItem(valeur(q, "Date_C").toDate().toString("dd/MM/yyyy"));
        // Matiere
        ligne << new QStandardItem(valeur(q, "Nom_M").toString() + " " + valeur(q, "Semestre_M").toString());
        // Type
        ligne << new QStandardItem(valeur(q, "Nom_TC").toString());
        // Heure
        ligne << new QStandardItem(v2time(valeur(q, "Heure_C")).toString("h'h'mm"));
        // Durée
        ligne << new QStandardItem(i2time(valeur(q, "Duree_C").toInt()).toString("h'h'mm"));
        // Coeff
        ligne << new QStandardItem(valeur(q, "Coefficient_C").toString());
        // Calc
        if(v2b(valeur(q, "Calculatrice_OK"))) {
            ligne << itemOui();
        }
        else {
            ligne << itemNon();
        }
        // Docs
        if(v2b(valeur(q, "Documents_OK"))) {
            ligne << itemOui();
        }
        else {
            ligne << itemNon();
        }
        // Surveiller ou pas
        if(&pPersonne != NULL) {
            if(controlesSurveilles.contains(valeur(q, "Id_C").toInt())) {
                ligne << new QStandardItem(QPixmap(":/icones/oui"), "Surveillé");
            }
            else {
                ligne << new QStandardItem(QPixmap(":/icones/non"), "Non surveillé");
            }
            if(controlesResponsable.contains(QString(valeur(q, "Nom_M").toString() + " " + valeur(q, "Semestre_M").toString()))
                    || pPersonne.estAdministrateur()
                    || pPersonne.estReponsablePlanning()) {
                ligne << new QStandardItem("Éditer");
            }
        }

        retour->appendRow(ligne);
    }

    return retour;
}


QString Bdd::getFiltre() const {
    return mFiltre;
}

void Bdd::setFiltre(QString pFiltre) {
    mFiltre = pFiltre;
}

void Bdd::ajouterControle(Controle &pControle) {
    QSqlQuery q;

    q.prepare("insert into CONTROLE "
              "(Date_C, Heure_C, Duree_C, Coefficient_C, "
              "Calculatrice_OK, Documents_OK, Id_M, Id_TC) "
              "values (:date, :heure, :duree, :coeff, :calc, :doc, :matiere, :type)");

    // OMGWTFBBQ, date != dateTime !! !!!!! !!!! !!!!! !!! !!! !! ! !! ! !!! !! !!! !
    q.bindValue(":dateTime", pControle.getDate().toString("yyyy-MM-dd"));
    q.bindValue(":heure", pControle.getHeure().toString("hh:mm"));
    q.bindValue(":duree", pControle.getDuree()*60);
    q.bindValue(":coeff", pControle.getCoefficient());
    q.bindValue(":calc", b2s(pControle.estAutoriseCalculatrice()));
    q.bindValue(":doc", b2s(pControle.estAutoriseDocuments()));
    q.bindValue(":matiere", pControle.getIdMatiere());
    q.bindValue(":type", pControle.getIdType());

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    // Salles
    /*QStringListIterator i(pControle.getSalles());
    while(i.hasNext()) {
        QString nomSalle = i.next();

        q.prepare("insert into SE_DEROULER "
                  "(Id_C, Id_Salle) "
                  "values ( "
                  "(select count(*) AS id "
                  " from CONTROLE"
                  "), "
                  "(select Id_Salle "
                  " from SALLE "
                  " where upper(Nom_S) = :nomSalle"
                  "))");

        q.bindValue(":nomSalle", nomSalle.toUpper());

        if(!q.exec()) {
            qDebug() << derniereErreur(q);;
            throw std::exception();
        }

    }*/
    //*/
}

void Bdd::editerControle(Controle &pAncien, Controle& pNouveau) {
    QSqlQuery q;

    q.prepare("update CONTROLE "
              " set date_c=:nDate, heure_c=:nHeure, duree_c=:nDuree, coefficient_c=:nCoeff, "
              " calculatrice_ok=:nCalc, documents_ok=:nDoc, id_m=:nMat, id_tc=:nTc "
              " where date_c=:aDate AND heure_c=:aHeure AND duree_c=:aDuree AND coefficient_c=:aCoeff AND "
              " calculatrice_ok=:aCalc AND documents_ok=:aDoc AND id_m=:aMat AND id_tc=:aTc ");

    q.bindValue(":nDate", pNouveau.getDate().toString("yyyy-MM-dd"));
    q.bindValue(":nHeure", pNouveau.getHeure().toString("hh:mm"));
    q.bindValue(":nDuree", pNouveau.getDuree()*60);
    q.bindValue(":nCoeff", pNouveau.getCoefficient());
    q.bindValue(":nCalc", b2s(pNouveau.estAutoriseCalculatrice()));
    q.bindValue(":nDoc", b2s(pNouveau.estAutoriseDocuments()));
    q.bindValue(":nMat", pNouveau.getIdMatiere());
    q.bindValue(":nTc", pNouveau.getIdType());

    q.bindValue(":aDate", pAncien.getDate().toString("yyyy-MM-dd"));
    q.bindValue(":aHeure", pAncien.getHeure().toString("hh:mm"));
    q.bindValue(":aDuree", pAncien.getDuree()*60);
    q.bindValue(":aCoeff", pAncien.getCoefficient());
    q.bindValue(":aCalc", b2s(pAncien.estAutoriseCalculatrice()));
    q.bindValue(":aDoc", b2s(pAncien.estAutoriseDocuments()));
    q.bindValue(":aMat", pAncien.getIdMatiere());
    q.bindValue(":aTc", pAncien.getIdType());

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    // Salles
    QStringListIterator i(pAncien.getSalles());
    while(i.hasNext()) {
        QString nomSalle = i.next();
        q.prepare("delete from SE_DEROULER "
                  "where Id_C="
                  "(select Id_C from CONTROLE where date_c=:date and heure_c=:heure "
                  "and id_m=:matiere) "
                  "  and Id_Salle=(select Id_Salle from SALLE where Nom_S = :nomSalle)"
                  );
        qDebug() << nomSalle;
        q.bindValue(":date", pNouveau.getDate().toString("yyyy-MM-dd"));
        q.bindValue(":heure", pNouveau.getHeure().toString("hh:mm"));
        q.bindValue(":matiere", pNouveau.getIdMatiere());
        q.bindValue(":nomSalle", nomSalle);

        if(!q.exec()) {
            qDebug() << derniereErreur(q);
            throw std::exception();
        }
    }

    QStringListIterator ii(pNouveau.getSalles());
    while(ii.hasNext()) {
        QString nomSalle = ii.next();

        q.prepare(  "insert into SE_DEROULER (Id_C, Id_Salle) "
                    "values ("
                    "(select Id_C from CONTROLE where date_c=:date and heure_c=:heure and id_m=:matiere), "
                    "(select Id_Salle from SALLE where Nom_S = :nomSalle)"
                    ")");

        q.bindValue(":date", pNouveau.getDate().toString("yyyy-MM-dd"));
        q.bindValue(":heure", pNouveau.getHeure().toString("hh:mm"));
        q.bindValue(":matiere", pNouveau.getIdMatiere());
        q.bindValue(":nomSalle", nomSalle);

        if(!q.exec()) {
            qDebug() << derniereErreur(q);
            throw std::exception();
        }
    }
    //*/
}

QStringList Bdd::getListeMatieres() {
    QStringList retour;

    QSqlQuery q;

    q.prepare("SELECT Nom_M, Semestre_M FROM MATIERE");

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    while(q.next()) {
        retour << QString(valeur(q, "Nom_M").toString() + " " + valeur(q, "Semestre_M").toString());
    }

    return retour;
}

QList<int> Bdd::getListeControlesSurveilles(const Personne& pPersonne){
    QList<int> retour;
    QSqlQuery q;

    q.prepare("SELECT controle.id_C FROM controle, surveiller, personne "
              "WHERE surveiller.id_C = controle.id_C AND personne.id_P = surveiller.id_P "
              "AND Personne.Nom_P=:nomPersonne AND Personne.Prenom_P=:prenomPersonne");
    q.bindValue(":nomPersonne", pPersonne.getNom());
    q.bindValue(":prenomPersonne", pPersonne.getPrenom());
    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    while(q.next()) {
        retour << valeur(q, "id_C").toInt();
    }

    return retour;
}


QString Bdd::getListeControlesSurveillesFormatHTML(const Personne& pPersonne){
    QString retour = "";
    QSqlQuery q;
    int nbMinutesRestantes = 0;


    q.prepare("SELECT nom_p, duree_c, date_c, nom_m, Semestre_M, nom_tc, heure_c, "
            "coefficient_c, Calculatrice_OK, Documents_OK "
              "FROM controle, surveiller, personne, matiere, type_controle  "
              "WHERE surveiller.id_C = controle.id_C "
              " AND personne.id_P = surveiller.id_P "
              " AND controle.Id_M = matiere.Id_M "
              " AND controle.Id_TC = type_controle.Id_TC "
              " AND personne.Nom_P=:nomPersonne "
              " AND personne.Prenom_P=:prenomPersonne "
              );

    q.bindValue(":nomPersonne", pPersonne.getNom());
    q.bindValue(":prenomPersonne", pPersonne.getPrenom());
    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    retour += "<h1><span style=\"color : #380379\">Liste des contrôles surveillés</h1>";
    retour += "<h2><em>"+ pPersonne.getPrenom() + " " +pPersonne.getNom()+"</em></span></h2>";
    retour += "<br/>";
    retour += "<h3>Quotas d'heures de surveillance le <em>" + QDateTime::currentDateTime().toString("dd/MM/yyyy à h'h'mm") + "</em></h3>";
    retour += "<strong>À efféctuer</strong>  " + pPersonne.getQuota().toString("h'h'mm") + "<br />";
    retour += "<strong>Éffectués</strong>  "+ pPersonne.getNbHeuresEffectuees().toString("h'h'mm")+ "<br />";
    retour += "<strong>Programmés</strong>  "+pPersonne.getNbHeuresProgrammes().toString("h'h'mm")+"<br />";

    nbMinutesRestantes = pPersonne.getQuota().hour() * 60 +
                         pPersonne.getQuota().minute() -
                         pPersonne.getNbHeuresEffectuees().hour() * 60 +
                         pPersonne.getNbHeuresEffectuees().minute();

    retour += "<strong>Restantes</strong>  "+QTime(nbMinutesRestantes/60, nbMinutesRestantes%60).toString("h'h'mm")+"<br />";

    retour += "<table style=\"border-width: 1px; border-color : black; border-style: solid; border-collapse: collapse;\"><tr><th>Date</th><th>Matière</th><th>Type</th><th>Heure</th>";
    retour += "<th>Durée</th><th>Coefficien</th><th>Calculatrice</th>";
    retour += "<th>Documents</th></tr>";

    while(q.next()) {
        retour +="<tr>";
        retour += "<td>  "+valeur(q, "Date_C").toDate().toString("dd/MM/yyyy")+"  </td>";
        retour += "<td>  "+valeur(q, "Nom_M").toString()+"  </td>";
        retour += "<td>  "+valeur(q, "Nom_TC").toString()+"  </td>";
        retour += "<td>  "+v2time(valeur(q, "Heure_C")).toString("h'h'mm")+"  </td>";
        retour += "<td>  " + i2time(valeur(q, "duree_c").toInt()).toString("h'h'mm") + "  </td>";
        retour += "<td>  "+valeur(q, "Coefficient_C").toString()+"  </td>";

        retour += "<td>  <img src=\":/icones/";
        retour += (v2b(valeur(q, "Documents_OK"))) ? "oui" : "non";
        retour += "\" width=\"23\"/> ";
        retour += (v2b(valeur(q, "Documents_OK"))) ? "oui" : "non";
        retour += "</td>";

        retour += "<td>  <img src=\":/icones/";
        retour += (v2b(valeur(q, "Calculatrice_OK"))) ? "oui" : "non";
        retour += "\" width=\"23\"/>";
        retour += (v2b(valeur(q, "Calculatrice_OK"))) ? "oui" : "non";
        retour +="</td>";
        retour += "</tr>";
    }

    retour += "</table>";

    return retour;
}

QString Bdd::getListeTousControleHTML (){
    QString retour = "";
    QSqlQuery q;

    q.prepare("SELECT DISTINCT duree_c, date_c, nom_m, Semestre_M, nom_tc, heure_c, "
            "coefficient_c, Calculatrice_OK, Documents_OK "
              "FROM controle, surveiller, personne, matiere, type_controle  "
              "WHERE surveiller.id_C = controle.id_C "
              " AND personne.id_P = surveiller.id_P "
              " AND controle.Id_M = matiere.Id_M "
              " AND controle.Id_TC = type_controle.Id_TC "
              );
    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    retour += "<h1><span style=\"color : #380379\">Liste des contrôles de l'année en cours</h1>";
    retour += "<br/>";
    retour += "<table style=\"border-width: 1px; border-color : black; border-style: solid; border-collapse: collapse;\"><tr><th>Date</th><th>Matière</th><th>Type</th><th>Heure</th>";
    retour += "<th>Durée</th><th>Coefficient</th><th>Calculatrice</th>";
    retour += "<th>Documents</th></tr>";

    while(q.next()) {
        retour +="<tr>";
        retour += "<td>  "+valeur(q, "Date_C").toDate().toString("dd/MM/yy")+"  </td>";
        retour += "<td>  "+valeur(q, "Nom_M").toString()+"  </td>";
        retour += "<td>  "+valeur(q, "Nom_TC").toString()+"  </td>";
        retour += "<td>  "+v2time(valeur(q, "Heure_C")).toString("h'h'mm")+"  </td>";
        retour += "<td>  " + i2time(valeur(q, "duree_c").toInt()).toString("h'h'mm") + "  </td>";
        retour += "<td>  "+valeur(q, "Coefficient_C").toString()+"  </td>";

        retour += "<td>  <img src=\":/icones/";
        retour += (v2b(valeur(q, "Documents_OK"))) ? "oui" : "non";
        retour += "\" width=\"23\"/> ";
        retour += (v2b(valeur(q, "Documents_OK"))) ? "oui" : "non";
        retour += "</td>";

        retour += "<td>  <img src=\":/icones/";
        retour += (v2b(valeur(q, "Calculatrice_OK"))) ? "oui" : "non";
        retour += "\" width=\"23\"/>";
        retour += (v2b(valeur(q, "Calculatrice_OK"))) ? "oui" : "non";
        retour +="</td>";
        retour += "</tr>";
    }

    retour += "</table>";
    retour += "<p align=\"right\">Imprimé le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy à h'h'mm") + "</p>";

    return retour;
}

QString Bdd::getListeControlesParEnseignantHTML () {
    QString retour = "";
    QSqlQuery qNomPrenom;
    QSqlQuery q;

    qNomPrenom.prepare("SELECT prenom_p, nom_p "
              "FROM personne "
              );
    if(!qNomPrenom.exec()) {
        qDebug() << derniereErreur(qNomPrenom);
        throw std::exception();
    }

    while (qNomPrenom.next()) {
        int nbMinutesRestantes = 0;
        q.prepare("SELECT nom_p, duree_c, date_c, nom_m, Semestre_M, nom_tc, heure_c, "
                "coefficient_c, Calculatrice_OK, Documents_OK "
                  "FROM controle, surveiller, personne, matiere, type_controle  "
                  "WHERE surveiller.id_C = controle.id_C "
                  " AND personne.id_P = surveiller.id_P "
                  " AND controle.Id_M = matiere.Id_M "
                  " AND controle.Id_TC = type_controle.Id_TC "
                  " AND personne.Nom_P=:nomPersonne "
                  " AND personne.Prenom_P=:prenomPersonne "
                  );

        q.bindValue(":nomPersonne", valeur(qNomPrenom, "nom_p"));
        q.bindValue(":prenomPersonne", valeur (qNomPrenom, "prenom_p"));

        if(!q.exec()) {
            qDebug() << derniereErreur(q);
            throw std::exception();
        }

        QString pLoginPersonneCourante = "" + valeur(qNomPrenom, "prenom_p").toString() + "." + valeur(qNomPrenom, "nom_p").toString();
        Personne* pPersonneCourante = getPersonne(pLoginPersonneCourante);

        retour += "<h1><span style=\"color : #380379\">Liste des contrôles surveillés</h1>";
        retour += "<h2><em>"+ pPersonneCourante->getPrenom() + " " + pPersonneCourante->getNom()+"</em></span></h2>";
        retour += "<br/>";
        retour += "<h3>Quotas d'heures de surveillance le <em>" + QDateTime::currentDateTime().toString("dd/MM/yyyy à h'h'mm") + "</em></h3>";
        retour += "<strong>À efféctuer</strong>  " + pPersonneCourante->getQuota().toString("h'h'mm") + "<br />";
        retour += "<strong>Éffectués</strong>  "+ pPersonneCourante->getNbHeuresEffectuees().toString("h'h'mm")+ "<br />";
        retour += "<strong>Programmés</strong>  "+pPersonneCourante->getNbHeuresProgrammes().toString("h'h'mm")+"<br />";

        nbMinutesRestantes = pPersonneCourante->getQuota().hour() * 60 +
                             pPersonneCourante->getQuota().minute() -
                             pPersonneCourante->getNbHeuresEffectuees().hour() * 60 +
                             pPersonneCourante->getNbHeuresEffectuees().minute();

        retour += "<strong>Restantes</strong>  "+QTime(nbMinutesRestantes/60, nbMinutesRestantes%60).toString("h'h'mm")+"<br />";

        retour += "<table style=\"border-width: 1px; border-color : black; border-style: solid; border-collapse: collapse;\"><tr><th>Date</th><th>Matière</th><th>Type</th><th>Heure</th>";
        retour += "<th>Durée</th><th>Coefficien</th><th>Calculatrice</th>";
        retour += "<th>Documents</th></tr>";

        while(q.next()) {
            retour +="<tr>";
            retour += "<td>  "+valeur(q, "Date_C").toDate().toString("dd/MM/yyyy")+"  </td>";
            retour += "<td>  "+valeur(q, "Nom_M").toString()+"  </td>";
            retour += "<td>  "+valeur(q, "Nom_TC").toString()+"  </td>";
            retour += "<td>  "+v2time(valeur(q, "Heure_C")).toString("h'h'mm")+"  </td>";
            retour += "<td>  " + i2time(valeur(q, "duree_c").toInt()).toString("h'h'mm") + "  </td>";
            retour += "<td>  "+valeur(q, "Coefficient_C").toString()+"  </td>";

            retour += "<td>  <img src=\":/icones/";
            retour += (v2b(valeur(q, "Documents_OK"))) ? "oui" : "non";
            retour += "\" width=\"23\"/> ";
            retour += (v2b(valeur(q, "Documents_OK"))) ? "oui" : "non";
            retour += "</td>";

            retour += "<td>  <img src=\":/icones/";
            retour += (v2b(valeur(q, "Calculatrice_OK"))) ? "oui" : "non";
            retour += "\" width=\"23\"/>";
            retour += (v2b(valeur(q, "Calculatrice_OK"))) ? "oui" : "non";
            retour +="</td>";
            retour += "</tr>";
        }

        retour += "</table>";
        retour += "<hr>";

    }
    return retour;
}

QString Bdd::getListeControlesParEnseignantTrieParQuotaHTML() {
    QString retour = "";

    QSqlQuery qNomPrenom;
    QSqlQuery q;
    QList<Personne*> listPersonneNonTrie;
    QList<Personne*> listPersonneTrie;
    qNomPrenom.prepare("SELECT prenom_p, nom_p "
              "FROM personne "
              );
    if(!qNomPrenom.exec()) {
        qDebug() << derniereErreur(qNomPrenom);
        throw std::exception();
    }

    int i = 0;
    while (qNomPrenom.next()) {
        QString pPassLoginPersonne = "" + valeur(qNomPrenom, "prenom_p").toString() + "." + valeur(qNomPrenom, "nom_p").toString();
        Personne* pPersonneCourante = getPersonne(pPassLoginPersonne);
        listPersonneNonTrie.push_back(pPersonneCourante);
        i++;
    }

    int j = 0;
    int quota;
    int index;
    int listSize = listPersonneNonTrie.size();
    while (listPersonneTrie.size() < listSize) {
        quota = -1;
        index = 0;
        for (int i = 0; i <= listPersonneNonTrie.size()-1; i++) {
            if (listPersonneNonTrie[i]->getNbHeuresEffectuees().hour() * 60 > quota) {
                quota = listPersonneNonTrie.at(i)->getNbHeuresEffectuees().hour() * 60;
                index = i;
            }
        }
        listPersonneTrie.push_back(listPersonneNonTrie.at(index));
        listPersonneNonTrie.removeAt(index);
        j++;
    }

    for (int k = 0; k < listPersonneTrie.size() -1; k++) {
        Personne* pPersonneCourante = listPersonneTrie.at(k);
        int nbMinutesRestantes = 0;
        q.prepare("SELECT nom_p, duree_c, date_c, nom_m, Semestre_M, nom_tc, heure_c, "
                "coefficient_c, Calculatrice_OK, Documents_OK "
                  "FROM controle, surveiller, personne, matiere, type_controle  "
                  "WHERE surveiller.id_C = controle.id_C "
                  " AND personne.id_P = surveiller.id_P "
                  " AND controle.Id_M = matiere.Id_M "
                  " AND controle.Id_TC = type_controle.Id_TC "
                  " AND personne.Nom_P=:nomPersonne "
                  " AND personne.Prenom_P=:prenomPersonne "
                  );

        q.bindValue(":nomPersonne", pPersonneCourante->getNom());
        q.bindValue(":prenomPersonne", pPersonneCourante->getPrenom());

        if(!q.exec()) {
            qDebug() << derniereErreur(q);
            throw std::exception();
        }

        retour += "<h1><span style=\"color : #380379\">Liste des contrôles surveillés</h1>";
        retour += "<h2><em>"+ pPersonneCourante->getPrenom() + " " + pPersonneCourante->getNom()+"</em></span></h2>";
        retour += "<br/>";
        retour += "<h3>Quotas d'heures de surveillance le <em>" + QDateTime::currentDateTime().toString("dd/MM/yyyy à h'h'mm") + "</em></h3>";
        retour += "<strong>À efféctuer</strong>  " + pPersonneCourante->getQuota().toString("h'h'mm") + "<br />";
        retour += "<strong>Éffectués</strong>  "+ pPersonneCourante->getNbHeuresEffectuees().toString("h'h'mm")+ "<br />";
        retour += "<strong>Programmés</strong>  "+pPersonneCourante->getNbHeuresProgrammes().toString("h'h'mm")+"<br />";

        nbMinutesRestantes = pPersonneCourante->getQuota().hour() * 60 +
                             pPersonneCourante->getQuota().minute() -
                             pPersonneCourante->getNbHeuresEffectuees().hour() * 60 +
                             pPersonneCourante->getNbHeuresEffectuees().minute();

        retour += "<strong>Restantes</strong>  "+QTime(nbMinutesRestantes/60, nbMinutesRestantes%60).toString("h'h'mm")+"<br />";

        retour += "<table style=\"border-width: 1px; border-color : black; border-style: solid; border-collapse: collapse;\"><tr><th>Date</th><th>Matière</th><th>Type</th><th>Heure</th>";
        retour += "<th>Durée</th><th>Coefficien</th><th>Calculatrice</th>";
        retour += "<th>Documents</th></tr>";

        while(q.next()) {
            retour +="<tr>";
            retour += "<td>  "+valeur(q, "Date_C").toDate().toString("dd/MM/yyyy")+"  </td>";
            retour += "<td>  "+valeur(q, "Nom_M").toString()+"  </td>";
            retour += "<td>  "+valeur(q, "Nom_TC").toString()+"  </td>";
            retour += "<td>  "+v2time(valeur(q, "Heure_C")).toString("h'h'mm")+"  </td>";
            retour += "<td>  " + i2time(valeur(q, "duree_c").toInt()).toString("h'h'mm") + "  </td>";
            retour += "<td>  "+valeur(q, "Coefficient_C").toString()+"  </td>";

            retour += "<td>  <img src=\":/icones/";
            retour += (v2b(valeur(q, "Documents_OK"))) ? "oui" : "non";
            retour += "\" width=\"23\"/> ";
            retour += (v2b(valeur(q, "Documents_OK"))) ? "oui" : "non";
            retour += "</td>";

            retour += "<td>  <img src=\":/icones/";
            retour += (v2b(valeur(q, "Calculatrice_OK"))) ? "oui" : "non";
            retour += "\" width=\"23\"/>";
            retour += (v2b(valeur(q, "Calculatrice_OK"))) ? "oui" : "non";
            retour +="</td>";
            retour += "</tr>";
        }

        retour += "</table>";
        retour += "<hr>";
    }
    return retour;
}


QSqlTableModel* Bdd::getTableControles() {
    QSqlTableModel* retour= new QSqlTableModel(0, mBdd);

    retour->setTable("CONTROLE");
    retour->select();
    //retour->setEditStrategy(QSqlTableModel::OnFieldChange);
    retour->setEditStrategy(QSqlTableModel::OnManualSubmit);
    retour->setHeaderData(1, Qt::Horizontal, qApp->tr("Type de contrôle"));
    retour->setHeaderData(2, Qt::Horizontal, qApp->tr("Matière"));
    retour->setHeaderData(3, Qt::Horizontal, qApp->tr("Date"));
    retour->setHeaderData(4, Qt::Horizontal, qApp->tr("Heure"));
    retour->setHeaderData(5, Qt::Horizontal, qApp->tr("Durée"));
    retour->setHeaderData(6, Qt::Horizontal, qApp->tr("Coefficient"));
    retour->setHeaderData(7, Qt::Horizontal, qApp->tr("Calculatrice"));
    retour->setHeaderData(8, Qt::Horizontal, qApp->tr("Documents"));


    return retour;
}

QStringList Bdd::getListePoles() {
    QStringList retour;

    QSqlQuery q;

    q.prepare("SELECT Nom_Pole FROM POLE");

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    while(q.next()) {
        retour << valeur(q, "Nom_Pole").toString();
    }

    return retour;
}

QSqlTableModel* Bdd::getTablePoles() {
    QSqlTableModel* retour= new QSqlTableModel(0, mBdd);

    retour->setTable("POLE");
    retour->setEditStrategy(QSqlTableModel::OnFieldChange);
    retour->select();
    retour->setHeaderData(1, Qt::Horizontal, qApp->tr("Pôle"));

    return retour;
}

QStringList Bdd::getListeSalles() {
    QStringList retour;

    QSqlQuery q;

    q.prepare("SELECT Nom_S FROM SALLE");

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    while(q.next()) {
        retour << valeur(q, "Nom_S").toString();
    }
    //    mModele->insertRecord(mModele->record())

    return retour;
}

QSqlTableModel* Bdd::getTableSalles() {
    QSqlTableModel* retour= new QSqlTableModel(0, mBdd);

    retour->setTable("SALLE");
    retour->setEditStrategy(QSqlTableModel::OnFieldChange);
    retour->select();
    retour->setHeaderData(1, Qt::Horizontal, qApp->tr("Nom"));
    retour->setHeaderData(2, Qt::Horizontal, qApp->tr("Surveillants"));
    retour->setHeaderData(3, Qt::Horizontal, qApp->tr("Capacité"));

    return retour;
}

QStringList Bdd::getListeTypeCtrl() {
    QStringList retour;

    QSqlQuery q;

    q.prepare("SELECT Nom_TC FROM TYPE_CONTROLE");

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    while(q.next()) {
        retour << valeur(q, "Nom_TC").toString();
    }

    return retour;
}

QSqlTableModel* Bdd::getTableTypeCtrl() {
    QSqlTableModel* retour= new QSqlTableModel(0, mBdd);

    retour->setTable("TYPE_CONTROLE");
    retour->setEditStrategy(QSqlTableModel::OnFieldChange);
    retour->select();
    retour->setHeaderData(1, Qt::Horizontal, qApp->tr("Type de contrôle"));

    return retour;
}

QStringList Bdd::getListeUtilisateurs() {
    QStringList retour;

    QSqlQuery q;

    q.prepare("SELECT Nom_P, Prenom_P FROM PERSONNE");

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    while(q.next()) {
        retour << QString(valeur(q, "Prenom_P").toString() + " " + valeur(q, "Nom_P").toString());
    }

    return retour;
}

Controle Bdd::getControle(QString pMatiere,
                          QDate   pDate,
                          QTime   pHeure) {
    Controle retour;

    QSqlQuery q;
    q.prepare("SELECT id_C, Date_C, Heure_C, Duree_C, Coefficient_C, Calculatrice_OK, Documents_OK, Id_M, Id_TC FROM controle "
              "WHERE id_m=(select id_m from matiere where nom_m=:nomMatiere) "
              "  AND date_c=:date AND heure_c=:heure");

    q.bindValue(":nomMatiere", pMatiere);
    q.bindValue(":date", pDate.toString("yyyy'-'MM'-'dd"));
    q.bindValue(":heure", pHeure.toString("hh':'mm"));

    if(!q.exec()) {
        qDebug() << derniereErreur(q);
        throw std::exception();
    }

    while(q.next()) {
        QSqlQuery qq;
        qq.prepare("SELECT Nom_S FROM Salle, se_derouler "
                   "WHERE salle.id_Salle = se_derouler.id_Salle"
                   "  AND se_derouler.id_C=:idC");
        qq.bindValue(":idC", valeur(q, "id_C"));
        if(!qq.exec()) {
            qDebug() << derniereErreur(qq);
            throw std::exception();
        }
        retour.setDate(valeur(q, "Date_C").toDate());
        retour.setHeure(v2time(valeur(q, "Heure_C")));
        retour.setDuree(valeur(q, "Duree_C").toInt()/60.0);
        retour.setCoefficient(valeur(q, "Coefficient_C").toDouble());
        retour.setIdMatiere(valeur(q, "Id_M").toInt());
        retour.setIdType(valeur(q, "Id_TC").toInt());
        retour.setAutorisationCalculatrice(v2b(valeur(q, "Calculatrice_OK")));
        retour.setAutorisationDocuments(v2b(valeur(q, "Documents_OK")));

        while(qq.next()){
            retour.ajouterSalle(valeur(qq, "Nom_S").toString());
        }

    }

    qDebug() << retour.getDate()
             << retour.getHeure()
             << retour.getDuree()
             << retour.getCoefficient()
             << retour.getIdMatiere()
             << retour.getIdType()
             << retour.estAutoriseCalculatrice()
             << retour.estAutoriseDocuments()
             << retour.getSalles();

    return retour;
}

void Bdd::creerBdd() {
    executerFichier("./creation.sql");
}

void Bdd::executerFichier(QString pNom) {
    QSqlQuery q;

    qDebug() << "Execution de" << pNom;
    QFile file(pNom);
    file.open(QIODevice::ReadOnly);

    QStringList requetes = QString(file.readAll()).split(";", QString::SkipEmptyParts);

    QStringListIterator i(requetes);
    while(i.hasNext()) {
        QString requete = i.next();

        // Verifier que la requete n'est pas vide
        if(requete.contains(QRegExp("[a-zA-Z]"))) {
            q.prepare(requete);

            if(!q.exec()) {
                qDebug() << q.lastQuery();
                qDebug() << derniereErreur(q);
                throw std::exception();
            }
        }
    }
    file.close();
}

inline QString Bdd::derniereErreur(const QSqlQuery& q) {
    QString retour;
    qDebug() << "[ ERREUR  ] " << q.lastError();
    qDebug() << "[ REQUETE ] " << q.lastQuery();
    qDebug() << "[ PARAMS  ] " << q.boundValues();

    return q.lastError().text();
}

inline QVariant Bdd::valeur(const QSqlQuery& q, const QString& champ) {
    return q.value(q.record().indexOf(champ));
}

inline QString Bdd::b2s(bool valeur) {
    return (valeur)
            ? "True"
            : "False";
}

inline bool Bdd::v2b(QVariant valeur) {
    return (valeur == "True");
}

inline QTime Bdd::v2time(QVariant valeur) {
    QStringList split = valeur.toString().split(":");
    return QTime(split.first().toInt(),
                 split.last().toInt());
}

inline QTime Bdd::i2time(int valeur) {
    return QTime(valeur/60,
                 valeur%60);
}

inline int Bdd::time2i(QTime valeur) {
    return valeur.hour()*60 + valeur.minute();
}

inline QStandardItem* Bdd::itemOui() {
    return new QStandardItem(QPixmap(":/icones/oui"), "Oui");
}

inline QStandardItem* Bdd::itemNon() {
    return new QStandardItem(QPixmap(":/icones/non"), "Non");
}
