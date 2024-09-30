#ifndef LINEGRAPHICSITEM_H
#define LINEGRAPHICSITEM_H

#include <QGraphicsItem>
#include "QPointF"
#include<QObject>
#include <QPainter>
#include <QPen>



class LineGraphicsItem : public QGraphicsItem
{

public:
    LineGraphicsItem(QGraphicsItem* parent=nullptr);

private:
QPointF l_Start;
QPointF l_End;


// QGraphicsItem interface
public:
virtual QRectF boundingRect() const override;
virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
void setL_Start(const QPointF &value);
void setL_End(const QPointF &value);
QPointF getL_Start() const;
QPointF getL_End() const;



};

#endif // LINEGRAPHICSITEM_H
