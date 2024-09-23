/*
 * Line.h
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

#ifndef RU_TCL_DXF_Line_H
#define RU_TCL_DXF_Line_H

#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/*
 * Класс Line представляет линию.
 */
class _TCL_DXF_CLASS Line : public Entity
{
public:

    // Конструкторы
    // ============

    Line ();
    virtual ~Line ();
    Line (const Line &obj);
    const Line & operator = (const Line &obj);

public:

    /*
     * Возвращает координаты конечной точки.
     */
    const Point3d & getEnd () const;

    /*
     * Возвращает координаты начальной точки.
     */
    const Point3d & getStart () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========

    Point3d start;
    Point3d end;

    // Константы
    // =========

    enum DxfIdentifires
    {
        START_X = 10,
        START_Y = 20,
        START_Z = 30,
        END_X   = 11,
        END_Y   = 21,
        END_Z   = 31
    };

    // Entity interface
    public:
    void draw(ScreenView *value);
};


inline const Point3d & Line::getEnd () const
{
    return end;
}

inline const Point3d & Line::getStart () const
{
    return start;
}

} // namespace

#endif // RU_TCL_DXF_Line_H
