/****************************************************************************
** Meta object code from reading C++ file 'lxHttp.h'
**
** Created: Tue Apr 22 11:41:18 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/lxHttp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxHttp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxHttp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      46,   17,    8,    7, 0x0a,
     125,   86,    8,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LxHttp[] = {
    "LxHttp\0\0QVariant\0varMethod,varUrl,varPostData\0"
    "httpRequest(QVariant,QVariant,QVariant)\0"
    "varMethod,varUrl,varPostData,varEncode\0"
    "httpRequestWithEncode(QVariant,QVariant,QVariant,QVariant)\0"
};

void LxHttp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LxHttp *_t = static_cast<LxHttp *>(_o);
        switch (_id) {
        case 0: { QVariant _r = _t->httpRequest((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 1: { QVariant _r = _t->httpRequestWithEncode((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LxHttp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LxHttp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxHttp,
      qt_meta_data_LxHttp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxHttp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxHttp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxHttp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxHttp))
        return static_cast<void*>(const_cast< LxHttp*>(this));
    return QObject::qt_metacast(_clname);
}

int LxHttp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
