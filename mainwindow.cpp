#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QThread>
#include <QSettings>
#include <QInputDialog>
#include <QPushButton>
#include <QDebug>


unsigned short MainWindow::crc16(const QByteArray &data) {
    unsigned short crc = 0xFFFF;
    for (int i = 0; i < data.size(); i++) {
        crc ^= static_cast<unsigned char>(data[i]);
        for (int j = 0; j < 8; j++) {
            if (crc & 0x0001) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}

QByteArray MainWindow::createModbusRequest(quint8 slaveAddress, quint8 functionCode, const QByteArray &data) {
    QByteArray message;
    message.append(slaveAddress);
    message.append(functionCode);
    message.append(data);

    unsigned short crc = crc16(message);
    message.append(static_cast<char>(crc & 0xFF));
    message.append(static_cast<char>((crc >> 8) & 0xFF));

    return message;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , baudRateChangeAllowed(false)
    , ADMIN_PASSWORD("123456Qw")
    , lastBaudRate(115200)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->lineEdit->setReadOnly(true);
    //ui->setupUi(this);


    serialPort = new QSerialPort(this);
    refreshPorts();



    QString portName = ui->lineEdit_portName->text();

    serialPort->setPortName(portName);
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        ui->textEdit->append("Seri port " + portName + " açıldı!");
    }


    ui->baudRateCombo->addItem("9600", QSerialPort::Baud9600);
    ui->baudRateCombo->addItem("19200", QSerialPort::Baud19200);
    ui->baudRateCombo->addItem("38400", QSerialPort::Baud38400);
    ui->baudRateCombo->addItem("57600", QSerialPort::Baud57600);
    ui->baudRateCombo->addItem("115200", QSerialPort::Baud115200);


    int index = ui->baudRateCombo->findData(QSerialPort::Baud115200);
    if (index >= 0) {
        ui->baudRateCombo->setCurrentIndex(index);
    }


    updateUIState(false);


    readTimer = new QTimer(this);
    connect(readTimer, &QTimer::timeout, this, &MainWindow::sendReadRequest);


    connect(ui->readButton, &QPushButton::clicked, this, &MainWindow::toggleContinuousRead);

    connect(ui->writeButton, &QPushButton::clicked, this, &MainWindow::sendWriteRequest);
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readData);
    connect(ui->connectButton, &QPushButton::clicked, this, &MainWindow::toggleConnection);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::on_clearButton_clicked);


    connect(ui->btnRefreshPorts, &QPushButton::clicked, this, &MainWindow::refreshPorts);


    // comboBox_portList'teki seçimi değiştiğinde, seçilen portu lineEdit_portName'e yazma
   /* connect(ui->comboBox_portList, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::updatePortName);*/
    // Constructor'da
    connect(ui->comboBox_portList, QOverload<int>::of(&QComboBox::activated),
            this, &MainWindow::updatePortName);


    connect(ui->btn_scanSpeed, &QPushButton::clicked, this, &MainWindow::readScanSpeed);
    connect(ui->btn_scanWidth, &QPushButton::clicked, this, &MainWindow::readScanWidth);
    connect(ui->btn_peakPower, &QPushButton::clicked, this, &MainWindow::readPeakPower);
    connect(ui->btn_dutyCycle, &QPushButton::clicked, this, &MainWindow::readDutyCycle);
    // connect(ui->btn_pulseFreqMSB, &QPushButton::clicked, this, &MainWindow::readPulseFreqMSB);
    //  connect(ui->btn_pulseFreqLSB, &QPushButton::clicked, this, &MainWindow::readPulseFreqLSB);

    connect(ui->btn_pulseFreqMSB_LSB, &QPushButton::clicked, this, &MainWindow::readPulseFreqMSB_LSB);

    connect(ui->btn_scanHeight, &QPushButton::clicked, this, &MainWindow::readScanHeight);
    connect(ui->btn_rotationAngle, &QPushButton::clicked, this, &MainWindow::readRotationAngle);
    connect(ui->btn_scanPattern, &QPushButton::clicked, this, &MainWindow::readScanPattern);

   // connect(ui->btnConfirmPassword, &QPushButton::clicked, this, &MainWindow::on_btnConfirmPassword_clicked);

    connect(ui->baudRateCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_baudRateCombo_currentIndexChanged);

    connect(ui->allReadButton, &QPushButton::clicked, this, &MainWindow::sendCustomReadRequest);

    isConnected = false;
    isReading = false;
    currentRequestType = None;


    ui->readButton->setText("Sürekli Oku");
}

MainWindow::~MainWindow()
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }
    delete ui;
}

void MainWindow::refreshPorts()
{
    ui->comboBox_portList->clear();
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    for (const QSerialPortInfo &port : ports) {
        ui->comboBox_portList->addItem(port.portName());
    }

    if (ports.isEmpty()) {
        ui->comboBox_portList->addItem("No ports available");
    }
}

void MainWindow::updatePortName()
{
    QString selectedPort = ui->comboBox_portList->currentText();
    ui->lineEdit_portName->setText(selectedPort);
}

void MainWindow::connectToSelectedPort()
{
    QString selectedPort = ui->lineEdit_portName->text();

    if (selectedPort.isEmpty() || selectedPort == "No ports available") {
        ui->lineEdit_portName->setText("Bağlantı Başarısız");
        return;
    }

    QSerialPort serialPort;
    serialPort.setPortName(selectedPort);

    if (serialPort.open(QIODevice::ReadWrite)) {
        ui->lineEdit_portName->setText("Bağlantı Başarılı");
    } else {
        ui->lineEdit_portName->setText("Bağlantı Başarısız");
    }

    serialPort.close();
}
void MainWindow::on_btnConfirmPassword_clicked()
{
    QString password = ui->lineEditPassword->text();
    bool isCorrect = validatePassword(password);

    if (isCorrect) {

        updateUIState(true);
        ui->lineEditPassword->clear();


        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Başarılı");
        msgBox.setText("Şifre doğru.");
        msgBox.setStyleSheet("QMessageBox { background-color: black; }"
                             "QLabel { color: #FF8C00; font-size: 14px; font-weight: bold; }");
        msgBox.exec();
        return;
    }
    else {

        ui->lineEditPassword->clear();


        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Hata");
        msgBox.setText("Şifre yanlış. Lütfen tekrar deneyin.");
        msgBox.setStyleSheet("QMessageBox { background-color: black; }"
                             "QLabel { color: #FF8C00; font-size: 14px; font-weight: bold; }");
        msgBox.exec();
        return;
    }
}

void MainWindow::on_baudRateCombo_currentIndexChanged(int index)
{

    if (index >= 0 && baudRateChangeAllowed) {
        int baudRate = ui->baudRateCombo->currentData().toInt();


        applyBaudRate(baudRate);


        updateUIState(false);

        ui->textEdit->append("Baud rate başarıyla " + QString::number(baudRate) + " olarak ayarlandı.");
        QMessageBox::information(this, "Baud Rate Değiştirildi",  "Baud rate başarıyla " + QString::number(baudRate) + " olarak ayarlandı.");
    }
}


bool MainWindow::validatePassword(const QString &password)
{
    qDebug() << "Girilen Şifre: " << password;
    return password == ADMIN_PASSWORD;
}


void MainWindow::applyBaudRate(int baudRate)
{

    if (serialPort->isOpen()) {

        serialPort->close();

        serialPort->setBaudRate(baudRate);
        lastBaudRate = baudRate;

        if (serialPort->open(QIODevice::ReadWrite)) {
            ui->textEdit->append("Seri port yeniden açıldı, baud rate: " + QString::number(baudRate));
        } else {
            ui->textEdit->append("Seri port yeniden açılamadı!");
        }
    } else {

        serialPort->setBaudRate(baudRate);
        lastBaudRate = baudRate;
        ui->textEdit->append("Baud rate ayarı değiştirildi: " + QString::number(baudRate));
    }
}

void MainWindow::on_closeButton_clicked()
{
    updateUIState(false);
}

void MainWindow::setWriteAndReadButtonsEnabled(bool enabled)
{
    ui->writeButton->setEnabled(enabled);
    ui->allReadButton->setEnabled(enabled);
}


void MainWindow::updateUIState(bool isPasswordCorrect)
{
     qDebug() << "UI güncelleniyor, şifre doğru mu? " << isPasswordCorrect;
    baudRateChangeAllowed = isPasswordCorrect;


    ui->baudRateCombo->setEnabled(isPasswordCorrect);

    ui->slaveAddressSpinBox->setEnabled(isPasswordCorrect);
    ui->writeSpinBox->setEnabled(isPasswordCorrect);
    ui->writeValueSpinBox->setEnabled(isPasswordCorrect);
    ui->spinBox_length->setEnabled(isPasswordCorrect);

    setWriteAndReadButtonsEnabled(isPasswordCorrect);
}



void MainWindow::toggleContinuousRead()
{
    if (!isConnected || !serialPort->isOpen()) {
        ui->textEdit->append("Port bağlı değil!");
        return;
    }

    if (isReading) {

        readTimer->stop();
        isReading = false;
        ui->readButton->setText("Sürekli Oku");
        ui->textEdit->append("Sürekli okuma durduruldu.");
    } else {

        readTimer->start(4000); // 4000 MS ARALIKLARLA OKUMA YAP
        isReading = true;
        ui->readButton->setText("Durdur");
        ui->textEdit->append("Sürekli okuma başlatıldı.");

        sendReadRequest();
    }
}

void MainWindow::sendReadRequest()
{

    quint8 slaveAddress = static_cast<quint8>(ui->slaveAddressSpinBox->value());

    quint16 startAddress = 0;

    int registerCount = 8;

    QByteArray requestData;


    requestData.append(static_cast<char>((startAddress >> 8) & 0xFF));
    requestData.append(static_cast<char>(startAddress & 0xFF));
    requestData.append(static_cast<char>((registerCount >> 8) & 0xFF));
    requestData.append(static_cast<char>(registerCount & 0xFF));


    QByteArray request = createModbusRequest(slaveAddress, 0x03, requestData);
    serialPort->write(request);


    ui->textEdit->append("READ REQUEST GÖNDERİLDİ: " + request.toHex().toUpper());


    currentRequestType = AllRegisters;


    requestData.clear();


    QTimer::singleShot(2000, this, [this, slaveAddress]() {

        quint16 nextStartAddress = 48;
        int nextRegisterCount = 1;


        QByteArray requestData;
        requestData.append(static_cast<char>((nextStartAddress >> 8) & 0xFF));
        requestData.append(static_cast<char>(nextStartAddress & 0xFF));
        requestData.append(static_cast<char>((nextRegisterCount >> 8) & 0xFF));
        requestData.append(static_cast<char>(nextRegisterCount & 0xFF));


        QByteArray request = createModbusRequest(slaveAddress, 0x03, requestData);
        serialPort->write(request);

        ui->textEdit->append("READ 48. ADDRESS GÖNDERİLDİ: " + request.toHex().toUpper());
    });
}


void MainWindow::sendCustomReadRequest()
{
    if (!isConnected || !serialPort->isOpen()) {
        ui->textEdit->append("Port bağlı değil!");
        return;
    }

    quint8 slaveAddress = static_cast<quint8>(ui->slaveAddressSpinBox->value());
    quint16 startAddress = static_cast<quint16>(ui->writeSpinBox->value());
    int registerCount = ui->spinBox_length->value();

    QByteArray requestData;
    requestData.append(static_cast<char>((startAddress >> 8) & 0xFF));
    requestData.append(static_cast<char>(startAddress & 0xFF));
    requestData.append(static_cast<char>((registerCount >> 8) & 0xFF));
    requestData.append(static_cast<char>(registerCount & 0xFF));

    QByteArray request = createModbusRequest(slaveAddress, 0x03, requestData);
    serialPort->write(request);

    ui->textEdit->append("READ REQUEST GÖNDERİLDİ: " + request.toHex().toUpper());
    currentRequestType = CustomRead;
}

void MainWindow::readSingleRegister(quint16 registerAddress, RequestType type)
{
    if (!isConnected || !serialPort->isOpen()) {
        ui->textEdit->append("Port bağlı değil!");
        return;
    }

    quint8 slaveAddress = static_cast<quint8>(ui->slaveAddressSpinBox->value());
    int registerCount = 1;

    QByteArray requestData;
    requestData.append(static_cast<char>((registerAddress >> 8) & 0xFF));
    requestData.append(static_cast<char>(registerAddress & 0xFF));
    requestData.append(static_cast<char>((registerCount >> 8) & 0xFF));
    requestData.append(static_cast<char>(registerCount & 0xFF));

    QByteArray request = createModbusRequest(slaveAddress, 0x03, requestData);
    serialPort->write(request);

    currentRequestType = type;
    ui->textEdit->append(QString("READ REGISTER %1 GÖNDERİLDİ: ").arg(registerAddress) + request.toHex().toUpper());
}

void MainWindow::readScanSpeed()
{
    readSingleRegister(0, ScanSpeed);
}

void MainWindow::readScanWidth()
{
    readSingleRegister(1, ScanWidth);
}

void MainWindow::readPeakPower()
{
    readSingleRegister(2, PeakPower);
}

void MainWindow::readDutyCycle()
{
    readSingleRegister(3, DutyCycle);
}

void MainWindow::readPulseFreqMSB()
{
    readSingleRegister(4, PulseFreqMSB);
}

void MainWindow::readPulseFreqLSB()
{
    readSingleRegister(5, PulseFreqLSB);
}

void MainWindow::readPulseFreqMSB_LSB()
{
    if (!isConnected || !serialPort->isOpen()) {
        ui->textEdit->append("Port bağlı değil!");
        return;
    }

    quint8 slaveAddress = static_cast<quint8>(ui->slaveAddressSpinBox->value());
    quint16 startAddress = 4;
    int registerCount = 2;

    QByteArray requestData;
    requestData.append(static_cast<char>((startAddress >> 8) & 0xFF));
    requestData.append(static_cast<char>(startAddress & 0xFF));
    requestData.append(static_cast<char>((registerCount >> 8) & 0xFF));
    requestData.append(static_cast<char>(registerCount & 0xFF));

    QByteArray request = createModbusRequest(slaveAddress, 0x03, requestData);
    serialPort->write(request);

    currentRequestType = PulseFreqMSB_LSB;
    ui->textEdit->append(QString("READ PULSE FREQ MSB & LSB GÖNDERİLDİ: ") + request.toHex().toUpper());
}

void MainWindow::readScanHeight()
{
    readSingleRegister(6, ScanHeight);
}

void MainWindow::readRotationAngle()
{
    readSingleRegister(7, RotationAngle);
}

void MainWindow::readScanPattern()
{
    readSingleRegister(48, ScanPattern);
}

void MainWindow::sendWriteRequest()
{
    quint8 slaveAddress = static_cast<quint8>(ui->slaveAddressSpinBox->value());

    quint16 startAddress = ui->writeSpinBox->value();
    quint16 value = ui->writeValueSpinBox->value();

    QByteArray requestData;

    requestData.append(static_cast<char>((startAddress >> 8) & 0xFF));
    requestData.append(static_cast<char>(startAddress & 0xFF));

    requestData.append(static_cast<char>((value >> 8) & 0xFF));
    requestData.append(static_cast<char>(value & 0xFF));

    QByteArray request = createModbusRequest(slaveAddress, 0x06, requestData);
    serialPort->write(request);

    ui->textEdit->append("WRITE REQUEST GÖNDERİLDİ: " + request.toHex().toUpper());
}

/*void MainWindow::on_pushWriteButton_clicked()
{
    if (!isConnected || !serialPort->isOpen()) {
        ui->textEdit->append("Port bağlı değil!");
        return;
    }

    quint16 value_0 = static_cast<quint16>(ui->spinWriteBoxValue_0->value());
    quint16 value_1 = static_cast<quint16>(ui->spinWriteBoxValue_1->value());
    quint16 value_2 = static_cast<quint16>(ui->spinWriteBoxValue_2->value());
    quint16 value_3 = static_cast<quint16>(ui->spinWriteBoxValue_3->value());
    quint16 value_6 = static_cast<quint16>(ui->spinWriteBoxValue_6->value());
    quint16 value_7 = static_cast<quint16>(ui->spinWriteBoxValue_7->value());
    quint16 value_30 = static_cast<quint16>(ui->spinWriteBoxValue_30->value());

    writeSpecificRegister(0, value_0);
    writeSpecificRegister(1, value_1);
    writeSpecificRegister(2, value_2);
    writeSpecificRegister(3, value_3);
    writeSpecificRegister(6, value_6);
    writeSpecificRegister(7, value_7);
    writeSpecificRegister(30, value_30);

    ui->textEdit->append("Tüm yazma işlemleri tamamlandı.");
}*/

void MainWindow::on_pushWriteButton_0_clicked()
{
    if (!isConnected || !serialPort->isOpen()) {
        ui->textEdit->append("Port bağlı değil!");
        return;
    }

    quint16 value_0 = static_cast<quint16>(ui->spinWriteBoxValue_0->value());
    writeSpecificRegister(0, value_0);
}

void MainWindow::on_pushWriteButton_1_clicked()
{
    if (!isConnected || !serialPort->isOpen()){
        ui->textEdit->append("Port bağlı değil!");
        return;
    }
    quint16 value_1 = static_cast<quint16>(ui->spinWriteBoxValue_1->value());
    writeSpecificRegister(1, value_1);
}

void MainWindow::on_pushWriteButton_2_clicked()
{
    if(!isConnected || ! serialPort->isOpen()){
        ui->textEdit->append("Port bağlı değil");
        return;
    }
    quint16 value_2 = static_cast<quint16>(ui->spinWriteBoxValue_2->value());
    writeSpecificRegister(2, value_2);
}

void MainWindow::on_pushWriteButton_3_clicked()
{
    if(!isConnected || ! serialPort->isOpen()){
        ui->textEdit->append("Port bağlı değil");
        return;
    }
    quint16 value_3 = static_cast<quint16>(ui->spinWriteBoxValue_3->value());
    writeSpecificRegister(3, value_3);
}

void MainWindow::on_pushWriteButton_4_5_clicked()
{
    if (!isConnected || !serialPort->isOpen()) {
        ui->textEdit->append("Port bağlı değil!");
        return;
    }

    quint32 value_4_5 = static_cast<quint32>(ui->spinWriteBoxValue_4_5->value());

    quint16 lsWord = value_4_5 & 0xFFFF;
    quint16 msWord = (value_4_5 >> 16) & 0xFFFF;

    writeSpecificRegister(4, msWord);

    QTimer::singleShot(2000, this, [this, lsWord]() {
        writeSpecificRegister(5, lsWord);
    });
}


void MainWindow::on_pushWriteButton_6_clicked()
{
    if(!isConnected || ! serialPort->isOpen()){
        ui->textEdit->append("Port bağlı değil");
        return;
    }
    quint16 value_6 = static_cast<quint16>(ui->spinWriteBoxValue_6->value());
    writeSpecificRegister(6, value_6);
}

void MainWindow::on_pushWriteButton_7_clicked()
{
    if(!isConnected || ! serialPort->isOpen()){
        ui->textEdit->append("Port bağlı değil");
        return;
    }
    quint16 value_7 = static_cast<quint16>(ui->spinWriteBoxValue_7->value());
    writeSpecificRegister(7, value_7);
}

void MainWindow::on_pushWriteButton_30_clicked()
{
    if(!isConnected || ! serialPort->isOpen()){
        ui->textEdit->append("Port bağlı değil");
        return;
    }
    quint16 value_48 = static_cast<quint16>(ui->spinWriteBoxValue_30->value());
    writeSpecificRegister(48, value_48);
}

void MainWindow::writeSpecificRegister(quint16 registerAddress, quint16 value)
{
    quint8 slaveAddress = static_cast<quint8>(ui->slaveAddressSpinBox->value());

    QByteArray requestData;

    requestData.append(static_cast<char>((registerAddress >> 8) & 0xFF));
    requestData.append(static_cast<char>(registerAddress & 0xFF));

    requestData.append(static_cast<char>((value >> 8) & 0xFF));
    requestData.append(static_cast<char>(value & 0xFF));

    QByteArray request = createModbusRequest(slaveAddress, 0x06, requestData);
    serialPort->write(request);

    ui->textEdit->append(QString("WRITE REQUEST %1 ADRESİNE %2 DEĞERİ GÖNDERİLDİ: %3")
                             .arg(registerAddress)
                             .arg(value)
                             .arg(QString(request.toHex().toUpper())));

    QThread::msleep(100);
}

void MainWindow::readData()
{
    QByteArray receivedData = serialPort->readAll();

    if (receivedData.size() < 3) {
        qDebug() << "YETERSİZ VERİ ALINDI:" << receivedData.toHex().toUpper();
        return;
    }

    quint8 functionCode = static_cast<quint8>(receivedData[1]);
    if (functionCode != 0x03) {
        qDebug() << "BİLİNMEYEN FONKSİYON KODU:" << QString::number(functionCode, 16).toUpper();
        return;
    }

    int byteCount = static_cast<quint8>(receivedData[2]);
    if (receivedData.size() < 3 + byteCount) {
        qDebug() << "TAMAMLANMAMIŞ PAKET ALINDI:" << receivedData.toHex().toUpper();
        return;
    }

    QByteArray data = receivedData.mid(3, byteCount);

    qDebug() << "Current Request Type:" << currentRequestType;

    QMap<int, QString> registerLabels = {
        {0, "mm/s"},
        {1, "mm/s"},
        {2, "W"},
        {3, "%"},
        {4, "Hz"},
        {5, "Hz"},
        {6, "mm/s"},
        {7, "°"},
        // {30, "Scanning pattern select"}
    };


    if (currentRequestType == CustomRead) {
        QString displayText = "GELEN VERİ (DECIMAL):\n";

        for (int i = 0; i < data.size(); i += 2) {
            if (i + 1 >= data.size()) break;

            quint16 registerValue = (static_cast<quint8>(data[i]) << 8) | static_cast<quint8>(data[i + 1]);
            int registerIndex = i / 2;

            displayText += QString("Register %1: %2\n").arg(ui->writeSpinBox->value() + registerIndex).arg(registerValue);
        }

        ui->textEdit->setText(displayText);
        return;
    }


    if (currentRequestType == PulseFreqMSB_LSB) {
        if (byteCount == 4) {
            quint16 val4 = (static_cast<quint8>(data[0]) << 8) | static_cast<quint8>(data[1]);
            quint16 val5 = (static_cast<quint8>(data[2]) << 8) | static_cast<quint8>(data[3]);

            quint32 combinedValue = (static_cast<quint32>(val4) << 16) | val5;

            ui->lineEdit_4->setText(QString::number(combinedValue) + " Hz");
            ui->textEdit->setText(QString("Pulse Frequency (32-bit): %1 Hz").arg(combinedValue));

            qDebug() << "DEBUG: Pulse Frequency (32-bit):" << combinedValue;
            return;
        }
    }

    if (byteCount == 2 && currentRequestType != AllRegisters && currentRequestType != CustomRead) {
        quint16 value = (static_cast<quint8>(data[0]) << 8) | static_cast<quint8>(data[1]);

        QString registerName;
        switch (currentRequestType) {
        case ScanSpeed:
            registerName = "mm/s";
            ui->lineEdit_0->setText(QString::number(value) + "  " + registerName);
            break;
        case ScanWidth:
            registerName = "mm/s";
            ui->lineEdit_1->setText(QString::number(value) + "  " + registerName);
            break;
        case PeakPower:
            registerName = "W";
            ui->lineEdit_2->setText(QString::number(value) + "  " + registerName);
            break;
        case DutyCycle:
            registerName = "%";
            ui->lineEdit_3->setText(QString::number(value) + " " + registerName);
            break;
        case PulseFreqMSB:
            registerName = "Hz";
            break;
        case PulseFreqLSB:
            registerName = "Hz";
            break;
        case ScanHeight:
            registerName = "mm/s";
            ui->lineEdit_6->setText(QString::number(value) + "  " + registerName);
            break;
        case RotationAngle:
            registerName = "°";
            ui->lineEdit_7->setText(QString::number(value) + "  " + registerName);
            break;
        case ScanPattern:
            registerName = "";
            ui->lineEdit_30->setText(QString::number(value) + "  " + registerName);
            break;
        default:
            registerName = "Unknown Register";
            break;
        }

        ui->textEdit->setText(registerName + ": " + QString::number(value));
        return;
    }

    if (currentRequestType == AllRegisters) {
        if (byteCount == 16) {
            QString displayText = "GELEN VERİ:\n";
            quint32 combinedValue = 0;

            for (int i = 0; i < data.size(); i += 2) {
                if (i + 1 >= data.size()) break;

                quint16 registerValue = (static_cast<quint8>(data[i]) << 8) | static_cast<quint8>(data[i + 1]);
                int registerIndex = i / 2;
                QString label = registerLabels.value(registerIndex, "Unknown");


                if (registerIndex == 0) {
                    ui->lineEdit_0->setText(QString::number(registerValue) + " " +label);
                } else if (registerIndex == 1) {
                    ui->lineEdit_1->setText(QString::number(registerValue) + " " + label);
                } else if (registerIndex == 2) {
                    ui->lineEdit_2->setText(QString::number(registerValue) + " " + label);
                } else if (registerIndex == 3) {
                    ui->lineEdit_3->setText(QString::number(registerValue) + " " + label);
                } else if (registerIndex == 6) {
                    ui->lineEdit_6->setText(QString::number(registerValue) + " " + label);
                } else if (registerIndex == 7) {
                    ui->lineEdit_7->setText(QString::number(registerValue) + " " + label);
                }



                if (registerIndex == 4) {
                    quint16 val4 = registerValue;
                    quint16 val5 = (static_cast<quint8>(data[i + 2]) << 8) | static_cast<quint8>(data[i + 3]);

                    combinedValue = (static_cast<quint32>(val4) << 16) | val5;


                    ui->lineEdit_4->setText(QString::number(combinedValue) + " Hz");

                    displayText += QString("Pulse Frequency (32-bit): %1\n").arg(combinedValue);
                    qDebug() << "DEBUG: Pulse Frequency (32-bit):" << combinedValue;

                    i += 2;
                } else {
                    displayText += QString("%1: %2\n").arg(label).arg(registerValue);
                    qDebug() << "DEBUG: Register" << registerIndex << ":" << registerValue;
                }
            }
            ui->textEdit->setText(displayText);
        }
        else if (byteCount == 2) {
            quint16 value = (static_cast<quint8>(data[0]) << 8) | static_cast<quint8>(data[1]);

            ui->lineEdit_30->setText(QString::number(value) + "");

            QString currentText = ui->textEdit->toPlainText();
            currentText += "GELEN VERİ:\nScanning pattern select: " + QString::number(value) + "\n";
            ui->textEdit->setText(currentText);
            qDebug() << "DEBUG: Register 30:" << value;
        }
    }
}

void MainWindow::on_clearButton_clicked()
{
    ui->textEdit->clear();

    ui->lineEdit_0->clear();
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_30->clear();

    /*ui->spinWriteBoxValue_0->clear();
ui->spinWriteBoxValue_1->clear();
ui->spinWriteBoxValue_2->clear();
ui->spinWriteBoxValue_3->clear();
ui->spinWriteBoxValue_6->clear();
ui->spinWriteBoxValue_7->clear();
ui->spinWriteBoxValue_30->clear();*/
}


void MainWindow::toggleConnection()
{
    if (isConnected) {
        if (serialPort->isOpen()) {

            if (isReading) {
                readTimer->stop();
                isReading = false;
                ui->readButton->setText("Oku");
            }

            serialPort->close();
            ui->lineEdit->setText("Bağlantı kapatıldı.");
        }
        ui->connectButton->setText("Connect");
        isConnected = false;
    } else {
        QString portName = ui->lineEdit_portName->text();
        serialPort->setPortName(portName);


        QSerialPort::BaudRate baudRate = static_cast<QSerialPort::BaudRate>(lastBaudRate);
        serialPort->setBaudRate(baudRate);

        if (serialPort->open(QIODevice::ReadWrite)) {
            ui->lineEdit->setText("Bağlantı açıldı: " + portName + "");
            ui->connectButton->setText("Disconnect");
            isConnected = true;
        } else {
            ui->lineEdit->setText("Seri port açılamadı.");
        }
    }
}
