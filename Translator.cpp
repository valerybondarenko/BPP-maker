/*
 * Translator.cpp
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

#include "Translator.h"

#include <fstream>

namespace ru_tcl_dxf
{

Entities *Translator::getEntities() const
{
    return entities;
}



Translator::Translator ()
    :
      header(new Header()),
      tables(new Tables()),
      blocks(new Blocks()),
      entities(new Entities())
{
}

Translator::~Translator ()
{
    delete header;
    delete tables;
    delete blocks;
    delete entities;
}

Translator::Translator (const Translator &obj)
:
    header(new Header(*obj.header)),
    tables(new Tables(*obj.tables)),
    blocks(new Blocks(*obj.blocks)),
    entities(new Entities(*obj.entities))
{
}

const Translator & Translator::operator = (const Translator &obj)
{
    if (this != &obj)
    {
        header   = new Header(*obj.header);
        tables   = new Tables(*obj.tables);
        blocks   = new Blocks(*obj.blocks);
        entities = new Entities(*obj.entities);
    }

    return *this;
}

void Translator::readDXF (const string &fileName)
{
    delete header;
    delete tables;
    delete blocks;
    delete entities;

    header   = new Header();
    tables   = new Tables();
    blocks   = new Blocks();
    entities = new Entities();
    ifstream  is(fileName.c_str());
    Tokenizer tokenizer(&is);

    if (!is)
        throw FileNotFoundError();

    while (true)
    {
        tokenizer.getToken();

        if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SECTION) == true)
        {
            readSection(tokenizer);
            continue;
        }

        if (tokenizer.compareCommand(Tokenizer::DXF_KEY_EOF) == true)

            break;

        tokenizer.badInstruction();
    }

    errors = tokenizer.getErrors();
}

void Translator::readSection (Tokenizer &tokenizer)
{
    tokenizer.getToken();

    if (tokenizer.compareCommand(Tokenizer::DXF_KEY_HEADER) == true)
    {
        header->readDXF(tokenizer);
        return;
    }

    if (tokenizer.compareCommand(Tokenizer::DXF_KEY_TABLES) == true)
    {
        tables->readDXF(tokenizer);
        return;
    }

    if (tokenizer.compareCommand(Tokenizer::DXF_KEY_BLOCKS) == true)
    {
        blocks->readDXF(tokenizer);
        return;
    }

    if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ENTITIES) == true)
    {
        entities->readDXF(tokenizer);
        return;
    }

    tokenizer.badInstruction();
}

} // namespace
