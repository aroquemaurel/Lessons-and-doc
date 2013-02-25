/****************************************************************************
** Meta object code from reading C++ file 'dialogchangerpass.h'
**
** Created: Sat Mar 31 16:05:46 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogchangerpass.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogchangerpass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogChangerPass[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_DialogChangerPass[] = {
    "DialogChangerPass\0"
};

const QMetaObject DialogChangerPass::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogChangerPass,
      qt_meta_data_DialogChangerPass, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogChangerPass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogChangerPass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogChangerPass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogChangerPass))
        return static_cast<void*>(const_cast< DialogChangerPass*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogChangerPass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
