/*
 * VportTable.h
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

#ifndef RU_TCL_DXF_VportTable_H
#define RU_TCL_DXF_VportTable_H

#include <vector>

#include "Table.h"
#include "Vport.h"

namespace ru_tcl_dxf
{

/*
 * ����� VportTable ������������ �������
 * ������� �������.
 */
class _TCL_DXF_CLASS VportTable : public Table
{
public:

    // ������������
    // ============

    VportTable ();
    virtual ~VportTable ();
    VportTable (const VportTable &obj);
    const VportTable & operator = (const VportTable &obj);

public:

    /*
     * ���������� ������ ������� �������.
     */
    const vector<Vport> & getItems () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    vector<Vport> items;
};


inline const vector<Vport> & VportTable::getItems () const
{
    return items;
}

} // namespace

#endif // RU_TCL_DXF_VportTable_H
