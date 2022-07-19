/****************************************************************************
** Meta object code from reading C++ file 'tab4onoff.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tab4onoff.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tab4onoff.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Tab4OnOff_t {
    QByteArrayData data[6];
    char stringdata[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Tab4OnOff_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Tab4OnOff_t qt_meta_stringdata_Tab4OnOff = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 17),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 12),
QT_MOC_LITERAL(4, 42, 12),
QT_MOC_LITERAL(5, 55, 16)
    },
    "Tab4OnOff\0sigSocketSendData\0\0slotOneOnOff\0"
    "slotTwoOnOff\0slotTab4RecvData\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tab4OnOff[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   37,    2, 0x08,
       4,    1,   40,    2, 0x08,
       5,    1,   43,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void Tab4OnOff::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tab4OnOff *_t = static_cast<Tab4OnOff *>(_o);
        switch (_id) {
        case 0: _t->sigSocketSendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotOneOnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->slotTwoOnOff((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->slotTab4RecvData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Tab4OnOff::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tab4OnOff::sigSocketSendData)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Tab4OnOff::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tab4OnOff.data,
      qt_meta_data_Tab4OnOff,  qt_static_metacall, 0, 0}
};


const QMetaObject *Tab4OnOff::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tab4OnOff::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tab4OnOff.stringdata))
        return static_cast<void*>(const_cast< Tab4OnOff*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tab4OnOff::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Tab4OnOff::sigSocketSendData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
