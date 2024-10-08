#include "arcgraphicsitem.h"


ArcGraphicsItem::ArcGraphicsItem(QGraphicsItem *parent)
{

}

ArcGraphicsItem::ArcGraphicsItem(QGraphicsItem *parent, QPointF center, float startA, float endA, float radiusR)
{
    setParentItem(parent);
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
    return QRectF(QPointF(centerPoint.x()+radius+1,dy - centerPoint.y()+radius+1),
                  QPointF(centerPoint.x()-radius-1,dy - centerPoint.y()-radius+1));
}

void ArcGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawArc(boundingRect(),startAngle*16,spanAngle*16);
}

void ArcGraphicsItem::mooveObj(float dxObj, float dyObj, float dzObj)
{
    float value = centerPoint.x();
    centerPoint.setX(value+dxObj);
    value = centerPoint.y();
    centerPoint.setY(value+dyObj);
}
