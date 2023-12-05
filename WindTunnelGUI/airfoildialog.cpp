#include "airfoildialog.h"
#include "ui_airfoildialog.h"

AirfoilDialog::AirfoilDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AirfoilDialog)
{
  rawPValue = new QLabel[numberTaps];
    rawPLabel = new QLabel[numberTaps];

    ui->setupUi(this);
    SetupPlot();

    // Create the labels for displaying the pressure tap values (Not Cp)
    int numColumns = 5;
    int numRows = numberTaps / 5;
    if (numberTaps < 5) {
        numColumns = numberTaps;
    }
    numRows *= 2; // For the labels
    int value_ndx = 0;
    int label_ndx = 0;
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numColumns; col++) {
            if (row % 2 != 0) {
            ui->gridLayout_pTaps->addWidget(&rawPValue[value_ndx], row, col, 1, 1);
              value_ndx++;
            } else {
                ui->gridLayout_pTaps->addWidget(&rawPLabel[label_ndx], row, col, 1, 1);
                rawPLabel[label_ndx].setText(QVariant(label_ndx + 1).toString());
                label_ndx++;
            }
        }
    }

    connect(ui->pTap_runButton, &QPushButton::clicked, this, &AirfoilDialog::runButtonPassthrough);
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
    ui->AirfoilDataPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->AirfoilDataPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
}

void AirfoilDialog::plotPressureData(QList<double> data) {
    // TODO: Replace x
    QVector<double> x = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    for (int i = 0; i < data.size(); i++) {
        // Data is the difference between static pressure at tap and free stream pressure
        // Cp = (p_s - p_inf) / q_inf
        data[i] = data[i]/af_sharedData->getDynamicPressure();
    }
    // TODO: Fix persistence
    ui->AirfoilDataPlot->graph(0)->setData(x, data);
    for (int ndx = 0; ndx < numberTaps; ndx++) {
        rawPValue[ndx].setText(QVariant(data[ndx]).toString());
    }
}

void AirfoilDialog::runButtonPassthrough() {
    emit runButtonPushed();
}



void AirfoilDialog::on_pTapReadingsCheckbox_toggled(bool checked)
{
    ui->pTapLCD_group->setVisible(checked);
}

