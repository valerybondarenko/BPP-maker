#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Translator.h"
#include "DxfObject.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
using namespace ru_tcl_dxf;
    Translator tr;
    tr.readDXF("C://1.DXF");
    tr.getEntities()->getItems().at(0)->draw();







}

MainWindow::~MainWindow()
{
    delete ui;
}

