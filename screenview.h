#ifndef SCREENVIEW_H
#define SCREENVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>

class ScreenView : public QGraphicsView
{
    Q_OBJECT
public:
    ScreenView(QWidget *parent = nullptr);
};

#endif // SCREENVIEW_H
