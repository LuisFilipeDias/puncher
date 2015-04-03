/****************************************************************************
** Meta object code from reading C++ file 'puncher.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/puncher.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'puncher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Puncher_t {
    QByteArrayData data[15];
    char stringdata[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Puncher_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Puncher_t qt_meta_stringdata_Puncher = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 4),
QT_MOC_LITERAL(2, 13, 6),
QT_MOC_LITERAL(3, 20, 0),
QT_MOC_LITERAL(4, 21, 15),
QT_MOC_LITERAL(5, 37, 13),
QT_MOC_LITERAL(6, 51, 13),
QT_MOC_LITERAL(7, 65, 14),
QT_MOC_LITERAL(8, 80, 14),
QT_MOC_LITERAL(9, 95, 14),
QT_MOC_LITERAL(10, 110, 18),
QT_MOC_LITERAL(11, 129, 19),
QT_MOC_LITERAL(12, 149, 21),
QT_MOC_LITERAL(13, 171, 22),
QT_MOC_LITERAL(14, 194, 9)
    },
    "Puncher\0init\0status\0\0update_displays\0"
    "edit_callback\0ctrl_callback\0close_callback\0"
    "reset_callback\0timer_callback\0"
    "check_raw_callback\0check_logs_callback\0"
    "stats_weekly_callback\0stats_monthly_callback\0"
    "get_hours\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Puncher[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    3, 0x08,
       4,    0,   75,    3, 0x08,
       5,    0,   76,    3, 0x08,
       6,    0,   77,    3, 0x08,
       7,    0,   78,    3, 0x08,
       8,    0,   79,    3, 0x08,
       9,    0,   80,    3, 0x08,
      10,    0,   81,    3, 0x08,
      11,    0,   82,    3, 0x08,
      12,    0,   83,    3, 0x08,
      13,    0,   84,    3, 0x08,
      14,    3,   85,    3, 0x0a,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 2, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    3,    3,

       0        // eod
};

void Puncher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Puncher *_t = static_cast<Puncher *>(_o);
        switch (_id) {
        case 0: { status _r = _t->init();
            if (_a[0]) *reinterpret_cast< status*>(_a[0]) = _r; }  break;
        case 1: { status _r = _t->update_displays();
            if (_a[0]) *reinterpret_cast< status*>(_a[0]) = _r; }  break;
        case 2: _t->edit_callback(); break;
        case 3: _t->ctrl_callback(); break;
        case 4: _t->close_callback(); break;
        case 5: _t->reset_callback(); break;
        case 6: _t->timer_callback(); break;
        case 7: _t->check_raw_callback(); break;
        case 8: _t->check_logs_callback(); break;
        case 9: _t->stats_weekly_callback(); break;
        case 10: _t->stats_monthly_callback(); break;
        case 11: { status _r = _t->get_hours((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< status*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Puncher::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Puncher.data,
      qt_meta_data_Puncher,  qt_static_metacall, 0, 0}
};


const QMetaObject *Puncher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Puncher::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Puncher.stringdata))
        return static_cast<void*>(const_cast< Puncher*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Puncher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
