/*
 * View.h
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

#ifndef RU_TCL_DXF_View_H
#define RU_TCL_DXF_View_H

#include "Entry.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/*
 * Класс View представляет элемент таблицы видов.
 */
class _TCL_DXF_CLASS View : public Entry
{
public:

    // Конструкторы
    // ============

    View ();
    virtual ~View ();
    View (const View &obj);
    const View & operator = (const View &obj);

public:

    /*
     * Возвращает заднюю секцию плоскости.
     */
    double getBackClipping () const;

    /*
     * Возвращает центральную точку вида (x, y).
     */
    const Point3d & getCenter () const;

    /*
     * Возвращает направление взгляда.
     */
    const Point3d & getDirection () const;

    /*
     * Возвращает переднюю секцию плоскости.
     */
    double getFrontClipping () const;

    /*
     * Возвращает высоту окна просмотра.
     */
    double getHeight () const;

    /*
     * Возвращает фокусное расстояние объектива.
     */
    double getLensLenght () const;

    /*
     * Возвращает координаты целевой точки.
     */
    const Point3d & getTarget () const;

    /*
     * Возвращает угол вращения.
     */
    double getTwistAngle () const;

    /*
     * Возвращает ширину окна просмотра.
     */
    double getWidth () const;

    /*
     * Возвращает true, если активна задняя плоскость отсечения.
     */
    bool isBackCippingOn () const;

    /*
     * Возвращает true, если выключены все режимы.
     */
    bool isDisabled () const;

    /*
     * Возвращает true, если активна передняя плоскость отсечения.
     */
    bool isFrontCippingOn () const;

    /*
     * Возвращает true, если передняя плоскость отсечения
     * не находится в поле зрения.
     */
    bool isFrontClipNotAtEye () const;

    /*
     * Возвращает true, если активна перспективная проекция.
     */
    bool isPerspectiveViewActive () const;

    /*
     * Возвращает true, если активен режим UCS.
     */
    bool isUCSOn () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========

    double   height;
    double   width;
    Point3d  center;
    Point3d  direction;
    Point3d  target;
    double   lens_length;
    double   front_clipping;
    double   back_clipping;
    double   twist_angle;
    int      view_mode;

    // Константы
    // =========

    enum DxfIdentifires
    {
        HEIGHT         = 40,
        WIDTH          = 41,
        CENTER_X       = 10,
        CENTER_Y       = 20,
        DIRECTION_X    = 11,
        DIRECTION_Y    = 21,
        DIRECTION_Z    = 31,
        TARGET_X       = 12,
        TARGET_Y       = 22,
        TARGET_Z       = 32,
        LENS_LENGTH    = 42,
        FRONT_CLIPPING = 43,
        BACK_CLIPPING  = 44,
        TWIST_ANGLE    = 45,
        VIEW_MODE      = 71
    };
};


inline double View::getBackClipping () const
{
    return back_clipping;
}

inline const Point3d & View::getCenter () const
{
    return center;
}

inline const Point3d & View::getDirection () const
{
    return direction;
}

inline double View::getFrontClipping () const
{
    return front_clipping;
}

inline double View::getHeight () const
{
    return height;
}

inline double View::getLensLenght () const
{
    return lens_length;
}

inline const Point3d & View::getTarget () const
{
    return target;
}

inline double View::getTwistAngle () const
{
    return twist_angle;
}

inline double View::getWidth () const
{
    return width;
}

inline bool View::isBackCippingOn () const
{
    return (view_mode & 4) == 4;
}

inline bool View::isDisabled () const
{
    return view_mode == 0;
}

inline bool View::isFrontCippingOn () const
{
    return (view_mode & 2) == 2;
}

inline bool View::isFrontClipNotAtEye () const
{
    return (view_mode & 16) == 16;
}

inline bool View::isPerspectiveViewActive () const
{
    return (view_mode & 1) == 1;
}

inline bool View::isUCSOn () const
{
    return (view_mode & 8) == 8;
}

} // namespace

#endif // RU_TCL_DXF_View_H
