/****************************************************************************
** Meta object code from reading C++ file 'lxfile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxfile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxfile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LxFile_t {
    QByteArrayData data[19];
    char stringdata[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LxFile_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LxFile_t qt_meta_stringdata_LxFile = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 12),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 11),
QT_MOC_LITERAL(4, 33, 6),
QT_MOC_LITERAL(5, 40, 7),
QT_MOC_LITERAL(6, 48, 6),
QT_MOC_LITERAL(7, 55, 6),
QT_MOC_LITERAL(8, 62, 10),
QT_MOC_LITERAL(9, 73, 10),
QT_MOC_LITERAL(10, 84, 4),
QT_MOC_LITERAL(11, 89, 7),
QT_MOC_LITERAL(12, 97, 7),
QT_MOC_LITERAL(13, 105, 4),
QT_MOC_LITERAL(14, 110, 11),
QT_MOC_LITERAL(15, 122, 4),
QT_MOC_LITERAL(16, 127, 11),
QT_MOC_LITERAL(17, 139, 5),
QT_MOC_LITERAL(18, 145, 4)
    },
    "LxFile\0readFileData\0\0varFilename\0"
    "encode\0isExits\0remove\0rename\0varOldName\0"
    "varNewName\0link\0oldname\0newName\0copy\0"
    "varFileName\0size\0permissions\0write\0"
    "text\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LxFile[] = {

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
       1,    2,   64,    2, 0x0a,
       5,    1,   69,    2, 0x0a,
       6,    1,   72,    2, 0x0a,
       7,    2,   75,    2, 0x0a,
      10,    2,   80,    2, 0x0a,
      13,    2,   85,    2, 0x0a,
      15,    1,   90,    2, 0x0a,
      16,    1,   93,    2, 0x0a,
      17,    3,   96,    2, 0x0a,
      17,    2,  103,    2, 0x2a,

 // slots: parameters
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QString,    3,    4,
    QMetaType::QVariant, QMetaType::QVariant,    3,
    QMetaType::QVariant, QMetaType::QVariant,    3,
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,    8,    9,
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,   11,   12,
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,   14,    9,
    QMetaType::QVariant, QMetaType::QVariant,    3,
    QMetaType::QVariant, QMetaType::QVariant,    3,
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QString,    3,   18,    4,
    QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,    3,   18,

       0        // eod
};

void LxFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LxFile *_t = static_cast<LxFile *>(_o);
        switch (_id) {
        case 0: { QVariant _r = _t->readFileData((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 1: { QVariant _r = _t->isExits((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 2: { QVariant _r = _t->remove((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 3: { QVariant _r = _t->rename((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 4: { QVariant _r = _t->link((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 5: { QVariant _r = _t->copy((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 6: { QVariant _r = _t->size((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 7: { QVariant _r = _t->permissions((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 8: { QVariant _r = _t->write((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 9: { QVariant _r = _t->write((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject LxFile::staticMetaObject = {
    { &LxOperate::staticMetaObject, qt_meta_stringdata_LxFile.data,
      qt_meta_data_LxFile,  qt_static_metacall, 0, 0}
};


const QMetaObject *LxFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LxFile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxFile.stringdata))
        return static_cast<void*>(const_cast< LxFile*>(this));
    return LxOperate::qt_metacast(_clname);
}

int LxFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
