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

private:
    Ui::AirfoilDialog *ui;
};

#endif // AIRFOILDIALOG_H
