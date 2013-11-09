/****************************************************************************
** Meta object code from reading C++ file 'lxcoreapplication.h'
**
** Created: Sat Nov 9 18:52:17 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxcoreapplication.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxcoreapplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxCoreApplication[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       8,   59, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   18,   19,   18, 0x08,
      41,   18,   19,   18, 0x08,
      50,   18,   19,   18, 0x08,
      60,   18,   19,   18, 0x08,
      78,   18,   69,   18, 0x08,
      93,   18,   69,   18, 0x08,
     106,   18,   69,   18, 0x08,
     119,   18,   18,   18, 0x08,
     139,   18,   19,   18, 0x08,

 // properties: name, type, flags
     153,   19, 0x88095001,
     158,   19, 0x88095001,
     166,   19, 0x88095001,
     171,   19, 0x88095001,
     175,   69, 0xff095001,
     183,   69, 0xff095001,
     188,   69, 0xff095001,
     196,   19, 0x88095001,

       0        // eod
};

static const char qt_meta_stringdata_LxCoreApplication[] = {
    "LxCoreApplication\0\0QObject*\0getDialogs()\0"
    "getLib()\0getFile()\0getDir()\0QVariant\0"
    "getArguments()\0getVersion()\0getAppPath()\0"
    "clearMemoryCaches()\0getHttpTool()\0"
    "libs\0dialogs\0file\0dir\0appPath\0args\0"
    "version\0net\0"
};

const QMetaObject LxCoreApplication::staticMetaObject = {
    { &LxOperate::staticMetaObject, qt_meta_stringdata_LxCoreApplication,
      qt_meta_data_LxCoreApplication, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxCoreApplication::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxCoreApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxCoreApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxCoreApplication))
        return static_cast<void*>(const_cast< LxCoreApplication*>(this));
    return LxOperate::qt_metacast(_clname);
}

int LxCoreApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LxOperate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QObject* _r = getDialogs();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 1: { QObject* _r = getLib();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 2: { QObject* _r = getFile();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 3: { QObject* _r = getDir();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 4: { QVariant _r = getArguments();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 5: { QVariant _r = getVersion();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 6: { QVariant _r = getAppPath();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 7: clearMemoryCaches(); break;
        case 8: { QObject* _r = getHttpTool();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        default: ;
        }
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
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
