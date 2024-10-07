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
        spanAngle =  endAngle - startAngle;
    } else

    {
        spanAngle = 360 - startAngle + endAngle ;
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
    float dy = parentItem()->boundingRect().height();
    return QRectF(QPointF(centerPoint.x()+radius,dy - centerPoint.y()+radius),
                  QPointF(centerPoint.x()-radius,dy - centerPoint.y()-radius));
}

void ArcGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawArc(boundingRect(),startAngle*16,spanAngle*16);
}
