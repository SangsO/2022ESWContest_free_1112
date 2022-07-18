/****************************************************************************
** Meta object code from reading C++ file 'socketclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "socketclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socketclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SocketClient_t {
    QByteArrayData data[11];
    char stringdata[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SocketClient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SocketClient_t qt_meta_stringdata_SocketClient = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 13),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 17),
QT_MOC_LITERAL(4, 46, 18),
QT_MOC_LITERAL(5, 65, 15),
QT_MOC_LITERAL(6, 81, 17),
QT_MOC_LITERAL(7, 99, 19),
QT_MOC_LITERAL(8, 119, 5),
QT_MOC_LITERAL(9, 125, 18),
QT_MOC_LITERAL(10, 144, 18)
    },
    "SocketClient\0sigSocketRecv\0\0"
    "sigSocketRecvData\0slotSocketReadData\0"
    "slotSocketError\0slotConnectServer\0"
    "slotConnectToServer\0bool&\0slotClosedByServer\0"
    "slotSocketSendData\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SocketClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06,
       3,    1,   57,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   60,    2, 0x08,
       5,    0,   61,    2, 0x08,
       6,    0,   62,    2, 0x08,
       7,    1,   63,    2, 0x0a,
       9,    0,   66,    2, 0x0a,
      10,    1,   67,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void SocketClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SocketClient *_t = static_cast<SocketClient *>(_o);
        switch (_id) {
        case 0: _t->sigSocketRecv((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigSocketRecvData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->slotSocketReadData(); break;
        case 3: _t->slotSocketError(); break;
        case 4: _t->slotConnectServer(); break;
        case 5: _t->slotConnectToServer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->slotClosedByServer(); break;
        case 7: _t->slotSocketSendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SocketClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketClient::sigSocketRecv)) {
                *result = 0;
            }
        }
        {
            typedef void (SocketClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SocketClient::sigSocketRecvData)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject SocketClient::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SocketClient.data,
      qt_meta_data_SocketClient,  qt_static_metacall, 0, 0}
};


const QMetaObject *SocketClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SocketClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SocketClient.stringdata))
        return static_cast<void*>(const_cast< SocketClient*>(this));
    return QWidget::qt_metacast(_clname);
}

int SocketClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SocketClient::sigSocketRecv(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SocketClient::sigSocketRecvData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
