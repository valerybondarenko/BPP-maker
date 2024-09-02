/*
 * Ucs.cpp
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

#include "Ucs.h"

namespace ru_tcl_dxf
{

Ucs::Ucs ()
:
    Entry(),
    origin(),
    x_axis_direction(),
    y_axis_direction()
{
}

Ucs::~Ucs ()
{
}

Ucs::Ucs (const Ucs &obj)
:
    Entry(obj),
    origin(obj.origin),
    x_axis_direction(obj.x_axis_direction),
    y_axis_direction(obj.y_axis_direction)
{
}

const Ucs & Ucs::operator = (const Ucs &obj)
{
    if (this != &obj)
    {
        *((Entry *)this) = obj;

        origin           = obj.origin;
        x_axis_direction = obj.x_axis_direction;
        y_axis_direction = obj.y_axis_direction;
    }

    return *this;
}

void Ucs::readDXF (Tokenizer &tokenizer)
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
            case ORIGIN_X:
            {
                origin.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case ORIGIN_Y:
            {
                origin.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case ORIGIN_Z:
            {
                origin.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case X_AXIS_DIRECTION_X:
            {
                x_axis_direction.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case X_AXIS_DIRECTION_Y:
            {
                x_axis_direction.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case X_AXIS_DIRECTION_Z:
            {
                x_axis_direction.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case Y_AXIS_DIRECTION_X:
            {
                y_axis_direction.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case Y_AXIS_DIRECTION_Y:
            {
                y_axis_direction.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case Y_AXIS_DIRECTION_Z:
            {
                y_axis_direction.setZ( tokenizer.getCommandAsDouble() );
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

