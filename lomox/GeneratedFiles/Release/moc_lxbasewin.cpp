/****************************************************************************
** Meta object code from reading C++ file 'lxbasewin.h'
**
** Created: Tue Mar 11 14:33:39 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxbasewin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxbasewin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxBaseWin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LxBaseWin[] = {
    "LxBaseWin\0\0url\0linkClickedAction(QUrl)\0"
};

void LxBaseWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LxBaseWin *_t = static_cast<LxBaseWin *>(_o);
        switch (_id) {
        case 0: _t->linkClickedAction((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LxBaseWin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LxBaseWin::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_LxBaseWin,
      qt_meta_data_LxBaseWin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxBaseWin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxBaseWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxBaseWin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxBaseWin))
        return static_cast<void*>(const_cast< LxBaseWin*>(this));
    return QWebView::qt_metacast(_clname);
}

int LxBaseWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
