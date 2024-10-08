#ifndef CIRCLEGRAPHICSITEM_H
#define CIRCLEGRAPHICSITEM_H


#include <QGraphicsItem>
#include "graphicsitem.h"


class CircleGraphicsItem : public GraphicsItem
{
public:
    CircleGraphicsItem(QGraphicsItem *parent=nullptr);
    CircleGraphicsItem(QGraphicsItem *parent, QPointF center, float radiusR);
private:
    QPointF centerPoint;
    float radius;

    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // GraphicsItem interface
public:
    virtual void mooveObj(float dxObj, float dyObj, float dzObj) override;
    virtual void rotateObj(QPoint rPoint, float angle) override{};
    virtual void scaleObj(QPoint sPoint, float rate) override{};
};

#endif // CIRCLEGRAPHICSITEM_H
