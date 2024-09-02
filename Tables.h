/*
 * Tables.h
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

#ifndef RU_TCL_DXF_Tables_H
#define RU_TCL_DXF_Tables_H

#include <string>

#include "Section.h"
#include "LayerTable.h"
#include "LineTypeTable.h"
#include "StyleTable.h"
#include "UcsTable.h"
#include "ViewTable.h"
#include "VportTable.h"

namespace ru_tcl_dxf
{

/*
 * Класс Tables представляет секцию таблиц в файле.
 */
class _TCL_DXF_CLASS Tables : public Section
{
public:

    // Конструкторы
    // ============

    Tables ();
    virtual ~Tables ();
    Tables (const Tables &obj);
    const Tables & operator = (const Tables &obj);

public:

    /*
     * Возвращает таблицу слоев.
     */
    const LayerTable & getLayerTable () const;

    /*
     * Возвращает таблицу типов линий.
     */
    const LineTypeTable & getLineTypeTable () const;

    /*
     * Возвращает таблицу стилей.
     */
    const StyleTable & getStyleTable () const;

    /*
     * Возвращает таблицу пользовательской системы координат.
     */
    const UcsTable & getUcsTable () const;

    /*
     * Возвращает таблицу видов.
     */
    const ViewTable & getViewTable () const;

    /*
     * Возвращает таблицу видовых экранов.
     */
    const VportTable & getVportTable () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========

    LineTypeTable line_type_table;
    LayerTable    layer_table;
    StyleTable    style_table;
    ViewTable     view_table;
    VportTable    vport_table;
    UcsTable      ucs_table;
};


inline const LayerTable & Tables::getLayerTable () const
{
    return layer_table;
}

inline const LineTypeTable & Tables::getLineTypeTable () const
{
    return line_type_table;
}

inline const StyleTable & Tables::getStyleTable () const
{
    return style_table;
}

inline const UcsTable & Tables::getUcsTable () const
{
    return ucs_table;
}

inline const ViewTable & Tables::getViewTable () const
{
    return view_table;
}

inline const VportTable & Tables::getVportTable () const
{
    return vport_table;
}

} // namespace

#endif // RU_TCL_DXF_Tables_H
