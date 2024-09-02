/*
 * Dimension.cpp
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

#include "Dimension.h"

namespace ru_tcl_dxf
{

Dimension::Dimension ()
:
    Entity(),
    block_name(""),
    definition(),
    middle(),
    insertion(),
    type(0),
    text(""),
    special_1(),
    special_2(),
    special_3(),
    special_4(),
    leader_length(0),
    angle(0),
    direction(0)
{
}

Dimension::~Dimension ()
{
}

Dimension::Dimension (const Dimension &obj)
:
    Entity(obj),
    block_name(obj.block_name),
    definition(obj.definition),
    middle(obj.middle),
    insertion(obj.insertion),
    type(obj.type),
    text(obj.text),
    special_1(obj.special_1),
    special_2(obj.special_2),
    special_3(obj.special_3),
    special_4(obj.special_4),
    leader_length(obj.leader_length),
    angle(obj.angle),
    direction(obj.direction)
{
}

const Dimension & Dimension::operator = (const Dimension &obj)
{
    if (this != &obj)
    {
        *((Entity *)this) = obj;

        block_name    = obj.block_name;
        definition    = obj.definition;
        middle        = obj.middle;
        insertion     = obj.insertion;
        type          = obj.type;
        text          = obj.text;
        special_1     = obj.special_1;
        special_2     = obj.special_2;
        special_3     = obj.special_3;
        special_4     = obj.special_4;
        leader_length = obj.leader_length;
        angle         = obj.angle;
        direction     = obj.direction;
    }

    return *this;
}

void Dimension::readDXF (Tokenizer &tokenizer)
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
            case BLOCK_NAME:
            {
                block_name = tokenizer.getCommand();
                break;
            }
            case DEFINITION_X:
            {
                definition.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case DEFINITION_Y:
            {
                definition.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case DEFINITION_Z:
            {
                definition.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case MIDDLE_X:
            {
                middle.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case MIDDLE_Y:
            {
                middle.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case MIDDLE_Z:
            {
                middle.setZ( tokenizer.getCommandAsDouble() );
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
            case TYPE:
            {
                type = tokenizer.getCommandAsInt();
                break;
            }
            case TEXT:
            {
                text = tokenizer.getCommand();
                break;
            }
            case SPECIAL_1_X:
            {
                special_1.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case SPECIAL_1_Y:
            {
                special_1.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case SPECIAL_1_Z:
            {
                special_1.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case SPECIAL_2_X:
            {
                special_2.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case SPECIAL_2_Y:
            {
                special_2.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case SPECIAL_2_Z:
            {
                special_2.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case SPECIAL_3_X:
            {
                special_3.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case SPECIAL_3_Y:
            {
                special_3.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case SPECIAL_3_Z:
            {
                special_3.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case SPECIAL_4_X:
            {
                special_4.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case SPECIAL_4_Y:
            {
                special_4.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case SPECIAL_4_Z:
            {
                special_4.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case LEADER_LENGTH:
            {
                leader_length = tokenizer.getCommandAsDouble();
                break;
            }
            case ANGLE:
            {
                angle = tokenizer.getCommandAsDouble();
                break;
            }
            case DIRECTION:
            {
                direction = tokenizer.getCommandAsDouble();
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

