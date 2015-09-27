/****************************************************************************
** Meta object code from reading C++ file 'ekran.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ekran.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ekran.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ekran_t {
    QByteArrayData data[18];
    char stringdata[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ekran_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ekran_t qt_meta_stringdata_Ekran = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 10),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 12),
QT_MOC_LITERAL(4, 31, 5),
QT_MOC_LITERAL(5, 37, 14),
QT_MOC_LITERAL(6, 52, 9),
QT_MOC_LITERAL(7, 62, 1),
QT_MOC_LITERAL(8, 64, 12),
QT_MOC_LITERAL(9, 77, 9),
QT_MOC_LITERAL(10, 87, 10),
QT_MOC_LITERAL(11, 98, 1),
QT_MOC_LITERAL(12, 100, 1),
QT_MOC_LITERAL(13, 102, 1),
QT_MOC_LITERAL(14, 104, 15),
QT_MOC_LITERAL(15, 120, 12),
QT_MOC_LITERAL(16, 133, 17),
QT_MOC_LITERAL(17, 151, 14)
    },
    "Ekran\0paintEvent\0\0QPaintEvent*\0event\0"
    "generuj_Pedzel\0QPainter*\0d\0rysuj_Pedzel\0"
    "rysuj_Tlo\0get_button\0G\0R\0B\0mousePressEvent\0"
    "QMouseEvent*\0mouseReleaseEvent\0"
    "mouseMoveEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ekran[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       5,    1,   57,    2, 0x0a /* Public */,
       8,    1,   60,    2, 0x0a /* Public */,
       9,    1,   63,    2, 0x0a /* Public */,
      10,    3,   66,    2, 0x0a /* Public */,
      14,    1,   73,    2, 0x0a /* Public */,
      16,    1,   76,    2, 0x0a /* Public */,
      17,    1,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   12,   13,
    QMetaType::Void, 0x80000000 | 15,    4,
    QMetaType::Void, 0x80000000 | 15,    4,
    QMetaType::Void, 0x80000000 | 15,    4,

       0        // eod
};

void Ekran::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ekran *_t = static_cast<Ekran *>(_o);
        switch (_id) {
        case 0: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 1: _t->generuj_Pedzel((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 2: _t->rysuj_Pedzel((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 3: _t->rysuj_Tlo((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        case 4: _t->get_button((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 5: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Ekran::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Ekran.data,
      qt_meta_data_Ekran,  qt_static_metacall, 0, 0}
};


const QMetaObject *Ekran::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ekran::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ekran.stringdata))
        return static_cast<void*>(const_cast< Ekran*>(this));
    return QWidget::qt_metacast(_clname);
}

int Ekran::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
