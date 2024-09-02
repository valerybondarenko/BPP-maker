/*
 * Blocks.cpp
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

#include "Blocks.h"

namespace ru_tcl_dxf
{

Blocks::Blocks ()
:
    Section(),
    items()
{
}

Blocks::~Blocks ()
{
}

Blocks::Blocks (const Blocks &obj)
:
    Section(obj),
    items(obj.items)
{
}

const Blocks & Blocks::operator = (const Blocks &obj)
{
    if (this != &obj)
    {
        *((Section *)this) = obj;

        items = obj.items;
    }

    return *this;
}

void Blocks::readDXF (Tokenizer &tokenizer)
{
    while (true)
    {
        tokenizer.getToken();

        if (tokenizer.getCode() == 0 &&
            tokenizer.compareCommand(Tokenizer::DXF_KEY_ENDSEC) == true)
        {
            return;
        }

        if (tokenizer.compareCommand(Tokenizer::DXF_KEY_BLOCK) == true)
        {
            Block block;
            block.readDXF(tokenizer);
            items.insert(items.end(), block);
        }
    }
}

} // namespace

