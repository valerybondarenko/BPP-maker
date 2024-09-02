/*
 * StyleTable.h
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

#ifndef RU_TCL_DXF_StyleTable_H
#define RU_TCL_DXF_StyleTable_H

#include <vector>

#include "Table.h"
#include "Style.h"

namespace ru_tcl_dxf
{

/*
 * ����� StyleTable ������������ ������� ������.
 */
class _TCL_DXF_CLASS StyleTable : public Table
{
public:

    // ������������
    // ============

    StyleTable ();
    virtual ~StyleTable ();
    StyleTable (const StyleTable &obj);
    const StyleTable & operator = (const StyleTable &obj);

public:

    /*
     * ���������� ������ ������.
     */
    const vector<Style> & getItems () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    vector<Style> items;
};


inline const vector<Style> & StyleTable::getItems () const
{
    return items;
}

} // namespace

#endif // RU_TCL_DXF_StyleTable_H
