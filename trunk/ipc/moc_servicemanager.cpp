/****************************************************************************
** Meta object code from reading C++ file 'servicemanager.h'
**
** Created: Thu Jun 11 16:55:24 2009
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "servicemanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servicemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Client[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      12,    8,    7,    7, 0x05,
      33,   30,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Client[] = {
    "Client\0\0cmd\0received(QString)\0id\0"
    "disconnected(ulong)\0readyRead()\0"
};

const QMetaObject Client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Client,
      qt_meta_data_Client, 0 }
};

const QMetaObject *Client::metaObject() const
{
    return &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Client))
	return static_cast<void*>(const_cast< Client*>(this));
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: received((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: disconnected((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 2: readyRead(); break;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Client::received(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Client::disconnected(ulong _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
static const uint qt_meta_data_Service[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_Service[] = {
    "Service\0"
};

const QMetaObject Service::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Service,
      qt_meta_data_Service, 0 }
};

const QMetaObject *Service::metaObject() const
{
    return &staticMetaObject;
}

void *Service::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Service))
	return static_cast<void*>(const_cast< Service*>(this));
    return QObject::qt_metacast(_clname);
}

int Service::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_ServiceManager[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      37,   32,   28,   15, 0x08,
      64,   55,   50,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ServiceManager[] = {
    "ServiceManager\0\0connected()\0int\0soap\0"
    "reg(QString)\0long\0svr,soap\0"
    "call(QString,QString)\0"
};

const QMetaObject ServiceManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ServiceManager,
      qt_meta_data_ServiceManager, 0 }
};

const QMetaObject *ServiceManager::metaObject() const
{
    return &staticMetaObject;
}

void *ServiceManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServiceManager))
	return static_cast<void*>(const_cast< ServiceManager*>(this));
    return QObject::qt_metacast(_clname);
}

int ServiceManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: connected(); break;
        case 1: { int _r = reg((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { long _r = call((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< long*>(_a[0]) = _r; }  break;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
