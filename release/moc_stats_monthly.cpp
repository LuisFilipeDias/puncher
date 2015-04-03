/****************************************************************************
** Meta object code from reading C++ file 'stats_monthly.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/stats_monthly.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stats_monthly.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Stats_Monthly_t {
    QByteArrayData data[8];
    char stringdata[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Stats_Monthly_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Stats_Monthly_t qt_meta_stringdata_Stats_Monthly = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 12),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 9),
QT_MOC_LITERAL(4, 38, 15),
QT_MOC_LITERAL(5, 54, 8),
QT_MOC_LITERAL(6, 63, 22),
QT_MOC_LITERAL(7, 86, 21)
    },
    "Stats_Monthly\0update_graph\0\0get_hours\0"
    "QVector<double>\0sw_pos[]\0"
    "month_changed_callback\0year_changed_callback\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Stats_Monthly[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08,
       3,    2,   35,    2, 0x08,
       6,    1,   40,    2, 0x08,
       7,    1,   43,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 4, QMetaType::Int, 0x80000000 | 5,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Stats_Monthly::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Stats_Monthly *_t = static_cast<Stats_Monthly *>(_o);
        switch (_id) {
        case 0: _t->update_graph(); break;
        case 1: { QVector<double> _r = _t->get_hours((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< sw_pos(*)[]>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVector<double>*>(_a[0]) = _r; }  break;
        case 2: _t->month_changed_callback((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->year_changed_callback((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Stats_Monthly::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Stats_Monthly.data,
      qt_meta_data_Stats_Monthly,  qt_static_metacall, 0, 0}
};


const QMetaObject *Stats_Monthly::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Stats_Monthly::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Stats_Monthly.stringdata))
        return static_cast<void*>(const_cast< Stats_Monthly*>(this));
    return QDialog::qt_metacast(_clname);
}

int Stats_Monthly::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
