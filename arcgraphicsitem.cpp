#include "arcgraphicsitem.h"

ArcGraphicsItem::ArcGraphicsItem(QGraphicsItem *parent)
{

}

ArcGraphicsItem::ArcGraphicsItem(QGraphicsItem *parent, QPointF center, float startA, float endA, float radiusR)
{
    centerPoint = center;
    startAngle = normalizeAngle(startA);
    endAngle = normalizeAngle(endA);
    radius = radiusR;
    //
    if(startAngle<endAngle)
    {
        arcAngle =  endAngle - startAngle;
    } else
    {
        arcAngle = startAngle - endAngle;
    }

}

float ArcGraphicsItem::normalizeAngle(float value)
{
    while (value<-360) {
        value +=360;
    }
    while (value>360) {
        value -=360;
    }
    return value;
}

QRectF ArcGraphicsItem::boundingRect() const
{
    return QRectF(QPointF(centerPoint.x()+radius,centerPoint.y()+radius),QPointF(centerPoint.x()-radius,centerPoint.y()-radius));
}

void ArcGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawArc(boundingRect(),startAngle*16,-arcAngle*16);
}
