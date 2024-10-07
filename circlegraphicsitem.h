#ifndef CIRCLEGRAPHICSITEM_H
#define CIRCLEGRAPHICSITEM_H

#include <QGraphicsItem>



class CircleGraphicsItem : public QGraphicsItem
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
};

#endif // CIRCLEGRAPHICSITEM_H
