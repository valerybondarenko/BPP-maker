/*
 * Entry.cpp
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

#include "Entry.h"

namespace ru_tcl_dxf
{

Entry::Entry ()
:
    DxfObject(),
    name(""),
    flags(0)
{
}

Entry::~Entry ()
{
}

Entry::Entry (const Entry &obj)
:
    DxfObject(obj),
    name(obj.name),
    flags(obj.flags)
{
}

const Entry & Entry::operator = (const Entry &obj)
{
    if (this != &obj)
    {
        *((DxfObject *)this) = obj;

        name  = obj.name;
        flags = obj.flags;
    }

    return *this;
}

bool Entry::readCommonPropertiesDXF (Tokenizer &tokenizer)
{
    switch ( tokenizer.getCode() )
    {
        case NAME:
        {
            name = tokenizer.getCommand();
            return true;
        }
        case FLAGS:
        {
            flags = tokenizer.getCommandAsInt();
            return true;
        }
    }

    return false;
}

} // namespace

