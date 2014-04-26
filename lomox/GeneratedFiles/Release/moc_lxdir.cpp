/****************************************************************************
** Meta object code from reading C++ file 'lxdir.h'
**
** Created: Sat Apr 26 16:10:00 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxdir.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxdir.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxDir[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   16,    7,    6, 0x0a,
      58,   53,    7,    6, 0x2a,
      90,   75,    7,    6, 0x0a,
     122,  114,    7,    6, 0x2a,
     153,  138,    7,    6, 0x0a,
     186,  178,    7,    6, 0x2a,
     243,  203,    7,    6, 0x0a,
     331,  298,    7,    6, 0x2a,
     406,  378,    7,    6, 0x2a,
     464,  444,    7,    6, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_LxDir[] = {
    "LxDir\0\0QVariant\0name,encode\0"
    "exists(QVariant,QString)\0name\0"
    "exists(QVariant)\0dirName,encode\0"
    "mkdir(QVariant,QString)\0dirName\0"
    "mkdir(QVariant)\0dirPath,encode\0"
    "mkpath(QVariant,QString)\0dirPath\0"
    "mkpath(QVariant)\0"
    "dirPath,nameFilters,filters,sort,encode\0"
    "entryList(QVariant,QVariant,QVariant,QVariant,QString)\0"
    "dirPath,nameFilters,filters,sort\0"
    "entryList(QVariant,QVariant,QVariant,QVariant)\0"
    "dirPath,nameFilters,filters\0"
    "entryList(QVariant,QVariant,QVariant)\0"
    "dirPath,nameFilters\0entryList(QVariant,QVariant)\0"
};

void LxDir::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LxDir *_t = static_cast<LxDir *>(_o);
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

const QMetaObjectExtraData LxDir::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LxDir::staticMetaObject = {
    { &LxOperate::staticMetaObject, qt_meta_stringdata_LxDir,
      qt_meta_data_LxDir, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxDir::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxDir::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxDir::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxDir))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
