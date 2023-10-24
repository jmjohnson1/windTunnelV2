#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include "airfoildialog.h"
#include "messagehandler.h"
#include "sharedData.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class QLabel;
class SettingsDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void updateFanManualSliderReadout(int position);
    void updateFanAutoSliderReadout(int position);
    void autoSpeedSet();
    void writeData(const QByteArray &data);
    void readData();
    unsigned int checkStartBit(const QByteArray *data);
    unsigned int checkStopBit(const QByteArray *data, int startIndex = 0);

    void handleError(QSerialPort::SerialPortError error);
    void handleBytesWritten(qint64 bytes);
    void handleWriteTimeout();

    void manualPowerSet();
    void scanPressureTaps();

    void updateAirpseed(QList<float> data);

private:
    void initActionsConnections();
    void showStatusMessage(const QString &message);
    void showWriteError(const QString &message);

private:
    Ui::MainWindow *ui;
    QLabel *m_status = nullptr;
    SettingsDialog *m_settings = nullptr;
    qint64 m_bytesToWrite = 0;
    QTimer *m_timer = nullptr;
    QSerialPort *m_serial = nullptr;
    AirfoilDialog *m_airfoil = nullptr;
    MessageHandler *m_messageHandler = nullptr;
    QByteArray messageReceived;
    bool readInProgress = false;
    sharedData *m_sharedData = nullptr;
};
#endif // MAINWINDOW_H
