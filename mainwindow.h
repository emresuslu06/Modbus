#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>
#include <QMessageBox>
#include <QSerialPortInfo>

#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:


    void connectToSelectedPort();


      void refreshPorts();


    void updatePortName();



    void on_btnConfirmPassword_clicked();
    void on_closeButton_clicked();

    void on_baudRateCombo_currentIndexChanged(int index);
    void readPulseFreqMSB_LSB();
    void sendCustomReadRequest();



    void sendReadRequest();
    void sendWriteRequest();
    void readData();
    void toggleConnection();
    void on_clearButton_clicked();
    void toggleContinuousRead();

    //void on_pushWriteButton_clicked();
    void writeSpecificRegister(quint16 registerAddress, quint16 value);

    void on_pushWriteButton_0_clicked();
    void on_pushWriteButton_1_clicked();

    void on_pushWriteButton_2_clicked();
    void on_pushWriteButton_3_clicked();

    void on_pushWriteButton_4_5_clicked();

    //void on_pushWriteButton_4_clicked();
    //void on_pushWriteButton_5_clicked();

    void on_pushWriteButton_6_clicked();
    void on_pushWriteButton_7_clicked();

    void on_pushWriteButton_30_clicked();




    // 9 tane ekledigim buton
    void readScanSpeed();
    void readScanWidth();
    void readPeakPower();
    void readDutyCycle();
    void readPulseFreqMSB();
    void readPulseFreqLSB();
    void readScanHeight();
    void readRotationAngle();
    void readScanPattern();


private:
    QSerialPort *serialPort;
    Ui::MainWindow *ui;



    bool validatePassword(const QString &password);
    void applyBaudRate(int baudRate);
    void updateUIState(bool isPasswordCorrect);
    bool baudRateChangeAllowed;
    const QString ADMIN_PASSWORD = "123456Qw";
    int lastBaudRate;
    bool isConnected;

      void setWriteAndReadButtonsEnabled(bool enabled);


        QTimer *readTimer;
    bool isReading;
    enum RequestType {
        None,
        AllRegisters,
        ScanSpeed,
        ScanWidth,
        PeakPower,
        PulseFreqMSB,
        DutyCycle,
        PulseFreqMSB_LSB,
        PulseFreqLSB,
        ScanHeight,
        RotationAngle,
        ScanPattern,
        CustomRead,
    };
    RequestType currentRequestType;
    unsigned short crc16(const QByteArray &data);
    QByteArray createModbusRequest(quint8 slaveAddress, quint8 functionCode, const QByteArray &data);
    void readSingleRegister(quint16 registerAddress, RequestType type);
};
#endif // MAINWINDOW_H
