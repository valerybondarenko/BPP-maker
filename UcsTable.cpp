/*
 * UcsTable.cpp
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

#include "UcsTable.h"

namespace ru_tcl_dxf
{

UcsTable::UcsTable ()
:
    Table(),
    items()
{
}

UcsTable::~UcsTable ()
{
}

UcsTable::UcsTable (const UcsTable &obj)
:
    Table(obj),
    items(obj.items)
{
}

const UcsTable & UcsTable::operator = (const UcsTable &obj)
{
    if (this != &obj)
    {
        *((Table *)this) = obj;

        items = obj.items;
    }

    return *this;
}

void UcsTable::readDXF (Tokenizer &tokenizer)
{
    while (true)
    {
        tokenizer.getToken();

        if (tokenizer.getCode() == 0 && tokenizer.compareCommand(Tokenizer::DXF_KEY_ENDTAB) == true)
            return;

        if (tokenizer.getCode() == 0 && tokenizer.compareCommand(Tokenizer::DXF_KEY_UCS) == true)
        {
            Ucs ucs;
            ucs.readDXF(tokenizer);
            items.insert(items.end(), ucs);
        }
    }
}

} // namespace

