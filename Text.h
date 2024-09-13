/*
 * Text.h
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

#ifndef RU_TCL_DXF_Text_H
#define RU_TCL_DXF_Text_H

#include <string>

#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

using namespace std;

/*
 * Класс Text представляет текст.
 */
class _TCL_DXF_CLASS Text : public Entity
{
public:

    /*
     * Константы выравнивания текста.
     */
    enum Alignment
    {
        /*
         * Выравненный влево.
         */
        LEFT_JUSTIFIED = 0,
        /*
         * Отцентрированный.
         */
        CENTERED = 1,
        /*
         * Выравненный вправо.
         */
        RIGHT_JUSTIFIED = 2,
        /*
         * Выравненный относительно указаной точки.
         */
        ALLIGN_BETWEEN_TWO_POINTS = 3,
        /*
         * Середина в указанной точки.
         */
        MIDDLE_CENTERED = 4,
        /*
         * Вписанный.
         */
        FIT_BETWEEN_TWO_POINTS = 5,
    };

public:

    // Конструкторы
    // ============

    Text ();
    virtual ~Text ();
    Text (const Text &obj);
    const Text & operator = (const Text &obj);

public:

    /*
     * Возвращает координаты точки выравнивания.
     */
    const Point3d & getAlignment () const;

    /*
     * Возвращает высоту текста.
     */
    double getHeight () const;

    /*
     * Возвращает координаты точки вставки текста.
     */
    const Point3d & getInsertion () const;

    /*
     * Возвращает тип выравнивания текста.
     */
    int getJustificationType () const;

    /*
     * Возвращает угол наклона литер (по умолчанию = 0).
     */
    double getObliquingAngle () const;

    /*
     * Возвращает угол поворота текста (по умолчанию = 0).
     */
    double getRotationAngle () const;

    /*
     * Возвращает имя стиля начертания (по умолчанию = STANDART).
     */
    const string & getStyle () const;

    /*
     * Возвращает текст.
     */
    const string & getText () const;

    /*
     * Возвращает линейный масштаб по оси x (по умолчанию = 1).
     */
    double getXScale () const;

    /*
     * Возвращает true, если текст зеркально отображен по оси х.
     */
    bool isBackwards () const;

    /*
     * Возвращает true, если текст перевернут относительно оси х.
     */
    bool isUpsideDown () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========

    Point3d insertion;
    double  height;
    string  text;
    double  rotation_angle;
    double  x_scale;
    double  obliquing_angle;
    string  style;
    int     generation_flags;
    int     justification_type;
    Point3d alignment;

    // Константы
    // =========

    enum DxfIdentifires
    {
        INSERTION_X        = 10,
        INSERTION_Y        = 20,
        INSERTION_Z        = 30,
        HEIGHT             = 40,
        TEXT               = 1,
        ROTATION_ANGLE     = 50,
        X_SCALE            = 41,
        OBLIQUING_ANGLE    = 51,
        STYLE              = 7,
        GENERATION_FLAGS   = 71,
        JUSTIFICATION_TYPE = 72,
        ALIGNMENT_X        = 11,
        ALIGNMENT_Y        = 21,
        ALIGNMENT_Z        = 31
    };

    // Entity interface
private:
    void draw();
};


inline const Point3d & Text::getAlignment () const
{
    return alignment;
}

inline double Text::getHeight () const
{
    return height;
}

inline const Point3d & Text::getInsertion () const
{
    return insertion;
}

inline int Text::getJustificationType () const
{
    return justification_type;
}

inline double Text::getObliquingAngle () const
{
    return obliquing_angle;
}

inline double Text::getRotationAngle () const
{
    return rotation_angle;
}

inline const string & Text::getStyle () const
{
    return style;
}

inline const string & Text::getText () const
{
    return text;
}

inline double Text::getXScale () const
{
    return x_scale;
}

inline bool Text::isBackwards () const
{
    return (generation_flags & 2) == 2;
}

inline bool Text::isUpsideDown () const
{
    return (generation_flags & 4) == 4;
}

} // namespace

#endif // RU_TCL_DXF_Text_H
