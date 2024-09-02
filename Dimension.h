/*
 * Dimension.h
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

#ifndef RU_TCL_DXF_Dimension_H
#define RU_TCL_DXF_Dimension_H

#include <string>

#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/*
 *  ласс Dimension представл€ет размерные надписи
 * рисунка.
 */
class _TCL_DXF_CLASS Dimension : public Entity
{
public:

    /**
     *  онстанты типа размера.
     */
    enum SizeType
    {
        /**
         * ѕовернутый, горизонтальный или вертикальный.
         */
        LINEAR = 0,
        /**
         * ¬ыравненный.
         */
        ALIGNED = 1,
        /*
         * ”гловой.
         */
        ANGULAR = 2,
        /*
         * ƒиаметр.
         */
        DIAMETER = 3,
        /*
         * –адиус.
         */
        RADIUS = 4,
        /*
         * «аданный пользователем.
         */
        USER_DEFINED = 128
    };

public:

    //  онструкторы
    // ============

    Dimension ();
    virtual ~Dimension ();
    Dimension (const Dimension &obj);
    const Dimension & operator = (const Dimension &obj);

public:

    /*
     * ¬озвращает угол наклонного горизонтального или
     * вертикального размера.
     */
    double getAngle () const;

    /*
     * ¬озвращает им€ блока.
     */
    const string & getBlockName () const;

    /*
     * ¬озвращает координаты точки, используемой при задании
     * размерной линии (линейные размеры).
     */
    const Point3d & getDefinition () const;

    /*
     * ¬озвращает ориентацию размерного текста.
     */
    double getDirection () const;

    /*
     * ¬озвращает координаты точки, используемой дл€ задани€
     * размерных линий при простановке размеров от базовой линии.
     */
    const Point3d & getInsertion () const;

    /*
     * ¬озвращает длину выносной линии при разметке размеров диаметров
     * и радиусов.
     */
    double getLeaderLength () const;

    /*
     * ¬озвращает координаты центра размерного текста.
     */
    const Point3d & getMiddle () const;

    /*
     * ¬озвращает координаты специальной точки 1.
     * ѕерва€ лини€ продолжени€ дл€ линейного размера или
     * конечна€ точка первой линии дл€ углового размера.
     */
    const Point3d & getSpecial1 () const;

    /*
     * ¬озвращает координаты специальной точки 2.
     * ¬тора€ лини€ продолжени€ дл€ линейного размера или
     * начальна€ точка первой линии дл€ углового размера.
     */
    const Point3d & getSpecial2 () const;

    /*
     * ¬озвращает координаты точки, используемой при образмеривании
     * круга, или дуги и радиуса.
     * ѕерва€ точка размерной линии дл€ радиуса и диаметра или
     * конечна€ точка второй линии дл€ углового размера.
     */
    const Point3d & getSpecial3 () const;

    /*
     * ¬озвращает координаты точки, определ€ющей размерную дугу
     * при простановке углового размера.
     */
    const Point3d & getSpecial4 () const;

    /*
     * ¬озвращает текст разметки размеров или количество измерений.
     */
    const string & getText () const;

    /*
     * ¬озвращает тип размера.
     */
    int getType () const;

    /*
     * —читывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // јтрибуты
    // ========

    string   block_name;
    Point3d  definition;
    Point3d  middle;
    Point3d  insertion;
    int      type;
    string   text;
    Point3d  special_1;
    Point3d  special_2;
    Point3d  special_3;
    Point3d  special_4;
    double   leader_length;
    double   angle;
    double   direction;

    //  онстанты
    // =========

    enum DxfIdentifires
    {
        BLOCK_NAME    = 2,
        DEFINITION_X  = 10,
        DEFINITION_Y  = 20,
        DEFINITION_Z  = 30,
        MIDDLE_X      = 11,
        MIDDLE_Y      = 21,
        MIDDLE_Z      = 31,
        INSERTION_X   = 12,
        INSERTION_Y   = 22,
        INSERTION_Z   = 32,
        TYPE          = 70,
        TEXT          = 1,
        SPECIAL_1_X   = 13,
        SPECIAL_1_Y   = 23,
        SPECIAL_1_Z   = 33,
        SPECIAL_2_X   = 14,
        SPECIAL_2_Y   = 24,
        SPECIAL_2_Z   = 34,
        SPECIAL_3_X   = 15,
        SPECIAL_3_Y   = 25,
        SPECIAL_3_Z   = 35,
        SPECIAL_4_X   = 16,
        SPECIAL_4_Y   = 26,
        SPECIAL_4_Z   = 36,
        LEADER_LENGTH = 40,
        ANGLE         = 50,
        DIRECTION     = 51
    };
};

inline double Dimension::getAngle () const
{
    return angle;
}

inline const string & Dimension::getBlockName () const
{
    return block_name;
}

inline const Point3d & Dimension::getDefinition () const
{
    return definition;
}

inline double Dimension::getDirection () const
{
    return direction;
}

inline const Point3d & Dimension::getInsertion () const
{
    return insertion;
}

inline double Dimension::getLeaderLength () const
{
    return leader_length;
}

inline const Point3d & Dimension::getMiddle () const
{
    return middle;
}

inline const Point3d & Dimension::getSpecial1 () const
{
    return special_1;
}

inline const Point3d & Dimension::getSpecial2 () const
{
    return special_2;
}

inline const Point3d & Dimension::getSpecial3 () const
{
    return special_3;
}

inline const Point3d & Dimension::getSpecial4 () const
{
    return special_4;
}

inline const string & Dimension::getText () const
{
    return text;
}

inline int Dimension::getType () const
{
    return type;
}

} // namespace

#endif // RU_TCL_DXF_Dimension_H
