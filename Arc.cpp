/*
 * Arc.cpp
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

#include "Arc.h"

namespace ru_tcl_dxf
{

Arc::Arc ()
:
    Entity(),
    center(),
    radius(0),
    start_angle(0),
    end_angle(0)
{
}

Arc::~Arc ()
{
}

Arc::Arc (const Arc &obj)
:
    Entity(obj),
    center(obj.center),
    radius(obj.radius),
    start_angle(obj.start_angle),
    end_angle(obj.end_angle)
{
}

const Arc & Arc::operator = (const Arc &obj)
{
    if (this != &obj)
    {
        *((Entity *)this) = obj;

        center      = obj.center;
        radius      = obj.radius;
        start_angle = obj.start_angle;
        end_angle   = obj.end_angle;
    }

    return *this;
}

void Arc::readDXF (Tokenizer &tokenizer)
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
            case CENTER_X:
            {
                center.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case CENTER_Y:
            {
                center.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case CENTER_Z:
            {
                center.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case RADIUS:
            {
                radius = tokenizer.getCommandAsDouble();
                break;
            }
            case START_ANGLE:
            {
                start_angle = tokenizer.getCommandAsDouble();
                break;
            }
            case END_ANGLE:
            {
                end_angle = tokenizer.getCommandAsDouble();
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

