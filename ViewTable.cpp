/*
 * ViewTable.cpp
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

#include "ViewTable.h"

namespace ru_tcl_dxf
{

ViewTable::ViewTable ()
:
    Table(),
    items()
{
}

ViewTable::~ViewTable ()
{
}

ViewTable::ViewTable (const ViewTable &obj)
:
    Table(obj),
    items(obj.items)
{
}

const ViewTable & ViewTable::operator = (const ViewTable &obj)
{
    if (this != &obj)
    {
        *((Table *)this) = obj;

        items = obj.items;
    }

    return *this;
}

void ViewTable::readDXF (Tokenizer &tokenizer)
{
    while (true)
    {
        tokenizer.getToken();

        if (tokenizer.getCode() == 0 && tokenizer.compareCommand(Tokenizer::DXF_KEY_ENDTAB) == true)
            return;

        if (tokenizer.getCode() == 0 && tokenizer.compareCommand(Tokenizer::DXF_KEY_LTYPE) == true)
        {
            LineType line_type;
            line_type.readDXF(tokenizer);
            items.insert(items.end(), line_type);
        }
    }
}

} // namespace

