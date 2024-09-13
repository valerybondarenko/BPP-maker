/*
 * Point.cpp
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

#include "Point.h"

namespace ru_tcl_dxf
{

Point::Point ()
:
    x(0),
    y(0),
    z(0),
    angle_x_axis(0)
{
}

Point::~Point ()
{
}

Point::Point (const Point &obj)
:
    x(obj.x),
    y(obj.y),
    z(obj.z),
    angle_x_axis(obj.angle_x_axis)
{
}

const Point & Point::operator = (const Point &obj)
{
    if (this != &obj)
    {
        x            = obj.x;
        y            = obj.y;
        z            = obj.z;
        angle_x_axis = obj.angle_x_axis;
    }

    return *this;
}

void Point::readDXF (Tokenizer &tokenizer)
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
            case X:
            {
                x = tokenizer.getCommandAsDouble();
                break;
            }
            case Y:
            {
                y = tokenizer.getCommandAsDouble();
                break;
            }
            case Z:
            {
                z = tokenizer.getCommandAsDouble();
                break;
            }
            case ANGLE_X_AXIS:
            {
                angle_x_axis = tokenizer.getCommandAsDouble();
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

void Point::draw()
{

}

} // namespace

