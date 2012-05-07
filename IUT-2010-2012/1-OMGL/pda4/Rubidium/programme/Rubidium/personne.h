#ifndef HEADER_PERSONNE
#define HEADER_PERSONNE

#include <QString>
#include <QTime>

class Personne {
public:
    Personne();
    Personne(const Personne& pPersonne);
    virtual ~Personne();

    virtual QString getNom() const;
    virtual void setNom(QString pNom);
    virtual QString getPrenom() const;
    virtual void setPrenom(QString pPrenom);
    virtual QString getMdp() const;
    virtual void setMdp(QString pMdp);
    virtual QTime getQuota() const;
    virtual void setQuota(QTime pQuota);
    virtual QTime getNbHeuresEffectuees() const;
    virtual QTime getNbHeuresProgrammes() const;
    virtual void setNbHeuresEffectuees(QTime pNbHeuresEffectuees);
    virtual void setNbHeuresProgrammes(QTime pNbHeuresProgrammes);
    virtual bool estReponsablePlanning() const;
    virtual void setResponsable(bool pResponsable);
    virtual bool estAdministrateur() const;
    virtual void setAdministrateur(bool pAdministrateur);
private:
    QString mNom;
    QString mPrenom;
    QString mMdp;
    QTime mQuota;
    QTime mHeuresEffectuees;
    QTime mHeuresProgrammes;
    bool mResponsablePlanning;
    bool mAdministrateur;
};

#endif // HEADER_PERSONNE
