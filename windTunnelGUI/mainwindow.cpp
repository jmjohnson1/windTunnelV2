#include "mainwindow.h"
#include <QCheckBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QMenu>
#include <QPushButton>
#include <QRadioButton>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(manualFanControlGroup(), 0, 0);
    setLayout(grid);

    setWindowTitle(tr("Group Boxes"));
    resize(480, 320);
}

QGroupBox *MainWindow::manualFanControlGroup() {
    QGroupBox *groupBox = new QGroupBox(tr("Manual Fan Control"));
    groupBox->setCheckable(true);
    groupBox->setChecked(false);

    QSlider *slider = new QSlider(Qt::Horizontal, this);
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(slider, 0, 0);

    groupBox->setLayout(grid);
    return groupBox;
}
