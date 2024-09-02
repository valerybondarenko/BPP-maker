/*
 * Block.cpp
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

#include "Block.h"

#include "Arc.h"
#include "Attdef.h"
#include "Attrib.h"
#include "Circle.h"
#include "Dimension.h"
#include "Face3d.h"
#include "Insert.h"
#include "Line.h"
#include "Line3d.h"
#include "Point.h"
#include "Polyline.h"
#include "Shape.h"
#include "Solid.h"
#include "Text.h"
#include "Trace.h"

namespace ru_tcl_dxf
{

Block::Block ()
:
    DxfObject(),
    base(),
    name(""),
    flags(0),
    items()
{
}

Block::~Block ()
{
}

Block::Block (const Block &obj)
:
    DxfObject(obj),
    base(obj.base),
    name(obj.name),
    flags(obj.flags),
    items(obj.items)
{
}

const Block & Block::operator = (const Block &obj)
{
    if (this != &obj)
    {
        *((DxfObject *)this) = obj;

        base  = obj.base;
        name  = obj.name;
        flags = obj.flags;
        items = obj.items;
    }

    return *this;
}

void Block::readDXF (Tokenizer &tokenizer)
{
    while (true)
    {
        tokenizer.getToken();

        switch ( tokenizer.getCode() )
        {
            case BASE_X:
            {
                base.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case BASE_Y:
            {
                base.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case BASE_Z:
            {
                base.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case NAME:
            {
                name = tokenizer.getCommand();
                break;
            }
            case FLAGS:
            {
                flags = tokenizer.getCommandAsInt();
                break;
            }
            case 0:
            {
                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ENDBLK) == true)
                    return;

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ARC) == true)
                {
                    Arc *obj = new Arc();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ATTDEF) == true)
                {
                    Attdef *obj = new Attdef();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ATTRIB) == true)
                {
                    Attrib *obj = new Attrib();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_CIRCLE) == true)
                {
                    Circle *obj = new Circle();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMENSION) == true)
                {
                    Dimension *obj = new Dimension();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_FACE3D) == true)
                {
                    Face3d *obj = new Face3d();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_INSERT) == true)
                {
                    Insert *obj = new Insert();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_LINE) == true)
                {
                    Line *obj = new Line();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_LINE3D) == true)
                {
                    Line3d *obj = new Line3d();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_POINT) == true)
                {
                    Point *obj = new Point();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_POLYLINE) == true)
                {
                    Polyline *obj = new Polyline();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SHAPE) == true)
                {
                    Shape *obj = new Shape();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SOLID) == true)
                {
                    Solid *obj = new Solid();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_TEXT) == true)
                {
                    Text *obj = new Text();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_TRACE) == true)
                {
                    Trace *obj = new Trace();
                    obj->readDXF(tokenizer);
                    items.insert(items.end(), obj);
                    continue;
                }

                break;
            }
            default:
            {
                tokenizer.badInstruction();
                break;
            }
        }
    }
}

} // namespace

