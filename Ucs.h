/*
 * Ucs.h
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

#ifndef RU_TCL_DXF_Ucs_H
#define RU_TCL_DXF_Ucs_H

#include "Entry.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/*
 * ����� Ucs ������������ ������� �������
 * ���������������� ������� ���������.
 */
class _TCL_DXF_CLASS Ucs : public Entry
{
public:

    // ������������
    // ============

    Ucs ();
    virtual ~Ucs ();
    Ucs (const Ucs &obj);
    const Ucs & operator = (const Ucs &obj);

public:

    /*
     * ���������� ������ ������� ��������� ������������
     * � ������� �����������.
     */
    const Point3d & getOrigin () const;

    /*
     * ���������� ����������� x-��� � ������� �����������.
     */
    const Point3d & getXAxisDirection () const;

    /*
     * ���������� ����������� y-��� � ������� �����������.
     */
    const Point3d & getYAxisDirection () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    Point3d origin;
    Point3d x_axis_direction;
    Point3d y_axis_direction;

    // ���������
    // =========

    enum DxfIdentifires
    {
        ORIGIN_X           = 10,
        ORIGIN_Y           = 20,
        ORIGIN_Z           = 30,
        X_AXIS_DIRECTION_X = 11,
        X_AXIS_DIRECTION_Y = 21,
        X_AXIS_DIRECTION_Z = 31,
        Y_AXIS_DIRECTION_X = 12,
        Y_AXIS_DIRECTION_Y = 22,
        Y_AXIS_DIRECTION_Z = 32
    };
};


inline const Point3d & Ucs::getOrigin () const
{
    return origin;
}

inline const Point3d & Ucs::getXAxisDirection () const
{
    return x_axis_direction;
}

inline const Point3d & Ucs::getYAxisDirection () const
{
    return y_axis_direction;
}

} // namespace

#endif // RU_TCL_DXF_Ucs_H
