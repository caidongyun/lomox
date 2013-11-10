/****************************************************************************
** Meta object code from reading C++ file 'lxdialogs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxdialogs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxdialogs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LxDialogs_t {
    QByteArrayData data[12];
    char stringdata[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LxDialogs_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LxDialogs_t qt_meta_stringdata_LxDialogs = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 6),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 3),
QT_MOC_LITERAL(4, 22, 13),
QT_MOC_LITERAL(5, 36, 9),
QT_MOC_LITERAL(6, 46, 3),
QT_MOC_LITERAL(7, 50, 6),
QT_MOC_LITERAL(8, 57, 5),
QT_MOC_LITERAL(9, 63, 3),
QT_MOC_LITERAL(10, 67, 3),
QT_MOC_LITERAL(11, 71, 6)
    },
    "LxDialogs\0append\0\0key\0LxDialogBase*\0"
    "pLxDialog\0get\0varKey\0count\0add\0url\0"
    "remove\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LxDialogs[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x0a,
       6,    1,   44,    2, 0x0a,
       8,    0,   47,    2, 0x0a,
       9,    2,   48,    2, 0x0a,
      11,    1,   53,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::QObjectStar, QMetaType::QString,    7,
    QMetaType::QVariant,
    QMetaType::QObjectStar, QMetaType::QString, QMetaType::QString,    3,   10,
    QMetaType::QVariant, QMetaType::QString,    3,

       0        // eod
};

void LxDialogs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LxDialogs *_t = static_cast<LxDialogs *>(_o);
        switch (_id) {
        case 0: _t->append((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< LxDialogBase*(*)>(_a[2]))); break;
        case 1: { QObject* _r = _t->get((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 2: { QVariant _r = _t->count();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 3: { QObject* _r = _t->add((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 4: { QVariant _r = _t->remove((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< LxDialogBase* >(); break;
            }
            break;
        }
    }
}

const QMetaObject LxDialogs::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxDialogs.data,
      qt_meta_data_LxDialogs,  qt_static_metacall, 0, 0}
};


const QMetaObject *LxDialogs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LxDialogs::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxDialogs.stringdata))
        return static_cast<void*>(const_cast< LxDialogs*>(this));
    return QObject::qt_metacast(_clname);
}

int LxDialogs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
