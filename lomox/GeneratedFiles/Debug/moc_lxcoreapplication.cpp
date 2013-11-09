/****************************************************************************
** Meta object code from reading C++ file 'lxcoreapplication.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxcoreapplication.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxcoreapplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxCoreApplication[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       9,   64, // properties
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
     153,   18,   19,   18, 0x08,

 // properties: name, type, flags
     168,   19, 0x88095001,
     173,   19, 0x88095001,
     181,   19, 0x88095001,
     186,   19, 0x88095001,
     190,   69, 0xff095001,
     198,   69, 0xff095001,
     203,   69, 0xff095001,
     211,   19, 0x88095001,
     215,   19, 0x88095001,

       0        // eod
};

static const char qt_meta_stringdata_LxCoreApplication[] = {
    "LxCoreApplication\0\0QObject*\0getDialogs()\0"
    "getLib()\0getFile()\0getDir()\0QVariant\0"
    "getArguments()\0getVersion()\0getAppPath()\0"
    "clearMemoryCaches()\0getHttpTool()\0"
    "getResources()\0libs\0dialogs\0file\0dir\0"
    "appPath\0args\0version\0net\0res\0"
};

void LxCoreApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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
        case 9: { QObject* _r = _t->getResources();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LxCoreApplication::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LxCoreApplication::staticMetaObject = {
    { &LxOperate::staticMetaObject, qt_meta_stringdata_LxCoreApplication,
      qt_meta_data_LxCoreApplication, &staticMetaObjectExtraData }
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
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
        case 8: *reinterpret_cast< QObject**>(_v) = getResources(); break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 9;
    } else if (_c == QMetaObject::ResetProperty) {
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
