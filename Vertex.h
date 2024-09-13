/*
 * Vertex.h
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

#ifndef RU_TCL_DXF_Vertex_H
#define RU_TCL_DXF_Vertex_H

#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/**
 * ����� Vertex ������������ ������� ���������.
 */
class _TCL_DXF_CLASS Vertex : public Entity
{
public:

    // ������������
    // ============

    Vertex ();
    virtual ~Vertex ();
    Vertex (const Vertex &obj);
    const Vertex & operator = (const Vertex &obj);

public:

    /*
     * ���������� ����������.
     */
    double getBulge () const;

    /*
     * ���������� �������� ������.
     */
    double getEndWidth () const;

    /*
     * ���������� ���������� �������.
     */
    const Point3d & getLocation () const;

    /*
     * ���������� ��������� ������.
     */
    double getStartWidth () const;

    /*
     * ���������� ���� ����������� � ������.
     */
    double getTangentDirection () const;

    /*
     * ���������� true, ���� ������� ������� ������� ������������ ��������.
     */
    bool isCreatedBySplineFitting () const;

    /*
     * ���������� true, ���� ��� �������������� ������� �� ����
     * ����������� ������.
     */
    bool isExtraVertex () const;

    /*
     * ���������� true, ���� ��� ������� ���������� ������������� ����.
     */
    bool isPolygonMeshVertex () const;

    /*
     * ���������� true, ���� ��� ������� ���������� ���������.
     */
    bool isPolyline3DVertex () const;

    /*
     * ���������� true, ���� ��� ����� ���������� ������ �������.
     */
    bool isSplineFrameControlPoint () const;

    /*
     * ���������� true, ���� ������� ����� �������� ����������� � �����
     * ���������� ������.
     */
    bool isTangentDefine () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    Point3d  location;
    double   start_width;
    double   end_width;
    double   bulge;
    int      flags;
    double   tangent_direction;

    // ���������
    // =========

    enum DxfIdentifires
    {
        LOCATION_X        = 10,
        LOCATION_Y        = 20,
        LOCATION_Z        = 30,
        START_WIDTH       = 40,
        END_WIDTH         = 41,
        BULGE             = 42,
        FLAGS             = 70,
        TANGENT_DIRECTION = 50
    };

    // Entity interface
private:
    void draw();
};


inline double Vertex::getBulge () const
{
    return bulge;
}

inline double Vertex::getEndWidth () const
{
    return end_width;
}

inline const Point3d & Vertex::getLocation () const
{
    return location;
}

inline double Vertex::getStartWidth () const
{
    return start_width;
}

inline double Vertex::getTangentDirection () const
{
    return tangent_direction;
}

inline bool Vertex::isCreatedBySplineFitting () const
{
    return (flags & 8) == 8;
}

inline bool Vertex::isExtraVertex () const
{
    return (flags & 1) == 1;
}

inline bool Vertex::isPolygonMeshVertex () const
{
    return (flags & 64) == 64;
}

inline bool Vertex::isPolyline3DVertex () const
{
    return (flags & 32) == 32;
}

inline bool Vertex::isSplineFrameControlPoint () const
{
    return (flags & 16) == 16;
}

inline bool Vertex::isTangentDefine () const
{
    return (flags & 2) == 2;
}

} // namespace

#endif // RU_TCL_DXF_Vertex_H
