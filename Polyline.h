/*
 * Polyline.h
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

#ifndef RU_TCL_DXF_Polyline_H
#define RU_TCL_DXF_Polyline_H

#include <vector>

#include "Entity.h"
#include "Vertex.h"

namespace ru_tcl_dxf
{

/*
 * ����� Polyline ������������ ���������� ����� ���������
 * ����� ������� ������� �����.
 */
class _TCL_DXF_CLASS Polyline : public Entity
{
public:

    /*
     * ��������� ����������� �����������.
     */
    enum SmoothType
    {
        /*
         * ��� �����������.
         */
        NO_SMOOTH = 0,
        /*
         * ������������ ������.
         */
        QUADRATIC_BSPLINE = 5,
        /*
         * ���������� ������ B-������.
         */
        CUBIC_BSPLINE = 6,
        /*
         * ������ �����.
         */
        BEZIER = 8
    };

public:

    // ������������
    // ============

    Polyline ();
    virtual ~Polyline ();
    Polyline (const Polyline &obj);
    const Polyline & operator = (const Polyline &obj);

public:

    /*
     * ���������� �������� ������ �� ���������.
     */
    double getDefaultEndWidth () const;

    /*
     * ���������� ��������� ������ �� ���������.
     */
    double getDefaultStartWidth () const;

    /*
     * ���������� ����� ������ ����������� � ������ �����������.
     */
    int getMeshMVertexCount () const;

    /*
     * ���������� ����� ������ ����������� �� ������ �����������.
     */
    int getMeshNVertexCount () const;

    /*
     * ���������� ��������� ����������� ����������� � ������ �����������.
     */
    int getSmoothSurfaceMDensities () const;

    /*
     * ���������� ��������� ����������� ����������� �� ������ �����������.
     */
    int getSmoothSurfaceNDensities () const;

    /*
     * ���������� ��� ����������� �����������.
     */
    int getSmoothSurfaceType () const;

    /*
     * ���������� true, ���� 3D ������������� ���� ��������.
     */
    bool isClosedPolygonMesh3D () const;

    /*
     * ���������� true, ���� ��������� ���������.
     */
    bool isClosedPolyline () const;

    /*
     * ���������� true, ���� ��������� ������� ����������� ������.
     */
    bool isCurveFit () const;

    /*
     * ���������� true, ���� ��� 3D ������������� ����.
     */
    bool isPolygonMesh3D () const;

    /*
     * ���������� true, ���� ��� 3D ���������.
     */
    bool isPolyline3D () const;

    /*
     * ���������� true, ���� ��������� ������� ������������ ��������.
     */
    bool isSplineFit () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    void readVerticesDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    int            flags;
    double         default_start_width;
    double         default_end_width;
    int            mesh_m_vertex_count;
    int            mesh_n_vertex_count;
    int            smooth_surface_m_densities;
    int            smooth_surface_n_densities;
    int            smooth_surface_type;
    vector<Vertex> items;

    // ���������
    // =========

    enum DxfIdentifires
    {
        VERTICES_FOLLOW            = 66,
        FLAGS                      = 70,
        DEFAULT_START_WIDTH        = 40,
        DEFAULT_END_WIDTH          = 41,
        MESH_M_VERTEX_COUNT        = 71,
        MESH_N_VERTEX_COUNT        = 72,
        SMOOTH_SURFACE_M_DENSITIES = 73,
        SMOOTH_SURFACE_N_DENSITIES = 74,
        SMOOTH_SURFACE_TYPE        = 75
    };

    // Entity interface
public:
    void draw();
};


inline double Polyline::getDefaultEndWidth () const
{
    return default_end_width;
}

inline double Polyline::getDefaultStartWidth () const
{
    return default_start_width;
}

inline int Polyline::getMeshMVertexCount () const
{
    return mesh_m_vertex_count;
}

inline int Polyline::getMeshNVertexCount () const
{
    return mesh_n_vertex_count;
}

inline int Polyline::getSmoothSurfaceMDensities () const
{
    return smooth_surface_m_densities;
}

inline int Polyline::getSmoothSurfaceNDensities () const
{
    return smooth_surface_n_densities;
}

inline int Polyline::getSmoothSurfaceType () const
{
    return smooth_surface_type;
}

inline bool Polyline::isClosedPolygonMesh3D () const
{
    return (flags & 32) == 32;
}

inline bool Polyline::isClosedPolyline () const
{
    return (flags & 1) == 1;
}

inline bool Polyline::isCurveFit () const
{
    return (flags & 2) == 2;
}

inline bool Polyline::isPolygonMesh3D () const
{
    return (flags & 16) == 16;
}

inline bool Polyline::isPolyline3D () const
{
    return (flags & 8) == 8;
}

inline bool Polyline::isSplineFit () const
{
    return (flags & 4) == 4;
}

} // namespace

#endif // RU_TCL_DXF_Polyline_H
