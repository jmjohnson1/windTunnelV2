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

private slots:
  void on_pTapReadingsCheckbox_toggled(bool checked);

private:
    Ui::AirfoilDialog *ui;
    void SetupPlot();
    void runButtonPassthrough();
    int numberTaps = 20;
    QLabel *rawPValue = nullptr;
    QLabel *rawPLabel = nullptr;
    sharedData *af_sharedData = nullptr;

    const QList<double> x_by_c_airfoil  = {0.0, 0.0303, 0.0789, 0.1287, 0.1790, 0.2507, 0.3250, 0.3994, 0.5479, 0.7702,
                                        1.0, 0.7702, 0.5479, 0.3994, 0.3250, 0.2507, 0.1790, 0.1287, 0.0789, 0.0303};
    const QList<double> x_by_c_cylinder = {0.0, 0.0243, 0.0960, 0.2084, 0.3498, 0.5062, 0.6622, 0.8019, 0.9113, 0.9797,
                                        1.0, 0.9703, 0.8940, 0.7776, 0.6339, 0.4765, 0.3218, 0.1847, 0.0794, 0.0160};
};

#endif // AIRFOILDIALOG_H
