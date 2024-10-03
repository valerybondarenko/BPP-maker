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
    void init(float lpx,float lpy, float lpz);
signals:
void confirm(float,float,float);


private slots:
void on_buttonBox_accepted();

private:
    Ui::PanelDialog *ui;
};

#endif // PANELDIALOG_H
