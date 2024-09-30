/*
 * Arc.h
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

#ifndef RU_TCL_DXF_Arc_H
#define RU_TCL_DXF_Arc_H

#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/*
 * ����� Arc ������������ ���� ����������.
 */
class _TCL_DXF_CLASS Arc : public Entity
{
public:

    // ������������
    // ============

    Arc ();
    virtual ~Arc ();
    Arc (const Arc &obj);
    const Arc & operator = (const Arc &obj);

public:

    /*
     * ���������� ���������� ������.
     */
    const Point3d & getCenter () const;

    /*
     * ���������� �������� ���� ���� ����������.
     */
    double getEndAngle () const;

    /*
     * ���������� ������.
     */
    double getRadius () const;

    /*
     * ���������� ��������� ���� ���� ����������.
     */
    double getStartAngle () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    Point3d center;
    double  radius;
    double  start_angle;
    double  end_angle;

    // ���������
    // =========

    enum DxfIdentifires
    {
        CENTER_X    = 10,
        CENTER_Y    = 20,
        CENTER_Z    = 30,
        RADIUS      = 40,
        START_ANGLE = 50,
        END_ANGLE   = 51
    };



};


inline const Point3d & Arc::getCenter () const
{
    return center;
}

inline double Arc::getEndAngle () const
{
    return end_angle;
}

inline double Arc::getRadius () const
{
    return radius;
}

inline double Arc::getStartAngle () const
{
    return start_angle;
}

} // namespace

#endif // RU_TCL_DXF_Arc_H
