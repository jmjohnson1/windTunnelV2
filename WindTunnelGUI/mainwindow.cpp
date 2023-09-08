#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "settingsdialog.h"

#include <QTimer>
#include <QMessageBox>
#include <chrono>
#include <QDebug>

static constexpr std::chrono::seconds kWriteTimeout = std::chrono::seconds{5};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_settings(new SettingsDialog(this)),
    m_timer(new QTimer(this)),
    m_serial(new QSerialPort(this)),
    m_airfoil(new AirfoilDialog(this)),
    m_messageHandler(new MessageHandler(this))
{
    ui->setupUi(this);

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);

    connect(ui->fan1ManualSlider, &QSlider::sliderMoved, this, &MainWindow::updateFanManualSliderReadout);
    connect(ui->fan1ManualSlider, &QSlider::valueChanged, this, &MainWindow::updateFanManualSliderReadout);
    connect(ui->autoSpeedSlider, &QSlider::sliderMoved, this, &MainWindow::updateFanAutoSliderReadout);
    connect(ui->autoSpeedSlider, &QSlider::valueChanged, this, &MainWindow::updateFanAutoSliderReadout);
    connect(ui->autoSpeedSetButton, &QPushButton::clicked, this, &MainWindow::autoSpeedSet);
    connect(ui->manualFanSetButton, &QPushButton::clicked, this, &MainWindow::manualPowerSet);
    connect(ui->button_OpenAirfoilDialog, &QPushButton::clicked, m_airfoil, &AirfoilDialog::show);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);

    initActionsConnections();
}

MainWindow::~MainWindow()
{
    delete m_settings;
    delete ui;
}

void MainWindow::openSerialPort() {
    const SettingsDialog::Settings p = m_settings->settings();
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);

    if (m_serial->open(QIODevice::ReadWrite)) {
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
    } else {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());
    }
}

void MainWindow::closeSerialPort() {
    if (m_serial->isOpen()) {
        m_serial->close();
    }
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
}

void MainWindow::writeData(const QByteArray &data) {
    const qint64 written = m_serial->write(data);
    if (written == data.size()) {
        m_bytesToWrite += written;
        m_timer->start(kWriteTimeout);
    } else {
        const QString error = tr("Failed to write all data to port %1.\n"
                                 "Error: %2").arg(m_serial->portName(),
                                       m_serial->errorString());

        showWriteError(error);
    }
}

void MainWindow::readData() {
    QByteArray data = m_serial->read(1);
    qDebug() << "Data: " << data;
    if (!strcmp(data, "<")) {
        storeMessage = true;
    } else if (!strcmp(data, ">")) {
        storeMessage = false;
        qDebug() << "Message: " << messageReceived;
        m_messageHandler->handleMessage(messageReceived);
        messageReceived.clear();
    } else if (storeMessage) {
        messageReceived.append(data);
    }
}

void MainWindow::handleError(QSerialPort::SerialPortError error) {
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::handleBytesWritten(qint64 bytes) {
    m_bytesToWrite -= bytes;
    if (m_bytesToWrite == 0) {
        m_timer->stop();
    }
}

void MainWindow::handleWriteTimeout() {
    const QString error = tr("Write operation timed out for port %1\n"
                             "Error: %2").arg(m_serial->portName(),
                                   m_serial->errorString());

    showWriteError(error);
}

void MainWindow::initActionsConnections() {
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(ui->actionConfigure, &QAction::triggered, m_settings, &SettingsDialog::show);
}

void MainWindow::updateFanManualSliderReadout(int position)
{
    ui->fan1ManualSliderReadout->setNum(position);
}


void MainWindow::updateFanAutoSliderReadout(int position)
{
    ui->autoSpeedSliderReadout->setNum(position);
}


void MainWindow::autoSpeedSet()
{
    ui->speedSetpointLCD->display(ui->autoSpeedSlider->value());

    QByteArray command("!SETSPEED");
    command.append(QByteArray::number(ui->autoSpeedSlider->value()));
    qDebug() << command;
}

void MainWindow::showStatusMessage(const QString &message)
{
    m_status->setText(message);
}

void MainWindow::showWriteError(const QString &message)
{
    QMessageBox::warning(this, tr("Warning"), message);
}

void MainWindow::manualPowerSet()
{
    QByteArray command("!SETPOWER");
    command.append(QByteArray::number(ui->fan1ManualSlider->value()));
    qDebug() << command;
}