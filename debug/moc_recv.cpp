/****************************************************************************
** Meta object code from reading C++ file 'recv.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../recv.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Recv_t {
    QByteArrayData data[9];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Recv_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Recv_t qt_meta_stringdata_Recv = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Recv"
QT_MOC_LITERAL(1, 5, 12), // "searchSignal"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "Word"
QT_MOC_LITERAL(4, 24, 11), // "fuzzySignal"
QT_MOC_LITERAL(5, 36, 13), // "QVector<Word>"
QT_MOC_LITERAL(6, 50, 13), // "similarSignal"
QT_MOC_LITERAL(7, 64, 14), // "sentenceSignal"
QT_MOC_LITERAL(8, 79, 11) // "recvMessage"

    },
    "Recv\0searchSignal\0\0Word\0fuzzySignal\0"
    "QVector<Word>\0similarSignal\0sentenceSignal\0"
    "recvMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Recv[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    2,   45,    2, 0x06 /* Public */,
       7,    2,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Recv::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Recv *_t = static_cast<Recv *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->searchSignal((*reinterpret_cast< Word(*)>(_a[1]))); break;
        case 1: _t->fuzzySignal((*reinterpret_cast< QVector<Word>(*)>(_a[1]))); break;
        case 2: _t->similarSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<Word>(*)>(_a[2]))); break;
        case 3: _t->sentenceSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->recvMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Recv::*_t)(Word );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Recv::searchSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (Recv::*_t)(QVector<Word> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Recv::fuzzySignal)) {
                *result = 1;
            }
        }
        {
            typedef void (Recv::*_t)(QString , QVector<Word> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Recv::similarSignal)) {
                *result = 2;
            }
        }
        {
            typedef void (Recv::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Recv::sentenceSignal)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Recv::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Recv.data,
      qt_meta_data_Recv,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Recv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Recv::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Recv.stringdata0))
        return static_cast<void*>(const_cast< Recv*>(this));
    return QObject::qt_metacast(_clname);
}

int Recv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Recv::searchSignal(Word _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Recv::fuzzySignal(QVector<Word> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Recv::similarSignal(QString _t1, QVector<Word> _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Recv::sentenceSignal(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
