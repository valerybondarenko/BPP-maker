/*
 * LineType.h
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

#ifndef RU_TCL_DXF_LineType_H
#define RU_TCL_DXF_LineType_H

#include <string>
#include <vector>

#include "Entry.h"

namespace ru_tcl_dxf
{

/*
 * ����� LineType ������������ ������� �������
 * ����� �����.
 */
class _TCL_DXF_CLASS LineType : public Entry
{
public:

    // ������������
    // ============

    LineType ();
    virtual ~LineType ();
    LineType (const LineType &obj);
    const LineType & operator = (const LineType &obj);

public:

    /*
     * ���������� ��������� ������������� �����.
     */
    const string & getASCIIType () const;

    /*
     * ���������� ����� ������� �����.
     */
    double getPatternLength () const;

    /*
     * ���������� ������ ������� �����. �������� �������
     * ���������������� ��������� �������:
     *
     * ������������� �������� = �������,
     * 0                      = �����,
     * ������������� �������� = �����.
     */
    const vector<double> & getItems () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    string         ascii_type;
    int            alignment;
    double         pattern_length;
    vector<double> items;

    // ���������
    // =========

    enum DxfIdentifires
    {
        ASCII_TYPE     = 3,
        ALIGNMENT      = 72,
        DASH_COUNTS    = 73,
        PATTERN_LENGTH = 40,
        DASH_LENGTH    = 49
    };
};


inline const string & LineType::getASCIIType () const
{
    return ascii_type;
}

inline double LineType::getPatternLength () const
{
    return pattern_length;
}

inline const vector<double> & LineType::getItems () const
{
    return items;
}

} // namespace

#endif // RU_TCL_DXF_LineType_H
