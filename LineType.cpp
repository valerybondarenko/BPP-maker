/*
 * LineType.cpp
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

#include "LineType.h"

namespace ru_tcl_dxf
{

LineType::LineType ()
:
    Entry(),
    ascii_type(""),
    alignment(0),
    pattern_length(0),
    items()
{
}

LineType::~LineType ()
{
}

LineType::LineType (const LineType &obj)
:
    Entry(obj),
    ascii_type(obj.ascii_type),
    alignment(obj.alignment),
    pattern_length(obj.pattern_length),
    items(obj.items)
{
}

const LineType & LineType::operator = (const LineType &obj)
{
    if (this != &obj)
    {
        *((Entry *)this) = obj;

        ascii_type     = obj.ascii_type;
        alignment      = obj.alignment;
        pattern_length = obj.pattern_length;
        items          = obj.items;
    }

    return *this;
}

void LineType::readDXF (Tokenizer &tokenizer)
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
            case ASCII_TYPE:
            {
                ascii_type = tokenizer.getCommand();
                break;
            }
            case ALIGNMENT:
            {
                alignment = tokenizer.getCommandAsInt();
                break;
            }
            case DASH_COUNTS:
            {
                break;
            }
            case PATTERN_LENGTH:
            {
                pattern_length = tokenizer.getCommandAsDouble();
                break;
            }
            case DASH_LENGTH:
            {
                items.insert(items.end(), tokenizer.getCommandAsDouble());
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

