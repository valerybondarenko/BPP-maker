/*
 * Point.h
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

#ifndef RU_TCL_DXF_Point_H
#define RU_TCL_DXF_Point_H

#include "Entity.h"

namespace ru_tcl_dxf
{

/*
 * ����� Point ������������ �����.
 */
class _TCL_DXF_CLASS Point : public Entity
{
public:

    // ������������
    // ============

    Point ();
    virtual ~Point ();
    Point (const Point &obj);
    const Point & operator = (const Point &obj);

public:

    /*
     * ���������� ���� � x-����.
     */
    double getAngleXAxis () const;

    /*
     * ���������� x-���������� �����.
     */
    double getX () const;

    /*
     * ���������� y-���������� �����.
     */
    double getY () const;

    /*
     * ���������� z-���������� �����.
     */
    double getZ () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    double x;
    double y;
    double z;
    double angle_x_axis;

    // ���������
    // =========

    enum DxfIdentifires
    {
        X            = 10,
        Y            = 20,
        Z            = 30,
        ANGLE_X_AXIS = 50
    };

    // Entity interface
private:
    void draw();
};


inline double Point::getAngleXAxis () const
{
    return angle_x_axis;
}

inline double Point::getX () const
{
    return x;
}

inline double Point::getY () const
{
    return y;
}

inline double Point::getZ () const
{
    return z;
}

} // namespace

#endif // RU_TCL_DXF_Point_H
