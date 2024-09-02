/*
 * Block.h
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

#ifndef RU_TCL_DXF_Block_H
#define RU_TCL_DXF_Block_H

#include <string>
#include <vector>

#include "DxfObject.h"
#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

using namespace std;

/*
 * Класс Block представляет блок примитивов.
 */
class _TCL_DXF_CLASS Block : public DxfObject
{
public:

    // Конструкторы
    // ============

    Block ();
    virtual ~Block ();
    Block (const Block &obj);
    const Block & operator = (const Block &obj);

public:

    /*
	 * Возвращает базовую точку.
     */
    const Point3d & getBase () const;

    /*
	 * Возвращает список примитивов.
     */
    const vector<Entity *> & getItems () const;

    /*
	 * Возвращает имя блока.
     */
    const string & getName () const;

    /*
	 * Возвращает true, если блок без имени.
     */
    bool isAnonymous () const;

    /*
	 * Возвращает true, если следует описание атрибутов.
     */
    bool isHaveAttributes () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========

    Point3d          base;
    string           name;
    int              flags;
    vector<Entity *> items;

    // Константы
    // =========

    enum DxfIdentifires
    {
        BASE_X = 10,
        BASE_Y = 20,
        BASE_Z = 30,
        NAME   = 2,
        FLAGS  = 70
    };
};


inline const Point3d & Block::getBase () const
{
    return base;
}

inline const vector<Entity *> & Block::getItems () const
{
    return items;
}

inline const string & Block::getName () const
{
    return name;
}

inline bool Block::isAnonymous () const
{
    return (flags & 1) == 1;
}

inline bool Block::isHaveAttributes () const
{
    return (flags & 2) == 2;
}

} // namespace

#endif // RU_TCL_DXF_Block_H
