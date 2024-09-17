#ifndef PAINTER_H
#define PAINTER_H
#include "Entity.h"

namespace ru_tcl_dxf
{
class Entity;
class Painter
{
public:
    Painter();
void drawLine(Entity*line);
void drawArc(Entity*arc);
void drawCircle(Entity*circle);
};
}
#endif // PAINTER_H
