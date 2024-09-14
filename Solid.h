/*
 * Solid.h
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

#ifndef RU_TCL_DXF_Solid_H
#define RU_TCL_DXF_Solid_H

#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/*
 * Класс Solid представляет замкнутые внутри четырех
 * точек поверхности (заполненные четырехугольниками).
 */
class _TCL_DXF_CLASS Solid : public Entity
{
public:

    // Конструкторы
    // ============

    Solid ();
    virtual ~Solid ();
    Solid (const Solid &obj);
    const Solid & operator = (const Solid &obj);

public:

    /*
     * Возвращает координаты первого угла.
     */
    const Point3d & getFirstCorner () const;

    /*
     * Возвращает координаты четвертого угла.
     */
    const Point3d & getFourthCorner () const;

    /*
     * Возвращает координаты второго угла.
     */
    const Point3d & getSecondCorner () const;

    /*
     * Возвращает координаты третьего угла.
     */
    const Point3d & getThirdCorner () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========

    Point3d first_corner;
    Point3d second_corner;
    Point3d third_corner;
    Point3d fourth_corner;

    // Константы
    // =========

    enum DxfIdentifires
    {
        FIRST_CORNER_X  = 10,
        FIRST_CORNER_Y  = 20,
        FIRST_CORNER_Z  = 30,
        SECOND_CORNER_X = 11,
        SECOND_CORNER_Y = 21,
        SECOND_CORNER_Z = 31,
        THIRD_CORNER_X  = 12,
        THIRD_CORNER_Y  = 22,
        THIRD_CORNER_Z  = 32,
        FOURTH_CORNER_X = 13,
        FOURTH_CORNER_Y = 23,
        FOURTH_CORNER_Z = 33
    };

    // Entity interface
public:
    void draw();
};


inline const Point3d & Solid::getFirstCorner () const
{
    return first_corner;
}

inline const Point3d & Solid::getFourthCorner () const
{
    return fourth_corner;
}

inline const Point3d & Solid::getSecondCorner () const
{
    return second_corner;
}

inline const Point3d & Solid::getThirdCorner () const
{
    return third_corner;
}

} // namespace

#endif // RU_TCL_DXF_Solid_H
