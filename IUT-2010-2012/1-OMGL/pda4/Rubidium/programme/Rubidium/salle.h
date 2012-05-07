#ifndef HEADER_SALLE
#define HEADER_SALLE

#include <QString>

class Salle {
public:
    Salle();
    Salle(const Salle& pSalle);
	virtual ~Salle();

    virtual QString getNom() const;
	virtual void setNom(QString pNom);
    virtual int getNbSurveillants() const;
	virtual void setNbSurveillants(int pNbSurveillants);
    virtual int getCapacite() const;
	virtual void setCapacite(int pCapacite);

private: 
	QString mNom;
	int mNbSurveillants;
	int mCapacite;
};


#endif // HEADER_SALLE
