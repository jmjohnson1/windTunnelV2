#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QGridLayout>
#include <QSlider>
#include <QLabel>
#include <QWidget>

class QGroupBox;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QGroupBox *manualFanControlGroup();
};

#endif
