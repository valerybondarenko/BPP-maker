/*
 * Face3d.h
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

#ifndef RU_TCL_DXF_Face3d_H
#define RU_TCL_DXF_Face3d_H

#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/*
 * Класс Face3d представляет трехмерные поверхности.
 */
class _TCL_DXF_CLASS Face3d : public Entity
{
public:

    // Конструкторы
    // ============

    Face3d ();
    virtual ~Face3d ();
    Face3d (const Face3d &obj);
    const Face3d & operator = (const Face3d &obj);

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

    /*
     * Видимость первого края.
     */
    bool visibleFirstEdge () const;

    /*
     * Видимость четвертого края.
     */
    bool visibleFourthEdge () const;

    /*
     * Видимость второго края.
     */
    bool visibleSecondEdge () const;

    /*
     * Видимость третьего края.
     */
    bool visibleThirdEdge () const;

private:

    // Атрибуты
    // ========

    Point3d first_corner;
    Point3d second_corner;
    Point3d third_corner;
    Point3d fourth_corner;
    int     flags;

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
        FOURTH_CORNER_Z = 33,
        FLAGS           = 70
    };

    // Entity interface
public:
    void draw();
};


inline const Point3d & Face3d::getFirstCorner () const
{
    return first_corner;
}

inline const Point3d & Face3d::getFourthCorner () const
{
    return fourth_corner;
}

inline const Point3d & Face3d::getSecondCorner () const
{
    return second_corner;
}

inline const Point3d & Face3d::getThirdCorner () const
{
    return third_corner;
}

inline bool Face3d::visibleFirstEdge () const
{
    return (flags & 1) == 1;
}

inline bool Face3d::visibleFourthEdge () const
{
    return (flags & 8) == 8;
}

inline bool Face3d::visibleSecondEdge () const
{
    return (flags & 2) == 2;
}

inline bool Face3d::visibleThirdEdge () const
{
    return (flags & 4) == 4;
}

} // namespace

#endif // RU_TCL_DXF_Face3d_H
