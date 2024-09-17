/*
 * Attrib.h
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

#ifndef RU_TCL_DXF_Attrib_H
#define RU_TCL_DXF_Attrib_H

#include <string>

#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

using namespace std;

/*
 * Класс Attrib представляет атрибут.
 */
class _TCL_DXF_CLASS Attrib : public Entity
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

    Attrib ();
    virtual ~Attrib ();
    Attrib (const Attrib &obj);
    const Attrib & operator = (const Attrib &obj);

public:

    /*
     * Возвращает координаты точки выравнивания.
     */
    const Point3d & getAlignment () const;

    /*
     * Возвращает длину поля (по умолчанию = 0).
     */
    double getFieldLength () const;

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
     * Возвращает имя атрибута.
     */
    const string & getName () const;

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
     * Возвращает значение атрибута.
     */
    const string & getValue () const;

    /*
     * Возвращает линейный масштаб по оси x (по умолчанию = 1).
     */
    double getXScale () const;

    /*
     * Возвращает true, если текст зеркально отображен по оси х.
     */
    bool isBackwards () const;

    /*
     * Возвращает true, если атрибут неизменяемый.
     */
    bool isConstant () const;

    /*
     * Возвращает true, если атрибут невидимый.
     */
    bool isInvisible () const;

    /*
     * Возвращает true, если не требуется подсказки при вставке.
     */
    bool isPreset () const;

    /*
     * Возвращает true, если текст перевернут относительно оси х.
     */
    bool isUpsideDown () const;

    /*
     * Возвращает true, если требуется подтверждение при вводе
     * атрибута.
     */
    bool isVerificationRequired () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========

    Point3d insertion;
    double  height;
    string  value;
    string  name;
    int     flags;
    int     field_length;
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
        VALUE              = 1,
        NAME               = 2,
        FLAGS              = 70,
        FIELD_LENGTH       = 73,
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
public:
    void draw(Painter *painter)override;
};


inline const Point3d & Attrib::getAlignment () const
{
    return alignment;
}

inline double Attrib::getFieldLength () const
{
    return field_length;
}

inline double Attrib::getHeight () const
{
    return height;
}

inline const Point3d & Attrib::getInsertion () const
{
    return insertion;
}

inline int Attrib::getJustificationType () const
{
    return justification_type;
}

inline const string & Attrib::getName () const
{
    return name;
}

inline double Attrib::getObliquingAngle () const
{
    return obliquing_angle;
}

inline double Attrib::getRotationAngle () const
{
    return rotation_angle;
}

inline const string & Attrib::getStyle () const
{
    return style;
}

inline const string & Attrib::getValue () const
{
    return value;
}

inline double Attrib::getXScale () const
{
    return x_scale;
}

inline bool Attrib::isBackwards () const
{
    return (generation_flags & 2) == 2;
}

inline bool Attrib::isConstant () const
{
    return (flags & 2) == 2;
}

inline bool Attrib::isInvisible () const
{
    return (flags & 1) == 1;
}

inline bool Attrib::isPreset () const
{
    return (flags & 8) == 8;
}

inline bool Attrib::isUpsideDown () const
{
    return (generation_flags & 4) == 4;
}

inline bool Attrib::isVerificationRequired () const
{
    return (flags & 4) == 4;
}

} // namespace

#endif // RU_TCL_DXF_Attrib_H
