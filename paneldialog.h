#ifndef PANELDIALOG_H
#define PANELDIALOG_H

#include <QDialog>
#include <QObject>

namespace Ui {
class PanelDialog;
}

class PanelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PanelDialog(QWidget *parent = nullptr);
    ~PanelDialog();
    void init(QRectF rect);
signals:
void confirm(QRectF);


private slots:
void on_buttonBox_accepted();

private:
    Ui::PanelDialog *ui;
    QRectF dxfRect;
};

#endif // PANELDIALOG_H
