#include "airfoildialog.h"
#include "ui_airfoildialog.h"

AirfoilDialog::AirfoilDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AirfoilDialog)
{
    ui->setupUi(this);
    SetupPlot();
}

AirfoilDialog::~AirfoilDialog()
{
    delete ui;
}

void AirfoilDialog::SetupPlot() {
    ui->AirfoilDataPlot->addGraph();
    ui->AirfoilDataPlot->xAxis->setRange(0, 1);
    ui->AirfoilDataPlot->yAxis->setRange(-1, 1);
    ui->AirfoilDataPlot->xAxis->setLabel(QString::fromUtf8("x/c"));
    ui->AirfoilDataPlot->yAxis->setLabel(QString::fromUtf8("Cₚ"));
}

void AirfoilDialog::plotPressureData(QList<double> data) {
    QVector<double> x = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    ui->AirfoilDataPlot->graph(0)->setData(x, data);
}
