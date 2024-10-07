#ifndef ARCGRAPHICSITEM_H
#define ARCGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QPainter>


class ArcGraphicsItem : public QGraphicsItem
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
};

#endif // ARCGRAPHICSITEM_H
