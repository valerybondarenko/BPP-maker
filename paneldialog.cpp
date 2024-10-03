#include "paneldialog.h"
#include "ui_paneldialog.h"
#include <QDebug>
#include <QDoubleValidator>

PanelDialog::PanelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PanelDialog)
{
    ui->setupUi(this);   
    ui->xEdit->setValidator(new QDoubleValidator(0, 100, 2, this));
    ui->yEdit->setValidator(new QDoubleValidator(0, 100, 2, this));
    ui->zEdit->setValidator(new QDoubleValidator(0, 100, 2, this));

}

PanelDialog::~PanelDialog()
{
    delete ui;
}

void PanelDialog::init(float lpx, float lpy, float lpz)
{
ui->xEdit->setText(QString::number(lpx));
ui->yEdit->setText(QString::number(lpy));
ui->zEdit->setText(QString::number(lpz));
}



void PanelDialog::on_buttonBox_accepted()
{
    emit confirm(ui->xEdit->text().toFloat(),
                 ui->yEdit->text().toFloat(),
                 ui->zEdit->text().toFloat());
}
