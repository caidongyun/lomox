/****************************************************************************
** Meta object code from reading C++ file 'lxlibmanager.h'
**
** Created: Sat Nov 9 19:14:38 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxlibmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxlibmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxLibManager[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   13,   14,   13, 0x0a,
      55,   40,   31,   13, 0x0a,
      83,   76,   14,   13, 0x0a,
      99,   76,   31,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LxLibManager[] = {
    "LxLibManager\0\0QVariant\0count()\0QObject*\0"
    "dllKey,dllPath\0add(QString,QString)\0"
    "dllKey\0remove(QString)\0get(QString)\0"
};

const QMetaObject LxLibManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxLibManager,
      qt_meta_data_LxLibManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxLibManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxLibManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxLibManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxLibManager))
        return static_cast<void*>(const_cast< LxLibManager*>(this));
    return QObject::qt_metacast(_clname);
}

int LxLibManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QVariant _r = count();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 1: { QObject* _r = add((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 2: { QVariant _r = remove((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 3: { QObject* _r = get((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
