#ifndef AIRFOILDIALOG_H
#define AIRFOILDIALOG_H

#include <QDialog>
#include "qcustomplot.h"
#include "sharedData.h"

namespace Ui {
class AirfoilDialog;
}

class AirfoilDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AirfoilDialog(QWidget *parent = nullptr);
    ~AirfoilDialog();

    void setSharedData(sharedData *sd) {
      af_sharedData = sd;
    }

public slots:
    void plotPressureData(QList<double> data);

signals:
    void runButtonPushed();

private:
    Ui::AirfoilDialog *ui;
    void SetupPlot();
    void runButtonPassthrough();
    int numberTaps = 20;
    QLCDNumber *LCDNumber = nullptr;
    QLabel *LCDLabels = nullptr;
    sharedData *af_sharedData = nullptr;
};

#endif // AIRFOILDIALOG_H
