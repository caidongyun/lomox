/****************************************************************************
** Meta object code from reading C++ file 'lxdialogoperate.h'
**
** Created: Sat Nov 9 19:14:23 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxdialogoperate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxdialogoperate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxDialogBase[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      25,   21,   13,   13, 0x0a,
      39,   13,   13,   13, 0x0a,
      55,   13,   13,   13, 0x0a,
      71,   13,   13,   13, 0x0a,
      79,   13,   13,   13, 0x0a,
      97,   13,   92,   13, 0x0a,
     111,   13,   92,   13, 0x0a,
     125,   13,   92,   13, 0x0a,
     144,   13,  140,   13, 0x0a,
     159,   13,  140,   13, 0x0a,
     175,   13,  140,   13, 0x0a,
     190,   13,  140,   13, 0x0a,
     216,  206,   13,   13, 0x0a,
     250,  240,   13,   13, 0x0a,
     279,  274,   13,   13, 0x0a,
     305,  300,   13,   13, 0x0a,
     332,  327,   13,   13, 0x0a,
     358,  353,   13,   13, 0x0a,
     380,   13,   13,   13, 0x0a,
     400,  387,   13,   13, 0x0a,
     431,   13,   13,   13, 0x0a,
     444,  440,   13,   13, 0x0a,
     462,   13,  140,   13, 0x0a,
     476,   13,  140,   13, 0x0a,
     497,  490,   13,   13, 0x0a,
     521,  513,   13,   13, 0x0a,
     545,  538,   13,   13, 0x0a,
     575,  570,  561,   13, 0x0a,
     590,   13,  561,   13, 0x0a,
     599,  570,   13,   13, 0x0a,
     626,   13,  617,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LxDialogBase[] = {
    "LxDialogBase\0\0move()\0x,y\0move(int,int)\0"
    "showMinimized()\0showMaximized()\0close()\0"
    "showNormal()\0bool\0isMinimized()\0"
    "isMaximized()\0isFullScreen()\0int\0"
    "minimumWidth()\0minimumHeight()\0"
    "maximumWidth()\0maximumHeight()\0minw,minh\0"
    "setMinimumSize(int,int)\0maxw,maxh\0"
    "setMaximumSize(int,int)\0minw\0"
    "setMinimumWidth(int)\0minh\0"
    "setMinimumHeight(int)\0maxw\0"
    "setMaximumWidth(int)\0maxh\0"
    "setMaximumHeight(int)\0show()\0Weight,Hight\0"
    "setDialogWH(QVariant,QVariant)\0reload()\0"
    "url\0openUrl(QVariant)\0getTopLeftX()\0"
    "getTopLeftY()\0strUrl\0setUrl(QString)\0"
    "visible\0setVisible(bool)\0hidden\0"
    "setHidden(bool)\0QVariant\0code\0"
    "eval(QVariant)\0toHTML()\0setHTML(QVariant)\0"
    "QObject*\0getCoreDialog()\0"
};

const QMetaObject LxDialogBase::staticMetaObject = {
    { &LxOperate::staticMetaObject, qt_meta_stringdata_LxDialogBase,
      qt_meta_data_LxDialogBase, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxDialogBase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxDialogBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxDialogBase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxDialogBase))
        return static_cast<void*>(const_cast< LxDialogBase*>(this));
    return LxOperate::qt_metacast(_clname);
}

int LxDialogBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LxOperate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: move(); break;
        case 1: move((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: showMinimized(); break;
        case 3: showMaximized(); break;
        case 4: close(); break;
        case 5: showNormal(); break;
        case 6: { bool _r = isMinimized();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = isMaximized();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = isFullScreen();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { int _r = minimumWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = minimumHeight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { int _r = maximumWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: { int _r = maximumHeight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: setMinimumSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: setMaximumSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: setMinimumWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: setMinimumHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: setMaximumWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: setMaximumHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: show(); break;
        case 20: setDialogWH((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        case 21: reload(); break;
        case 22: openUrl((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 23: { int _r = getTopLeftX();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 24: { int _r = getTopLeftY();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 25: setUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: setVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: setHidden((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: { QVariant _r = eval((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 29: { QVariant _r = toHTML();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 30: setHTML((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 31: { QObject* _r = getCoreDialog();
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
