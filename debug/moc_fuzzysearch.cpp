/****************************************************************************
** Meta object code from reading C++ file 'fuzzysearch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fuzzysearch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fuzzysearch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fuzzySearch_t {
    QByteArrayData data[6];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fuzzySearch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fuzzySearch_t qt_meta_stringdata_fuzzySearch = {
    {
QT_MOC_LITERAL(0, 0, 11), // "fuzzySearch"
QT_MOC_LITERAL(1, 12, 10), // "searchWord"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "recvMessage"
QT_MOC_LITERAL(4, 36, 13), // "QVector<Word>"
QT_MOC_LITERAL(5, 50, 19) // "editingFinishedSlot"

    },
    "fuzzySearch\0searchWord\0\0recvMessage\0"
    "QVector<Word>\0editingFinishedSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fuzzySearch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    1,   30,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,

       0        // eod
};

void fuzzySearch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fuzzySearch *_t = static_cast<fuzzySearch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->searchWord(); break;
        case 1: _t->recvMessage((*reinterpret_cast< QVector<Word>(*)>(_a[1]))); break;
        case 2: _t->editingFinishedSlot(); break;
        default: ;
        }
    }
}

const QMetaObject fuzzySearch::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fuzzySearch.data,
      qt_meta_data_fuzzySearch,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fuzzySearch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fuzzySearch::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fuzzySearch.stringdata0))
        return static_cast<void*>(const_cast< fuzzySearch*>(this));
    return QDialog::qt_metacast(_clname);
}

int fuzzySearch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
