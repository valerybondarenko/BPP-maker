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
void confirm();


private:
    Ui::PanelDialog *ui;
};

#endif // PANELDIALOG_H
