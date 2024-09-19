#ifndef PAINTER_H
#define PAINTER_H
#include "Entity.h"
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_1_1>
namespace ru_tcl_dxf
{
class Entity;
class Painter :public QOpenGLWidget, protected QOpenGLFunctions
{
   // Q_OBJECT
public:
    Painter(QWidget *parent) : QOpenGLWidget(parent) { }
void drawLine(Entity* entity);
void drawArc(Entity* entity);
void drawCircle(Entity*circle);

// QOpenGLWidget interface
void setItems(std::vector<Entity *> *value);

protected:
void initializeGL() override;
void resizeGL(int w, int h) override;
void paintGL() override;
private:

std::vector<Entity*> items;
};
}
#endif // PAINTER_H
