/*
 * Polyline.cpp
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

#include "Polyline.h"

namespace ru_tcl_dxf
{

Polyline::Polyline ()
:
    Entity(),
    flags(0),
    default_start_width(0),
    default_end_width(0),
    mesh_m_vertex_count(0),
    mesh_n_vertex_count(0),
    smooth_surface_m_densities(0),
    smooth_surface_n_densities(0),
    smooth_surface_type(0),
    items()
{
}

Polyline::~Polyline ()
{
}

Polyline::Polyline (const Polyline &obj)
:
    Entity(obj),
    flags(obj.flags),
    default_start_width(obj.default_start_width),
    default_end_width(obj.default_end_width),
    mesh_m_vertex_count(obj.mesh_m_vertex_count),
    mesh_n_vertex_count(obj.mesh_n_vertex_count),
    smooth_surface_m_densities(obj.smooth_surface_m_densities),
    smooth_surface_n_densities(obj.smooth_surface_n_densities),
    smooth_surface_type(obj.smooth_surface_type),
    items(obj.items)
{
}

const Polyline & Polyline::operator = (const Polyline &obj)
{
    if (this != &obj)
    {
        *((Entity *)this) = obj;

        flags                      = obj.flags;
        default_start_width        = obj.default_start_width;
        default_end_width          = obj.default_end_width;
        mesh_m_vertex_count        = obj.mesh_m_vertex_count;
        mesh_n_vertex_count        = obj.mesh_n_vertex_count;
        smooth_surface_m_densities = obj.smooth_surface_m_densities;
        smooth_surface_n_densities = obj.smooth_surface_n_densities;
        smooth_surface_type        = obj.smooth_surface_type;
        items                      = obj.items;
    }

    return *this;
}

void Polyline::readDXF (Tokenizer &tokenizer)
{
    bool end             = false;
    int  vertices_follow = 0;

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
            case 9:
            {
                end = true;
                break;
            }
            case VERTICES_FOLLOW:
            {
                vertices_follow = tokenizer.getCommandAsInt();
                break;
            }
            case FLAGS:
            {
                flags = tokenizer.getCommandAsInt();
                break;
            }
            case DEFAULT_START_WIDTH:
            {
                default_start_width = tokenizer.getCommandAsDouble();
                break;
            }
            case DEFAULT_END_WIDTH:
            {
                default_end_width = tokenizer.getCommandAsDouble();
                break;
            }
            case MESH_M_VERTEX_COUNT:
            {
                mesh_m_vertex_count = tokenizer.getCommandAsInt();
                break;
            }
            case MESH_N_VERTEX_COUNT:
            {
                mesh_n_vertex_count = tokenizer.getCommandAsInt();
                break;
            }
            case SMOOTH_SURFACE_M_DENSITIES:
            {
                smooth_surface_m_densities = tokenizer.getCommandAsInt();
                break;
            }
            case SMOOTH_SURFACE_N_DENSITIES:
            {
                smooth_surface_m_densities = tokenizer.getCommandAsInt();
                break;
            }
            case SMOOTH_SURFACE_TYPE:
            {
                smooth_surface_type = tokenizer.getCommandAsInt();
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

    if (vertices_follow == 1)
        readVerticesDXF(tokenizer);
}

void Polyline::readVerticesDXF (Tokenizer &tokenizer)
{
    while (true)
    {
        tokenizer.getToken();

        if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SEQEND) == true)
            return;

        if (tokenizer.compareCommand(Tokenizer::DXF_KEY_VERTEX) == true)
        {
            Vertex vertex;
            vertex.readDXF(tokenizer);
            items.insert(items.end(), vertex);
        }
    }
}

void Polyline::draw()
{

}

} // namespace

