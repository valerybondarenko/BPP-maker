/*
 * Shape.h
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

#ifndef RU_TCL_DXF_Shape_H
#define RU_TCL_DXF_Shape_H

#include <string>

#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/*
 * Класс Shape представляет символ.
 */
class _TCL_DXF_CLASS Shape : public Entity
{
public:

    // Конструкторы
    // ============

    Shape ();
    virtual ~Shape ();
    Shape (const Shape &obj);
    const Shape & operator = (const Shape &obj);

public:

    /*
     * Возвращает координаты точки вставки символа.
     */
    const Point3d & getInsertion () const;

    /*
     * Возвращает угол наклона (по умолчанию = 0).
     */
    double getObliquingAngle () const;

    /*
     * Возвращает угол поворота (по умолчанию = 0).
     */
    double getRotationAngle () const;

    /*
     * Возвращает имя графического символа (формы).
     */
    const string & getShapeName () const;

    /*
     * Возвращает размер символа.
     */
    double getSize () const;

    /*
     * Возвращает линейный масштаб по оси x (по умолчанию = 1).
     */
    double getXScale () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========

    Point3d insertion;
    double  size;
    string  shape_name;
    double  rotation_angle;
    double  x_scale;
    double  obliquing_angle;

    // Константы
    // =========

    enum DxfIdentifires
    {
        INSERTION_X     = 10,
        INSERTION_Y     = 20,
        INSERTION_Z     = 30,
        SIZE            = 40,
        SHAPE_NAME      = 1,
        ROTATION_ANGLE  = 50,
        X_SCALE         = 41,
        OBLIQUING_ANGLE = 51
    };

    // Entity interface
public:
    void draw();
};


inline const Point3d & Shape::getInsertion () const
{
    return insertion;
}

inline double Shape::getObliquingAngle () const
{
    return obliquing_angle;
}

inline double Shape::getRotationAngle () const
{
    return rotation_angle;
}

inline const string & Shape::getShapeName () const
{
    return shape_name;
}

inline double Shape::getSize () const
{
    return size;
}

inline double Shape::getXScale () const
{
    return x_scale;
}

} // namespace

#endif // RU_TCL_DXF_Shape_H
