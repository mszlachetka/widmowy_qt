/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata[445];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 11),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 5),
QT_MOC_LITERAL(4, 30, 3),
QT_MOC_LITERAL(5, 34, 4),
QT_MOC_LITERAL(6, 39, 21),
QT_MOC_LITERAL(7, 61, 23),
QT_MOC_LITERAL(8, 85, 14),
QT_MOC_LITERAL(9, 100, 9),
QT_MOC_LITERAL(10, 110, 12),
QT_MOC_LITERAL(11, 123, 5),
QT_MOC_LITERAL(12, 129, 2),
QT_MOC_LITERAL(13, 132, 23),
QT_MOC_LITERAL(14, 156, 22),
QT_MOC_LITERAL(15, 179, 22),
QT_MOC_LITERAL(16, 202, 27),
QT_MOC_LITERAL(17, 230, 5),
QT_MOC_LITERAL(18, 236, 25),
QT_MOC_LITERAL(19, 262, 26),
QT_MOC_LITERAL(20, 289, 22),
QT_MOC_LITERAL(21, 312, 22),
QT_MOC_LITERAL(22, 335, 32),
QT_MOC_LITERAL(23, 368, 40),
QT_MOC_LITERAL(24, 409, 4),
QT_MOC_LITERAL(25, 414, 4),
QT_MOC_LITERAL(26, 419, 25)
    },
    "MainWindow\0send_button\0\0Green\0Red\0"
    "Blue\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0serial_receive\0"
    "serial_dc\0receive_data\0delay\0ms\0"
    "on_pushButton_3_clicked\0on_save_Button_clicked\0"
    "on_load_Button_clicked\0"
    "on_GreenSlider_valueChanged\0value\0"
    "on_RedSlider_valueChanged\0"
    "on_BlueSlider_valueChanged\0"
    "on_lowerButton_clicked\0on_upperButton_clicked\0"
    "on_edit_led_size_editingFinished\0"
    "on_edit_brush_size_cursorPositionChanged\0"
    "arg1\0arg2\0on_lineEdit_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  111,    2, 0x0a /* Public */,
       7,    0,  112,    2, 0x0a /* Public */,
       8,    0,  113,    2, 0x0a /* Public */,
       9,    0,  114,    2, 0x0a /* Public */,
      10,    0,  115,    2, 0x0a /* Public */,
      11,    1,  116,    2, 0x0a /* Public */,
      13,    0,  119,    2, 0x08 /* Private */,
      14,    0,  120,    2, 0x08 /* Private */,
      15,    0,  121,    2, 0x08 /* Private */,
      16,    1,  122,    2, 0x08 /* Private */,
      18,    1,  125,    2, 0x08 /* Private */,
      19,    1,  128,    2, 0x08 /* Private */,
      20,    0,  131,    2, 0x08 /* Private */,
      21,    0,  132,    2, 0x08 /* Private */,
      22,    0,  133,    2, 0x08 /* Private */,
      23,    2,  134,    2, 0x08 /* Private */,
      26,    0,  139,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   24,   25,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->send_button((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->serial_receive(); break;
        case 4: _t->serial_dc(); break;
        case 5: _t->receive_data(); break;
        case 6: _t->delay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_3_clicked(); break;
        case 8: _t->on_save_Button_clicked(); break;
        case 9: _t->on_load_Button_clicked(); break;
        case 10: _t->on_GreenSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_RedSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_BlueSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_lowerButton_clicked(); break;
        case 14: _t->on_upperButton_clicked(); break;
        case 15: _t->on_edit_led_size_editingFinished(); break;
        case 16: _t->on_edit_brush_size_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->on_lineEdit_returnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(const int , const int , const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::send_button)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::send_button(const int _t1, const int _t2, const int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
