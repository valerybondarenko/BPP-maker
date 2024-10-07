#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsItem>



class GraphicsItem : public QGraphicsItem
{
public:
    GraphicsItem(QGraphicsItem *parent = nullptr);
    virtual void mooveObj(float dxObj,float dyObj,float dzObj=0){};
    virtual void rotateObj(QPoint rPoint, float angle){};
    virtual void scaleObj(QPoint sPoint, float rate){};
};

#endif // GRAPHICSITEM_H
