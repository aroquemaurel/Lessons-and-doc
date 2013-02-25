#ifndef DIALOGAJOUTCTRL_H
#define DIALOGAJOUTCTRL_H

#include "controle.h"

#include "ui_dialogajoutctrl.h"

class DialogAjoutCtrl
        : public QDialog,
        public Controle,
        private Ui::DialogAjoutCtrl {
    Q_OBJECT

public:
    explicit DialogAjoutCtrl(Controle& pAncien, QWidget *parent = 0);
    virtual ~DialogAjoutCtrl();

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
    QList<QCheckBox*> mSalles;
};

#endif // DIALOGAJOUTCTRL_H
