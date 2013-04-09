/****************************************************************************
** Meta object code from reading C++ file 'lxlibrary.h'
**
** Created: Thu Feb 28 19:26:12 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxlibrary.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxlibrary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxLibrary[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   20,   11,   10, 0x0a,
      68,   42,   11,   10, 0x0a,
     118,   99,   11,   10, 0x2a,
     141,   10,   11,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LxLibrary[] = {
    "LxLibrary\0\0QVariant\0dllPath\0load(QString)\0"
    "functionName,param,encode\0"
    "exec(QString,QVariant,QString)\0"
    "functionName,param\0exec(QString,QVariant)\0"
    "unload()\0"
};

void LxLibrary::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LxLibrary *_t = static_cast<LxLibrary *>(_o);
        switch (_id) {
        case 0: { QVariant _r = _t->load((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 1: { QVariant _r = _t->exec((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 2: { QVariant _r = _t->exec((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 3: { QVariant _r = _t->unload();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LxLibrary::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LxLibrary::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxLibrary,
      qt_meta_data_LxLibrary, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxLibrary::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxLibrary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxLibrary::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxLibrary))
        return static_cast<void*>(const_cast< LxLibrary*>(this));
    return QObject::qt_metacast(_clname);
}

int LxLibrary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
