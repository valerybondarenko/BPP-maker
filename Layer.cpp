/*
 * Layer.cpp
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

#include "Layer.h"

namespace ru_tcl_dxf
{

Layer::Layer ()
:
    Entry(),
    color(0),
    line_type("")
{
}

Layer::~Layer ()
{
}

Layer::Layer (const Layer &obj)
:
    Entry(obj),
    color(obj.color),
    line_type(obj.line_type)
{
}

const Layer & Layer::operator = (const Layer &obj)
{
    if (this != &obj)
    {
        *((Entry *)this) = obj;

        color     = obj.color;
        line_type = obj.line_type;
    }

    return *this;
}

void Layer::readDXF (Tokenizer &tokenizer)
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
            case COLOR:
            {
                color = tokenizer.getCommandAsInt();
                break;
            }
            case LINE_TYPE:
            {
                line_type = tokenizer.getCommand();
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

