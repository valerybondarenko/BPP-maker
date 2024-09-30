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
 * Класс Entity является базовым для всех
 * примитивов.
 */
class _TCL_DXF_CLASS Entity : public DxfObject
{
public:

    // Конструкторы
    // ============

    Entity ();
    virtual ~Entity ();
    Entity (const Entity &obj);
    const Entity & operator = (const Entity &obj);

public:

    /*
     * Возвращает номер цвета (по умолчанию BYLAYER).
     */
    int getColorNumber () const;

    /*
     * Возвращает уровень возвышения (по умолчанию = 0).
     */
    double getElevation () const;

    /*
     * Возвращает направление экструзии.
     */
    const Point3d & getExtrusionDirection () const;

    /*
     * Возвращает имя слоя.
     */
    const string & getLayerName () const;

    /*
     * Возвращает имя типа линии (по умоляанию BYLAYER).
     */
    const string & getLineTypeName () const;

    /*
     * Возвращает высоту (толщину) (по умолчанию = 0).
     */
    double getThickness () const;

    string getName() const;
    void setName(const string &value);

protected:

    /*
     * Считывает общее свойство примитивов. Возвращает true,
     * если считывание прошло успешно.
     */
    bool readCommonPropertiesDXF (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========


    double  elevation;
    double  thickness;
    int     color_number;

    string  line_type_name;
    string  layer_name;
    Point3d extrusion_direction;


    // Константы
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
