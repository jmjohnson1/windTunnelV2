/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionConnect;
    QWidget *centralwidget;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QPushButton *button_OpenAirfoilDialog;
    QPushButton *button_OpenCylinderDialog;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *testSectionSpeedGroup;
    QGridLayout *gridLayout_3;
    QGroupBox *manualFanControlGroup;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *manualFanSetButton;
    QSpacerItem *horizontalSpacer_4;
    QSlider *fan1ManualSlider;
    QLabel *fan1ManualSliderReadout;
    QGroupBox *autoSpeedControlGroup;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *autoSpeedSetButton;
    QSlider *autoSpeedSlider;
    QLabel *autoSpeedSliderReadout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QLCDNumber *staticPressureLCD;
    QLCDNumber *speedSetpointLCD;
    QLCDNumber *totalPressureLCD;
    QLCDNumber *speedLCD;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName("actionDisconnect");
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName("actionConfigure");
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName("actionConnect");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_7 = new QGridLayout(centralwidget);
        gridLayout_7->setObjectName("gridLayout_7");
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName("gridLayout_6");
        button_OpenAirfoilDialog = new QPushButton(groupBox_3);
        button_OpenAirfoilDialog->setObjectName("button_OpenAirfoilDialog");

        gridLayout_6->addWidget(button_OpenAirfoilDialog, 0, 1, 1, 1);

        button_OpenCylinderDialog = new QPushButton(groupBox_3);
        button_OpenCylinderDialog->setObjectName("button_OpenCylinderDialog");

        gridLayout_6->addWidget(button_OpenCylinderDialog, 0, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 0, 4, 1, 1);


        gridLayout_7->addWidget(groupBox_3, 1, 0, 1, 2);

        testSectionSpeedGroup = new QGroupBox(centralwidget);
        testSectionSpeedGroup->setObjectName("testSectionSpeedGroup");
        gridLayout_3 = new QGridLayout(testSectionSpeedGroup);
        gridLayout_3->setObjectName("gridLayout_3");
        manualFanControlGroup = new QGroupBox(testSectionSpeedGroup);
        manualFanControlGroup->setObjectName("manualFanControlGroup");
        manualFanControlGroup->setCheckable(true);
        manualFanControlGroup->setChecked(false);
        gridLayout = new QGridLayout(manualFanControlGroup);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        manualFanSetButton = new QPushButton(manualFanControlGroup);
        manualFanSetButton->setObjectName("manualFanSetButton");

        gridLayout->addWidget(manualFanSetButton, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        fan1ManualSlider = new QSlider(manualFanControlGroup);
        fan1ManualSlider->setObjectName("fan1ManualSlider");
        fan1ManualSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(fan1ManualSlider, 0, 0, 1, 3);

        fan1ManualSliderReadout = new QLabel(manualFanControlGroup);
        fan1ManualSliderReadout->setObjectName("fan1ManualSliderReadout");

        gridLayout->addWidget(fan1ManualSliderReadout, 0, 3, 1, 1);


        gridLayout_3->addWidget(manualFanControlGroup, 0, 0, 1, 1);

        autoSpeedControlGroup = new QGroupBox(testSectionSpeedGroup);
        autoSpeedControlGroup->setObjectName("autoSpeedControlGroup");
        gridLayout_2 = new QGridLayout(autoSpeedControlGroup);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        autoSpeedSetButton = new QPushButton(autoSpeedControlGroup);
        autoSpeedSetButton->setObjectName("autoSpeedSetButton");

        gridLayout_2->addWidget(autoSpeedSetButton, 1, 1, 1, 1);

        autoSpeedSlider = new QSlider(autoSpeedControlGroup);
        autoSpeedSlider->setObjectName("autoSpeedSlider");
        autoSpeedSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(autoSpeedSlider, 0, 0, 1, 3);

        autoSpeedSliderReadout = new QLabel(autoSpeedControlGroup);
        autoSpeedSliderReadout->setObjectName("autoSpeedSliderReadout");

        gridLayout_2->addWidget(autoSpeedSliderReadout, 0, 3, 1, 1);


        gridLayout_3->addWidget(autoSpeedControlGroup, 1, 0, 1, 1);


        gridLayout_7->addWidget(testSectionSpeedGroup, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(300, 0));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName("gridLayout_4");
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName("gridLayout_5");
        staticPressureLCD = new QLCDNumber(groupBox_2);
        staticPressureLCD->setObjectName("staticPressureLCD");

        gridLayout_5->addWidget(staticPressureLCD, 1, 1, 1, 1);

        speedSetpointLCD = new QLCDNumber(groupBox_2);
        speedSetpointLCD->setObjectName("speedSetpointLCD");

        gridLayout_5->addWidget(speedSetpointLCD, 3, 1, 1, 1);

        totalPressureLCD = new QLCDNumber(groupBox_2);
        totalPressureLCD->setObjectName("totalPressureLCD");

        gridLayout_5->addWidget(totalPressureLCD, 0, 1, 1, 1);

        speedLCD = new QLCDNumber(groupBox_2);
        speedLCD->setObjectName("speedLCD");

        gridLayout_5->addWidget(speedLCD, 2, 1, 1, 1);

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


        gridLayout_7->addWidget(groupBox, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionConnect);
        toolBar->addAction(actionDisconnect);
        toolBar->addAction(actionConfigure);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        actionConfigure->setText(QCoreApplication::translate("MainWindow", "Configure", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Test Routines", nullptr));
        button_OpenAirfoilDialog->setText(QCoreApplication::translate("MainWindow", "Airfoil", nullptr));
        button_OpenCylinderDialog->setText(QCoreApplication::translate("MainWindow", "Cylinder", nullptr));
        testSectionSpeedGroup->setTitle(QCoreApplication::translate("MainWindow", "Test Section Speed", nullptr));
        manualFanControlGroup->setTitle(QCoreApplication::translate("MainWindow", "Manual Fan Control", nullptr));
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
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
