/*
 * Tables.cpp
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

#include "Tables.h"

namespace ru_tcl_dxf
{

Tables::Tables ()
:
    Section(),
    line_type_table(),
    layer_table(),
    style_table(),
    view_table(),
    vport_table(),
    ucs_table()
{
}

Tables::~Tables ()
{
}

Tables::Tables (const Tables &obj)
:
    Section(obj),
    line_type_table(obj.line_type_table),
    layer_table(obj.layer_table),
    style_table(obj.style_table),
    view_table(obj.view_table),
    vport_table(obj.vport_table),
    ucs_table(obj.ucs_table)
{
}

const Tables & Tables::operator = (const Tables &obj)
{
    if (this != &obj)
    {
        *((Section *)this) = obj;

        line_type_table = obj.line_type_table;
        layer_table     = obj.layer_table;
        style_table     = obj.style_table;
        view_table      = obj.view_table;
        vport_table     = obj.vport_table;
        ucs_table       = obj.ucs_table;
    }

    return *this;
}

void Tables::readDXF (Tokenizer &tokenizer)
{
    while (true)
    {
        tokenizer.getToken();

        if (tokenizer.getCode() == 0)
        {
            if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ENDSEC) == true)
                return;

            if (tokenizer.compareCommand(Tokenizer::DXF_KEY_TABLE) == true)
                continue;
        }

        if (tokenizer.getCode() == 2)
        {
            if (tokenizer.compareCommand(Tokenizer::DXF_KEY_LTYPE_TABLE) == true)
            {
                line_type_table.readDXF(tokenizer);
                continue;
            }

           if (tokenizer.compareCommand(Tokenizer::DXF_KEY_LAYER_TABLE) == true)
           {
                layer_table.readDXF(tokenizer);
                continue;
           }

           if (tokenizer.compareCommand(Tokenizer::DXF_KEY_STYLE_TABLE) == true)
           {
                style_table.readDXF(tokenizer);
                continue;
           }

           if (tokenizer.compareCommand(Tokenizer::DXF_KEY_VIEW_TABLE) == true)
           {
                view_table.readDXF(tokenizer);
                continue;
           }

           if (tokenizer.compareCommand(Tokenizer::DXF_KEY_VPORT_TABLE) == true)
           {
                vport_table.readDXF(tokenizer);
                continue;
           }

           if (tokenizer.compareCommand(Tokenizer::DXF_KEY_UCS_TABLE) == true)
           {
                ucs_table.readDXF(tokenizer);
                continue;
           }
        }

        tokenizer.badInstruction();
    }
}

} // namespace
