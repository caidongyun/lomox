/****************************************************************************
** Meta object code from reading C++ file 'lxcoreapplication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxcoreapplication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxcoreapplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LxCoreApplication_t {
    QByteArrayData data[24];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LxCoreApplication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LxCoreApplication_t qt_meta_stringdata_LxCoreApplication = {
    {
QT_MOC_LITERAL(0, 0, 17), // "LxCoreApplication"
QT_MOC_LITERAL(1, 18, 10), // "getDialogs"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "getLib"
QT_MOC_LITERAL(4, 37, 7), // "getFile"
QT_MOC_LITERAL(5, 45, 6), // "getDir"
QT_MOC_LITERAL(6, 52, 12), // "getArguments"
QT_MOC_LITERAL(7, 65, 10), // "getVersion"
QT_MOC_LITERAL(8, 76, 10), // "getAppPath"
QT_MOC_LITERAL(9, 87, 17), // "clearMemoryCaches"
QT_MOC_LITERAL(10, 105, 11), // "getHttpTool"
QT_MOC_LITERAL(11, 117, 12), // "getResources"
QT_MOC_LITERAL(12, 130, 7), // "execute"
QT_MOC_LITERAL(13, 138, 10), // "varProgram"
QT_MOC_LITERAL(14, 149, 12), // "varArguments"
QT_MOC_LITERAL(15, 162, 4), // "libs"
QT_MOC_LITERAL(16, 167, 7), // "dialogs"
QT_MOC_LITERAL(17, 175, 4), // "file"
QT_MOC_LITERAL(18, 180, 3), // "dir"
QT_MOC_LITERAL(19, 184, 7), // "appPath"
QT_MOC_LITERAL(20, 192, 4), // "args"
QT_MOC_LITERAL(21, 197, 7), // "version"
QT_MOC_LITERAL(22, 205, 3), // "net"
QT_MOC_LITERAL(23, 209, 3) // "res"

    },
    "LxCoreApplication\0getDialogs\0\0getLib\0"
    "getFile\0getDir\0getArguments\0getVersion\0"
    "getAppPath\0clearMemoryCaches\0getHttpTool\0"
    "getResources\0execute\0varProgram\0"
    "varArguments\0libs\0dialogs\0file\0dir\0"
    "appPath\0args\0version\0net\0res"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LxCoreApplication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       9,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    2,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QObjectStar,
    QMetaType::QObjectStar,
    QMetaType::QObjectStar,
    QMetaType::QObjectStar,
    QMetaType::QVariant,
    QMetaType::QVariant,
    QMetaType::QVariant,
    QMetaType::Void,
    QMetaType::QObjectStar,
    QMetaType::QObjectStar,
    QMetaType::Int, QMetaType::QVariant, QMetaType::QVariant,   13,   14,

 // properties: name, type, flags
      15, QMetaType::QObjectStar, 0x00095001,
      16, QMetaType::QObjectStar, 0x00095001,
      17, QMetaType::QObjectStar, 0x00095001,
      18, QMetaType::QObjectStar, 0x00095001,
      19, QMetaType::QVariant, 0x00095001,
      20, QMetaType::QVariant, 0x00095001,
      21, QMetaType::QVariant, 0x00095001,
      22, QMetaType::QObjectStar, 0x00095001,
      23, QMetaType::QObjectStar, 0x00095001,

       0        // eod
};

void LxCoreApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LxCoreApplication *_t = static_cast<LxCoreApplication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QObject* _r = _t->getDialogs();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 1: { QObject* _r = _t->getLib();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 2: { QObject* _r = _t->getFile();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 3: { QObject* _r = _t->getDir();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 4: { QVariant _r = _t->getArguments();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 5: { QVariant _r = _t->getVersion();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 6: { QVariant _r = _t->getAppPath();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 7: _t->clearMemoryCaches(); break;
        case 8: { QObject* _r = _t->getHttpTool();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 9: { QObject* _r = _t->getResources();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->execute((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        LxCoreApplication *_t = static_cast<LxCoreApplication *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QObject**>(_v) = _t->getLib(); break;
        case 1: *reinterpret_cast< QObject**>(_v) = _t->getDialogs(); break;
        case 2: *reinterpret_cast< QObject**>(_v) = _t->getFile(); break;
        case 3: *reinterpret_cast< QObject**>(_v) = _t->getDir(); break;
        case 4: *reinterpret_cast< QVariant*>(_v) = _t->getAppPath(); break;
        case 5: *reinterpret_cast< QVariant*>(_v) = _t->getArguments(); break;
        case 6: *reinterpret_cast< QVariant*>(_v) = _t->getVersion(); break;
        case 7: *reinterpret_cast< QObject**>(_v) = _t->getHttpTool(); break;
        case 8: *reinterpret_cast< QObject**>(_v) = _t->getResources(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject LxCoreApplication::staticMetaObject = {
    { &LxOperate::staticMetaObject, qt_meta_stringdata_LxCoreApplication.data,
      qt_meta_data_LxCoreApplication,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LxCoreApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LxCoreApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LxCoreApplication.stringdata0))
        return static_cast<void*>(const_cast< LxCoreApplication*>(this));
    return LxOperate::qt_metacast(_clname);
}

int LxCoreApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LxOperate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
