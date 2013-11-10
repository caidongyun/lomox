/****************************************************************************
** Meta object code from reading C++ file 'lxlibmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxlibmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxlibmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LxLibManager_t {
    QByteArrayData data[8];
    char stringdata[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LxLibManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LxLibManager_t qt_meta_stringdata_LxLibManager = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 5),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 3),
QT_MOC_LITERAL(4, 24, 6),
QT_MOC_LITERAL(5, 31, 7),
QT_MOC_LITERAL(6, 39, 6),
QT_MOC_LITERAL(7, 46, 3)
    },
    "LxLibManager\0count\0\0add\0dllKey\0dllPath\0"
    "remove\0get\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LxLibManager[] = {

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
       1,    0,   34,    2, 0x0a,
       3,    2,   35,    2, 0x0a,
       6,    1,   40,    2, 0x0a,
       7,    1,   43,    2, 0x0a,

 // slots: parameters
    QMetaType::QVariant,
    QMetaType::QObjectStar, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::QVariant, QMetaType::QString,    4,
    QMetaType::QObjectStar, QMetaType::QString,    4,

       0        // eod
};

void LxLibManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LxLibManager *_t = static_cast<LxLibManager *>(_o);
        switch (_id) {
        case 0: { QVariant _r = _t->count();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 1: { QObject* _r = _t->add((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 2: { QVariant _r = _t->remove((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 3: { QObject* _r = _t->get((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject LxLibManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxLibManager.data,
      qt_meta_data_LxLibManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *LxLibManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LxLibManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxLibManager.stringdata))
        return static_cast<void*>(const_cast< LxLibManager*>(this));
    return QObject::qt_metacast(_clname);
}

int LxLibManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
