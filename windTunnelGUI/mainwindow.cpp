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
    QGridLayout *grid = new QGridLayout;

    QLabel *fan1Label = new QLabel(tr("Fan 1:"));
    grid->addWidget(fan1Label, 0, 0);
    ValuedSlider *fan1Slider = new ValuedSlider(Qt::Horizontal, this);
    grid->addWidget(fan1Slider, 1, 0);

    QLabel *fan2Label = new QLabel(tr("Fan 2:"));
    grid->addWidget(fan2Label, 2, 0);
    ValuedSlider *fan2Slider = new ValuedSlider(Qt::Horizontal, this);
    grid->addWidget(fan2Slider, 3, 0);

    groupBox->setLayout(grid);
    return groupBox;
}

void MainWindow::fan1ManualSliderChanged() {

}
