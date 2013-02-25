#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QtCore>
#include <QString>

#include <QMessageBox>

class Exception
        : public QtConcurrent::Exception {
public:
    enum Niveau {
        Attention,
        Erreur
    };

    Exception(const QString& pMessage,
              const QString& pClasse,
              const Niveau&  pNiveau = Attention) throw() {
        mMessage = pMessage;
        mClasse	 = pClasse;
        mNiveau	 = pNiveau;

        if(mNiveau == Attention)
            QMessageBox::information(NULL,
                                     mClasse,
                                     mMessage);
        else {
            QMessageBox::critical(NULL,
                                  mClasse,
                                  mMessage);
            qApp->quit();
        }
    }

    ~Exception() throw() {}

    virtual const char* what() const throw() {
        return QString("%1 : %2").arg(mClasse).arg(mMessage)
                .toStdString().c_str();
    }

    Niveau	niveau()	const throw() {
        return mNiveau;
    }
    QString	message()	const throw() {
        return mMessage;
    }

    QString	classe()	const throw() {
        return mClasse;
    }

    void raise() const {
        throw *this;
    }

    Ex* clone() const {
        return new Ex(*this);
    }

private:
    QString	mMessage;
    QString	mClasse;
    Niveau	mNiveau;

}

#endif // EXCEPTION_H
