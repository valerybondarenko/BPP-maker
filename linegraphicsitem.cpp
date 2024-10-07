#include "linegraphicsitem.h"
#include<QDebug>

LineGraphicsItem::LineGraphicsItem(QGraphicsItem *parent)
{
l_Start = QPointF(0.0,0.0);
l_End = QPointF(0.0,0.0);
}

void LineGraphicsItem::setL_End(const QPointF &value)
{
    l_End = value;
}

void LineGraphicsItem::setL_Start(const QPointF &value)
{
    l_Start = value;
}

QPointF LineGraphicsItem::getL_End() const
{
    return l_End;
}

QRectF LineGraphicsItem::boundingRect() const
{
float dy = parentItem()->boundingRect().height();
    return QRectF(QPoint(l_Start.x(),dy-l_Start.y()),QPoint(l_End.x(),dy-l_End.y()));
}

void LineGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen redPen(Qt::red);
    QPen blackPen(Qt::black);

    if (isSelected()) {
        painter->setPen(redPen);
    } else {
        painter->setPen(blackPen);
    }

    float dy = parentItem()->boundingRect().height();
    painter->drawLine(QPoint(l_Start.x(),dy-l_Start.y()),QPoint(l_End.x(),dy-l_End.y()));
}

QPointF LineGraphicsItem::getL_Start() const
{
    return l_Start;
}
