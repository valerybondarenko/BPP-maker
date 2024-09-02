/*
 * Style.h
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

#ifndef RU_TCL_DXF_Style_H
#define RU_TCL_DXF_Style_H

#include <string>

#include "Entry.h"

namespace ru_tcl_dxf
{

/*
 * ����� Style ������������ ������� ������� ������.
 */
class _TCL_DXF_CLASS Style : public Entry
{
public:

    // ������������
    // ============

    Style ();
    virtual ~Style ();
    Style (const Style &obj);
    const Style & operator = (const Style &obj);

public:

    /*
     * ���������� ��� ����� Bigfont.
     */
    const string & getBigfontFileName () const;

    /*
     * ���������� ������������� ������ ������ (0 = �� ������).
     */
    double getFixedHeight () const;

    /*
     * ���������� ������, �������� � ��������� ���.
     */
    double getLastHeightUsed () const;

    /*
     * ���������� ���� �������.
     */
    double getObliquingAngle () const;

    /*
     * ���������� ��� ������ ��������.
     */
    const string & getPrimaryFileName () const;

    /*
     * ���������� ������� ������.
     */
    double getWidthFactor () const;

    /*
     * ���������� true, ���� ����� ��������� ��������� �� ��� �.
     */
    bool isBackwards () const;

    /*
     * ���������� true, ���� ��� ������� ��������.
     */
    bool isShapeTable () const;

    /*
     * ���������� true, ���� ����� ���������� ������������ ��� �.
     */
    bool isUpsideDown () const;

    /*
     * ���������� true, ���� ����� ����������� ������������.
     */
    bool isVerticallyText () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    double fixed_height;
    double width_factor;
    double obliquing_angle;
    int    generation_flags;
    double last_height_used;
    string primary_file_name;
    string bigfont_file_name;

    // ���������
    // =========

    enum DxfIdentifires
    {
        FIXED_HEIGHT      = 40,
        WIDTH_FACTOR      = 41,
        OBLIQUING_ANGLE   = 50,
        GENERATION_FLAGS  = 71,
        LAST_HEIGHT_USED  = 42,
        PRIMARY_FILE_NAME = 3,
        BIGFONT_FILE_NAME = 4
    };
};


inline const string & Style::getBigfontFileName () const
{
    return bigfont_file_name;
}

inline double Style::getFixedHeight () const
{
    return fixed_height;
}

inline double Style::getLastHeightUsed () const
{
    return last_height_used;
}

inline double Style::getObliquingAngle () const
{
    return obliquing_angle;
}

inline const string & Style::getPrimaryFileName () const
{
    return primary_file_name;
}

inline double Style::getWidthFactor () const
{
    return width_factor;
}

inline bool Style::isBackwards () const
{
    return (generation_flags & 2) == 2;
}

inline bool Style::isShapeTable () const
{
    return (getFlags() & 1) == 1;
}

inline bool Style::isUpsideDown () const
{
    return (generation_flags & 4) == 4;
}

inline bool Style::isVerticallyText () const
{
    return (getFlags() & 4) == 4;
}

} // namespace

#endif // RU_TCL_DXF_Style_H
