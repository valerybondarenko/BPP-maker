#ifndef ARCGRAPHICSITEM_H
#define ARCGRAPHICSITEM_H

#include "graphicsitem.h"

#include <QGraphicsItem>
#include <QPainter>


class ArcGraphicsItem : public GraphicsItem
{
public:
    ArcGraphicsItem(QGraphicsItem *parent = nullptr);
    ArcGraphicsItem(QGraphicsItem *parent, QPointF, float, float, float);
private:
    float normalizeAngle (float value);



    QPointF centerPoint;
    QPointF startPoint;
    QPointF endPoint;
    QPointF midlePoint;
    float startAngle;
    float endAngle;
    float spanAngle;
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

#endif // ARCGRAPHICSITEM_H
