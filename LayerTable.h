/*
 * LayerTable.h
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

#ifndef RU_TCL_DXF_LayerTable_H
#define RU_TCL_DXF_LayerTable_H

#include <vector>

#include "Table.h"
#include "Layer.h"

namespace ru_tcl_dxf
{

/*
 * ����� LayerTable ������������ ������� �����.
 */
class _TCL_DXF_CLASS LayerTable : public Table
{
public:

    // ������������
    // ============

    LayerTable ();
    virtual ~LayerTable ();
    LayerTable (const LayerTable &obj);
    const LayerTable & operator = (const LayerTable &obj);

public:

    /*
     * ���������� ������ �����.
     */
    const vector<Layer> & getItems () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    vector<Layer> items;
};


inline const vector<Layer> & LayerTable::getItems () const
{
    return items;
}


} // namespace

#endif // RU_TCL_DXF_LayerTable_H
