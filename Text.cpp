/*
 * Text.cpp
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

#include "Text.h"

namespace ru_tcl_dxf
{

Text::Text ()
:
    Entity(),
    insertion(),
    height(0),
    text(""),
    rotation_angle(0),
    x_scale(1),
    obliquing_angle(0),
    style("STANDART"),
    generation_flags(0),
    justification_type(0),
    alignment()
{
}

Text::~Text ()
{
}

Text::Text (const Text &obj)
:
    Entity(obj),
    insertion(obj.insertion),
    height(obj.height),
    text(obj.text),
    rotation_angle(obj.rotation_angle),
    x_scale(obj.x_scale),
    obliquing_angle(obj.obliquing_angle),
    style(obj.style),
    generation_flags(obj.generation_flags),
    justification_type(obj.justification_type),
    alignment(obj.alignment)
{
}

const Text & Text::operator = (const Text &obj)
{
    if (this != &obj)
    {
        *((Entity *)this) = obj;

        insertion          = obj.insertion;
        height             = obj.height;
        text               = obj.text;
        rotation_angle     = obj.rotation_angle;
        x_scale            = obj.x_scale;
        obliquing_angle    = obj.obliquing_angle;
        style              = obj.style;
        generation_flags   = obj.generation_flags;
        justification_type = obj.justification_type;
        alignment          = obj.alignment;
    }

    return *this;
}

void Text::readDXF (Tokenizer &tokenizer)
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
            case HEIGHT:
            {
                height = tokenizer.getCommandAsDouble();
                break;
            }
            case TEXT:
            {
                text = tokenizer.getCommand();
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
            case STYLE:
            {
                style = tokenizer.getCommand();
                break;
            }
            case GENERATION_FLAGS:
            {
                generation_flags = tokenizer.getCommandAsInt();
                break;
            }
            case JUSTIFICATION_TYPE:
            {
                justification_type = tokenizer.getCommandAsInt();
                break;
            }
            case ALIGNMENT_X:
            {
                alignment.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case ALIGNMENT_Y:
            {
                alignment.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case ALIGNMENT_Z:
            {
                alignment.setZ( tokenizer.getCommandAsDouble() );
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

