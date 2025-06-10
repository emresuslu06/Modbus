/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPushButton *writeButton;
    QPushButton *readButton;
    QSpinBox *writeSpinBox;
    QLabel *label_3;
    QSpinBox *writeValueSpinBox;
    QLabel *label_4;
    QSpinBox *slaveAddressSpinBox;
    QLabel *label_5;
    QLineEdit *lineEdit_portName;
    QLabel *label_6;
    QPushButton *connectButton;
    QPushButton *clearButton;
    QPushButton *btn_scanSpeed;
    QPushButton *btn_scanWidth;
    QPushButton *btn_peakPower;
    QPushButton *btn_dutyCycle;
    QPushButton *btn_scanHeight;
    QPushButton *btn_rotationAngle;
    QPushButton *btn_scanPattern;
    QPushButton *btn_pulseFreqMSB_LSB;
    QSpinBox *spinWriteBoxValue_0;
    QSpinBox *spinWriteBoxValue_1;
    QSpinBox *spinWriteBoxValue_2;
    QSpinBox *spinWriteBoxValue_4_5;
    QSpinBox *spinWriteBoxValue_7;
    QSpinBox *spinWriteBoxValue_6;
    QSpinBox *spinWriteBoxValue_3;
    QSpinBox *spinWriteBoxValue_30;
    QLineEdit *lineEdit_0;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_30;
    QPushButton *pushWriteButton_0;
    QPushButton *pushWriteButton_1;
    QPushButton *pushWriteButton_2;
    QPushButton *pushWriteButton_3;
    QPushButton *pushWriteButton_4_5;
    QPushButton *pushWriteButton_6;
    QPushButton *pushWriteButton_7;
    QPushButton *pushWriteButton_30;
    QComboBox *baudRateCombo;
    QLineEdit *lineEditPassword;
    QPushButton *btnConfirmPassword;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *spinBox_length;
    QPushButton *allReadButton;
    QLabel *label_9;
    QComboBox *comboBox_portList;
    QPushButton *btnRefreshPorts;
    QPushButton *closeButton;
    QFrame *frame;
    QFrame *frame_2;
    QLabel *label_10;
    QMenuBar *menubar;
    QToolBar *toolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 650);
        MainWindow->setMinimumSize(QSize(900, 650));
        MainWindow->setMaximumSize(QSize(900, 650));
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setStyleStrategy(QFont::PreferDefault);
        MainWindow->setFont(font);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        MainWindow->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(330, 15, 150, 30));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setStyleStrategy(QFont::PreferDefault);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(580, 420, 280, 160));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        textEdit->setFont(font2);
        textEdit->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/new/prefix1/images/background.jpg);\n"
"color: rgb(0, 0, 0);\n"
"/* #FF7F00 */"));
        writeButton = new QPushButton(centralwidget);
        writeButton->setObjectName("writeButton");
        writeButton->setGeometry(QRect(720, 360, 90, 35));
        writeButton->setFont(font1);
        writeButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        readButton = new QPushButton(centralwidget);
        readButton->setObjectName("readButton");
        readButton->setGeometry(QRect(200, 495, 100, 35));
        readButton->setFont(font1);
        readButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        writeSpinBox = new QSpinBox(centralwidget);
        writeSpinBox->setObjectName("writeSpinBox");
        writeSpinBox->setGeometry(QRect(720, 220, 80, 28));
        writeSpinBox->setFont(font1);
        writeSpinBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        writeSpinBox->setMaximum(49999);
        writeSpinBox->setValue(0);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(580, 225, 131, 20));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);"));
        writeValueSpinBox = new QSpinBox(centralwidget);
        writeValueSpinBox->setObjectName("writeValueSpinBox");
        writeValueSpinBox->setGeometry(QRect(720, 310, 80, 28));
        writeValueSpinBox->setFont(font1);
        writeValueSpinBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        writeValueSpinBox->setMaximum(65535);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(580, 315, 61, 20));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);"));
        slaveAddressSpinBox = new QSpinBox(centralwidget);
        slaveAddressSpinBox->setObjectName("slaveAddressSpinBox");
        slaveAddressSpinBox->setGeometry(QRect(720, 130, 80, 28));
        slaveAddressSpinBox->setFont(font1);
        slaveAddressSpinBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        slaveAddressSpinBox->setMinimum(1);
        slaveAddressSpinBox->setMaximum(247);
        slaveAddressSpinBox->setValue(9);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(580, 135, 111, 20));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);"));
        lineEdit_portName = new QLineEdit(centralwidget);
        lineEdit_portName->setObjectName("lineEdit_portName");
        lineEdit_portName->setGeometry(QRect(70, 15, 100, 30));
        lineEdit_portName->setFont(font1);
        lineEdit_portName->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(15, 20, 51, 20));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
""));
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName("connectButton");
        connectButton->setGeometry(QRect(205, 15, 90, 32));
        connectButton->setFont(font1);
        connectButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(350, 495, 100, 35));
        clearButton->setFont(font1);
        clearButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        btn_scanSpeed = new QPushButton(centralwidget);
        btn_scanSpeed->setObjectName("btn_scanSpeed");
        btn_scanSpeed->setGeometry(QRect(10, 130, 160, 35));
        btn_scanSpeed->setFont(font1);
        btn_scanSpeed->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);\n"
"border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        btn_scanWidth = new QPushButton(centralwidget);
        btn_scanWidth->setObjectName("btn_scanWidth");
        btn_scanWidth->setGeometry(QRect(10, 175, 160, 35));
        btn_scanWidth->setFont(font1);
        btn_scanWidth->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);\n"
"border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        btn_peakPower = new QPushButton(centralwidget);
        btn_peakPower->setObjectName("btn_peakPower");
        btn_peakPower->setGeometry(QRect(10, 220, 160, 35));
        btn_peakPower->setFont(font1);
        btn_peakPower->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        btn_dutyCycle = new QPushButton(centralwidget);
        btn_dutyCycle->setObjectName("btn_dutyCycle");
        btn_dutyCycle->setGeometry(QRect(10, 265, 160, 35));
        btn_dutyCycle->setFont(font1);
        btn_dutyCycle->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        btn_scanHeight = new QPushButton(centralwidget);
        btn_scanHeight->setObjectName("btn_scanHeight");
        btn_scanHeight->setGeometry(QRect(10, 355, 160, 35));
        btn_scanHeight->setFont(font1);
        btn_scanHeight->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
"border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        btn_rotationAngle = new QPushButton(centralwidget);
        btn_rotationAngle->setObjectName("btn_rotationAngle");
        btn_rotationAngle->setGeometry(QRect(10, 400, 160, 35));
        btn_rotationAngle->setFont(font1);
        btn_rotationAngle->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
"border-radius: 5px;\n"
" border: 2px solid darkorange;\n"
"\n"
""));
        btn_scanPattern = new QPushButton(centralwidget);
        btn_scanPattern->setObjectName("btn_scanPattern");
        btn_scanPattern->setGeometry(QRect(10, 445, 160, 35));
        btn_scanPattern->setFont(font1);
        btn_scanPattern->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
"border-radius: 5px;\n"
" border: 2px solid darkorange;\n"
"\n"
""));
        btn_pulseFreqMSB_LSB = new QPushButton(centralwidget);
        btn_pulseFreqMSB_LSB->setObjectName("btn_pulseFreqMSB_LSB");
        btn_pulseFreqMSB_LSB->setGeometry(QRect(10, 310, 160, 35));
        btn_pulseFreqMSB_LSB->setFont(font1);
        btn_pulseFreqMSB_LSB->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
"border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        spinWriteBoxValue_0 = new QSpinBox(centralwidget);
        spinWriteBoxValue_0->setObjectName("spinWriteBoxValue_0");
        spinWriteBoxValue_0->setGeometry(QRect(330, 130, 130, 35));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinWriteBoxValue_0->sizePolicy().hasHeightForWidth());
        spinWriteBoxValue_0->setSizePolicy(sizePolicy);
        spinWriteBoxValue_0->setSizeIncrement(QSize(0, 0));
        spinWriteBoxValue_0->setBaseSize(QSize(0, 0));
        spinWriteBoxValue_0->setFont(font1);
        spinWriteBoxValue_0->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
"\n"
" border: 2px solid darkorange;"));
        spinWriteBoxValue_0->setWrapping(false);
        spinWriteBoxValue_0->setFrame(true);
        spinWriteBoxValue_0->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinWriteBoxValue_0->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinWriteBoxValue_0->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        spinWriteBoxValue_0->setProperty("showGroupSeparator", QVariant(false));
        spinWriteBoxValue_0->setMaximum(999999);
        spinWriteBoxValue_1 = new QSpinBox(centralwidget);
        spinWriteBoxValue_1->setObjectName("spinWriteBoxValue_1");
        spinWriteBoxValue_1->setGeometry(QRect(330, 175, 130, 35));
        spinWriteBoxValue_1->setFont(font1);
        spinWriteBoxValue_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
"\n"
" border: 2px solid darkorange;"));
        spinWriteBoxValue_1->setMaximum(999999);
        spinWriteBoxValue_1->setValue(0);
        spinWriteBoxValue_2 = new QSpinBox(centralwidget);
        spinWriteBoxValue_2->setObjectName("spinWriteBoxValue_2");
        spinWriteBoxValue_2->setGeometry(QRect(330, 220, 130, 35));
        spinWriteBoxValue_2->setFont(font1);
        spinWriteBoxValue_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange; \n"
" border: 2px solid darkorange;"));
        spinWriteBoxValue_2->setMaximum(999999);
        spinWriteBoxValue_4_5 = new QSpinBox(centralwidget);
        spinWriteBoxValue_4_5->setObjectName("spinWriteBoxValue_4_5");
        spinWriteBoxValue_4_5->setGeometry(QRect(330, 310, 130, 35));
        spinWriteBoxValue_4_5->setFont(font1);
        spinWriteBoxValue_4_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        spinWriteBoxValue_4_5->setMaximum(999999);
        spinWriteBoxValue_7 = new QSpinBox(centralwidget);
        spinWriteBoxValue_7->setObjectName("spinWriteBoxValue_7");
        spinWriteBoxValue_7->setGeometry(QRect(330, 400, 130, 35));
        spinWriteBoxValue_7->setFont(font1);
        spinWriteBoxValue_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
"\n"
" border: 2px solid darkorange;"));
        spinWriteBoxValue_7->setMaximum(999999);
        spinWriteBoxValue_6 = new QSpinBox(centralwidget);
        spinWriteBoxValue_6->setObjectName("spinWriteBoxValue_6");
        spinWriteBoxValue_6->setGeometry(QRect(330, 355, 130, 35));
        spinWriteBoxValue_6->setFont(font1);
        spinWriteBoxValue_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        spinWriteBoxValue_6->setMaximum(999999);
        spinWriteBoxValue_3 = new QSpinBox(centralwidget);
        spinWriteBoxValue_3->setObjectName("spinWriteBoxValue_3");
        spinWriteBoxValue_3->setGeometry(QRect(330, 265, 130, 35));
        spinWriteBoxValue_3->setFont(font1);
        spinWriteBoxValue_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);\n"
"border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        spinWriteBoxValue_3->setMaximum(999999);
        spinWriteBoxValue_30 = new QSpinBox(centralwidget);
        spinWriteBoxValue_30->setObjectName("spinWriteBoxValue_30");
        spinWriteBoxValue_30->setGeometry(QRect(330, 445, 130, 35));
        spinWriteBoxValue_30->setFont(font1);
        spinWriteBoxValue_30->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
"\n"
" border: 2px solid darkorange;"));
        spinWriteBoxValue_30->setMaximum(999999);
        lineEdit_0 = new QLineEdit(centralwidget);
        lineEdit_0->setObjectName("lineEdit_0");
        lineEdit_0->setEnabled(true);
        lineEdit_0->setGeometry(QRect(180, 130, 140, 35));
        lineEdit_0->setFont(font1);
        lineEdit_0->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        lineEdit_0->setReadOnly(true);
        lineEdit_1 = new QLineEdit(centralwidget);
        lineEdit_1->setObjectName("lineEdit_1");
        lineEdit_1->setGeometry(QRect(180, 175, 140, 35));
        lineEdit_1->setFont(font1);
        lineEdit_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        lineEdit_1->setReadOnly(true);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(180, 220, 140, 35));
        lineEdit_2->setFont(font1);
        lineEdit_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(180, 265, 140, 35));
        lineEdit_3->setFont(font1);
        lineEdit_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(180, 310, 140, 35));
        lineEdit_4->setFont(font1);
        lineEdit_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        lineEdit_4->setMaxLength(99999999);
        lineEdit_4->setFrame(true);
        lineEdit_4->setReadOnly(true);
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(180, 355, 140, 35));
        lineEdit_6->setFont(font1);
        lineEdit_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        lineEdit_6->setReadOnly(true);
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(180, 400, 140, 35));
        lineEdit_7->setFont(font1);
        lineEdit_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        lineEdit_7->setReadOnly(true);
        lineEdit_30 = new QLineEdit(centralwidget);
        lineEdit_30->setObjectName("lineEdit_30");
        lineEdit_30->setGeometry(QRect(180, 445, 140, 35));
        lineEdit_30->setFont(font1);
        lineEdit_30->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        lineEdit_30->setReadOnly(true);
        pushWriteButton_0 = new QPushButton(centralwidget);
        pushWriteButton_0->setObjectName("pushWriteButton_0");
        pushWriteButton_0->setGeometry(QRect(475, 130, 50, 35));
        pushWriteButton_0->setFont(font1);
        pushWriteButton_0->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        pushWriteButton_1 = new QPushButton(centralwidget);
        pushWriteButton_1->setObjectName("pushWriteButton_1");
        pushWriteButton_1->setGeometry(QRect(475, 175, 50, 35));
        sizePolicy.setHeightForWidth(pushWriteButton_1->sizePolicy().hasHeightForWidth());
        pushWriteButton_1->setSizePolicy(sizePolicy);
        pushWriteButton_1->setFont(font1);
        pushWriteButton_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
"border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        pushWriteButton_2 = new QPushButton(centralwidget);
        pushWriteButton_2->setObjectName("pushWriteButton_2");
        pushWriteButton_2->setGeometry(QRect(475, 220, 50, 35));
        pushWriteButton_2->setFont(font1);
        pushWriteButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        pushWriteButton_3 = new QPushButton(centralwidget);
        pushWriteButton_3->setObjectName("pushWriteButton_3");
        pushWriteButton_3->setGeometry(QRect(475, 265, 50, 35));
        pushWriteButton_3->setFont(font1);
        pushWriteButton_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        pushWriteButton_4_5 = new QPushButton(centralwidget);
        pushWriteButton_4_5->setObjectName("pushWriteButton_4_5");
        pushWriteButton_4_5->setGeometry(QRect(475, 310, 50, 35));
        pushWriteButton_4_5->setFont(font1);
        pushWriteButton_4_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        pushWriteButton_6 = new QPushButton(centralwidget);
        pushWriteButton_6->setObjectName("pushWriteButton_6");
        pushWriteButton_6->setGeometry(QRect(475, 355, 50, 35));
        pushWriteButton_6->setFont(font1);
        pushWriteButton_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        pushWriteButton_7 = new QPushButton(centralwidget);
        pushWriteButton_7->setObjectName("pushWriteButton_7");
        pushWriteButton_7->setGeometry(QRect(475, 400, 50, 35));
        pushWriteButton_7->setFont(font1);
        pushWriteButton_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        pushWriteButton_30 = new QPushButton(centralwidget);
        pushWriteButton_30->setObjectName("pushWriteButton_30");
        pushWriteButton_30->setGeometry(QRect(475, 445, 50, 35));
        pushWriteButton_30->setFont(font1);
        pushWriteButton_30->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        baudRateCombo = new QComboBox(centralwidget);
        baudRateCombo->setObjectName("baudRateCombo");
        baudRateCombo->setEnabled(false);
        baudRateCombo->setGeometry(QRect(720, 175, 80, 28));
        baudRateCombo->setFont(font1);
        baudRateCombo->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        lineEditPassword = new QLineEdit(centralwidget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(654, 15, 90, 30));
        lineEditPassword->setFont(font1);
        lineEditPassword->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        lineEditPassword->setEchoMode(QLineEdit::Password);
        btnConfirmPassword = new QPushButton(centralwidget);
        btnConfirmPassword->setObjectName("btnConfirmPassword");
        btnConfirmPassword->setGeometry(QRect(780, 15, 100, 35));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        font3.setKerning(true);
        font3.setStyleStrategy(QFont::PreferDefault);
        btnConfirmPassword->setFont(font3);
        btnConfirmPassword->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(570, 20, 81, 20));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(580, 180, 110, 20));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);"));
        spinBox_length = new QSpinBox(centralwidget);
        spinBox_length->setObjectName("spinBox_length");
        spinBox_length->setGeometry(QRect(720, 265, 80, 28));
        spinBox_length->setFont(font1);
        spinBox_length->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);background-color: rgb(0, 0, 0);border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        allReadButton = new QPushButton(centralwidget);
        allReadButton->setObjectName("allReadButton");
        allReadButton->setGeometry(QRect(580, 360, 90, 35));
        allReadButton->setFont(font1);
        allReadButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(580, 270, 131, 20));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);"));
        comboBox_portList = new QComboBox(centralwidget);
        comboBox_portList->setObjectName("comboBox_portList");
        comboBox_portList->setGeometry(QRect(70, 60, 70, 30));
        comboBox_portList->setFont(font1);
        comboBox_portList->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);\n"
"border: 2px solid orange;\n"
" border: 2px solid darkorange;"));
        btnRefreshPorts = new QPushButton(centralwidget);
        btnRefreshPorts->setObjectName("btnRefreshPorts");
        btnRefreshPorts->setGeometry(QRect(160, 60, 50, 32));
        btnRefreshPorts->setFont(font1);
        btnRefreshPorts->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);\n"
"background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;\n"
""));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(790, 60, 70, 30));
        closeButton->setFont(font1);
        closeButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);background-color: rgb(0, 0, 0);border: 2px solid orange;border-radius: 5px;\n"
" border: 2px solid darkorange;"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 100, 901, 5));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 140, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(540, -10, 5, 652));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 140, 0);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(570, 52, 141, 41));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 140, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 26));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "NUR\304\260\305\236 MODBUS", nullptr));
        writeButton->setText(QCoreApplication::translate("MainWindow", "Yaz", nullptr));
        readButton->setText(QCoreApplication::translate("MainWindow", "S\303\274rekli Oku", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ba\305\237lang\304\261\303\247 Adresi :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Value : ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Slave Address :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Port :", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Temizle", nullptr));
        btn_scanSpeed->setText(QCoreApplication::translate("MainWindow", "Tarama H\304\261z\304\261", nullptr));
        btn_scanWidth->setText(QCoreApplication::translate("MainWindow", "Tarama Geni\305\237li\304\237i", nullptr));
        btn_peakPower->setText(QCoreApplication::translate("MainWindow", "Tepe G\303\274c\303\274", nullptr));
        btn_dutyCycle->setText(QCoreApplication::translate("MainWindow", "\303\207al\304\261\305\237ma S\303\274resi", nullptr));
        btn_scanHeight->setText(QCoreApplication::translate("MainWindow", "Tarama Y\303\274ksekli\304\237i", nullptr));
        btn_rotationAngle->setText(QCoreApplication::translate("MainWindow", "D\303\266nme A\303\247\304\261s\304\261", nullptr));
        btn_scanPattern->setText(QCoreApplication::translate("MainWindow", "Tarama Deseni Se\303\247imi", nullptr));
        btn_pulseFreqMSB_LSB->setText(QCoreApplication::translate("MainWindow", "Darbe Frekans\304\261", nullptr));
        spinWriteBoxValue_0->setSpecialValueText(QString());
        pushWriteButton_0->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        pushWriteButton_1->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        pushWriteButton_2->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        pushWriteButton_3->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        pushWriteButton_4_5->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        pushWriteButton_6->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        pushWriteButton_7->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        pushWriteButton_30->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        btnConfirmPassword->setText(QCoreApplication::translate("MainWindow", "\305\236ifre Kontrol", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\305\236ifreyi Gir :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Baud Rate :", nullptr));
        allReadButton->setText(QCoreApplication::translate("MainWindow", "Oku", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Ka\303\247 register oku :", nullptr));
        btnRefreshPorts->setText(QCoreApplication::translate("MainWindow", "Yenile", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "Kapat", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Bu alan\304\261 kullanmak<br/>i\303\247in \305\237ifreyi giriniz .</p></body></html>", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
