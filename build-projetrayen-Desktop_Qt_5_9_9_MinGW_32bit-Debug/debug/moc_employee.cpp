/****************************************************************************
** Meta object code from reading C++ file 'employee.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../interface/employee.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'employee.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_employee_t {
    QByteArrayData data[12];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_employee_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_employee_t qt_meta_stringdata_employee = {
    {
QT_MOC_LITERAL(0, 0, 8), // "employee"
QT_MOC_LITERAL(1, 9, 29), // "on_pushButton_ajouter_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 31), // "on_pushButton_supprimer_clicked"
QT_MOC_LITERAL(4, 72, 30), // "on_pushButton_modifier_clicked"
QT_MOC_LITERAL(5, 103, 23), // "on_tableView1_activated"
QT_MOC_LITERAL(6, 127, 5), // "index"
QT_MOC_LITERAL(7, 133, 27), // "on_pushButton_reset_clicked"
QT_MOC_LITERAL(8, 161, 28), // "on_pushButton_search_clicked"
QT_MOC_LITERAL(9, 190, 26), // "on_pushButton_sort_clicked"
QT_MOC_LITERAL(10, 217, 28), // "on_pushButton_export_clicked"
QT_MOC_LITERAL(11, 246, 26) // "on_pushButton_send_clicked"

    },
    "employee\0on_pushButton_ajouter_clicked\0"
    "\0on_pushButton_supprimer_clicked\0"
    "on_pushButton_modifier_clicked\0"
    "on_tableView1_activated\0index\0"
    "on_pushButton_reset_clicked\0"
    "on_pushButton_search_clicked\0"
    "on_pushButton_sort_clicked\0"
    "on_pushButton_export_clicked\0"
    "on_pushButton_send_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_employee[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void employee::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        employee *_t = static_cast<employee *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_ajouter_clicked(); break;
        case 1: _t->on_pushButton_supprimer_clicked(); break;
        case 2: _t->on_pushButton_modifier_clicked(); break;
        case 3: _t->on_tableView1_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_reset_clicked(); break;
        case 5: _t->on_pushButton_search_clicked(); break;
        case 6: _t->on_pushButton_sort_clicked(); break;
        case 7: _t->on_pushButton_export_clicked(); break;
        case 8: _t->on_pushButton_send_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject employee::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_employee.data,
      qt_meta_data_employee,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *employee::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *employee::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_employee.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int employee::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
