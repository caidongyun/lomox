/****************************************************************************
** Meta object code from reading C++ file 'lxdir.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxdir.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxdir.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LxDir_t {
    QByteArrayData data[13];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LxDir_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LxDir_t qt_meta_stringdata_LxDir = {
    {
QT_MOC_LITERAL(0, 0, 5), // "LxDir"
QT_MOC_LITERAL(1, 6, 6), // "exists"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 4), // "name"
QT_MOC_LITERAL(4, 19, 6), // "encode"
QT_MOC_LITERAL(5, 26, 5), // "mkdir"
QT_MOC_LITERAL(6, 32, 7), // "dirName"
QT_MOC_LITERAL(7, 40, 6), // "mkpath"
QT_MOC_LITERAL(8, 47, 7), // "dirPath"
QT_MOC_LITERAL(9, 55, 9), // "entryList"
QT_MOC_LITERAL(10, 65, 11), // "nameFilters"
QT_MOC_LITERAL(11, 77, 7), // "filters"
QT_MOC_LITERAL(12, 85, 4) // "sort"

    },
    "LxDir\0exists\0\0name\0encode\0mkdir\0dirName\0"
    "mkpath\0dirPath\0entryList\0nameFilters\0"
    "filters\0sort"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LxDir[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x0a /* Public */,
       1,    1,   69,    2, 0x2a /* Public | MethodCloned */,
       5,    2,   72,    2, 0x0a /* Public */,
       5,    1,   77,    2, 0x2a /* Public | MethodCloned */,
       7,    2,   80,    2, 0x0a /* Public */,
       7,    1,   85,    2, 0x2a /* Public | MethodCloned */,
       9,    5,   88,    2, 0x0a /* Public */,
       9,    4,   99,    2, 0x2a /* Public | MethodCloned */,
       9,    3,  108,    2, 0x2a /* Public | MethodCloned */,
       9,    2,  115,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QString,    3,    4,
    QMetaType::QVariant, QMetaType::QVariant,    3,
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QString,    6,    4,
    QMetaType::QVariant, QMetaType::QVariant,    6,
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QString,    8,    4,
    QMetaType::QVariant, QMetaType::QVariant,    8,
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QString,    8,   10,   11,   12,    4,
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,    8,   10,   11,   12,
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,    8,   10,   11,
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,    8,   10,

       0        // eod
};

void LxDir::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LxDir *_t = static_cast<LxDir *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariant _r = _t->exists((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 1: { QVariant _r = _t->exists((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 2: { QVariant _r = _t->mkdir((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 3: { QVariant _r = _t->mkdir((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 4: { QVariant _r = _t->mkpath((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 5: { QVariant _r = _t->mkpath((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 6: { QVariant _r = _t->entryList((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 7: { QVariant _r = _t->entryList((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 8: { QVariant _r = _t->entryList((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 9: { QVariant _r = _t->entryList((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject LxDir::staticMetaObject = {
    { &LxOperate::staticMetaObject, qt_meta_stringdata_LxDir.data,
      qt_meta_data_LxDir,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LxDir::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LxDir::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LxDir.stringdata0))
        return static_cast<void*>(const_cast< LxDir*>(this));
    return LxOperate::qt_metacast(_clname);
}

int LxDir::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LxOperate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
