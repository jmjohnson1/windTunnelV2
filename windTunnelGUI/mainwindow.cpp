#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSlider *slider = new QSlider(Qt::Horizontal, this);
    slider->setRange(1, 4);
    slider->setSingleStep(1);
    ui->gridLayout1->addWidget(slider, 1, 0, 1, 3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

