/****************************************************************************
** Meta object code from reading C++ file 'lxresources.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/lxresources.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxresources.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxResources[] = {

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
      30,   18,   13,   12, 0x0a,
      56,   18,   13,   12, 0x0a,
     109,   84,   13,   12, 0x0a,
     151,   84,   13,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LxResources[] = {
    "LxResources\0\0bool\0rccFilename\0"
    "registerResource(QString)\0"
    "unregisterResource(QString)\0"
    "rccFilename,resourceRoot\0"
    "registerResourceFromRoot(QString,QString)\0"
    "unregisterResourceFromRoot(QString,QString)\0"
};

void LxResources::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LxResources *_t = static_cast<LxResources *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->registerResource((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->unregisterResource((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->registerResourceFromRoot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->unregisterResourceFromRoot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LxResources::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LxResources::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxResources,
      qt_meta_data_LxResources, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxResources::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxResources::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxResources::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxResources))
        return static_cast<void*>(const_cast< LxResources*>(this));
    return QObject::qt_metacast(_clname);
}

int LxResources::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
