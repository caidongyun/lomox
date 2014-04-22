/****************************************************************************
** Meta object code from reading C++ file 'lxoption.h'
**
** Created: Tue Apr 22 11:41:16 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxoption.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxoption.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxOption[] = {

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
      18,    9,   10,    9, 0x0a,
      45,    9,   10,    9, 0x0a,
      59,    9,   10,    9, 0x0a,
      81,    9,   72,    9, 0x0a,
     100,    9,   10,    9, 0x0a,
     115,    9,   10,    9, 0x0a,
     135,    9,  130,    9, 0x0a,
     160,    9,  130,    9, 0x0a,
     186,    9,  130,    9, 0x0a,
     216,    9,   10,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LxOption[] = {
    "LxOption\0\0QString\0getStartResourceFileName()\0"
    "getStartUrl()\0getAppPath()\0QObject*\0"
    "getCoreAppOption()\0getConfgPath()\0"
    "getMainTitle()\0bool\0getNeedShowMainNcFrame()\0"
    "getNeedShowChildNcFrame()\0"
    "getMainWindowStaysOnTopHint()\0"
    "getCookieFilePath()\0"
};

void LxOption::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LxOption *_t = static_cast<LxOption *>(_o);
        switch (_id) {
        case 0: { QString _r = _t->getStartResourceFileName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: { QString _r = _t->getStartUrl();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: { QString _r = _t->getAppPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { QObject* _r = _t->getCoreAppOption();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->getConfgPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->getMainTitle();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->getNeedShowMainNcFrame();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->getNeedShowChildNcFrame();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->getMainWindowStaysOnTopHint();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { QString _r = _t->getCookieFilePath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LxOption::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LxOption::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxOption,
      qt_meta_data_LxOption, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxOption::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxOption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxOption::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxOption))
        return static_cast<void*>(const_cast< LxOption*>(this));
    return QObject::qt_metacast(_clname);
}

int LxOption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
