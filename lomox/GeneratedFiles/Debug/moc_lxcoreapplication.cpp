/****************************************************************************
** Meta object code from reading C++ file 'lxcoreapplication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxcoreapplication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxcoreapplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LxCoreApplication_t {
    QByteArrayData data[19];
    char stringdata[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LxCoreApplication_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LxCoreApplication_t qt_meta_stringdata_LxCoreApplication = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 10),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 6),
QT_MOC_LITERAL(4, 37, 7),
QT_MOC_LITERAL(5, 45, 6),
QT_MOC_LITERAL(6, 52, 12),
QT_MOC_LITERAL(7, 65, 10),
QT_MOC_LITERAL(8, 76, 10),
QT_MOC_LITERAL(9, 87, 17),
QT_MOC_LITERAL(10, 105, 11),
QT_MOC_LITERAL(11, 117, 4),
QT_MOC_LITERAL(12, 122, 7),
QT_MOC_LITERAL(13, 130, 4),
QT_MOC_LITERAL(14, 135, 3),
QT_MOC_LITERAL(15, 139, 7),
QT_MOC_LITERAL(16, 147, 4),
QT_MOC_LITERAL(17, 152, 7),
QT_MOC_LITERAL(18, 160, 3)
    },
    "LxCoreApplication\0getDialogs\0\0getLib\0"
    "getFile\0getDir\0getArguments\0getVersion\0"
    "getAppPath\0clearMemoryCaches\0getHttpTool\0"
    "libs\0dialogs\0file\0dir\0appPath\0args\0"
    "version\0net\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LxCoreApplication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       8,   68, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08,
       3,    0,   60,    2, 0x08,
       4,    0,   61,    2, 0x08,
       5,    0,   62,    2, 0x08,
       6,    0,   63,    2, 0x08,
       7,    0,   64,    2, 0x08,
       8,    0,   65,    2, 0x08,
       9,    0,   66,    2, 0x08,
      10,    0,   67,    2, 0x08,

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

 // properties: name, type, flags
      11, QMetaType::QObjectStar, 0x00095001,
      12, QMetaType::QObjectStar, 0x00095001,
      13, QMetaType::QObjectStar, 0x00095001,
      14, QMetaType::QObjectStar, 0x00095001,
      15, QMetaType::QVariant, 0x00095001,
      16, QMetaType::QVariant, 0x00095001,
      17, QMetaType::QVariant, 0x00095001,
      18, QMetaType::QObjectStar, 0x00095001,

       0        // eod
};

void LxCoreApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LxCoreApplication *_t = static_cast<LxCoreApplication *>(_o);
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
        default: ;
        }
    }
}

const QMetaObject LxCoreApplication::staticMetaObject = {
    { &LxOperate::staticMetaObject, qt_meta_stringdata_LxCoreApplication.data,
      qt_meta_data_LxCoreApplication,  qt_static_metacall, 0, 0}
};


const QMetaObject *LxCoreApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LxCoreApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxCoreApplication.stringdata))
        return static_cast<void*>(const_cast< LxCoreApplication*>(this));
    return LxOperate::qt_metacast(_clname);
}

int LxCoreApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LxOperate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QObject**>(_v) = getLib(); break;
        case 1: *reinterpret_cast< QObject**>(_v) = getDialogs(); break;
        case 2: *reinterpret_cast< QObject**>(_v) = getFile(); break;
        case 3: *reinterpret_cast< QObject**>(_v) = getDir(); break;
        case 4: *reinterpret_cast< QVariant*>(_v) = getAppPath(); break;
        case 5: *reinterpret_cast< QVariant*>(_v) = getArguments(); break;
        case 6: *reinterpret_cast< QVariant*>(_v) = getVersion(); break;
        case 7: *reinterpret_cast< QObject**>(_v) = getHttpTool(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
