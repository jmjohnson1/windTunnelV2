/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WindTunnelGUI/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "openSerialPort",
    "",
    "closeSerialPort",
    "updateFanManualSliderReadout",
    "position",
    "updateFanAutoSliderReadout",
    "autoSpeedSet",
    "writeData",
    "data",
    "readData",
    "handleError",
    "QSerialPort::SerialPortError",
    "error",
    "handleBytesWritten",
    "bytes",
    "handleWriteTimeout",
    "manualPowerSet"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[36];
    char stringdata0[11];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[29];
    char stringdata5[9];
    char stringdata6[27];
    char stringdata7[13];
    char stringdata8[10];
    char stringdata9[5];
    char stringdata10[9];
    char stringdata11[12];
    char stringdata12[29];
    char stringdata13[6];
    char stringdata14[19];
    char stringdata15[6];
    char stringdata16[19];
    char stringdata17[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 14),  // "openSerialPort"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 15),  // "closeSerialPort"
        QT_MOC_LITERAL(43, 28),  // "updateFanManualSliderReadout"
        QT_MOC_LITERAL(72, 8),  // "position"
        QT_MOC_LITERAL(81, 26),  // "updateFanAutoSliderReadout"
        QT_MOC_LITERAL(108, 12),  // "autoSpeedSet"
        QT_MOC_LITERAL(121, 9),  // "writeData"
        QT_MOC_LITERAL(131, 4),  // "data"
        QT_MOC_LITERAL(136, 8),  // "readData"
        QT_MOC_LITERAL(145, 11),  // "handleError"
        QT_MOC_LITERAL(157, 28),  // "QSerialPort::SerialPortError"
        QT_MOC_LITERAL(186, 5),  // "error"
        QT_MOC_LITERAL(192, 18),  // "handleBytesWritten"
        QT_MOC_LITERAL(211, 5),  // "bytes"
        QT_MOC_LITERAL(217, 18),  // "handleWriteTimeout"
        QT_MOC_LITERAL(236, 14)   // "manualPowerSet"
    },
    "MainWindow",
    "openSerialPort",
    "",
    "closeSerialPort",
    "updateFanManualSliderReadout",
    "position",
    "updateFanAutoSliderReadout",
    "autoSpeedSet",
    "writeData",
    "data",
    "readData",
    "handleError",
    "QSerialPort::SerialPortError",
    "error",
    "handleBytesWritten",
    "bytes",
    "handleWriteTimeout",
    "manualPowerSet"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    1,   82,    2, 0x08,    3 /* Private */,
       6,    1,   85,    2, 0x08,    5 /* Private */,
       7,    0,   88,    2, 0x08,    7 /* Private */,
       8,    1,   89,    2, 0x08,    8 /* Private */,
      10,    0,   92,    2, 0x08,   10 /* Private */,
      11,    1,   93,    2, 0x08,   11 /* Private */,
      14,    1,   96,    2, 0x08,   13 /* Private */,
      16,    0,   99,    2, 0x08,   15 /* Private */,
      17,    0,  100,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::LongLong,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'openSerialPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeSerialPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateFanManualSliderReadout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateFanAutoSliderReadout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'autoSpeedSet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'writeData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'readData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSerialPort::SerialPortError, std::false_type>,
        // method 'handleBytesWritten'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'handleWriteTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'manualPowerSet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openSerialPort(); break;
        case 1: _t->closeSerialPort(); break;
        case 2: _t->updateFanManualSliderReadout((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->updateFanAutoSliderReadout((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->autoSpeedSet(); break;
        case 5: _t->writeData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 6: _t->readData(); break;
        case 7: _t->handleError((*reinterpret_cast< std::add_pointer_t<QSerialPort::SerialPortError>>(_a[1]))); break;
        case 8: _t->handleBytesWritten((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 9: _t->handleWriteTimeout(); break;
        case 10: _t->manualPowerSet(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
