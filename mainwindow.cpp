#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Translator.h"
#include "DxfObject.h"
#include<QDebug>
#include<QFileDialog>
#include"Line.h"
#include "Arc.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


scene = new QGraphicsScene(this);
using namespace ru_tcl_dxf;
panelRect = new QGraphicsRectItem;
panelDialog = new PanelDialog(this);
connect(panelDialog,SIGNAL(confirm(float,float,float)),this,SLOT(panelData(float,float,float)));
panelRect->setRect(0.0,0.0,680,660);
panelRect->setBrush(Qt::gray);
panelRect->setPen(QPen(Qt::red));
panelRect->setFlag(QGraphicsItem::ItemIsMovable);
panelDialog->init(800.0,500.0,18.0);
panelDialog->exec();
scene->addItem(panelRect);
//arcItem = new ArcGraphicsItem(nullptr,QPointF(100.0,100.0),-90.0,180.0,80);
//arcItem->setParentItem(panelRect);



ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete panelRect;
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
        } else if (itemList.at(i)->elementType==ru_tcl_dxf::Entity::ARC){
            ru_tcl_dxf::Arc *dxf_arc = static_cast<ru_tcl_dxf::Arc *>(itemList.at(i));
            QPointF arcCenter(dxf_arc->getCenter().getX(),dxf_arc->getCenter().getY());
            float arcStartAngle = dxf_arc->getStartAngle();
            float arcEndAngle = dxf_arc->getEndAngle();
            float arcRadius = dxf_arc->getRadius();
           arcItem  = new ArcGraphicsItem(nullptr,arcCenter,arcStartAngle,arcEndAngle,arcRadius);
           arcItem->setFlag(QGraphicsItem::ItemIsSelectable);
           arcItem->setParentItem(panelRect);
        }
    }
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::panelData(float lpx, float lpy, float lpz)
{
    panelRect->setRect(0.0,0.0,lpx,lpy);
}
