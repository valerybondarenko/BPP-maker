#include "painter.h"
using namespace ru_tcl_dxf;
#include<QDebug>
#include"Line.h"
#include"Arc.h"
#include"Circle.h"
 Painter::Painter()
{

}

void Painter::drawLine(ru_tcl_dxf::Entity *line)
{
    Line* ln = (Line*)line;
    qDebug()<<"Painter draw line - start "<<ln->getStart().getX()<<","<<ln->getStart().getY()<<"end "<<ln->getEnd().getX()<<","<<ln->getEnd().getY();

}

void Painter::drawArc(Entity *arc)
{
    Arc* ar = (Arc*)arc;
    qDebug()<<"Painter draw Arc - center "<<ar->getCenter().getX()<<","<<ar->getCenter().getY()<<"R = "<<ar->getRadius();
}

void Painter::drawCircle(Entity *circle)
{
    qDebug()<<"Painter draw circle";
}
