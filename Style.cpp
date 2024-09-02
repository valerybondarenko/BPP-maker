/*
 * Style.cpp
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

#include "Style.h"

namespace ru_tcl_dxf
{

Style::Style ()
:
    Entry(),
    fixed_height(0),
    width_factor(0),
    obliquing_angle(0),
    generation_flags(0),
    last_height_used(0),
    primary_file_name(""),
    bigfont_file_name("")
{
}

Style::~Style ()
{
}

Style::Style (const Style &obj)
:
    Entry(obj),
    fixed_height(obj.fixed_height),
    width_factor(obj.width_factor),
    obliquing_angle(obj.obliquing_angle),
    generation_flags(obj.generation_flags),
    last_height_used(obj.last_height_used),
    primary_file_name(obj.primary_file_name),
    bigfont_file_name(obj.bigfont_file_name)
{
}

const Style & Style::operator = (const Style &obj)
{
    if (this != &obj)
    {
        *((Entry *)this) = obj;

        fixed_height      = obj.fixed_height;
        width_factor      = obj.width_factor;
        obliquing_angle   = obj.obliquing_angle;
        generation_flags  = obj.generation_flags;
        last_height_used  = obj.last_height_used;
        primary_file_name = obj.primary_file_name;
        bigfont_file_name = obj.bigfont_file_name;
    }

    return *this;
}

void Style::readDXF (Tokenizer &tokenizer)
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
            case FIXED_HEIGHT:
            {
                fixed_height = tokenizer.getCommandAsDouble();
                break;
            }
            case WIDTH_FACTOR:
            {
                width_factor = tokenizer.getCommandAsDouble();
                break;
            }
            case OBLIQUING_ANGLE:
            {
                obliquing_angle = tokenizer.getCommandAsDouble();
                break;
            }
            case GENERATION_FLAGS:
            {
                generation_flags = tokenizer.getCommandAsInt();
                break;
            }
            case LAST_HEIGHT_USED:
            {
                last_height_used = tokenizer.getCommandAsDouble();
                break;
            }
            case PRIMARY_FILE_NAME:
            {
                primary_file_name = tokenizer.getCommand();
                break;
            }
            case BIGFONT_FILE_NAME:
            {
                bigfont_file_name = tokenizer.getCommand();
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

