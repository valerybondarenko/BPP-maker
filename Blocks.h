/*
 * Blocks.h
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

#ifndef RU_TCL_DXF_Blocks_H
#define RU_TCL_DXF_Blocks_H

#include <vector>

#include "Section.h"
#include "Block.h"

namespace ru_tcl_dxf
{

/*
 * Класс Blocks представляет секцию блоков в файле.
 */
class _TCL_DXF_CLASS Blocks : public Section
{
public:

    // Конструкторы
    // ============

    Blocks ();
    virtual ~Blocks ();
    Blocks (const Blocks &obj);
    const Blocks & operator = (const Blocks &obj);

public:

    /*
	 * Возвращает список блоков.
     */
    const vector<Block> & getItems () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========

    vector<Block> items;
};


inline const vector<Block> & Blocks::getItems () const
{
    return items;
}

} // namespace

#endif // RU_TCL_DXF_Blocks_H
