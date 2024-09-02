/*
 * LineTypeTable.h
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

#ifndef RU_TCL_DXF_LineTypeTable_H
#define RU_TCL_DXF_LineTypeTable_H

#include <vector>

#include "Table.h"
#include "LineType.h"

namespace ru_tcl_dxf
{

/*
 * ����� LineTypeTable ������������ �������
 * ����� �����.
 */
class _TCL_DXF_CLASS LineTypeTable : public Table
{
public:

    // ������������
    // ============

    LineTypeTable ();
    virtual ~LineTypeTable ();
    LineTypeTable (const LineTypeTable &obj);
    const LineTypeTable & operator = (const LineTypeTable &obj);

public:

    /*
     * ���������� ������ ����� �����.
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


inline const vector<LineType> & LineTypeTable::getItems () const
{
    return items;
}

} // namespace

#endif // RU_TCL_DXF_LineTypeTable_H
