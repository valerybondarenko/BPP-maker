#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"painter.h"
#include "Translator.h"
#include "DxfObject.h"
#include<QDebug>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
using namespace ru_tcl_dxf;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "/home",
                                                      tr("AutoCAD (*.DXF)"));
    if(fileName.isEmpty())
        return;
    trans.readDXF(fileName.toStdString());
    Painter painter(this);
    items = trans.getEntities()->getItems();
    painter.setItems(&items);
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}
