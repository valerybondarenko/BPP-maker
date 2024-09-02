/*
 * Translator.h
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

#ifndef RU_TCL_DXF_Translator_H
#define RU_TCL_DXF_Translator_H

#include <vector>
#include <string>
#include <stdexcept>

#include "Tokenizer.h"
#include "Header.h"
#include "Tables.h"
#include "Blocks.h"
#include "Entities.h"

namespace ru_tcl_dxf
{

using namespace std;


class _TCL_DXF_CLASS FileNotFoundError : public runtime_error
{
public:

	FileNotFoundError ()
	:
        runtime_error("File not found!")
    {
    }
};


/*
 * ����� Translator ������������ ���������� dxf ������.
 */
class _TCL_DXF_CLASS Translator
{
private:

    // ��������
    // ========

    Header         *header;
    Tables         *tables;
    Blocks         *blocks;
    Entities       *entities;
    vector<string> errors;

public:

    // ������������
    // ============

    Translator ();
    virtual ~Translator ();
    Translator (const Translator &obj);
    const Translator & operator = (const Translator &obj);

public:

    /*
     * ���������� ������ ������.
     */
    const Blocks & getBlocksSection () const;

    /*
     * ���������� ������ ����������.
     */
    const Entities & getEntitiesSection () const;

    /*
     * ���������� ������ ������.
     */
    const vector<string> & getErrors () const;

    /*
     * ���������� ������ ���������.
     */
    const Header & getHeaderSection () const;

    /*
     * ���������� ������ ������.
     */
    const Tables & getTablesSection () const;

    /*
     * ���������� dxf �����.
     */
    void readDXF (const string &fileName);

private:

    void readSection (Tokenizer &tokenizer);
};


inline const Blocks & Translator::getBlocksSection () const
{
    return *blocks;
}

inline const Entities & Translator::getEntitiesSection () const
{
    return *entities;
}

inline const vector<string> & Translator::getErrors () const
{
    return errors;
}

inline const Header & Translator::getHeaderSection () const
{
    return *header;
}

inline const Tables & Translator::getTablesSection () const
{
    return *tables;
}

} // namespace

#endif // RU_TCL_DXF_Translator_H
