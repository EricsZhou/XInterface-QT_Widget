/****************************************************************************
** Meta object code from reading C++ file 'tcp.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ui_1/MRStage-QT/tcp.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tcp_t {
    const uint offsetsAndSize[46];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Tcp_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Tcp_t qt_meta_stringdata_Tcp = {
    {
QT_MOC_LITERAL(0, 3), // "Tcp"
QT_MOC_LITERAL(4, 9), // "serverMsg"
QT_MOC_LITERAL(14, 0), // ""
QT_MOC_LITERAL(15, 12), // "CreateServer"
QT_MOC_LITERAL(28, 9), // "HandleMsg"
QT_MOC_LITERAL(38, 3), // "str"
QT_MOC_LITERAL(42, 15), // "DisplayErrorMsg"
QT_MOC_LITERAL(58, 3), // "msg"
QT_MOC_LITERAL(62, 13), // "SendCameraMsg"
QT_MOC_LITERAL(76, 6), // "motion"
QT_MOC_LITERAL(83, 19), // "SendCameraWidgetMsg"
QT_MOC_LITERAL(103, 14), // "OpenScreenFile"
QT_MOC_LITERAL(118, 11), // "SendItemMsg"
QT_MOC_LITERAL(130, 4), // "item"
QT_MOC_LITERAL(135, 17), // "SendAutoMotionMsg"
QT_MOC_LITERAL(153, 4), // "name"
QT_MOC_LITERAL(158, 5), // "state"
QT_MOC_LITERAL(164, 16), // "SendAutoFwBtnMsg"
QT_MOC_LITERAL(181, 17), // "Open_SChangWidget"
QT_MOC_LITERAL(199, 21), // "HandleCameraChangeMsg"
QT_MOC_LITERAL(221, 13), // "sendScenceMsg"
QT_MOC_LITERAL(235, 15), // "sendSliderValue"
QT_MOC_LITERAL(251, 5) // "value"

    },
    "Tcp\0serverMsg\0\0CreateServer\0HandleMsg\0"
    "str\0DisplayErrorMsg\0msg\0SendCameraMsg\0"
    "motion\0SendCameraWidgetMsg\0OpenScreenFile\0"
    "SendItemMsg\0item\0SendAutoMotionMsg\0"
    "name\0state\0SendAutoFwBtnMsg\0"
    "Open_SChangWidget\0HandleCameraChangeMsg\0"
    "sendScenceMsg\0sendSliderValue\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tcp[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  101,    2, 0x0a,    3 /* Public */,
       4,    1,  102,    2, 0x0a,    4 /* Public */,
       6,    1,  105,    2, 0x0a,    6 /* Public */,
       8,    1,  108,    2, 0x0a,    8 /* Public */,
      10,    1,  111,    2, 0x0a,   10 /* Public */,
      11,    0,  114,    2, 0x0a,   12 /* Public */,
      12,    1,  115,    2, 0x0a,   13 /* Public */,
      14,    2,  118,    2, 0x0a,   15 /* Public */,
      17,    1,  123,    2, 0x0a,   18 /* Public */,
      18,    0,  126,    2, 0x0a,   20 /* Public */,
      19,    1,  127,    2, 0x0a,   21 /* Public */,
      20,    1,  130,    2, 0x0a,   23 /* Public */,
      21,    1,  133,    2, 0x0a,   25 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   15,   16,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int,   22,

       0        // eod
};

void Tcp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tcp *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->serverMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->CreateServer(); break;
        case 2: _t->HandleMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->DisplayErrorMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->SendCameraMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->SendCameraWidgetMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->OpenScreenFile(); break;
        case 7: _t->SendItemMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->SendAutoMotionMsg((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->SendAutoFwBtnMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->Open_SChangWidget(); break;
        case 11: _t->HandleCameraChangeMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->sendScenceMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->sendSliderValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Tcp::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tcp::serverMsg)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Tcp::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Tcp.offsetsAndSize,
    qt_meta_data_Tcp,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Tcp_t
, QtPrivate::TypeAndForceComplete<Tcp, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *Tcp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tcp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tcp.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Tcp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Tcp::serverMsg(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
