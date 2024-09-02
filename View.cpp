/*
 * View.cpp
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

#include "View.h"

namespace ru_tcl_dxf
{

View::View ()
:
    Entry(),
    height(0),
    width(0),
    center(),
    direction(),
    target(),
    lens_length(0),
    front_clipping(0),
    back_clipping(0),
    twist_angle(0),
    view_mode(0)
{
}

View::~View ()
{
}

View::View (const View &obj)
:
    Entry(obj),
    height(obj.height),
    width(obj.width),
    center(obj.center),
    direction(obj.direction),
    target(obj.target),
    lens_length(obj.lens_length),
    front_clipping(obj.front_clipping),
    back_clipping(obj.back_clipping),
    twist_angle(obj.twist_angle),
    view_mode(obj.view_mode)
{
}

const View & View::operator = (const View &obj)
{
    if (this != &obj)
    {
        *((Entry *)this) = obj;

        height         = obj.height;
        width          = obj.width;
        center         = obj.center;
        direction      = obj.direction;
        target         = obj.target;
        lens_length    = obj.lens_length;
        front_clipping = obj.front_clipping;
        back_clipping  = obj.back_clipping;
        twist_angle    = obj.twist_angle;
        view_mode      = obj.view_mode;
    }

    return *this;
}

void View::readDXF (Tokenizer &tokenizer)
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
            case HEIGHT:
            {
                height = tokenizer.getCommandAsDouble();
                break;
            }
            case WIDTH:
            {
                width = tokenizer.getCommandAsDouble();
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
            case DIRECTION_X:
            {
                direction.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case DIRECTION_Y:
            {
                direction.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case DIRECTION_Z:
            {
                direction.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case TARGET_X:
            {
                target.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case TARGET_Y:
            {
                target.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case TARGET_Z:
            {
                target.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case LENS_LENGTH:
            {
                lens_length = tokenizer.getCommandAsDouble();
                break;
            }
            case FRONT_CLIPPING:
            {
                front_clipping = tokenizer.getCommandAsDouble();
                break;
            }
            case BACK_CLIPPING:
            {
                back_clipping = tokenizer.getCommandAsDouble();
                break;
            }
            case TWIST_ANGLE:
            {
                twist_angle = tokenizer.getCommandAsDouble();
                break;
            }
            case VIEW_MODE:
            {
                view_mode = tokenizer.getCommandAsInt();
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

