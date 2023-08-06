#include "airfoildialog.h"
#include "ui_airfoildialog.h"

AirfoilDialog::AirfoilDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AirfoilDialog)
{
    ui->setupUi(this);
}

AirfoilDialog::~AirfoilDialog()
{
    delete ui;
}
