/*
 * Line3d.cpp
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

#include "Line3d.h"

namespace ru_tcl_dxf
{

Line3d::Line3d ()
:
    Entity(),
    start(),
    end()
{
}

Line3d::~Line3d ()
{
}

Line3d::Line3d (const Line3d &obj)
:
    Entity(obj),
    start(obj.start),
    end(obj.end)
{
}

const Line3d & Line3d::operator = (const Line3d &obj)
{
    if (this != &obj)
    {
        *((Entity *)this) = obj;

        start = obj.start;
        end   = obj.end;
    }

    return *this;
}

void Line3d::readDXF (Tokenizer &tokenizer)
{
    bool is_end = false;

    while (is_end == false)
    {
        tokenizer.getToken();

        if (readCommonPropertiesDXF(tokenizer) == true)
            continue;

        switch ( tokenizer.getCode() )
        {
            case 0:
            {
                is_end = true;
                break;
            }
            case 9:
            {
                is_end = true;
                break;
            }
            case START_X:
            {
                start.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case START_Y:
            {
                start.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case START_Z:
            {
                start.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case END_X:
            {
                end.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case END_Y:
            {
                end.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case END_Z:
            {
                end.setZ( tokenizer.getCommandAsDouble() );
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

