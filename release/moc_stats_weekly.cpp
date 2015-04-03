/****************************************************************************
** Meta object code from reading C++ file 'stats_weekly.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/stats_weekly.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stats_weekly.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Stats_Weekly_t {
    QByteArrayData data[10];
    char stringdata[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Stats_Weekly_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Stats_Weekly_t qt_meta_stringdata_Stats_Weekly = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 12),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 9),
QT_MOC_LITERAL(4, 37, 15),
QT_MOC_LITERAL(5, 53, 8),
QT_MOC_LITERAL(6, 62, 13),
QT_MOC_LITERAL(7, 76, 6),
QT_MOC_LITERAL(8, 83, 13),
QT_MOC_LITERAL(9, 97, 21)
    },
    "Stats_Weekly\0update_graph\0\0get_hours\0"
    "QVector<double>\0sw_pos[]\0fill_next_pos\0"
    "sw_pos\0fill_prev_pos\0week_changed_callback\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Stats_Weekly[] = {

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
       1,    0,   39,    2, 0x08,
       3,    2,   40,    2, 0x08,
       6,    1,   45,    2, 0x08,
       8,    1,   48,    2, 0x08,
       9,    1,   51,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 4, QMetaType::Int, 0x80000000 | 5,    2,    2,
    0x80000000 | 7, 0x80000000 | 7,    2,
    0x80000000 | 7, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Stats_Weekly::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Stats_Weekly *_t = static_cast<Stats_Weekly *>(_o);
        switch (_id) {
        case 0: _t->update_graph(); break;
        case 1: { QVector<double> _r = _t->get_hours((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< sw_pos(*)[]>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVector<double>*>(_a[0]) = _r; }  break;
        case 2: { sw_pos _r = _t->fill_next_pos((*reinterpret_cast< sw_pos(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< sw_pos*>(_a[0]) = _r; }  break;
        case 3: { sw_pos _r = _t->fill_prev_pos((*reinterpret_cast< sw_pos(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< sw_pos*>(_a[0]) = _r; }  break;
        case 4: _t->week_changed_callback((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Stats_Weekly::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Stats_Weekly.data,
      qt_meta_data_Stats_Weekly,  qt_static_metacall, 0, 0}
};


const QMetaObject *Stats_Weekly::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Stats_Weekly::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Stats_Weekly.stringdata))
        return static_cast<void*>(const_cast< Stats_Weekly*>(this));
    return QDialog::qt_metacast(_clname);
}

int Stats_Weekly::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
