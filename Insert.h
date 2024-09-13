/*
 * Insert.h
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

#ifndef RU_TCL_DXF_Insert_H
#define RU_TCL_DXF_Insert_H

#include <string>
#include <vector>

#include "Entity.h"
#include "Point3d.h"
#include "Attrib.h"

namespace ru_tcl_dxf
{

/*
 * С помощью данного класса повторно вводится в изображение
 * описанный ранее объект.
 */
class _TCL_DXF_CLASS Insert : public Entity
{
public:

    // Конструкторы
    // ============

    Insert ();
    virtual ~Insert ();
    Insert (const Insert &obj);
    const Insert & operator = (const Insert &obj);

public:

    /*
     * Возвращает список атрибутов.
     */
    const vector<Attrib> & getAttributes () const;

    /*
     * Возвращает имя вводимого блока.
     */
    const string & getBlockName () const;

    /*
     * Возвращает число колонок при многократном выводе (по умолчанию = 1).
     */
    int getColumnCounts () const;

    /*
     * Возвращает расстояние между колонками.
     */
    double getColumnSpacing () const;

    /*
     * Возвращает координаты точки блока.
     */
    const Point3d & getInsertion () const;

    /*
     * Возвращает угол поворота (по умочанию = 0).
     */
    double getRotationAngle () const;

    /*
     * Возвращает число рядов при многократном выводе (по умолчанию = 1).
     */
    int getRowCounts () const;

    /*
     * Возвращает расстояние между рядами.
     */
    double getRowSpacing () const;

    /*
     * Возвращает масштабный коэффициент по x-оси.
     */
    double getXScale () const;

    /*
     * Возвращает масштабный коэффициент по y-оси.
     */
    double getYScale () const;

    /*
     * Возвращает масштабный коэффициент по z-оси.
     */
    double getZScale () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    void readAttributesDXF (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========

    string         block_name;
    Point3d        insertion;
    double         x_scale;
    double         y_scale;
    double         z_scale;
    double         rotation_angle;
    int            column_counts;
    int            row_counts;
    double         column_spacing;
    double         row_spacing;
    vector<Attrib> attributes;

    // Константы
    // =========

    enum DxfIdentifires
    {
        ATTRIBUTES_FOLLOW = 66,
        BLOCK_NAME        = 2,
        INSERTION_X       = 10,
        INSERTION_Y       = 20,
        INSERTION_Z       = 30,
        X_SCALE           = 41,
        Y_SCALE           = 42,
        Z_SCALE           = 43,
        ROTATION_ANGLE    = 50,
        COLUMN_COUNTS     = 70,
        ROW_COUNTS        = 71,
        COLUMN_SPACING    = 44,
        ROW_SPACING       = 45
    };

    // Entity interface
private:
    void draw();
};


inline const vector<Attrib> & Insert::getAttributes () const
{
    return attributes;
}

inline const string & Insert::getBlockName () const
{
    return block_name;
}

inline int Insert::getColumnCounts () const
{
    return column_counts;
}

inline double Insert::getColumnSpacing () const
{
    return column_spacing;
}

inline const Point3d & Insert::getInsertion () const
{
    return insertion;
}

inline double Insert::getRotationAngle () const
{
    return rotation_angle;
}

inline int Insert::getRowCounts () const
{
    return row_counts;
}

inline double Insert::getRowSpacing () const
{
    return row_spacing;
}

inline double Insert::getXScale () const
{
    return x_scale;
}

inline double Insert::getYScale () const
{
    return y_scale;
}

inline double Insert::getZScale () const
{
    return z_scale;
}

} // namespace

#endif // RU_TCL_DXF_Insert_H
