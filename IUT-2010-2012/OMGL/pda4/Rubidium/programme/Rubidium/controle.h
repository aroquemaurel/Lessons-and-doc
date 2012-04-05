#ifndef HEADER_CONTROLE
#define HEADER_CONTROLE

#include <QDateTime>
#include <QStringList>

class Controle {
public:
	Controle();
    Controle(const Controle &pControle);
	virtual ~Controle();

    virtual double getDuree() const;
	virtual void setDuree(double pDuree);
    virtual double getCoefficient() const;
	virtual void setCoefficient(double pCoefficient);
    virtual QDate getDate() const;
    virtual void setDate(QDate pDate);
    virtual QTime getHeure() const;
    virtual void setHeure(QTime pDate);
    virtual bool estAutoriseCalculatrice() const;
	virtual void setAutorisationCalculatrice(bool pCalculatrice);
    virtual bool estAutoriseDocuments() const;
	virtual void setAutorisationDocuments(bool pDocuments);
    virtual int getIdMatiere() const;
    virtual void setIdMatiere(int pIdMatiere);
    virtual int getIdType() const;
    virtual void setIdType(int pIdType);
    virtual QStringList getSalles();
    virtual void ajouterSalle(QString pSalle);
    virtual void supprimerSalle(QString pSalle);

private:
	double mDuree;
	double mCoefficient;
    QDate mDate;
    QTime mHeure;
	bool mCalculatrice;
	bool mDocuments;
    int  mIdMatiere;
    int  mIdTypeControle;
    QStringList mSalles;
};


#endif // HEADER_CONTROLE
