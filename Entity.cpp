/*
 * Entity.cpp
 *
 * TCL DXF, version 1.0.0
 * Copyright (c) 1998 by Basil Tunegov
 *
 * THE AUTHOR MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY
 * OF THE SOFTWARE, EITHER  EXPRESS OR IMPLIED, INCLUDING  BUT NOT LIMITED
 * TO THE IMPLIED WARRANTIES OF  MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, OR  NON-INFRINGEMENT. THE  AUTHOR SHALL NOT BE LIABLE  FOR ANY
 * DAMAGES  SUFFERED  BY  LICENSEE  AS  A  RESULT  OF USING,  MODIFYING OR
 * DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 *
 */

#include "Entity.h"
#include <QDebug>
namespace ru_tcl_dxf
{

Entity::Entity ()
:
    DxfObject(),
    elevation(0),
    thickness(0),
    color_number(0),
    line_type_name("BYLAYER"),
    layer_name(""),
    extrusion_direction()

{
      qDebug()<<"Constuctor Entity default";
}

Entity::~Entity ()
{
}

Entity::Entity (const Entity &obj)
:
    DxfObject(obj),   
    elevation(obj.elevation),
    thickness(obj.thickness),
    color_number(obj.color_number),
    line_type_name(obj.line_type_name),
    layer_name(obj.layer_name),
    extrusion_direction(obj.extrusion_direction)
{
    qDebug()<<"Constuctor Entity copy";
}

const Entity & Entity::operator = (const Entity &obj)
{
    if (this != &obj)
    {
        *((DxfObject *)this) = obj;

        elevation           = obj.elevation;
        thickness           = obj.thickness;
        color_number        = obj.color_number;
        line_type_name      = obj.line_type_name;
        layer_name          = obj.layer_name;
        extrusion_direction = obj.extrusion_direction;
    }

    return *this;
}

void Entity::draw(ScreenView *value)
{

}

bool Entity::readCommonPropertiesDXF (Tokenizer &tokenizer)
{
    switch ( tokenizer.getCode() )
    {
        case LAYER_NAME:
        {
            layer_name = tokenizer.getCommand();
            return true;
        }
        case LINE_TYPE_NAME:
        {
            line_type_name = tokenizer.getCommand();
            return true;
        }
        case ELEVATION:
        {
            elevation = tokenizer.getCommandAsDouble();
            return true;
        }
        case THICKNESS:
        {
            thickness = tokenizer.getCommandAsDouble();
            return true;
        }
        case COLOR_NUMBER:
        {
            color_number = tokenizer.getCommandAsInt();
            return true;
        }
        case EXTRUSION_DIRECTION_X:
        {
            extrusion_direction.setX( tokenizer.getCommandAsDouble() );
            return true;
        }
        case EXTRUSION_DIRECTION_Y:
        {
            extrusion_direction.setY( tokenizer.getCommandAsDouble() );
            return true;
        }
        case EXTRUSION_DIRECTION_Z:
        {
            extrusion_direction.setZ( tokenizer.getCommandAsDouble() );
            return true;
        }
    }

    return false;
}






} // namespace

