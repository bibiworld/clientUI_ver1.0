/****************************************************************************
** Meta object code from reading C++ file 'search.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../search.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'search.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_search_t {
    QByteArrayData data[8];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_search_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_search_t qt_meta_stringdata_search = {
    {
QT_MOC_LITERAL(0, 0, 6), // "search"
QT_MOC_LITERAL(1, 7, 10), // "searchWord"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "recvMessage"
QT_MOC_LITERAL(4, 31, 4), // "Word"
QT_MOC_LITERAL(5, 36, 7), // "addWord"
QT_MOC_LITERAL(6, 44, 13), // "addWordtoBook"
QT_MOC_LITERAL(7, 58, 19) // "editingFinishedSlot"

    },
    "search\0searchWord\0\0recvMessage\0Word\0"
    "addWord\0addWordtoBook\0editingFinishedSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_search[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    1,   40,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void search::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        search *_t = static_cast<search *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->searchWord(); break;
        case 1: _t->recvMessage((*reinterpret_cast< Word(*)>(_a[1]))); break;
        case 2: _t->addWord(); break;
        case 3: _t->addWordtoBook(); break;
        case 4: _t->editingFinishedSlot(); break;
        default: ;
        }
    }
}

const QMetaObject search::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_search.data,
      qt_meta_data_search,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *search::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *search::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_search.stringdata0))
        return static_cast<void*>(const_cast< search*>(this));
    return QDialog::qt_metacast(_clname);
}

int search::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
