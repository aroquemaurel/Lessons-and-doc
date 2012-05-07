/****************************************************************************
** Meta object code from reading C++ file 'dockfiltres.h'
**
** Created: Sat Mar 31 16:05:40 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dockfiltres.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dockfiltres.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DockFiltres[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   12,   12,   12, 0x0a,
      43,   35,   12,   12, 0x08,
      69,   35,   12,   12, 0x08,
      94,   35,   12,   12, 0x08,
     124,   35,   12,   12, 0x08,
     157,   35,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DockFiltres[] = {
    "DockFiltres\0\0nouveauFiltre()\0maj()\0"
    "activer\0semestreSelectionne(bool)\0"
    "matiereSelectionne(bool)\0"
    "surveillanceSelectionne(bool)\0"
    "voirMesMatieresSelectionne(bool)\0"
    "voirMatieresResponsableSelectionne(bool)\0"
};

const QMetaObject DockFiltres::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DockFiltres,
      qt_meta_data_DockFiltres, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DockFiltres::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DockFiltres::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DockFiltres::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DockFiltres))
        return static_cast<void*>(const_cast< DockFiltres*>(this));
    return QWidget::qt_metacast(_clname);
}

int DockFiltres::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: nouveauFiltre(); break;
        case 1: maj(); break;
        case 2: semestreSelectionne((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: matiereSelectionne((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: surveillanceSelectionne((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: voirMesMatieresSelectionne((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: voirMatieresResponsableSelectionne((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DockFiltres::nouveauFiltre()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
