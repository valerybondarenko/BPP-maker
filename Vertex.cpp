/*
 * Vertex.cpp
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

#include "Vertex.h"

namespace ru_tcl_dxf
{

Vertex::Vertex ()
:
    Entity(),
    location(),
    start_width(0),
    end_width(0),
    bulge(0),
    flags(0),
    tangent_direction(0)
{
}

Vertex::~Vertex ()
{
}

Vertex::Vertex (const Vertex &obj)
:
    Entity(obj),
    location(obj.location),
    start_width(obj.start_width),
    end_width(obj.end_width),
    bulge(obj.bulge),
    flags(obj.flags),
    tangent_direction(obj.tangent_direction)
{
}

const Vertex & Vertex::operator = (const Vertex &obj)
{
    if (this != &obj)
    {
        *((Entity *)this) = obj;

        location          = obj.location;
        start_width       = obj.start_width;
        end_width         = obj.end_width;
        bulge             = obj.bulge;
        flags             = obj.flags;
        tangent_direction = obj.tangent_direction;
    }

    return *this;
}

void Vertex::readDXF (Tokenizer &tokenizer)
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
            case LOCATION_X:
            {
                location.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case LOCATION_Y:
            {
                location.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case LOCATION_Z:
            {
                location.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case START_WIDTH:
            {
                start_width = tokenizer.getCommandAsDouble();
                break;
            }
            case END_WIDTH:
            {
                end_width = tokenizer.getCommandAsDouble();
                break;
            }
            case BULGE:
            {
                bulge = tokenizer.getCommandAsDouble();
                break;
            }
            case FLAGS:
            {
                flags = tokenizer.getCommandAsInt();
                break;
            }
            case TANGENT_DIRECTION:
            {
                tangent_direction = tokenizer.getCommandAsDouble();
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

