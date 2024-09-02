/*
 * Vport.cpp
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

#include "Vport.h"

namespace ru_tcl_dxf
{

Vport::Vport ()
:
    Entry(),
    left_corner(),
    right_corner(),
    view_center(),
    snap_base(),
    snap_spacing_x(0),
    snap_spacing_y(0),
    grid_spacing_x(0),
    grid_spacing_y(0),
    view_direction(),
    view_target(),
    view_height(0),
    aspect_ratio(0),
    lens_length(0),
    front_clipping(0),
    back_clipping(0),
    snap_rotation_angle(0),
    view_twist_angle(0),
    view_mode(0),
    circle_zoom_percent(0),
    fast_zoom_setting(0),
    ucsicon_setting(0),
    snap(0),
    grid(0),
    snap_style(0),
    snap_isopair(0)
{
}

Vport::~Vport ()
{
}

Vport::Vport (const Vport &obj)
:
    Entry(obj),
    left_corner(obj.left_corner),
    right_corner(obj.right_corner),
    view_center(obj.view_center),
    snap_base(obj.snap_base),
    snap_spacing_x(obj.snap_spacing_x),
    snap_spacing_y(obj.snap_spacing_y),
    grid_spacing_x(obj.grid_spacing_x),
    grid_spacing_y(obj.grid_spacing_y),
    view_direction(obj.view_direction),
    view_target(obj.view_target),
    view_height(obj.view_height),
    aspect_ratio(obj.aspect_ratio),
    lens_length(obj.lens_length),
    front_clipping(obj.front_clipping),
    back_clipping(obj.back_clipping),
    snap_rotation_angle(obj.snap_rotation_angle),
    view_twist_angle(obj.view_twist_angle),
    view_mode(obj.view_mode),
    circle_zoom_percent(obj.circle_zoom_percent),
    fast_zoom_setting(obj.fast_zoom_setting),
    ucsicon_setting(obj.ucsicon_setting),
    snap(obj.snap),
    grid(obj.grid),
    snap_style(obj.snap_style),
    snap_isopair(obj.snap_isopair)
{
}

const Vport & Vport::operator = (const Vport &obj)
{
    if (this != &obj)
    {
        *((Entry *)this) = obj;

        left_corner         = obj.left_corner;
        right_corner        = obj.right_corner;
        view_center         = obj.view_center;
        snap_base           = obj.snap_base;
        snap_spacing_x      = obj.snap_spacing_x;
        snap_spacing_y      = obj.snap_spacing_y;
        grid_spacing_x      = obj.grid_spacing_x;
        grid_spacing_y      = obj.grid_spacing_y;
        view_direction      = obj.view_direction;
        view_target         = obj.view_target;
        view_height         = obj.view_height;
        aspect_ratio        = obj.aspect_ratio;
        lens_length         = obj.lens_length;
        front_clipping      = obj.front_clipping;
        back_clipping       = obj.back_clipping;
        snap_rotation_angle = obj.snap_rotation_angle;
        view_twist_angle    = obj.view_twist_angle;
        view_mode           = obj.view_mode;
        circle_zoom_percent = obj.circle_zoom_percent;
        fast_zoom_setting   = obj.fast_zoom_setting;
        ucsicon_setting     = obj.ucsicon_setting;
        snap                = obj.snap;
        grid                = obj.grid;
        snap_style          = obj.snap_style;
        snap_isopair        = obj.snap_isopair;
    }

    return *this;
}

void Vport::readDXF (Tokenizer &tokenizer)
{
    bool end = false;

    while (end == false)
    {
        tokenizer.getToken();

        if (readCommonPropertiesDXF(tokenizer) == true)
            continue;

        switch ( tokenizer.getCode() )
        {
            case 0:
            {
                end = true;
                break;
            }
            case LEFT_CORNER_X:
            {
                left_corner.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case LEFT_CORNER_Y:
            {
                left_corner.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case RIGHT_CORNER_X:
            {
                right_corner.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case RIGHT_CORNER_Y:
            {
                right_corner.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case VIEW_CENTER_X:
            {
                view_center.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case VIEW_CENTER_Y:
            {
                view_center.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case SNAP_BASE_X:
            {
                snap_base.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case SNAP_BASE_Y:
            {
                snap_base.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case SNAP_SPACING_X:
            {
                snap_spacing_x = tokenizer.getCommandAsDouble();
                break;
            }
            case SNAP_SPACING_Y:
            {
                snap_spacing_y = tokenizer.getCommandAsDouble();
                break;
            }
            case GRID_SPACING_X:
            {
                grid_spacing_x = tokenizer.getCommandAsDouble();
                break;
            }
            case GRID_SPACING_Y:
            {
                grid_spacing_y = tokenizer.getCommandAsDouble();
                break;
            }
            case VIEW_DIRECTION_X:
            {
                view_direction.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case VIEW_DIRECTION_Y:
            {
                view_direction.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case VIEW_DIRECTION_Z:
            {
                view_direction.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case VIEW_TARGET_X:
            {
                view_target.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case VIEW_TARGET_Y:
            {
                view_target.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case VIEW_TARGET_Z:
            {
                view_target.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            case VIEW_HEIGHT:
            {
                view_height = tokenizer.getCommandAsDouble();
                break;
            }
            case ASPECT_RATIO:
            {
                aspect_ratio = tokenizer.getCommandAsDouble();
                break;
            }
            case LENS_LENGTH:
            {
                lens_length = tokenizer.getCommandAsDouble();
                break;
            }
            case FRONT_CLIPPING:
            {
                front_clipping = tokenizer.getCommandAsDouble();
                break;
            }
            case BACK_CLIPPING:
            {
                back_clipping = tokenizer.getCommandAsDouble();
                break;
            }
            case SNAP_ROTATION_ANGLE:
            {
                snap_rotation_angle = tokenizer.getCommandAsDouble();
                break;
            }
            case VIEW_TWIST_ANGLE:
            {
                view_twist_angle = tokenizer.getCommandAsDouble();
                break;
            }
            case VIEW_MODE:
            {
                view_mode = tokenizer.getCommandAsInt();
                break;
            }
            case CIRCLE_ZOOM_PERCENT:
            {
                circle_zoom_percent = tokenizer.getCommandAsInt();
                break;
            }
            case FAST_ZOOM_SETTING:
            {
                fast_zoom_setting = tokenizer.getCommandAsInt();
                break;
            }
            case UCSICON_SETTING:
            {
                ucsicon_setting = tokenizer.getCommandAsInt();
                break;
            }
            case SNAP:
            {
                snap = tokenizer.getCommandAsInt();
                break;
            }
            case GRID:
            {
                grid = tokenizer.getCommandAsInt();
                break;
            }
            case SNAP_STYLE:
            {
                snap_style = tokenizer.getCommandAsInt();
                break;
            }
            case SNAP_ISOPAIR:
            {
                snap_isopair = tokenizer.getCommandAsInt();
                break;
            }
            default:
            {
                tokenizer.badInstruction();
                break;
            }
        }
    }

    tokenizer.gotoBack();
}

} // namespace

