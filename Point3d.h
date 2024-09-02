/*
 * Point3d.h
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

#ifndef RU_TCL_DXF_Point3d_H
#define RU_TCL_DXF_Point3d_H

#include "tcl_dxf_defs.h"

namespace ru_tcl_dxf
{

/*
 * Класс Point3d представляет точку.
 */
class _TCL_DXF_CLASS Point3d
{
public:

    // Конструкторы
    // ============

    Point3d ();
    virtual ~Point3d ();
    Point3d (const Point3d &obj);
    const Point3d & operator = (const Point3d &obj);

public:

    /*
     * Возвращает x-координату точки.
     */
    double getX () const;

    /*
     * Возвращает y-координату точки.
     */
    double getY () const;

    /*
     * Возвращает z-координату точки.
     */
    double getZ () const;

    /*
     * Установливает новую x-координату точки.
     */
    void setX (double x);

    /*
     * Установливает новую y-координату точки.
     */
    void setY (double y);

    /*
     * Установливает новую z-координату точки.
     */
    void setZ (double z);

private:

    // Атрибуты
    // ========

    double x;
    double y;
    double z;
};


inline double Point3d::getX () const
{
    return x;
}

inline double Point3d::getY () const
{
    return y;
}

inline double Point3d::getZ () const
{
    return z;
}

inline void Point3d::setX (double x)
{
    this->x = x;
}

inline void Point3d::setY (double y)
{
    this->y = y;
}

inline void Point3d::setZ (double z)
{
    this->z = z;
}

} // namespace

#endif // RU_TCL_DXF_Point3d_H
