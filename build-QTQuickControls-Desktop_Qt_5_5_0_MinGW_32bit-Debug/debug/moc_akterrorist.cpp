/****************************************************************************
** Meta object code from reading C++ file 'akterrorist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTQuickControls/akterrorist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'akterrorist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AkTerrorist_t {
    QByteArrayData data[11];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AkTerrorist_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AkTerrorist_t qt_meta_stringdata_AkTerrorist = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AkTerrorist"
QT_MOC_LITERAL(1, 12, 10), // "PosChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "takeShelter"
QT_MOC_LITERAL(4, 36, 9), // "fireAShot"
QT_MOC_LITERAL(5, 46, 8), // "deathMan"
QT_MOC_LITERAL(6, 55, 9), // "timerSlot"
QT_MOC_LITERAL(7, 65, 11), // "shotedCheck"
QT_MOC_LITERAL(8, 77, 9), // "xOrdinate"
QT_MOC_LITERAL(9, 87, 9), // "yOrdinate"
QT_MOC_LITERAL(10, 97, 6) // "aCtive"

    },
    "AkTerrorist\0PosChanged\0\0takeShelter\0"
    "fireAShot\0deathMan\0timerSlot\0shotedCheck\0"
    "xOrdinate\0yOrdinate\0aCtive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AkTerrorist[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       3,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   50,    2, 0x0a /* Public */,
       7,    2,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,

 // properties: name, type, flags
       8, QMetaType::Double, 0x00495001,
       9, QMetaType::Double, 0x00495001,
      10, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       0,

       0        // eod
};

void AkTerrorist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AkTerrorist *_t = static_cast<AkTerrorist *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PosChanged(); break;
        case 1: _t->takeShelter(); break;
        case 2: _t->fireAShot(); break;
        case 3: _t->deathMan((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 4: _t->timerSlot(); break;
        case 5: _t->shotedCheck((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AkTerrorist::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AkTerrorist::PosChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (AkTerrorist::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AkTerrorist::takeShelter)) {
                *result = 1;
            }
        }
        {
            typedef void (AkTerrorist::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AkTerrorist::fireAShot)) {
                *result = 2;
            }
        }
        {
            typedef void (AkTerrorist::*_t)(QObject * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AkTerrorist::deathMan)) {
                *result = 3;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        AkTerrorist *_t = static_cast<AkTerrorist *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->getX(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->getY(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getVisibel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject AkTerrorist::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AkTerrorist.data,
      qt_meta_data_AkTerrorist,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AkTerrorist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AkTerrorist::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AkTerrorist.stringdata0))
        return static_cast<void*>(const_cast< AkTerrorist*>(this));
    return QObject::qt_metacast(_clname);
}

int AkTerrorist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AkTerrorist::PosChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void AkTerrorist::takeShelter()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void AkTerrorist::fireAShot()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void AkTerrorist::deathMan(QObject * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
