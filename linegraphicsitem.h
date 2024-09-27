#ifndef LINEGRAPHICSITEM_H
#define LINEGRAPHICSITEM_H

#include <QGraphicsItem>
#include "QPointF"
#include<QObject>
#include <QPainter>



class LineGraphicsItem : public QGraphicsItem
{

public:
    LineGraphicsItem(QGraphicsItem *parent = nullptr);
QPointF l_Start;
QPointF l_End;
QPointF getL_Start() const;
QPointF getL_End() const;

// QGraphicsItem interface
public:
virtual QRectF boundingRect() const override;
virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // LINEGRAPHICSITEM_H
