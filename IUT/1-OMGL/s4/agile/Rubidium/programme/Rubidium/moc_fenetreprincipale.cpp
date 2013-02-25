/****************************************************************************
** Meta object code from reading C++ file 'fenetreprincipale.h'
**
** Created: Sat Mar 31 16:05:38 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fenetreprincipale.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetreprincipale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FenetrePrincipale[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   18,   18,   18, 0x0a,
      41,   18,   18,   18, 0x0a,
      55,   18,   18,   18, 0x0a,
      71,   18,   18,   18, 0x0a,
     106,   18,   18,   18, 0x0a,
     135,   18,   18,   18, 0x0a,
     177,   18,   18,   18, 0x0a,
     231,   18,   18,   18, 0x0a,
     246,   18,   18,   18, 0x0a,
     258,   18,   18,   18, 0x0a,
     272,   18,   18,   18, 0x0a,
     292,   18,   18,   18, 0x0a,
     312,   18,   18,   18, 0x0a,
     330,   18,   18,   18, 0x0a,
     340,   18,   18,   18, 0x0a,
     358,   18,   18,   18, 0x0a,
     381,   18,   18,   18, 0x0a,
     401,   18,   18,   18, 0x0a,
     423,   18,   18,   18, 0x0a,
     430,   18,   18,   18, 0x0a,
     439,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FenetrePrincipale[] = {
    "FenetrePrincipale\0\0miseAJour()\0quitter()\0"
    "seConnecter()\0seDeconnecter()\0"
    "imprimerListeControlesSurveilles()\0"
    "imprimerListeTousControles()\0"
    "imprimerListeDetailsHeuresSurveillances()\0"
    "imprimerListeDetailsHeuresSurveillancesTrieParQuota()\0"
    "adminMatiere()\0adminPole()\0adminSalles()\0"
    "adminTypeControle()\0adminUtilisateurs()\0"
    "remplirJeuEssai()\0viderBd()\0"
    "ajouterControle()\0initialiserControles()\0"
    "majListeControles()\0majActionsControles()\0"
    "menu()\0editer()\0surveiller()\0"
};

const QMetaObject FenetrePrincipale::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FenetrePrincipale,
      qt_meta_data_FenetrePrincipale, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FenetrePrincipale::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FenetrePrincipale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FenetrePrincipale::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FenetrePrincipale))
        return static_cast<void*>(const_cast< FenetrePrincipale*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FenetrePrincipale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: miseAJour(); break;
        case 1: quitter(); break;
        case 2: seConnecter(); break;
        case 3: seDeconnecter(); break;
        case 4: imprimerListeControlesSurveilles(); break;
        case 5: imprimerListeTousControles(); break;
        case 6: imprimerListeDetailsHeuresSurveillances(); break;
        case 7: imprimerListeDetailsHeuresSurveillancesTrieParQuota(); break;
        case 8: adminMatiere(); break;
        case 9: adminPole(); break;
        case 10: adminSalles(); break;
        case 11: adminTypeControle(); break;
        case 12: adminUtilisateurs(); break;
        case 13: remplirJeuEssai(); break;
        case 14: viderBd(); break;
        case 15: ajouterControle(); break;
        case 16: initialiserControles(); break;
        case 17: majListeControles(); break;
        case 18: majActionsControles(); break;
        case 19: menu(); break;
        case 20: editer(); break;
        case 21: surveiller(); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void FenetrePrincipale::miseAJour()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
