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
panelDialog = new PanelDialog(this);
connect(panelDialog,SIGNAL(confirm(float,float,float)),this,SLOT(panelData(float,float,float)));
panelRect->setRect(0.0,0.0,680,660);
panelRect->setBrush(Qt::gray);
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
    float leftCorner = 1525.0;
    float rightCorner =0.0;
    float bottomCorner = 1525.0;
    float topCorner = 0.0;
     for (unsigned long long i=0;i<itemList.size();i++)
    {
        switch (itemList.at(i)->elementType)        
        {
        case  ru_tcl_dxf::Entity::LINE:
        {
            lineItem = new LineGraphicsItem();
            ru_tcl_dxf::Line *dxf_line = static_cast<ru_tcl_dxf::Line *>(itemList.at(i));

            // lift panel corner
            if(leftCorner > dxf_line->getStart().getX())
                leftCorner = dxf_line->getStart().getX();
            if(leftCorner > dxf_line->getEnd().getX())
                leftCorner = dxf_line->getEnd().getX();
            // right panel corner
            if(rightCorner < dxf_line->getStart().getX())
                rightCorner = dxf_line->getStart().getX();
            if(rightCorner < dxf_line->getEnd().getX())
                rightCorner = dxf_line->getEnd().getX();
            // bottom panel corner
            if(bottomCorner > dxf_line->getStart().getY())
                bottomCorner = dxf_line->getStart().getY();
            if(bottomCorner > dxf_line->getEnd().getY())
                bottomCorner=dxf_line->getEnd().getY();
            // top panel corner
            if(topCorner < dxf_line->getStart().getY())
                topCorner = dxf_line->getStart().getY();
            if(topCorner < dxf_line->getEnd().getY())
                topCorner=dxf_line->getEnd().getY();
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
            if(leftCorner>arcCenter.x()-arcRadius)
                leftCorner=arcCenter.x()-arcRadius;
            if(rightCorner<arcCenter.x()+arcRadius)
                rightCorner=arcCenter.x()+arcRadius;
            if(bottomCorner>arcCenter.y()-arcRadius)
                bottomCorner=arcCenter.y()-arcRadius;
            if(topCorner<arcCenter.y()+arcRadius)
                topCorner=arcCenter.y()+arcRadius;
            arcItem  = new ArcGraphicsItem(panelRect,arcCenter,arcStartAngle,arcEndAngle,arcRadius);
            arcItem->setFlag(QGraphicsItem::ItemIsSelectable);
            break;
        }
        case ru_tcl_dxf::Entity::CIRCLE:
        {
            ru_tcl_dxf::Circle *dxf_circle = static_cast<ru_tcl_dxf::Circle *>(itemList.at(i));
            QPointF circleCenter(dxf_circle->getCenter().getX(),dxf_circle->getCenter().getY());
            float circleRadius = dxf_circle->getRadius();
            if(leftCorner>circleCenter.x()-circleRadius)
                leftCorner=circleCenter.x()-circleRadius;
            if(rightCorner<circleCenter.x()+circleRadius)
                rightCorner=circleCenter.x()+circleRadius;
            if(bottomCorner>circleCenter.y()-circleRadius)
                bottomCorner=circleCenter.y()-circleRadius;
            if(topCorner<circleCenter.y()+circleRadius)
                topCorner=circleCenter.y()+circleRadius;
            circleItem = new CircleGraphicsItem(panelRect,circleCenter,circleRadius);
        }
        default:{}
        }
    }
     panelDialog->init(rightCorner-leftCorner,
                       topCorner-bottomCorner,
                       18.0);
     panelDialog->exec();

     for (int i = 0;i<panelRect->childItems().count();i++) {
         static_cast<GraphicsItem*>(panelRect->childItems().at(i))->mooveObj(-leftCorner,-bottomCorner,0);
     }
     scene->addItem(panelRect);
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::panelData(float lpx, float lpy, float lpz)
{
    panelRect->setRect(0.0,0.0,lpx,lpy);
}
