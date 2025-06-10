/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
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
#error "This file was generated using the moc from 6.5.3. It"
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
    "connectToSelectedPort",
    "",
    "refreshPorts",
    "updatePortName",
    "on_btnConfirmPassword_clicked",
    "on_closeButton_clicked",
    "on_baudRateCombo_currentIndexChanged",
    "index",
    "readPulseFreqMSB_LSB",
    "sendCustomReadRequest",
    "sendReadRequest",
    "sendWriteRequest",
    "readData",
    "toggleConnection",
    "on_clearButton_clicked",
    "toggleContinuousRead",
    "writeSpecificRegister",
    "registerAddress",
    "value",
    "on_pushWriteButton_0_clicked",
    "on_pushWriteButton_1_clicked",
    "on_pushWriteButton_2_clicked",
    "on_pushWriteButton_3_clicked",
    "on_pushWriteButton_4_5_clicked",
    "on_pushWriteButton_6_clicked",
    "on_pushWriteButton_7_clicked",
    "on_pushWriteButton_30_clicked",
    "readScanSpeed",
    "readScanWidth",
    "readPeakPower",
    "readDutyCycle",
    "readPulseFreqMSB",
    "readPulseFreqLSB",
    "readScanHeight",
    "readRotationAngle",
    "readScanPattern"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[74];
    char stringdata0[11];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[15];
    char stringdata5[30];
    char stringdata6[23];
    char stringdata7[37];
    char stringdata8[6];
    char stringdata9[21];
    char stringdata10[22];
    char stringdata11[16];
    char stringdata12[17];
    char stringdata13[9];
    char stringdata14[17];
    char stringdata15[23];
    char stringdata16[21];
    char stringdata17[22];
    char stringdata18[16];
    char stringdata19[6];
    char stringdata20[29];
    char stringdata21[29];
    char stringdata22[29];
    char stringdata23[29];
    char stringdata24[31];
    char stringdata25[29];
    char stringdata26[29];
    char stringdata27[30];
    char stringdata28[14];
    char stringdata29[14];
    char stringdata30[14];
    char stringdata31[14];
    char stringdata32[17];
    char stringdata33[17];
    char stringdata34[15];
    char stringdata35[18];
    char stringdata36[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 21),  // "connectToSelectedPort"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 12),  // "refreshPorts"
        QT_MOC_LITERAL(47, 14),  // "updatePortName"
        QT_MOC_LITERAL(62, 29),  // "on_btnConfirmPassword_clicked"
        QT_MOC_LITERAL(92, 22),  // "on_closeButton_clicked"
        QT_MOC_LITERAL(115, 36),  // "on_baudRateCombo_currentIndex..."
        QT_MOC_LITERAL(152, 5),  // "index"
        QT_MOC_LITERAL(158, 20),  // "readPulseFreqMSB_LSB"
        QT_MOC_LITERAL(179, 21),  // "sendCustomReadRequest"
        QT_MOC_LITERAL(201, 15),  // "sendReadRequest"
        QT_MOC_LITERAL(217, 16),  // "sendWriteRequest"
        QT_MOC_LITERAL(234, 8),  // "readData"
        QT_MOC_LITERAL(243, 16),  // "toggleConnection"
        QT_MOC_LITERAL(260, 22),  // "on_clearButton_clicked"
        QT_MOC_LITERAL(283, 20),  // "toggleContinuousRead"
        QT_MOC_LITERAL(304, 21),  // "writeSpecificRegister"
        QT_MOC_LITERAL(326, 15),  // "registerAddress"
        QT_MOC_LITERAL(342, 5),  // "value"
        QT_MOC_LITERAL(348, 28),  // "on_pushWriteButton_0_clicked"
        QT_MOC_LITERAL(377, 28),  // "on_pushWriteButton_1_clicked"
        QT_MOC_LITERAL(406, 28),  // "on_pushWriteButton_2_clicked"
        QT_MOC_LITERAL(435, 28),  // "on_pushWriteButton_3_clicked"
        QT_MOC_LITERAL(464, 30),  // "on_pushWriteButton_4_5_clicked"
        QT_MOC_LITERAL(495, 28),  // "on_pushWriteButton_6_clicked"
        QT_MOC_LITERAL(524, 28),  // "on_pushWriteButton_7_clicked"
        QT_MOC_LITERAL(553, 29),  // "on_pushWriteButton_30_clicked"
        QT_MOC_LITERAL(583, 13),  // "readScanSpeed"
        QT_MOC_LITERAL(597, 13),  // "readScanWidth"
        QT_MOC_LITERAL(611, 13),  // "readPeakPower"
        QT_MOC_LITERAL(625, 13),  // "readDutyCycle"
        QT_MOC_LITERAL(639, 16),  // "readPulseFreqMSB"
        QT_MOC_LITERAL(656, 16),  // "readPulseFreqLSB"
        QT_MOC_LITERAL(673, 14),  // "readScanHeight"
        QT_MOC_LITERAL(688, 17),  // "readRotationAngle"
        QT_MOC_LITERAL(706, 15)   // "readScanPattern"
    },
    "MainWindow",
    "connectToSelectedPort",
    "",
    "refreshPorts",
    "updatePortName",
    "on_btnConfirmPassword_clicked",
    "on_closeButton_clicked",
    "on_baudRateCombo_currentIndexChanged",
    "index",
    "readPulseFreqMSB_LSB",
    "sendCustomReadRequest",
    "sendReadRequest",
    "sendWriteRequest",
    "readData",
    "toggleConnection",
    "on_clearButton_clicked",
    "toggleContinuousRead",
    "writeSpecificRegister",
    "registerAddress",
    "value",
    "on_pushWriteButton_0_clicked",
    "on_pushWriteButton_1_clicked",
    "on_pushWriteButton_2_clicked",
    "on_pushWriteButton_3_clicked",
    "on_pushWriteButton_4_5_clicked",
    "on_pushWriteButton_6_clicked",
    "on_pushWriteButton_7_clicked",
    "on_pushWriteButton_30_clicked",
    "readScanSpeed",
    "readScanWidth",
    "readPeakPower",
    "readDutyCycle",
    "readPulseFreqMSB",
    "readPulseFreqLSB",
    "readScanHeight",
    "readRotationAngle",
    "readScanPattern"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  206,    2, 0x08,    1 /* Private */,
       3,    0,  207,    2, 0x08,    2 /* Private */,
       4,    0,  208,    2, 0x08,    3 /* Private */,
       5,    0,  209,    2, 0x08,    4 /* Private */,
       6,    0,  210,    2, 0x08,    5 /* Private */,
       7,    1,  211,    2, 0x08,    6 /* Private */,
       9,    0,  214,    2, 0x08,    8 /* Private */,
      10,    0,  215,    2, 0x08,    9 /* Private */,
      11,    0,  216,    2, 0x08,   10 /* Private */,
      12,    0,  217,    2, 0x08,   11 /* Private */,
      13,    0,  218,    2, 0x08,   12 /* Private */,
      14,    0,  219,    2, 0x08,   13 /* Private */,
      15,    0,  220,    2, 0x08,   14 /* Private */,
      16,    0,  221,    2, 0x08,   15 /* Private */,
      17,    2,  222,    2, 0x08,   16 /* Private */,
      20,    0,  227,    2, 0x08,   19 /* Private */,
      21,    0,  228,    2, 0x08,   20 /* Private */,
      22,    0,  229,    2, 0x08,   21 /* Private */,
      23,    0,  230,    2, 0x08,   22 /* Private */,
      24,    0,  231,    2, 0x08,   23 /* Private */,
      25,    0,  232,    2, 0x08,   24 /* Private */,
      26,    0,  233,    2, 0x08,   25 /* Private */,
      27,    0,  234,    2, 0x08,   26 /* Private */,
      28,    0,  235,    2, 0x08,   27 /* Private */,
      29,    0,  236,    2, 0x08,   28 /* Private */,
      30,    0,  237,    2, 0x08,   29 /* Private */,
      31,    0,  238,    2, 0x08,   30 /* Private */,
      32,    0,  239,    2, 0x08,   31 /* Private */,
      33,    0,  240,    2, 0x08,   32 /* Private */,
      34,    0,  241,    2, 0x08,   33 /* Private */,
      35,    0,  242,    2, 0x08,   34 /* Private */,
      36,    0,  243,    2, 0x08,   35 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort, QMetaType::UShort,   18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        // method 'connectToSelectedPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refreshPorts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updatePortName'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnConfirmPassword_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_closeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_baudRateCombo_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'readPulseFreqMSB_LSB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendCustomReadRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendReadRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendWriteRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleContinuousRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'writeSpecificRegister'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'on_pushWriteButton_0_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushWriteButton_1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushWriteButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushWriteButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushWriteButton_4_5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushWriteButton_6_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushWriteButton_7_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushWriteButton_30_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readScanSpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readScanWidth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readPeakPower'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readDutyCycle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readPulseFreqMSB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readPulseFreqLSB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readScanHeight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readRotationAngle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readScanPattern'
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
        case 0: _t->connectToSelectedPort(); break;
        case 1: _t->refreshPorts(); break;
        case 2: _t->updatePortName(); break;
        case 3: _t->on_btnConfirmPassword_clicked(); break;
        case 4: _t->on_closeButton_clicked(); break;
        case 5: _t->on_baudRateCombo_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->readPulseFreqMSB_LSB(); break;
        case 7: _t->sendCustomReadRequest(); break;
        case 8: _t->sendReadRequest(); break;
        case 9: _t->sendWriteRequest(); break;
        case 10: _t->readData(); break;
        case 11: _t->toggleConnection(); break;
        case 12: _t->on_clearButton_clicked(); break;
        case 13: _t->toggleContinuousRead(); break;
        case 14: _t->writeSpecificRegister((*reinterpret_cast< std::add_pointer_t<quint16>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2]))); break;
        case 15: _t->on_pushWriteButton_0_clicked(); break;
        case 16: _t->on_pushWriteButton_1_clicked(); break;
        case 17: _t->on_pushWriteButton_2_clicked(); break;
        case 18: _t->on_pushWriteButton_3_clicked(); break;
        case 19: _t->on_pushWriteButton_4_5_clicked(); break;
        case 20: _t->on_pushWriteButton_6_clicked(); break;
        case 21: _t->on_pushWriteButton_7_clicked(); break;
        case 22: _t->on_pushWriteButton_30_clicked(); break;
        case 23: _t->readScanSpeed(); break;
        case 24: _t->readScanWidth(); break;
        case 25: _t->readPeakPower(); break;
        case 26: _t->readDutyCycle(); break;
        case 27: _t->readPulseFreqMSB(); break;
        case 28: _t->readPulseFreqLSB(); break;
        case 29: _t->readScanHeight(); break;
        case 30: _t->readRotationAngle(); break;
        case 31: _t->readScanPattern(); break;
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
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 32;
    }
    return _id;
}
QT_WARNING_POP
