/*
 * Point3d.cpp
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

#include "Point3d.h"

namespace ru_tcl_dxf
{

Point3d::Point3d ()
:
    x(0),
    y(0),
    z(0)
{
}

Point3d::~Point3d ()
{
}

Point3d::Point3d (const Point3d &obj)
:
    x(obj.x),
    y(obj.y),
    z(obj.z)
{
}

const Point3d & Point3d::operator = (const Point3d &obj)
{
    if (this != &obj)
    {
        x = obj.x;
        y = obj.y;
        z = obj.z;
    }

    return *this;
}

} // namespace

