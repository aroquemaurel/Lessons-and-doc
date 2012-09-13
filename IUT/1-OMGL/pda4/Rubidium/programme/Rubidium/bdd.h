#ifndef BDD_H
#define BDD_H

#include <exception>

#include <QtSql>
#include <QStandardItemModel>

#include "personne.h"
#include "controle.h"

class Bdd {
		// SINGLETON
	public:
		~Bdd();
		static Bdd* getInstance();
		static void       detruire();

	private:
		Bdd();
		static Bdd* mInstance;
		//*/

	public:
		void jeuDEssai();
        void viderBdd();

        bool        validerPersonne(QString pLogin, QString pMotDePasse);
        Personne*   getPersonne(QString pLogin);
        QStringList getResponsableMatieres(const Personne& pPersonne);
        QStringList getMatieres(const Personne& pPersonne);
        void        ajouterPersonne(const Personne& pPersonne);
		void        editerPersonne(QString pLogin, const Personne& pPersonne);
		void        supprimerPersonne(QString pLogin);
        void        surveiller(const Personne& pPersonne,
                               const Controle& pControle,
                               bool pValeur);

        QStandardItemModel* getTableauControles(const Personne& pPersonne);
        void setFiltre(QString pFiltre);
        QString getFiltre() const;

        void        ajouterControle(Controle& pControle);
        void        editerControle(Controle& pAncien, Controle& pNouveau);

		QStringList getListeMatieres();

		QStringList getListePoles();
        QSqlTableModel* getTablePoles();

        QList<int> getListeControlesSurveilles(const Personne& pPersonne);

        QSqlTableModel* getTableControles();

        QStringList getListeSalles();
        QSqlTableModel* getTableSalles();

        QStringList getListeTypeCtrl();
        QSqlTableModel* getTableTypeCtrl();

        QStringList getListeUtilisateurs();

        Controle    getControle(QString pMatiere,
                                QDate   pDate,
                                QTime   pHeure);
        QString getListeControlesSurveillesFormatHTML(const Personne& pPersonne);
        QString getListeTousControleHTML();
        QString getListeControlesParEnseignantHTML();
        QString getListeControlesParEnseignantTrieParQuotaHTML();


	private :
		void creerBdd();
		void executerFichier(QString pNom);

		inline QString  derniereErreur(const QSqlQuery& q);
        inline QVariant valeur(const QSqlQuery& q, const QString& champ);
        inline QString  b2s(bool valeur);
        inline bool     v2b(QVariant valeur);
        inline QTime    v2time(QVariant valeur);
        inline QTime    i2time(int valeur);
        inline int      time2i(QTime valeur);
        inline QStandardItem* itemOui();
        inline QStandardItem* itemNon();

        QString mFiltre;

	private:
		QSqlDatabase mBdd;
};

#endif // BDD_H
