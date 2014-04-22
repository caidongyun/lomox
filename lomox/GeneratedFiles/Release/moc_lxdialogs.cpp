/****************************************************************************
** Meta object code from reading C++ file 'lxdialogs.h'
**
** Created: Tue Apr 22 11:41:20 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxdialogs.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxdialogs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxDialogs[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   11,   10,   10, 0x0a,
      71,   64,   55,   10, 0x0a,
      93,   10,   84,   10, 0x0a,
     109,  101,   55,   10, 0x0a,
     134,  130,   84,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LxDialogs[] = {
    "LxDialogs\0\0key,pLxDialog\0"
    "append(QString,LxDialogBase*)\0QObject*\0"
    "varKey\0get(QString)\0QVariant\0count()\0"
    "key,url\0add(QString,QString)\0key\0"
    "remove(QString)\0"
};

void LxDialogs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LxDialogs *_t = static_cast<LxDialogs *>(_o);
        switch (_id) {
        case 0: _t->append((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< LxDialogBase*(*)>(_a[2]))); break;
        case 1: { QObject* _r = _t->get((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 2: { QVariant _r = _t->count();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 3: { QObject* _r = _t->add((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 4: { QVariant _r = _t->remove((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LxDialogs::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LxDialogs::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxDialogs,
      qt_meta_data_LxDialogs, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxDialogs::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxDialogs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxDialogs::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxDialogs))
        return static_cast<void*>(const_cast< LxDialogs*>(this));
    return QObject::qt_metacast(_clname);
}

int LxDialogs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
