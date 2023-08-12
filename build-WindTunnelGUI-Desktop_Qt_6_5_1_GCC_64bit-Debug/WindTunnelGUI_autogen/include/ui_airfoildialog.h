/********************************************************************************
** Form generated from reading UI file 'airfoildialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRFOILDIALOG_H
#define UI_AIRFOILDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include "../../../WindTunnelGUI/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_AirfoilDialog
{
public:
    QCustomPlot *widget;

    void setupUi(QDialog *AirfoilDialog)
    {
        if (AirfoilDialog->objectName().isEmpty())
            AirfoilDialog->setObjectName("AirfoilDialog");
        AirfoilDialog->resize(522, 420);
        widget = new QCustomPlot(AirfoilDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(70, 60, 381, 301));

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
