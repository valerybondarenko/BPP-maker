#include "linegraphicsitem.h"

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
    return QRectF(l_Start,l_End);
}

void LineGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawLine(l_Start,l_End);
}

QPointF LineGraphicsItem::getL_Start() const
{
    return l_Start;
}
