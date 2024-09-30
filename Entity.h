/*
 * Entity.h
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

#ifndef RU_TCL_DXF_Entity_H
#define RU_TCL_DXF_Entity_H

#include <string>
#include "DxfObject.h"
#include "Point3d.h"
#include <QDebug>

namespace ru_tcl_dxf
{
/*
 * ����� Entity �������� ������� ��� ����
 * ����������.
 */
class _TCL_DXF_CLASS Entity : public DxfObject
{
public:

    // ������������
    // ============

    Entity ();
    virtual ~Entity ();
    Entity (const Entity &obj);
    const Entity & operator = (const Entity &obj);

public:

    /*
     * ���������� ����� ����� (�� ��������� BYLAYER).
     */
    int getColorNumber () const;

    /*
     * ���������� ������� ���������� (�� ��������� = 0).
     */
    double getElevation () const;

    /*
     * ���������� ����������� ���������.
     */
    const Point3d & getExtrusionDirection () const;

    /*
     * ���������� ��� ����.
     */
    const string & getLayerName () const;

    /*
     * ���������� ��� ���� ����� (�� ��������� BYLAYER).
     */
    const string & getLineTypeName () const;

    /*
     * ���������� ������ (�������) (�� ��������� = 0).
     */
    double getThickness () const;

    string getName() const;
    void setName(const string &value);

protected:

    /*
     * ��������� ����� �������� ����������. ���������� true,
     * ���� ���������� ������ �������.
     */
    bool readCommonPropertiesDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========


    double  elevation;
    double  thickness;
    int     color_number;

    string  line_type_name;
    string  layer_name;
    Point3d extrusion_direction;


    // ���������
    // =========

    enum DxfIdentifires
    {
        LAYER_NAME            = 8,
        LINE_TYPE_NAME        = 6,
        ELEVATION             = 38,
        THICKNESS             = 39,
        COLOR_NUMBER          = 62,
        EXTRUSION_DIRECTION_X = 210,
        EXTRUSION_DIRECTION_Y = 220,
        EXTRUSION_DIRECTION_Z = 230
    };
public:
    enum ElementType
    {
        POINT,
        LINE,
        ARC,
        CIRCLE
    };

    ElementType elementType;
};

inline int Entity::getColorNumber () const
{
    return color_number;
}

inline double Entity::getElevation () const
{
    return elevation;
}

inline const Point3d & Entity::getExtrusionDirection () const
{
    return extrusion_direction;
}

inline const string & Entity::getLayerName () const
{
    return layer_name;
}

inline const string & Entity::getLineTypeName () const
{
    return line_type_name;
}

inline double Entity::getThickness () const
{
    return thickness;
}

} // namespace

#endif // RU_TCL_DXF_Entity_H
