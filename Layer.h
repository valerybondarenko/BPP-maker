/*
 * Layer.h
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

#ifndef RU_TCL_DXF_Layer_H
#define RU_TCL_DXF_Layer_H

#include <string>

#include "Entry.h"

namespace ru_tcl_dxf
{

/*
 * ����� Layer ������������ ������� ������� �����.
 */
class _TCL_DXF_CLASS Layer : public Entry
{
public:

    // ������������
    // ============

    Layer ();
    virtual ~Layer ();
    Layer (const Layer &obj);
    const Layer & operator = (const Layer &obj);

public:

    /*
     * ���������� ���� ����.
     */
    int getColor () const;

    /*
     * ���������� ��� ���� �����.
     */
    const string & getLineType () const;

    /*
     * ���������� true, ���� ���� ���������.
     */
    bool isFrozen () const;

    /*
     * ���������� true, ���� ���� ��������.
     */
    bool isOff () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    int    color;
    string line_type;

    // ���������
    // =========

    enum DxfIdentifires
    {
        COLOR     = 62,
        LINE_TYPE = 6
    };
};


inline int Layer::getColor () const
{
    return color;
}

inline const string & Layer::getLineType () const
{
    return line_type;
}

inline bool Layer::isFrozen () const
{
    return (getFlags() & 1) == 1;
}

inline bool Layer::isOff () const
{
    return color < 0;
}

} // namespace

#endif // RU_TCL_DXF_Layer_H
