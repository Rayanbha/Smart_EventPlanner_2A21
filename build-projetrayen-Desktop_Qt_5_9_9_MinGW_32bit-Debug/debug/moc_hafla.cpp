/****************************************************************************
** Meta object code from reading C++ file 'hafla.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../interface/hafla.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hafla.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hafla_t {
    QByteArrayData data[20];
    char stringdata0[449];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hafla_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hafla_t qt_meta_stringdata_hafla = {
    {
QT_MOC_LITERAL(0, 0, 5), // "hafla"
QT_MOC_LITERAL(1, 6, 31), // "on_pushButton_add_event_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 34), // "on_pushButton_delete_event_cl..."
QT_MOC_LITERAL(4, 74, 34), // "on_pushButton_modify_event_cl..."
QT_MOC_LITERAL(5, 109, 28), // "on_tableView_event_activated"
QT_MOC_LITERAL(6, 138, 5), // "index"
QT_MOC_LITERAL(7, 144, 19), // "on_TRI_NAME_clicked"
QT_MOC_LITERAL(8, 164, 19), // "on_TRI_DATE_clicked"
QT_MOC_LITERAL(9, 184, 19), // "on_TRI_TYPE_clicked"
QT_MOC_LITERAL(10, 204, 31), // "on_pushButton_pdf_event_clicked"
QT_MOC_LITERAL(11, 236, 12), // "statistiques"
QT_MOC_LITERAL(12, 249, 15), // "QVector<double>"
QT_MOC_LITERAL(13, 265, 8), // "makePlot"
QT_MOC_LITERAL(14, 274, 37), // "on_pushButton_statistic_event..."
QT_MOC_LITERAL(15, 312, 32), // "on_tableView_event_doubleClicked"
QT_MOC_LITERAL(16, 345, 32), // "on_pushButtontop_event_2_clicked"
QT_MOC_LITERAL(17, 378, 37), // "on_pushButton_reduction_event..."
QT_MOC_LITERAL(18, 416, 27), // "on_search_event_textChanged"
QT_MOC_LITERAL(19, 444, 4) // "arg1"

    },
    "hafla\0on_pushButton_add_event_clicked\0"
    "\0on_pushButton_delete_event_clicked\0"
    "on_pushButton_modify_event_clicked\0"
    "on_tableView_event_activated\0index\0"
    "on_TRI_NAME_clicked\0on_TRI_DATE_clicked\0"
    "on_TRI_TYPE_clicked\0on_pushButton_pdf_event_clicked\0"
    "statistiques\0QVector<double>\0makePlot\0"
    "on_pushButton_statistic_event_clicked\0"
    "on_tableView_event_doubleClicked\0"
    "on_pushButtontop_event_2_clicked\0"
    "on_pushButton_reduction_event_clicked\0"
    "on_search_event_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hafla[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    1,   92,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    1,  102,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    0,  106,    2, 0x08 /* Private */,
      18,    1,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,

       0        // eod
};

void hafla::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hafla *_t = static_cast<hafla *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_add_event_clicked(); break;
        case 1: _t->on_pushButton_delete_event_clicked(); break;
        case 2: _t->on_pushButton_modify_event_clicked(); break;
        case 3: _t->on_tableView_event_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_TRI_NAME_clicked(); break;
        case 5: _t->on_TRI_DATE_clicked(); break;
        case 6: _t->on_TRI_TYPE_clicked(); break;
        case 7: _t->on_pushButton_pdf_event_clicked(); break;
        case 8: { QVector<double> _r = _t->statistiques();
            if (_a[0]) *reinterpret_cast< QVector<double>*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->makePlot(); break;
        case 10: _t->on_pushButton_statistic_event_clicked(); break;
        case 11: _t->on_tableView_event_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->on_pushButtontop_event_2_clicked(); break;
        case 13: _t->on_pushButton_reduction_event_clicked(); break;
        case 14: _t->on_search_event_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject hafla::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_hafla.data,
      qt_meta_data_hafla,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *hafla::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hafla::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hafla.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int hafla::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
