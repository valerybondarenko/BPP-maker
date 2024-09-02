/*
 * Insert.cpp
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

#include "Insert.h"

namespace ru_tcl_dxf
{

Insert::Insert ()
:
    Entity(),
    block_name(""),
    insertion(),
    x_scale(1),
    y_scale(1),
    z_scale(1),
    rotation_angle(0),
    column_counts(1),
    row_counts(1),
    column_spacing(0),
    row_spacing(0),
    attributes()
{
}

Insert::~Insert ()
{
}

Insert::Insert (const Insert &obj)
:
    Entity(obj),
    block_name(obj.block_name),
    insertion(obj.insertion),
    x_scale(obj.x_scale),
    y_scale(obj.y_scale),
    z_scale(obj.z_scale),
    rotation_angle(obj.rotation_angle),
    column_counts(obj.column_counts),
    row_counts(obj.row_counts),
    column_spacing(obj.column_spacing),
    row_spacing(obj.row_spacing),
    attributes(obj.attributes)
{
}

const Insert & Insert::operator = (const Insert &obj)
{
    if (this != &obj)
    {
        *((Entity *)this) = obj;

        block_name     = obj.block_name;
        insertion      = obj.insertion;
        x_scale        = obj.x_scale;
        y_scale        = obj.y_scale;
        z_scale        = obj.z_scale;
        rotation_angle = obj.rotation_angle;
        column_counts  = obj.column_counts;
        row_counts     = obj.row_counts;
        column_spacing = obj.column_spacing;
        row_spacing    = obj.row_spacing;
        attributes     = obj.attributes;
    }

    return *this;
}

void Insert::readDXF (Tokenizer &tokenizer)
{
    bool end               = false;
    int  attributes_follow = 0;

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
            case ATTRIBUTES_FOLLOW:
            {
                attributes_follow = tokenizer.getCommandAsInt();
                break;
            }
            case BLOCK_NAME:
            {
                block_name = tokenizer.getCommand();
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
            case X_SCALE:
            {
                x_scale = tokenizer.getCommandAsDouble();
                break;
            }
            case Y_SCALE:
            {
                y_scale = tokenizer.getCommandAsDouble();
                break;
            }
            case Z_SCALE:
            {
                z_scale = tokenizer.getCommandAsDouble();
                break;
            }
            case ROTATION_ANGLE:
            {
                rotation_angle = tokenizer.getCommandAsDouble();
                break;
            }
            case COLUMN_COUNTS:
            {
                column_counts = tokenizer.getCommandAsInt();
                break;
            }
            case ROW_COUNTS:
            {
                row_counts = tokenizer.getCommandAsInt();
                break;
            }
            case COLUMN_SPACING:
            {
                column_spacing = tokenizer.getCommandAsDouble();
                break;
            }
            case ROW_SPACING:
            {
                row_spacing = tokenizer.getCommandAsDouble();
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

    if (attributes_follow == 1)
        readAttributesDXF(tokenizer);
}

void Insert::readAttributesDXF (Tokenizer &tokenizer)
{
    while (true)
    {
        tokenizer.getToken();

        if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SEQEND) == true)
            return;

        if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ATTRIB) == true)
        {
            Attrib attrib;
            attrib.readDXF(tokenizer);
            attributes.insert(attributes.end(), attrib);
        }
    }
}

} // namespace

