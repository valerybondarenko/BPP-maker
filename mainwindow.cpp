#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Translator.h"
#include "DxfObject.h"
#include<QDebug>
#include<QFileDialog>
#include"Line.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

scene = new QGraphicsScene(this);
using namespace ru_tcl_dxf;
panelRect = new QGraphicsRectItem;
panelRect->setRect(0.0,0.0,680,660);
panelRect->setBrush(Qt::gray);
panelRect->setPen(QPen(Qt::red));
panelRect->setFlag(QGraphicsItem::ItemIsMovable);

scene->addItem(panelRect);
ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete lineItem;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "/home",
                                                      tr("AutoCAD (*.DXF)"));
    if(fileName.isEmpty())
        return;
    trans.readDXF(fileName.toStdString());
    itemList = trans.getEntities()->getItems();

    for (unsigned long long i=0;i<itemList.size();i++) {
        if(itemList.at(i)->elementType==ru_tcl_dxf::Entity::LINE){
           lineItem = new LineGraphicsItem();
           ru_tcl_dxf::Line *dxf_line = static_cast<ru_tcl_dxf::Line *>(itemList.at(i));
           lineItem->setL_Start(QPointF(dxf_line->getStart().getX(),dxf_line->getStart().getY()));
           lineItem->setL_End(QPointF(dxf_line->getEnd().getX(),dxf_line->getEnd().getY()));
           lineItem->setFlag(QGraphicsItem::ItemIsSelectable);
           lineItem->setParentItem(panelRect);
        }
    }
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}
