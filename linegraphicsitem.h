#ifndef LINEGRAPHICSITEM_H
#define LINEGRAPHICSITEM_H

#include <QGraphicsItem>
#include "QPointF"
#include<QObject>
#include <QPainter>
#include <QPen>
#include "graphicsitem.h"


class LineGraphicsItem : public GraphicsItem
{

public:
    LineGraphicsItem(QGraphicsItem* parent=nullptr);

private:
QPointF l_Start;
QPointF l_End;


// QGraphicsItem interface
public:
virtual QRectF boundingRect() const override;
virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
void setL_Start(const QPointF &value);
void setL_End(const QPointF &value);
QPointF getL_Start() const;
QPointF getL_End() const;




// GraphicsItem interface
public:
virtual void mooveObj(float dxObj, float dyObj, float dzObj) override;
virtual void rotateObj(QPoint rPoint, float angle) override{};
virtual void scaleObj(QPoint sPoint, float rate) override{};
};

#endif // LINEGRAPHICSITEM_H
