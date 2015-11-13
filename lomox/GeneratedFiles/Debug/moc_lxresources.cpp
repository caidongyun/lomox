/****************************************************************************
** Meta object code from reading C++ file 'lxresources.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/lxresources.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxresources.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LxResources_t {
    QByteArrayData data[8];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LxResources_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LxResources_t qt_meta_stringdata_LxResources = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LxResources"
QT_MOC_LITERAL(1, 12, 16), // "registerResource"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "rccFilename"
QT_MOC_LITERAL(4, 42, 18), // "unregisterResource"
QT_MOC_LITERAL(5, 61, 24), // "registerResourceFromRoot"
QT_MOC_LITERAL(6, 86, 12), // "resourceRoot"
QT_MOC_LITERAL(7, 99, 26) // "unregisterResourceFromRoot"

    },
    "LxResources\0registerResource\0\0rccFilename\0"
    "unregisterResource\0registerResourceFromRoot\0"
    "resourceRoot\0unregisterResourceFromRoot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LxResources[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       5,    2,   40,    2, 0x0a /* Public */,
       7,    2,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    3,    6,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    3,    6,

       0        // eod
};

void LxResources::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LxResources *_t = static_cast<LxResources *>(_o);
        Q_UNUSED(_t)
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

const QMetaObject LxResources::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxResources.data,
      qt_meta_data_LxResources,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LxResources::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LxResources::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LxResources.stringdata0))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
