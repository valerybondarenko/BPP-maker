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

void PanelDialog::init(QRectF rect)
{
    dxfRect = rect;
    ui->xEdit->setText(QString::number(rect.width()));
    ui->yEdit->setText(QString::number(rect.height()));
    ui->zEdit->setText(QString::number(18.00));
}


void PanelDialog::on_buttonBox_accepted()
{    
    if (ui->centeringCheckBox)
    {
        float dx = ui->xEdit->text().toFloat() - dxfRect.width();
        float dy = ui->yEdit->text().toFloat() - dxfRect.height();
        dxfRect.setLeft(dx/2);
        dxfRect.setBottom(dy/2);
        dxfRect.setWidth(ui->xEdit->text().toFloat());
        dxfRect.setHeight(ui->yEdit->text().toFloat());
    } else
    {
        dxfRect.setLeft(0.0);
        dxfRect.setBottom(0.0);
        dxfRect.setWidth(ui->xEdit->text().toFloat());
        dxfRect.setHeight(ui->yEdit->text().toFloat());
    }
    emit confirm(dxfRect);
}
