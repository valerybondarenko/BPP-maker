/*
 * Solid.cpp
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

#include "Solid.h"

namespace ru_tcl_dxf
{

Solid::Solid ()
:
    Entity(),
    first_corner(),
    second_corner(),
    third_corner(),
    fourth_corner()
{
}

Solid::~Solid ()
{
}

Solid::Solid (const Solid &obj)
:
    Entity(obj),
    first_corner(obj.first_corner),
    second_corner(obj.second_corner),
    third_corner(obj.third_corner),
    fourth_corner(obj.fourth_corner)
{
}

const Solid & Solid::operator = (const Solid &obj)
{
    if (this != &obj)
    {
        *((Entity *)this) = obj;

        first_corner  = obj.first_corner;
        second_corner = obj.second_corner;
        third_corner  = obj.third_corner;
        fourth_corner = obj.fourth_corner;
    }

    return *this;
}

void Solid::readDXF (Tokenizer &tokenizer)
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
            case FIRST_CORNER_X:
            {
                first_corner.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case FIRST_CORNER_Y:
            {
                first_corner.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case FIRST_CORNER_Z:
            {
                first_corner.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case SECOND_CORNER_X:
            {
                second_corner.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case SECOND_CORNER_Y:
            {
                second_corner.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case SECOND_CORNER_Z:
            {
                second_corner.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case THIRD_CORNER_X:
            {
                third_corner.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case THIRD_CORNER_Y:
            {
                third_corner.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case THIRD_CORNER_Z:
            {
                third_corner.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case FOURTH_CORNER_X:
            {
                fourth_corner.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case FOURTH_CORNER_Y:
            {
                fourth_corner.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case FOURTH_CORNER_Z:
            {
                fourth_corner.setZ( tokenizer.getCommandAsDouble() );
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

void Solid::draw()
{

}

} // namespace

