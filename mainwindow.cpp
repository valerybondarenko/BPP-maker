#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Translator.h"
#include "DxfObject.h"
#include<QDebug>
#include<QFileDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

scene = new QGraphicsScene(this);
using namespace ru_tcl_dxf;
panelRect.setRect(0.0,0.0,680,660);
panelRect.setBrush(Qt::gray);
QPen redPen(Qt::red);
panelRect.setPen(redPen);
panelRect.setFlag(QGraphicsItem::ItemIsMovable);
//lineItem = new LineGraphicsItem();
//lineItem->setL_Start(QPointF(15.0,15.0));
//lineItem->setL_End(QPointF(45.0,45.0));
//lineItem->setFlag(QGraphicsItem::ItemIsSelectable);
//lineItem->setParentItem(&panelRect);
//scene->addItem(lineItem);

scene->addItem(&panelRect);
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
    trans.getEntities()->setParentGraphicsItem(&panelRect);
    trans.readDXF(fileName.toStdString());
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}
