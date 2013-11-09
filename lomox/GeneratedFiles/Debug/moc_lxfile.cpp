/****************************************************************************
** Meta object code from reading C++ file 'lxfile.h'
**
** Created: Sat Nov 9 18:52:33 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxfile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxfile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxFile[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      36,   17,    8,    7, 0x0a,
      79,   67,    8,    7, 0x0a,
      97,   67,    8,    7, 0x0a,
     136,  114,    8,    7, 0x0a,
     178,  162,    8,    7, 0x0a,
     225,  202,    8,    7, 0x0a,
     249,   67,    8,    7, 0x0a,
     264,   67,    8,    7, 0x0a,
     310,  286,    8,    7, 0x0a,
     360,  343,    8,    7, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_LxFile[] = {
    "LxFile\0\0QVariant\0varFilename,encode\0"
    "readFileData(QVariant,QString)\0"
    "varFilename\0isExits(QVariant)\0"
    "remove(QVariant)\0varOldName,varNewName\0"
    "rename(QVariant,QVariant)\0oldname,newName\0"
    "link(QVariant,QVariant)\0varFileName,varNewName\0"
    "copy(QVariant,QVariant)\0size(QVariant)\0"
    "permissions(QVariant)\0varFilename,text,encode\0"
    "write(QVariant,QVariant,QString)\0"
    "varFilename,text\0write(QVariant,QVariant)\0"
};

const QMetaObject LxFile::staticMetaObject = {
    { &LxOperate::staticMetaObject, qt_meta_stringdata_LxFile,
      qt_meta_data_LxFile, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxFile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxFile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxFile))
        return static_cast<void*>(const_cast< LxFile*>(this));
    return LxOperate::qt_metacast(_clname);
}

int LxFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LxOperate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QVariant _r = readFileData((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 1: { QVariant _r = isExits((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 2: { QVariant _r = remove((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 3: { QVariant _r = rename((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 4: { QVariant _r = link((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 5: { QVariant _r = copy((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 6: { QVariant _r = size((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 7: { QVariant _r = permissions((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 8: { QVariant _r = write((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 9: { QVariant _r = write((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
