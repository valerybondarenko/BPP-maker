/*
 * Circle.h
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

#ifndef RU_TCL_DXF_Circle_H
#define RU_TCL_DXF_Circle_H

#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/*
 * ����� Circle ������������ ����������.
 */
class _TCL_DXF_CLASS Circle : public Entity
{
public:

    // ������������
    // ============

    Circle ();
    virtual ~Circle ();
    Circle (const Circle &obj);
    const Circle & operator = (const Circle &obj);

public:

    /*
     * ���������� ���������� ������.
     */
    const Point3d & getCenter () const;

    /*
     * ���������� ������.
     */
    double getRadius () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    Point3d center;
    double  radius;

    // ���������
    // =========

    enum DxfIdentifires
    {
        CENTER_X    = 10,
        CENTER_Y    = 20,
        CENTER_Z    = 30,
        RADIUS      = 40
    };
};


inline const Point3d & Circle::getCenter () const
{
    return center;
}

inline double Circle::getRadius () const
{
    return radius;
}

} // namespace

#endif // RU_TCL_DXF_Circle_H
