/*
 * Entities.h
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

#ifndef RU_TCL_DXF_Entities_H
#define RU_TCL_DXF_Entities_H

#include <vector>
#include <QGraphicsItem>
#include "Section.h"
#include "Entity.h"

namespace ru_tcl_dxf
{

/*
 * Класс Entities представляет секцию примитивов в файле.
 */
class _TCL_DXF_CLASS Entities : public Section
{
public:

    // Конструкторы
    // ============

    Entities ();
    virtual ~Entities ();
    Entities (const Entities &obj);
    const Entities & operator = (const Entities &obj);

public:

    /*
     * Возвращает список примитивов.
     */
    const vector<Entity *> & getItems () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);


    void setParentGraphicsItem(QGraphicsItem *value);

private:

    // Атрибуты
    // ========

    vector<Entity *> items;
    QGraphicsItem *parentGraphicsItem;
};


inline const vector<Entity *> & Entities::getItems () const
{
    return items;
}

} // namespace

#endif // RU_TCL_DXF_Entities_H
