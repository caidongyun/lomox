/****************************************************************************
** Meta object code from reading C++ file 'lxwebeditplugin.h'
**
** Created: Thu Feb 28 19:28:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lxwebeditplugin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lxwebeditplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LxWebEditPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_LxWebEditPlugin[] = {
    "LxWebEditPlugin\0"
};

void LxWebEditPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LxWebEditPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LxWebEditPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LxWebEditPlugin,
      qt_meta_data_LxWebEditPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LxWebEditPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LxWebEditPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LxWebEditPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LxWebEditPlugin))
        return static_cast<void*>(const_cast< LxWebEditPlugin*>(this));
    if (!strcmp(_clname, "LxWebKitPluginInterface"))
        return static_cast< LxWebKitPluginInterface*>(const_cast< LxWebEditPlugin*>(this));
    if (!strcmp(_clname, "LomoXTeam/1.0"))
        return static_cast< LxWebKitPluginInterface*>(const_cast< LxWebEditPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int LxWebEditPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_MyAddEdit[] = {

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
      21,   15,   11,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyAddEdit[] = {
    "MyAddEdit\0\0int\0a,b,c\0AddNum(int,int,int)\0"
};

void MyAddEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyAddEdit *_t = static_cast<MyAddEdit *>(_o);
        switch (_id) {
        case 0: { int _r = _t->AddNum((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyAddEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyAddEdit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_MyAddEdit,
      qt_meta_data_MyAddEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyAddEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyAddEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyAddEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyAddEdit))
        return static_cast<void*>(const_cast< MyAddEdit*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int MyAddEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
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
