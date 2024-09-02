/*
 * Dimension.h
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

#ifndef RU_TCL_DXF_Dimension_H
#define RU_TCL_DXF_Dimension_H

#include <string>

#include "Entity.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

/*
 * ����� Dimension ������������ ��������� �������
 * �������.
 */
class _TCL_DXF_CLASS Dimension : public Entity
{
public:

    /**
     * ��������� ���� �������.
     */
    enum SizeType
    {
        /**
         * ����������, �������������� ��� ������������.
         */
        LINEAR = 0,
        /**
         * �����������.
         */
        ALIGNED = 1,
        /*
         * �������.
         */
        ANGULAR = 2,
        /*
         * �������.
         */
        DIAMETER = 3,
        /*
         * ������.
         */
        RADIUS = 4,
        /*
         * �������� �������������.
         */
        USER_DEFINED = 128
    };

public:

    // ������������
    // ============

    Dimension ();
    virtual ~Dimension ();
    Dimension (const Dimension &obj);
    const Dimension & operator = (const Dimension &obj);

public:

    /*
     * ���������� ���� ���������� ��������������� ���
     * ������������� �������.
     */
    double getAngle () const;

    /*
     * ���������� ��� �����.
     */
    const string & getBlockName () const;

    /*
     * ���������� ���������� �����, ������������ ��� �������
     * ��������� ����� (�������� �������).
     */
    const Point3d & getDefinition () const;

    /*
     * ���������� ���������� ���������� ������.
     */
    double getDirection () const;

    /*
     * ���������� ���������� �����, ������������ ��� �������
     * ��������� ����� ��� ����������� �������� �� ������� �����.
     */
    const Point3d & getInsertion () const;

    /*
     * ���������� ����� �������� ����� ��� �������� �������� ���������
     * � ��������.
     */
    double getLeaderLength () const;

    /*
     * ���������� ���������� ������ ���������� ������.
     */
    const Point3d & getMiddle () const;

    /*
     * ���������� ���������� ����������� ����� 1.
     * ������ ����� ����������� ��� ��������� ������� ���
     * �������� ����� ������ ����� ��� �������� �������.
     */
    const Point3d & getSpecial1 () const;

    /*
     * ���������� ���������� ����������� ����� 2.
     * ������ ����� ����������� ��� ��������� ������� ���
     * ��������� ����� ������ ����� ��� �������� �������.
     */
    const Point3d & getSpecial2 () const;

    /*
     * ���������� ���������� �����, ������������ ��� ��������������
     * �����, ��� ���� � �������.
     * ������ ����� ��������� ����� ��� ������� � �������� ���
     * �������� ����� ������ ����� ��� �������� �������.
     */
    const Point3d & getSpecial3 () const;

    /*
     * ���������� ���������� �����, ������������ ��������� ����
     * ��� ����������� �������� �������.
     */
    const Point3d & getSpecial4 () const;

    /*
     * ���������� ����� �������� �������� ��� ���������� ���������.
     */
    const string & getText () const;

    /*
     * ���������� ��� �������.
     */
    int getType () const;

    /*
     * ���������� ������� �� dxf �����.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    // ��������
    // ========

    string   block_name;
    Point3d  definition;
    Point3d  middle;
    Point3d  insertion;
    int      type;
    string   text;
    Point3d  special_1;
    Point3d  special_2;
    Point3d  special_3;
    Point3d  special_4;
    double   leader_length;
    double   angle;
    double   direction;

    // ���������
    // =========

    enum DxfIdentifires
    {
        BLOCK_NAME    = 2,
        DEFINITION_X  = 10,
        DEFINITION_Y  = 20,
        DEFINITION_Z  = 30,
        MIDDLE_X      = 11,
        MIDDLE_Y      = 21,
        MIDDLE_Z      = 31,
        INSERTION_X   = 12,
        INSERTION_Y   = 22,
        INSERTION_Z   = 32,
        TYPE          = 70,
        TEXT          = 1,
        SPECIAL_1_X   = 13,
        SPECIAL_1_Y   = 23,
        SPECIAL_1_Z   = 33,
        SPECIAL_2_X   = 14,
        SPECIAL_2_Y   = 24,
        SPECIAL_2_Z   = 34,
        SPECIAL_3_X   = 15,
        SPECIAL_3_Y   = 25,
        SPECIAL_3_Z   = 35,
        SPECIAL_4_X   = 16,
        SPECIAL_4_Y   = 26,
        SPECIAL_4_Z   = 36,
        LEADER_LENGTH = 40,
        ANGLE         = 50,
        DIRECTION     = 51
    };
};

inline double Dimension::getAngle () const
{
    return angle;
}

inline const string & Dimension::getBlockName () const
{
    return block_name;
}

inline const Point3d & Dimension::getDefinition () const
{
    return definition;
}

inline double Dimension::getDirection () const
{
    return direction;
}

inline const Point3d & Dimension::getInsertion () const
{
    return insertion;
}

inline double Dimension::getLeaderLength () const
{
    return leader_length;
}

inline const Point3d & Dimension::getMiddle () const
{
    return middle;
}

inline const Point3d & Dimension::getSpecial1 () const
{
    return special_1;
}

inline const Point3d & Dimension::getSpecial2 () const
{
    return special_2;
}

inline const Point3d & Dimension::getSpecial3 () const
{
    return special_3;
}

inline const Point3d & Dimension::getSpecial4 () const
{
    return special_4;
}

inline const string & Dimension::getText () const
{
    return text;
}

inline int Dimension::getType () const
{
    return type;
}

} // namespace

#endif // RU_TCL_DXF_Dimension_H
