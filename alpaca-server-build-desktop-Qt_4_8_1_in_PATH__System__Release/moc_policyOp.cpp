/****************************************************************************
** Meta object code from reading C++ file 'policyOp.h'
**
** Created: Fri Jun 20 08:22:57 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../alpaca-server/policyOp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'policyOp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_policyOp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   10,    9,    9, 0x05,
      37,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,    9,    9,    9, 0x0a,
      70,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_policyOp[] = {
    "policyOp\0\0x\0setProgressBarValue(int)\0"
    "setProgressBarRange(int)\0alter()\0"
    "checkToStart()\0"
};

void policyOp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        policyOp *_t = static_cast<policyOp *>(_o);
        switch (_id) {
        case 0: _t->setProgressBarValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setProgressBarRange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->alter(); break;
        case 3: _t->checkToStart(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData policyOp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject policyOp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_policyOp,
      qt_meta_data_policyOp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &policyOp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *policyOp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *policyOp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_policyOp))
        return static_cast<void*>(const_cast< policyOp*>(this));
    return QObject::qt_metacast(_clname);
}

int policyOp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void policyOp::setProgressBarValue(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void policyOp::setProgressBarRange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
