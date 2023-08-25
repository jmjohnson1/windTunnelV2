/********************************************************************************
** Form generated from reading UI file 'airfoildialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRFOILDIALOG_H
#define UI_AIRFOILDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include "../../../WindTunnelGUI/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_AirfoilDialog
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *AirfoilDataPlot;

    void setupUi(QDialog *AirfoilDialog)
    {
        if (AirfoilDialog->objectName().isEmpty())
            AirfoilDialog->setObjectName("AirfoilDialog");
        AirfoilDialog->resize(522, 420);
        gridLayout = new QGridLayout(AirfoilDialog);
        gridLayout->setObjectName("gridLayout");
        AirfoilDataPlot = new QCustomPlot(AirfoilDialog);
        AirfoilDataPlot->setObjectName("AirfoilDataPlot");

        gridLayout->addWidget(AirfoilDataPlot, 0, 0, 1, 1);


        retranslateUi(AirfoilDialog);

        QMetaObject::connectSlotsByName(AirfoilDialog);
    } // setupUi

    void retranslateUi(QDialog *AirfoilDialog)
    {
        AirfoilDialog->setWindowTitle(QCoreApplication::translate("AirfoilDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AirfoilDialog: public Ui_AirfoilDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRFOILDIALOG_H
