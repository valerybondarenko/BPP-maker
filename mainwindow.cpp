#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Translator.h"
#include "DxfObject.h"
#include "Entity.h"
#include<QDebug>
#include<QFileDialog>
#include"Line.h"
#include "Arc.h"
#include "Circle.h"
#include "graphicsitem.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

scene = new QGraphicsScene(this);
using namespace ru_tcl_dxf;
panelRect = new QGraphicsRectItem;
importRect  = new QGraphicsRectItem;
panelDialog = new PanelDialog(this);
connect(panelDialog,SIGNAL(confirm(float,float,float)),this,SLOT(panelData(float,float,float)));
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
    float leftLimit = 1525.0;
    float rightLimit = 0.0;
    float bottomLimit = 1525.0;
    float topLimit = 0.0;
     for (unsigned long long i=0;i<itemList.size();i++)
    {
        switch (itemList.at(i)->elementType)        
        {
        case  ru_tcl_dxf::Entity::LINE:
        {
            lineItem = new LineGraphicsItem();
            ru_tcl_dxf::Line *dxf_line = static_cast<ru_tcl_dxf::Line *>(itemList.at(i));
            // left panel limit
            if(leftLimit > dxf_line->getStart().getX())
                leftLimit = dxf_line->getStart().getX();
            if(leftLimit > dxf_line->getEnd().getX())
                leftLimit = dxf_line->getEnd().getX();
            // right panel corner
            if(rightLimit < dxf_line->getStart().getX())
                rightLimit = dxf_line->getStart().getX();
            if(rightLimit < dxf_line->getEnd().getX())
                rightLimit = dxf_line->getEnd().getX();
            // bottom panel corner
            if(bottomLimit > dxf_line->getStart().getY())
                bottomLimit = dxf_line->getStart().getY();
            if(bottomLimit > dxf_line->getEnd().getY())
                bottomLimit=dxf_line->getEnd().getY();
            // top panel corner
            if(topLimit < dxf_line->getStart().getY())
                topLimit = dxf_line->getStart().getY();
            if(topLimit < dxf_line->getEnd().getY())
                topLimit=dxf_line->getEnd().getY();
            lineItem->setL_Start(QPointF(dxf_line->getStart().getX(),dxf_line->getStart().getY()));
            lineItem->setL_End(QPointF(dxf_line->getEnd().getX(),dxf_line->getEnd().getY()));
            lineItem->setFlag(QGraphicsItem::ItemIsSelectable);
            lineItem->setParentItem(panelRect);
            break;
        }
        case ru_tcl_dxf::Entity::ARC:
        {
            ru_tcl_dxf::Arc *dxf_arc = static_cast<ru_tcl_dxf::Arc *>(itemList.at(i));
            QPointF arcCenter(dxf_arc->getCenter().getX(),dxf_arc->getCenter().getY());
            float arcStartAngle = dxf_arc->getStartAngle();
            float arcEndAngle = dxf_arc->getEndAngle();
            float arcRadius = dxf_arc->getRadius();
            if(leftLimit>arcCenter.x()-arcRadius)
                leftLimit=arcCenter.x()-arcRadius;
            if(rightLimit<arcCenter.x()+arcRadius)
                rightLimit=arcCenter.x()+arcRadius;
            if(bottomLimit>arcCenter.y()-arcRadius)
                bottomLimit=arcCenter.y()-arcRadius;
            if(topLimit<arcCenter.y()+arcRadius)
                topLimit=arcCenter.y()+arcRadius;
            arcItem  = new ArcGraphicsItem(panelRect,arcCenter,arcStartAngle,arcEndAngle,arcRadius);
            arcItem->setFlag(QGraphicsItem::ItemIsSelectable);
            break;
        }
        case ru_tcl_dxf::Entity::CIRCLE:
        {
            ru_tcl_dxf::Circle *dxf_circle = static_cast<ru_tcl_dxf::Circle *>(itemList.at(i));
            QPointF circleCenter(dxf_circle->getCenter().getX(),dxf_circle->getCenter().getY());
            float circleRadius = dxf_circle->getRadius();
            if(leftLimit>circleCenter.x()-circleRadius)
                leftLimit=circleCenter.x()-circleRadius;
            if(rightLimit<circleCenter.x()+circleRadius)
                rightLimit=circleCenter.x()+circleRadius;
            if(bottomLimit>circleCenter.y()-circleRadius)
                bottomLimit=circleCenter.y()-circleRadius;
            if(topLimit<circleCenter.y()+circleRadius)
                topLimit=circleCenter.y()+circleRadius;
            circleItem = new CircleGraphicsItem(panelRect,circleCenter,circleRadius);
        }
        default:{}
        }
    }
     panelDialog->init(rightLimit-leftLimit,
                       topLimit-bottomLimit,
                       18.0);
     panelDialog->exec();

     for (int i = 0;i<panelRect->childItems().count();i++) {
         static_cast<GraphicsItem*>(panelRect->childItems().at(i))->mooveObj(-leftLimit,-bottomLimit,0);
     }
     scene->addItem(panelRect);
     scene->addItem(importRect);
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::panelData(float lpx, float lpy, float lpz)
{
    QPen greenPen(Qt::green);
    greenPen.setWidth(1);
    QPen bluePen(Qt::blue);
    bluePen.setWidth(1);
    importRect->setRect(0.0,0.0,lpx,lpy);
    importRect->setPen(greenPen);
    panelRect->setRect(lpx+50,0.0,lpx,lpy);
    panelRect->setPen(bluePen);
}
