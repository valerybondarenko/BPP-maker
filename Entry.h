/*
 * Entry.h
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

#ifndef RU_TCL_DXF_Entry_H
#define RU_TCL_DXF_Entry_H

#include <string>

#include "DxfObject.h"

namespace ru_tcl_dxf
{

/*
 * ����� Entry �������� ������� ��� ����
 * ��������� ������.
 */
class _TCL_DXF_CLASS Entry : public DxfObject
{
public:

    // ������������
    // ============

    Entry ();
    virtual ~Entry ();
    Entry (const Entry &obj);
    const Entry & operator = (const Entry &obj);

public:

    /*
     * ���������� ������ �������� �������.
     */
    int getFlags () const;

    /*
     * ���������� ��� �������� �������.
     */
    const string & getName () const;

protected:

    /*
     * ��������� ����� �������� ��������� ���������. ���������� true,
     * ���� ���������� ������ �������.
     */
    bool readCommonPropertiesDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    string name;
    int    flags;

    // ���������
    // =========

    enum DxfIdentifires
    {
        NAME  = 2,
        FLAGS = 70
    };
};


inline int Entry::getFlags () const
{
    return flags;
}

inline const string & Entry::getName () const
{
    return name;
}

} // namespace

#endif // RU_TCL_DXF_Entry_H
