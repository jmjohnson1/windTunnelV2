#ifndef AIRFOILDIALOG_H
#define AIRFOILDIALOG_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class AirfoilDialog;
}

class AirfoilDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AirfoilDialog(QWidget *parent = nullptr);
    ~AirfoilDialog();

public slots:
    void plotPressureData(QList<double> data);

private:
    Ui::AirfoilDialog *ui;
    void SetupPlot();
    int numberTaps = 20;
    QLCDNumber *LCDNumber = nullptr;
    QLabel *LCDLabels = nullptr;
};

#endif // AIRFOILDIALOG_H
