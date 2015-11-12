/****************************************************************************
** Meta object code from reading C++ file 'lxoption.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxoption.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxoption.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LxOption_t {
    QByteArrayData data[21];
    char stringdata0[410];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LxOption_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LxOption_t qt_meta_stringdata_LxOption = {
    {
QT_MOC_LITERAL(0, 0, 8), // "LxOption"
QT_MOC_LITERAL(1, 9, 24), // "getStartResourceFileName"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 11), // "getStartUrl"
QT_MOC_LITERAL(4, 47, 10), // "getAppPath"
QT_MOC_LITERAL(5, 58, 16), // "getCoreAppOption"
QT_MOC_LITERAL(6, 75, 12), // "getConfgPath"
QT_MOC_LITERAL(7, 88, 12), // "getMainTitle"
QT_MOC_LITERAL(8, 101, 22), // "getNeedShowMainNcFrame"
QT_MOC_LITERAL(9, 124, 23), // "getNeedShowChildNcFrame"
QT_MOC_LITERAL(10, 148, 27), // "getMainWindowStaysOnTopHint"
QT_MOC_LITERAL(11, 176, 28), // "getChildWindowStaysOnTopHint"
QT_MOC_LITERAL(12, 205, 22), // "getDialogsRelationShip"
QT_MOC_LITERAL(13, 228, 17), // "getNeedSystemTray"
QT_MOC_LITERAL(14, 246, 21), // "getSystemTrayIconName"
QT_MOC_LITERAL(15, 268, 17), // "getCookieFilePath"
QT_MOC_LITERAL(16, 286, 30), // "getLoadHrefInCurrentMainDialog"
QT_MOC_LITERAL(17, 317, 31), // "getLoadHrefInCurrentChildDialog"
QT_MOC_LITERAL(18, 349, 21), // "getNeedShowLoadingGif"
QT_MOC_LITERAL(19, 371, 18), // "getLoadingGifWidth"
QT_MOC_LITERAL(20, 390, 19) // "getLoadingGifHeight"

    },
    "LxOption\0getStartResourceFileName\0\0"
    "getStartUrl\0getAppPath\0getCoreAppOption\0"
    "getConfgPath\0getMainTitle\0"
    "getNeedShowMainNcFrame\0getNeedShowChildNcFrame\0"
    "getMainWindowStaysOnTopHint\0"
    "getChildWindowStaysOnTopHint\0"
    "getDialogsRelationShip\0getNeedSystemTray\0"
    "getSystemTrayIconName\0getCookieFilePath\0"
    "getLoadHrefInCurrentMainDialog\0"
    "getLoadHrefInCurrentChildDialog\0"
    "getNeedShowLoadingGif\0getLoadingGifWidth\0"
    "getLoadingGifHeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LxOption[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x0a /* Public */,
       3,    0,  110,    2, 0x0a /* Public */,
       4,    0,  111,    2, 0x0a /* Public */,
       5,    0,  112,    2, 0x0a /* Public */,
       6,    0,  113,    2, 0x0a /* Public */,
       7,    0,  114,    2, 0x0a /* Public */,
       8,    0,  115,    2, 0x0a /* Public */,
       9,    0,  116,    2, 0x0a /* Public */,
      10,    0,  117,    2, 0x0a /* Public */,
      11,    0,  118,    2, 0x0a /* Public */,
      12,    0,  119,    2, 0x0a /* Public */,
      13,    0,  120,    2, 0x0a /* Public */,
      14,    0,  121,    2, 0x0a /* Public */,
      15,    0,  122,    2, 0x0a /* Public */,
      16,    0,  123,    2, 0x0a /* Public */,
      17,    0,  124,    2, 0x0a /* Public */,
      18,    0,  125,    2, 0x0a /* Public */,
      19,    0,  126,    2, 0x0a /* Public */,
      20,    0,  127,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QObjectStar,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void LxOption::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LxOption *_t = static_cast<LxOption *>(_o);
        Q_UNUSED(_t)
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
        case 9: { bool _r = _t->getChildWindowStaysOnTopHint();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->getDialogsRelationShip();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->getNeedSystemTray();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { QString _r = _t->getSystemTrayIconName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: { QString _r = _t->getCookieFilePath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: { bool _r = _t->getLoadHrefInCurrentMainDialog();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: { bool _r = _t->getLoadHrefInCurrentChildDialog();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: { bool _r = _t->getNeedShowLoadingGif();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: { int _r = _t->getLoadingGifWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 18: { int _r = _t->getLoadingGifHeight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject LxOption::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxOption.data,
      qt_meta_data_LxOption,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LxOption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LxOption::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LxOption.stringdata0))
        return static_cast<void*>(const_cast< LxOption*>(this));
    return QObject::qt_metacast(_clname);
}

int LxOption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
