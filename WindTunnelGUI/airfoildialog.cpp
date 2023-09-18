#include "airfoildialog.h"
#include "ui_airfoildialog.h"

AirfoilDialog::AirfoilDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AirfoilDialog)
{
    LCDNumber = new QLCDNumber[numberTaps];
    LCDLabels = new QLabel[numberTaps];

    ui->setupUi(this);
    SetupPlot();

    int numColumns = 5;
    int numRows = numberTaps / 5;
    if (numberTaps < 5) {
        numColumns = numberTaps;
    }
    numRows *= 2; // For the labels

    int lcd_ndx = 0;
    int label_ndx = 0;
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numColumns; col++) {
            if (row % 2 != 0) {
                ui->gridLayout_pTaps->addWidget(&LCDNumber[lcd_ndx], row, col, 1, 1);
                lcd_ndx++;
            } else {
                ui->gridLayout_pTaps->addWidget(&LCDLabels[label_ndx], row, col, 1, 1);
                LCDLabels[label_ndx].setText(QVariant(label_ndx + 1).toString());
                label_ndx++;
            }
        }
    }
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
    // TODO: Replace x
    QVector<double> x = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    ui->AirfoilDataPlot->graph(0)->setData(x, data);
    for (int ndx = 0; ndx < numberTaps; ndx++) {
        LCDLabels[ndx].setNum(data[ndx]);
    }
}
