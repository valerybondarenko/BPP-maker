/*
 * DxfObject.h
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

#ifndef RU_TCL_DXF_DxfObject_H
#define RU_TCL_DXF_DxfObject_H

#include "Tokenizer.h"

namespace ru_tcl_dxf
{

/*
 * Класс DxfObject является базовым для всех
 * классов в данном пакете.
 */
class _TCL_DXF_CLASS DxfObject
{
public:

    // Конструкторы
    // ============

    virtual ~DxfObject ();

public:

    /*
     * Считывание объекта из dxf файла.
     */
    virtual void readDXF (Tokenizer &tokenizer) = 0;
};

} // namespace

#endif // RU_TCL_DXF_DxfObject_H
