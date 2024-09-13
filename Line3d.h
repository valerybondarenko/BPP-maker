/*
 * Line3d.h
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

#ifndef RU_TCL_DXF_Line3d_H
#define RU_TCL_DXF_Line3d_H

#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/*
 * ����� Line3d ������������ ����� � ������������.
 */
class _TCL_DXF_CLASS Line3d : public Entity
{
public:

    // ������������
    // ============

    Line3d ();
    virtual ~Line3d ();
    Line3d (const Line3d &obj);
    const Line3d & operator = (const Line3d &obj);

public:

    /*
     * ���������� ���������� �������� �����.
     */
    const Point3d & getEnd () const;

    /*
     * ���������� ���������� ��������� �����.
     */
    const Point3d & getStart () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    Point3d start;
    Point3d end;

    // ���������
    // =========

    enum DxfIdentifires
    {
        START_X = 10,
        START_Y = 20,
        START_Z = 30,
        END_X   = 11,
        END_Y   = 21,
        END_Z   = 31
    };

    // Entity interface
private:
    void draw();
};

inline const Point3d & Line3d::getEnd () const
{
    return end;
}

inline const Point3d & Line3d::getStart () const
{
    return start;
}

} // namespace

#endif // RU_TCL_DXF_Line3d_H
