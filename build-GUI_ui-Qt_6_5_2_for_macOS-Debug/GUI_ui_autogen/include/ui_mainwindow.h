/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *testSectionSpeedGroup;
    QGridLayout *gridLayout_3;
    QGroupBox *manualFanControlGroup;
    QGridLayout *gridLayout;
    QLabel *fan2ManualSliderReadout;
    QPushButton *manualFanSetButton;
    QLabel *fan1ManualSliderReadout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSlider *fan2ManualSlider;
    QSlider *fan1ManualSlider;
    QGroupBox *autoSpeedControlGroup;
    QGridLayout *gridLayout_2;
    QPushButton *autoSpeedSetButton;
    QLabel *autoSpeedSliderReadout;
    QSpacerItem *horizontalSpacer;
    QSlider *autoSpeedSlider;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_4;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        testSectionSpeedGroup = new QGroupBox(centralwidget);
        testSectionSpeedGroup->setObjectName("testSectionSpeedGroup");
        testSectionSpeedGroup->setGeometry(QRect(30, 30, 300, 300));
        gridLayout_3 = new QGridLayout(testSectionSpeedGroup);
        gridLayout_3->setObjectName("gridLayout_3");
        manualFanControlGroup = new QGroupBox(testSectionSpeedGroup);
        manualFanControlGroup->setObjectName("manualFanControlGroup");
        manualFanControlGroup->setCheckable(true);
        manualFanControlGroup->setChecked(false);
        gridLayout = new QGridLayout(manualFanControlGroup);
        gridLayout->setObjectName("gridLayout");
        fan2ManualSliderReadout = new QLabel(manualFanControlGroup);
        fan2ManualSliderReadout->setObjectName("fan2ManualSliderReadout");

        gridLayout->addWidget(fan2ManualSliderReadout, 1, 2, 1, 1);

        manualFanSetButton = new QPushButton(manualFanControlGroup);
        manualFanSetButton->setObjectName("manualFanSetButton");

        gridLayout->addWidget(manualFanSetButton, 2, 1, 1, 1);

        fan1ManualSliderReadout = new QLabel(manualFanControlGroup);
        fan1ManualSliderReadout->setObjectName("fan1ManualSliderReadout");

        gridLayout->addWidget(fan1ManualSliderReadout, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        fan2ManualSlider = new QSlider(manualFanControlGroup);
        fan2ManualSlider->setObjectName("fan2ManualSlider");
        fan2ManualSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(fan2ManualSlider, 1, 0, 1, 2);

        fan1ManualSlider = new QSlider(manualFanControlGroup);
        fan1ManualSlider->setObjectName("fan1ManualSlider");
        fan1ManualSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(fan1ManualSlider, 0, 0, 1, 2);


        gridLayout_3->addWidget(manualFanControlGroup, 0, 0, 1, 1);

        autoSpeedControlGroup = new QGroupBox(testSectionSpeedGroup);
        autoSpeedControlGroup->setObjectName("autoSpeedControlGroup");
        gridLayout_2 = new QGridLayout(autoSpeedControlGroup);
        gridLayout_2->setObjectName("gridLayout_2");
        autoSpeedSetButton = new QPushButton(autoSpeedControlGroup);
        autoSpeedSetButton->setObjectName("autoSpeedSetButton");

        gridLayout_2->addWidget(autoSpeedSetButton, 1, 1, 1, 1);

        autoSpeedSliderReadout = new QLabel(autoSpeedControlGroup);
        autoSpeedSliderReadout->setObjectName("autoSpeedSliderReadout");

        gridLayout_2->addWidget(autoSpeedSliderReadout, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        autoSpeedSlider = new QSlider(autoSpeedControlGroup);
        autoSpeedSlider->setObjectName("autoSpeedSlider");
        autoSpeedSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(autoSpeedSlider, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        gridLayout_3->addWidget(autoSpeedControlGroup, 1, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(380, 30, 300, 300));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName("gridLayout_4");
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName("gridLayout_5");
        lcdNumber_2 = new QLCDNumber(groupBox_2);
        lcdNumber_2->setObjectName("lcdNumber_2");

        gridLayout_5->addWidget(lcdNumber_2, 1, 1, 1, 1);

        lcdNumber_4 = new QLCDNumber(groupBox_2);
        lcdNumber_4->setObjectName("lcdNumber_4");

        gridLayout_5->addWidget(lcdNumber_4, 3, 1, 1, 1);

        lcdNumber = new QLCDNumber(groupBox_2);
        lcdNumber->setObjectName("lcdNumber");

        gridLayout_5->addWidget(lcdNumber, 0, 1, 1, 1);

        lcdNumber_3 = new QLCDNumber(groupBox_2);
        lcdNumber_3->setObjectName("lcdNumber_3");

        gridLayout_5->addWidget(lcdNumber_3, 2, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName("label");

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");

        gridLayout_5->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");

        gridLayout_5->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");

        gridLayout_5->addWidget(label_4, 3, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        testSectionSpeedGroup->setTitle(QCoreApplication::translate("MainWindow", "Test Section Speed", nullptr));
        manualFanControlGroup->setTitle(QCoreApplication::translate("MainWindow", "Manual Fan Control", nullptr));
        fan2ManualSliderReadout->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        manualFanSetButton->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        fan1ManualSliderReadout->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        autoSpeedControlGroup->setTitle(QCoreApplication::translate("MainWindow", "Speed Selection", nullptr));
        autoSpeedSetButton->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        autoSpeedSliderReadout->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Airspeed Measurements", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Total Pressure", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Static Pressure", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Speed Setpoint", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
