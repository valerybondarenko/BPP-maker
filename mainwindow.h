#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "Translator.h"
#include"Entity.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "linegraphicsitem.h"
#include "arcgraphicsitem.h"
#include "paneldialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionQuit_triggered();
    void panelData(float lpx,float lpy,float lpz);

private:
    Ui::MainWindow *ui;   

ru_tcl_dxf::Translator trans;
std::vector <ru_tcl_dxf::Entity*> itemList;

QGraphicsScene *scene;
QGraphicsRectItem *panelRect;
LineGraphicsItem *lineItem;
ArcGraphicsItem *arcItem;
PanelDialog *panelDialog;
QTransform transformation;
};
#endif // MAINWINDOW_H
