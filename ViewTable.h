/*
 * ViewTable.h
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

#ifndef RU_TCL_DXF_ViewTable_H
#define RU_TCL_DXF_ViewTable_H

#include <vector>

#include "Table.h"
#include "LineType.h"

namespace ru_tcl_dxf
{

/*
 * ����� ViewTable ������������ ������� �����.
 */
class _TCL_DXF_CLASS ViewTable : public Table
{
public:

    // ������������
    // ============

    ViewTable ();
    virtual ~ViewTable ();
    ViewTable (const ViewTable &obj);
    const ViewTable & operator = (const ViewTable &obj);

public:

    /*
     * ���������� ������ �����.
     */
    const vector<LineType> & getItems () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    vector<LineType> items;
};


inline const vector<LineType> & ViewTable::getItems () const
{
    return items;
}

} // namespace

#endif // RU_TCL_DXF_ViewTable_H
