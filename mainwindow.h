#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Translator.h"
#include <vector>
#include"Entity.h"
#include"screenview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace ru_tcl_dxf;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;   

Translator trans;
ScreenView* view;

};
#endif // MAINWINDOW_H
