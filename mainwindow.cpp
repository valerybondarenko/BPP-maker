#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"painter.h"
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
    Painter pntr;
    items = tr.getEntities()->getItems();
    for (unsigned long long i=0;i<items.size();i++) {
        items.at(i)->draw(&pntr);
    }






}

MainWindow::~MainWindow()
{
    delete ui;
}

