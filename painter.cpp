#include "painter.h"
using namespace ru_tcl_dxf;

#include<QDebug>
#include"Line.h"
#include"Arc.h"
#include"Circle.h"




void Painter::drawLine(ru_tcl_dxf::Entity *entity)
{
    Line* line = (Line*) entity;

}

void Painter::drawArc(Entity *entity)
{
    Arc* arc = (Arc*)entity;

}

void Painter::drawCircle(Entity *circle)
{
    qDebug()<<"Painter draw circle";
}

void Painter::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);
}

void Painter::resizeGL(int w, int h)
{
glViewport(0,0,w,h);
}

void Painter::paintGL()
{
glClearColor(0.75,0.75,0.75,1);



}
void Painter::setItems(std::vector<Entity *> *value)
{
    items = *value;
}

