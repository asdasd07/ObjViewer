#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->doubleSpinBox_7,
            SIGNAL(valueChanged(double)),
            ui->widget,
            SLOT(posX(double)));
    connect(ui->doubleSpinBox_8,
            SIGNAL(valueChanged(double)),
            ui->widget,
            SLOT(posY(double)));
    connect(ui->doubleSpinBox_9,
            SIGNAL(valueChanged(double)),
            ui->widget,
            SLOT(posZ(double)));

    connect(ui->doubleSpinBox,
            SIGNAL(valueChanged(double)),
            ui->widget,
            SLOT(rotX(double)));
    connect(ui->doubleSpinBox_2,
            SIGNAL(valueChanged(double)),
            ui->widget,
            SLOT(rotY(double)));
    connect(ui->doubleSpinBox_3,
            SIGNAL(valueChanged(double)),
            ui->widget,
            SLOT(rotZ(double)));

    connect(ui->doubleSpinBox_4,
            SIGNAL(valueChanged(double)),
            ui->widget,
            SLOT(sizX(double)));
    connect(ui->doubleSpinBox_5,
            SIGNAL(valueChanged(double)),
            ui->widget,
            SLOT(sizY(double)));
    connect(ui->doubleSpinBox_6,
            SIGNAL(valueChanged(double)),
            ui->widget,
            SLOT(sizZ(double)));
    connect(ui->spinBox,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(fo(int)));

    connect(ui->radioButton,
            SIGNAL(toggled(bool)),
            ui->widget,
            SLOT(OoP(bool)));

    connect(ui->Wireframe,
            SIGNAL(clicked(bool)),
            ui->widget,
            SLOT(wireframe(bool)));
    connect(ui->Backface,
            SIGNAL(clicked(bool)),
            ui->widget,
            SLOT(back(bool)));
    connect(ui->Texture,
            SIGNAL(clicked(bool)),
            ui->widget,
            SLOT(tex(bool)));
    connect(ui->Face,
            SIGNAL(clicked(bool)),
            ui->widget,
            SLOT(fac(bool)));
    connect(ui->Malarz,
            SIGNAL(clicked(bool)),
            ui->widget,
            SLOT(mal(bool)));
    connect(ui->Phong,
            SIGNAL(clicked(bool)),
            ui->widget,
            SLOT(pho(bool)));
    connect(ui->Normal,
            SIGNAL(clicked(bool)),
            ui->widget,
            SLOT(nm(bool)));

    connect(ui->horizontalSlider,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(ligW(int)));
    connect(ui->verticalSlider,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(ligH(int)));

    connect(ui->k1,
            SIGNAL(valueChanged(double)),
            ui->widget,
            SLOT(k1(double)));
    connect(ui->k2,
            SIGNAL(valueChanged(double)),
            ui->widget,
            SLOT(k2(double)));
    connect(ui->k3,
            SIGNAL(valueChanged(double)),
            ui->widget,
            SLOT(k3(double)));
    connect(ui->k4,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(k4(int)));
    connect(ui->Load,
            SIGNAL(clicked(bool)),
            ui->widget,
            SLOT(load()));


}

MainWindow::~MainWindow()
{
    delete ui;
}
