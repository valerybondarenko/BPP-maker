/*
 * Vport.h
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

#ifndef RU_TCL_DXF_Vport_H
#define RU_TCL_DXF_Vport_H

#include "Entry.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/*
 * Класс Vport представляет элемент таблицы
 * видовых экранов.
 */
class _TCL_DXF_CLASS Vport : public Entry
{
public:

    /*
     * Константы изометрического стиля (изометрический план).
     */
    enum SnapIsopairType
    {
        /*
         * Левый.
         */
        SNAP_ISOPAIR_LEFT = 0,
        /*
         * Верхний.
         */
        SNAP_ISOPAIR_TOP = 1,
        /*
         * Правый.
         */
        SNAP_ISOPAIR_RIGHT = 2
    };

    /*
     * Константа способа привязки.
     */
    enum SnapStyleType
    {
        /*
         * Стандартный.
         */
        SNAP_STYLE_STANDART = 0,
        /*
         * Изометрический.
         */
        SNAP_STYLE_ISOMETRIC = 1
    };

public:

    // Конструкторы
    // ============

    Vport ();
    virtual ~Vport ();
    Vport (const Vport &obj);
    const Vport & operator = (const Vport &obj);

public:

    /*
     * Возвращает соотношение сторон видового экрана.
     */
    double getAspectRatio () const;

    /*
     * Возвращает заднюю секцию плоскости.
     */
    double getBackClipping () const;

    /*
     * Возвращает точность аппроксимации окружности.
     */
    int getCircleZoomPercent () const;

    /*
     * Возвращает переднюю секцию плоскости.
     */
    double getFrontClipping () const;

    /*
     * Возвращает интервал сетки в x-направлении.
     */
    double getGridSpacingX () const;

    /*
     * Возвращает интервал сетки в y-направлении.
     */
    double getGridSpacingY () const;

    /*
     * Возвращает левый нижний угол видового экрана (x, y).
     */
    const Point3d & getLeftCorner () const;

    /*
     * Возвращает фокусное расстояние объектива.
     */
    double getLensLenght () const;

    /*
     * Возвращает правый верхний угол видового экрана (x, y).
     */
    const Point3d & getRightCorner () const;

    /*
     * Возвращает базовую точку шаговой привязки (x, y).
     */
    const Point3d & getSnapBase () const;

    /*
     * Возвращает изометрический стиль.
     */
    int getSnapIsopair () const;

    /*
     * Возвращает угол поворота сетки привязки.
     */
    double getSnapRotationAngle () const;

    /*
     * Возвращает интервал шаговой привязки в x-направлении.
     */
    double getSnapSpacingX () const;

    /*
     * Возвращает интервал шаговой привязки в y-направлении.
     */
    double getSnapSpacingY () const;

    /*
     * Возвращает способ привязки.
     */
    int getSnapStyle () const;

    /*
     * Возвращает пиктограмму системы координат.
     */
    int getUCSICONSetting () const;

    /*
     * Возвращает среднюю точку вида (x, y).
     */
    const Point3d & getViewCenter () const;

    /*
     * Возвращает направление взгляда.
     */
    const Point3d & getViewDirection () const;

    /*
     * Возвращает высоту вида.
     */
    double getViewHeight () const;

    /*
     * Возвращает координаты точки цели.
     */
    const Point3d & getViewTarget () const;

    /*
     * Возвращает угол вращения вида.
     */
    double getViewTwistAngle () const;

    /*
     * Возвращает true, если активна задняя плоскость отсечения.
     */
    bool isBackCippingOn () const;

    /*
     * Возвращает true, если выключены все режимы.
     */
    bool isDisabled () const;

    /*
     * Возвращает true, если включен режим fast zoom.
     */
    bool isFastZoomOn () const;

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
     * Возвращает true, если GRID включен.
     */
    bool isGridModeOn () const;

    /*
     * Возвращает true, если активна перспективная проекция.
     */
    bool isPerspectiveViewActive () const;

    /*
     * Возвращает true, если SNAP включен.
     */
    bool isSnapModeOn () const;

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

    Point3d  left_corner;
    Point3d  right_corner;
    Point3d  view_center;
    Point3d  snap_base;
    double   snap_spacing_x;
    double   snap_spacing_y;
    double   grid_spacing_x;
    double   grid_spacing_y;
    Point3d  view_direction;
    Point3d  view_target;
    double   view_height;
    double   aspect_ratio;
    double   lens_length;
    double   front_clipping;
    double   back_clipping;
    double   snap_rotation_angle;
    double   view_twist_angle;
    int      view_mode;
    int      circle_zoom_percent;
    int      fast_zoom_setting;
    int      ucsicon_setting;
    int      snap;
    int      grid;
    int      snap_style;
    int      snap_isopair;

    // Константы
    // =========

    enum DxfIdentifires
    {
        LEFT_CORNER_X       = 10,
        LEFT_CORNER_Y       = 20,
        RIGHT_CORNER_X      = 11,
        RIGHT_CORNER_Y      = 21,
        VIEW_CENTER_X       = 12,
        VIEW_CENTER_Y       = 22,
        SNAP_BASE_X         = 13,
        SNAP_BASE_Y         = 23,
        SNAP_SPACING_X      = 14,
        SNAP_SPACING_Y      = 24,
        GRID_SPACING_X      = 15,
        GRID_SPACING_Y      = 25,
        VIEW_DIRECTION_X    = 16,
        VIEW_DIRECTION_Y    = 26,
        VIEW_DIRECTION_Z    = 36,
        VIEW_TARGET_X       = 17,
        VIEW_TARGET_Y       = 27,
        VIEW_TARGET_Z       = 37,
        VIEW_HEIGHT         = 40,
        ASPECT_RATIO        = 41,
        LENS_LENGTH         = 42,
        FRONT_CLIPPING      = 43,
        BACK_CLIPPING       = 44,
        SNAP_ROTATION_ANGLE = 50,
        VIEW_TWIST_ANGLE    = 51,
        VIEW_MODE           = 71,
        CIRCLE_ZOOM_PERCENT = 72,
        FAST_ZOOM_SETTING   = 73,
        UCSICON_SETTING     = 74,
        SNAP                = 75,
        GRID                = 76,
        SNAP_STYLE          = 77,
        SNAP_ISOPAIR        = 78
    };
};


inline double Vport::getAspectRatio () const
{
    return aspect_ratio;
}

inline double Vport::getBackClipping () const
{
    return back_clipping;
}

inline int Vport::getCircleZoomPercent () const
{
    return circle_zoom_percent;
}

inline double Vport::getFrontClipping () const
{
    return front_clipping;
}

inline double Vport::getGridSpacingX () const
{
    return grid_spacing_x;
}

inline double Vport::getGridSpacingY () const
{
    return grid_spacing_y;
}

inline const Point3d & Vport::getLeftCorner () const
{
    return left_corner;
}

inline double Vport::getLensLenght () const
{
    return lens_length;
}

inline const Point3d & Vport::getRightCorner () const
{
    return right_corner;
}

inline const Point3d & Vport::getSnapBase () const
{
    return snap_base;
}

inline int Vport::getSnapIsopair () const
{
    return snap_isopair;
}

inline double Vport::getSnapRotationAngle () const
{
    return snap_rotation_angle;
}

inline double Vport::getSnapSpacingX () const
{
    return snap_spacing_x;
}

inline double Vport::getSnapSpacingY () const
{
    return snap_spacing_y;
}

inline int Vport::getSnapStyle () const
{
    return snap_style;
}

inline int Vport::getUCSICONSetting () const
{
    return ucsicon_setting;
}

inline const Point3d & Vport::getViewCenter () const
{
    return view_center;
}

inline const Point3d & Vport::getViewDirection () const
{
    return view_direction;
}

inline double Vport::getViewHeight () const
{
    return view_height;
}

inline const Point3d & Vport::getViewTarget () const
{
    return view_target;
}

inline double Vport::getViewTwistAngle () const
{
    return view_twist_angle;
}

inline bool Vport::isBackCippingOn () const
{
    return (view_mode & 4) == 4;
}

inline bool Vport::isDisabled () const
{
    return view_mode == 0;
}

inline bool Vport::isFastZoomOn () const
{
    return fast_zoom_setting != 0;
}

inline bool Vport::isFrontCippingOn () const
{
    return (view_mode & 2) == 2;
}

inline bool Vport::isFrontClipNotAtEye () const
{
    return (view_mode & 16) == 16;
}

inline bool Vport::isGridModeOn () const
{
    return grid != 0;
}

inline bool Vport::isPerspectiveViewActive () const
{
    return (view_mode & 1) == 1;
}

inline bool Vport::isSnapModeOn () const
{
    return snap != 0;
}

inline bool Vport::isUCSOn () const
{
    return (view_mode & 8) == 8;
}

} // namespace

#endif // RU_TCL_DXF_Vport_H
