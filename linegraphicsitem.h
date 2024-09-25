#ifndef LINEGRAPHICSITEM_H
#define LINEGRAPHICSITEM_H
#include<QGraphicsItem>

namespace ru_tcl_dxf
{
class LineGraphicsItem : public QGraphicsItem
{
public:
    LineGraphicsItem(QGraphicsItem *parent = nullptr);
private:



    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
}
#endif // LINEGRAPHICSITEM_H
