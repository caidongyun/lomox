/****************************************************************************
** Meta object code from reading C++ file 'lxlibrary.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxlibrary.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxlibrary.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LxLibrary_t {
    QByteArrayData data[9];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LxLibrary_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LxLibrary_t qt_meta_stringdata_LxLibrary = {
    {
QT_MOC_LITERAL(0, 0, 9), // "LxLibrary"
QT_MOC_LITERAL(1, 10, 4), // "load"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 7), // "dllPath"
QT_MOC_LITERAL(4, 24, 4), // "exec"
QT_MOC_LITERAL(5, 29, 12), // "functionName"
QT_MOC_LITERAL(6, 42, 5), // "param"
QT_MOC_LITERAL(7, 48, 6), // "encode"
QT_MOC_LITERAL(8, 55, 6) // "unload"

    },
    "LxLibrary\0load\0\0dllPath\0exec\0functionName\0"
    "param\0encode\0unload"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LxLibrary[] = {

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
       4,    3,   37,    2, 0x0a /* Public */,
       4,    2,   44,    2, 0x2a /* Public | MethodCloned */,
       8,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QVariant, QMetaType::QString,    3,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QVariant, QMetaType::QString,    5,    6,    7,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QVariant,    5,    6,
    QMetaType::QVariant,

       0        // eod
};

void LxLibrary::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LxLibrary *_t = static_cast<LxLibrary *>(_o);
        Q_UNUSED(_t)
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

const QMetaObject LxLibrary::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxLibrary.data,
      qt_meta_data_LxLibrary,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LxLibrary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LxLibrary::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LxLibrary.stringdata0))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
