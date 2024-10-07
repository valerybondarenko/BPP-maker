#include "circlegraphicsitem.h"

#include <QPainter>

CircleGraphicsItem::CircleGraphicsItem(QGraphicsItem *parent)
{
    centerPoint = QPointF(0.0,0.0);
    radius = 0.0;
}

CircleGraphicsItem::CircleGraphicsItem(QGraphicsItem *parent, QPointF center, float radiusR)
{
    centerPoint = center;
    radius = radiusR;
    setParentItem(parent);
}

QRectF CircleGraphicsItem::boundingRect() const
{
    float dy = parentItem()->boundingRect().height();
    return QRectF(QPointF(centerPoint.x()+radius+1,dy - centerPoint.y()+radius+1),
                  QPointF(centerPoint.x()-radius-1,dy - centerPoint.y()-radius+1));
}

void CircleGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawArc(boundingRect(),0,360*16);

}
