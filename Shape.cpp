/*
 * Shape.cpp
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

#include "Shape.h"

namespace ru_tcl_dxf
{

Shape::Shape ()
:
    Entity(),
    insertion(),
    size(0),
    shape_name(""),
    rotation_angle(0),
    x_scale(1),
    obliquing_angle(0)
{
}

Shape::~Shape ()
{
}

Shape::Shape (const Shape &obj)
:
    Entity(obj),
    insertion(obj.insertion),
    size(obj.size),
    shape_name(obj.shape_name),
    rotation_angle(obj.rotation_angle),
    x_scale(obj.x_scale),
    obliquing_angle(obj.obliquing_angle)
{
}

const Shape & Shape::operator = (const Shape &obj)
{
    if (this != &obj)
    {
        *((Entity *)this) = obj;

        insertion       = obj.insertion;
        size            = obj.size;
        shape_name      = obj.shape_name;
        rotation_angle  = obj.rotation_angle;
        x_scale         = obj.x_scale;
        obliquing_angle = obj.obliquing_angle;
    }

    return *this;
}

void Shape::readDXF (Tokenizer &tokenizer)
{
    bool end = false;

    while (end == false)
    {
        tokenizer.getToken();

        if (readCommonPropertiesDXF(tokenizer) == true)
            continue;

        switch ( tokenizer.getCode() )
        {
            case 0:
            {
                end = true;
                break;
            }
            case 9:
            {
                end = true;
                break;
            }
            case INSERTION_X:
            {
                insertion.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case INSERTION_Y:
            {
                insertion.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case INSERTION_Z:
            {
                insertion.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case SIZE:
            {
                size = tokenizer.getCommandAsDouble();
                break;
            }
            case SHAPE_NAME:
            {
                shape_name = tokenizer.getCommand();
                break;
            }
            case ROTATION_ANGLE:
            {
                rotation_angle = tokenizer.getCommandAsDouble();
                break;
            }
            case X_SCALE:
            {
                x_scale = tokenizer.getCommandAsDouble();
                break;
            }
            case OBLIQUING_ANGLE:
            {
                obliquing_angle = tokenizer.getCommandAsDouble();
                break;
            }
            default:
            {
                tokenizer.badInstruction();
                break;
            }
        }
    }

    tokenizer.gotoBack();
}

} // namespace

