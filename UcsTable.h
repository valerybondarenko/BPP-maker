/*
 * UcsTable.h
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

#ifndef RU_TCL_DXF_UcsTable_H
#define RU_TCL_DXF_UcsTable_H

#include <vector>

#include "Table.h"
#include "Ucs.h"

namespace ru_tcl_dxf
{

/*
 * Класс UcsTable представляет таблицу
 * пользовательской системы координат.
 */
class _TCL_DXF_CLASS UcsTable : public Table
{
public:

    // Конструкторы
    // ============

    UcsTable ();
    virtual ~UcsTable ();
    UcsTable (const UcsTable &obj);
    const UcsTable & operator = (const UcsTable &obj);

public:

    /*
     * Возвращает список UCS.
     */
    const vector<Ucs> & getItems () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========

    vector<Ucs> items;
};


inline const vector<Ucs> & UcsTable::getItems () const
{
    return items;
}

} // namespace

#endif // RU_TCL_DXF_UcsTable_H
