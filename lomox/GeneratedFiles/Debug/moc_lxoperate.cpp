/****************************************************************************
** Meta object code from reading C++ file 'lxoperate.h'
**
** Created: Sat Nov 9 18:52:45 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxoperate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxoperate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxOperate[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,   11,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LxOperate[] = {
    "LxOperate\0\0bool\0setupJsAPIObject()\0"
};

const QMetaObject LxOperate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxOperate,
      qt_meta_data_LxOperate, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxOperate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxOperate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxOperate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxOperate))
        return static_cast<void*>(const_cast< LxOperate*>(this));
    return QObject::qt_metacast(_clname);
}

int LxOperate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = setupJsAPIObject();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
