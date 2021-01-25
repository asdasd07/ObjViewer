/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "d3.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    d3 *widget;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_2;
    QSlider *verticalSlider;
    QRadioButton *radioButton;
    QCheckBox *Texture;
    QSlider *horizontalSlider;
    QCheckBox *Phong;
    QCheckBox *Backface;
    QRadioButton *radioButton_2;
    QCheckBox *Wireframe;
    QSpinBox *spinBox;
    QCheckBox *Malarz;
    QCheckBox *Face;
    QDoubleSpinBox *k1;
    QDoubleSpinBox *k2;
    QDoubleSpinBox *k3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *Normal;
    QSpinBox *k4;
    QPushButton *Load;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1230, 700);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new d3(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 30, 900, 600));
        doubleSpinBox_7 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(970, 30, 62, 22));
        doubleSpinBox_7->setMinimum(-999.000000000000000);
        doubleSpinBox_7->setMaximum(999.000000000000000);
        doubleSpinBox_7->setSingleStep(0.100000000000000);
        doubleSpinBox_8 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        doubleSpinBox_8->setGeometry(QRect(1040, 30, 62, 22));
        doubleSpinBox_8->setMinimum(-999.000000000000000);
        doubleSpinBox_8->setMaximum(999.000000000000000);
        doubleSpinBox_8->setSingleStep(0.100000000000000);
        doubleSpinBox = new QDoubleSpinBox(centralWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(970, 80, 62, 22));
        doubleSpinBox->setDecimals(2);
        doubleSpinBox->setMinimum(-100.000000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox->setValue(0.000000000000000);
        doubleSpinBox_5 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setGeometry(QRect(1040, 130, 62, 22));
        doubleSpinBox_5->setDecimals(2);
        doubleSpinBox_5->setMinimum(-100.000000000000000);
        doubleSpinBox_5->setSingleStep(0.100000000000000);
        doubleSpinBox_5->setValue(1.000000000000000);
        doubleSpinBox_9 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        doubleSpinBox_9->setGeometry(QRect(1110, 30, 62, 22));
        doubleSpinBox_9->setDecimals(2);
        doubleSpinBox_9->setMinimum(-999.000000000000000);
        doubleSpinBox_9->setMaximum(999.000000000000000);
        doubleSpinBox_9->setSingleStep(0.100000000000000);
        doubleSpinBox_9->setValue(5.000000000000000);
        doubleSpinBox_4 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(970, 130, 62, 22));
        doubleSpinBox_4->setDecimals(2);
        doubleSpinBox_4->setMinimum(-100.000000000000000);
        doubleSpinBox_4->setSingleStep(0.100000000000000);
        doubleSpinBox_4->setValue(1.000000000000000);
        doubleSpinBox_3 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(1110, 80, 62, 22));
        doubleSpinBox_3->setDecimals(2);
        doubleSpinBox_3->setMinimum(-100.000000000000000);
        doubleSpinBox_3->setSingleStep(0.100000000000000);
        doubleSpinBox_3->setValue(0.000000000000000);
        doubleSpinBox_6 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(1110, 130, 62, 22));
        doubleSpinBox_6->setDecimals(2);
        doubleSpinBox_6->setMinimum(-100.000000000000000);
        doubleSpinBox_6->setSingleStep(0.100000000000000);
        doubleSpinBox_6->setValue(1.000000000000000);
        doubleSpinBox_2 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(1040, 80, 62, 22));
        doubleSpinBox_2->setDecimals(2);
        doubleSpinBox_2->setMinimum(-100.000000000000000);
        doubleSpinBox_2->setSingleStep(0.100000000000000);
        doubleSpinBox_2->setValue(0.000000000000000);
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(1160, 380, 22, 160));
        verticalSlider->setMinimum(-90);
        verticalSlider->setMaximum(90);
        verticalSlider->setOrientation(Qt::Vertical);
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(970, 170, 82, 17));
        radioButton->setChecked(true);
        Texture = new QCheckBox(centralWidget);
        Texture->setObjectName(QString::fromUtf8("Texture"));
        Texture->setGeometry(QRect(970, 310, 70, 17));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(980, 450, 160, 22));
        horizontalSlider->setMaximum(360);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setValue(360);
        horizontalSlider->setSliderPosition(360);
        horizontalSlider->setOrientation(Qt::Horizontal);
        Phong = new QCheckBox(centralWidget);
        Phong->setObjectName(QString::fromUtf8("Phong"));
        Phong->setGeometry(QRect(970, 360, 70, 17));
        Backface = new QCheckBox(centralWidget);
        Backface->setObjectName(QString::fromUtf8("Backface"));
        Backface->setGeometry(QRect(1080, 250, 70, 17));
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(1060, 170, 82, 17));
        Wireframe = new QCheckBox(centralWidget);
        Wireframe->setObjectName(QString::fromUtf8("Wireframe"));
        Wireframe->setGeometry(QRect(970, 250, 70, 17));
        Wireframe->setChecked(true);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(1090, 200, 42, 22));
        spinBox->setMinimum(-1000);
        spinBox->setMaximum(1000);
        spinBox->setValue(500);
        Malarz = new QCheckBox(centralWidget);
        Malarz->setObjectName(QString::fromUtf8("Malarz"));
        Malarz->setGeometry(QRect(1080, 280, 70, 17));
        Face = new QCheckBox(centralWidget);
        Face->setObjectName(QString::fromUtf8("Face"));
        Face->setGeometry(QRect(970, 280, 70, 17));
        k1 = new QDoubleSpinBox(centralWidget);
        k1->setObjectName(QString::fromUtf8("k1"));
        k1->setGeometry(QRect(970, 550, 41, 22));
        k1->setMaximum(10.000000000000000);
        k1->setSingleStep(0.100000000000000);
        k1->setValue(1.000000000000000);
        k2 = new QDoubleSpinBox(centralWidget);
        k2->setObjectName(QString::fromUtf8("k2"));
        k2->setGeometry(QRect(1020, 550, 41, 22));
        k2->setMaximum(2.000000000000000);
        k2->setSingleStep(0.100000000000000);
        k2->setValue(1.000000000000000);
        k3 = new QDoubleSpinBox(centralWidget);
        k3->setObjectName(QString::fromUtf8("k3"));
        k3->setGeometry(QRect(1070, 550, 41, 22));
        k3->setMaximum(10.000000000000000);
        k3->setSingleStep(0.100000000000000);
        k3->setValue(1.000000000000000);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(970, 0, 51, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(970, 60, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(970, 110, 47, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1060, 200, 31, 16));
        Normal = new QCheckBox(centralWidget);
        Normal->setObjectName(QString::fromUtf8("Normal"));
        Normal->setGeometry(QRect(1080, 310, 91, 17));
        k4 = new QSpinBox(centralWidget);
        k4->setObjectName(QString::fromUtf8("k4"));
        k4->setGeometry(QRect(1120, 550, 42, 22));
        k4->setMaximum(100);
        k4->setValue(20);
        Load = new QPushButton(centralWidget);
        Load->setObjectName(QString::fromUtf8("Load"));
        Load->setGeometry(QRect(970, 600, 75, 23));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(980, 530, 31, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(980, 440, 91, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1080, 530, 31, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1130, 530, 31, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(990, 480, 151, 31));
        label_9->setText(QString::fromUtf8("I = Ka + Kd * (N dot L) +\n"
"  + Ks * (N dot ( L + V / 2))^n"));
        label_9->setTextFormat(Qt::AutoText);
        label_9->setWordWrap(false);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(1130, 360, 71, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(1030, 530, 31, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1230, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Obj Viewer", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Ortographic", nullptr));
        Texture->setText(QCoreApplication::translate("MainWindow", "Texture", nullptr));
        Phong->setText(QCoreApplication::translate("MainWindow", "Phong", nullptr));
        Backface->setText(QCoreApplication::translate("MainWindow", "Backface", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Perspective", nullptr));
        Wireframe->setText(QCoreApplication::translate("MainWindow", "Wireframe", nullptr));
        Malarz->setText(QCoreApplication::translate("MainWindow", "Painter", nullptr));
        Face->setText(QCoreApplication::translate("MainWindow", "Face", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "FOV", nullptr));
        Normal->setText(QCoreApplication::translate("MainWindow", "Normal Map", nullptr));
        Load->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Ka", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Horizontal light", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Ks", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "n", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Vertical light", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Kd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
