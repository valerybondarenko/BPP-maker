/*
 * Tokenizer.h
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

#ifndef RU_TCL_DXF_Tokenizer_H
#define RU_TCL_DXF_Tokenizer_H

#include <string>
#include <vector>
#include <iostream>

#include "tcl_dxf_defs.h"

namespace ru_tcl_dxf
{

using namespace std;

/*
 * Класс Tokenizer представляет входной поток,
 * с дополнительными возможностями обработки. Этот класс нужен
 * для внутреннего использования.
 */
class _TCL_DXF_CLASS Tokenizer
{
public:

    // Глобальные константы
    // ====================

    static const string DXF_KEY_BLOCKS; // "BLOCKS"
    static const string DXF_KEY_ENDSEC; // "ENDSEC"
    static const string DXF_KEY_EOF; // "EOF"
    static const string DXF_KEY_ENTITIES; // "ENTITIES"
    static const string DXF_KEY_HEADER; // "HEADER"
    static const string DXF_KEY_SECTION; // "SECTION"
    static const string DXF_KEY_TABLE; // "TABLE"
    static const string DXF_KEY_TABLES; // "TABLES"
    static const string DXF_KEY_LAYER_TABLE; // "LAYER"
    static const string DXF_KEY_LTYPE_TABLE; // "LTYPE"
    static const string DXF_KEY_STYLE_TABLE; // "STYLE"
    static const string DXF_KEY_VIEW_TABLE; // "VIEW"
    static const string DXF_KEY_VPORT_TABLE; // "VPORT"
    static const string DXF_KEY_UCS_TABLE; // "UCS"
    static const string DXF_KEY_ARC; // "ARC"
    static const string DXF_KEY_ATTDEF; // "ATTDEF"
    static const string DXF_KEY_ATTRIB; // "ATTRIBUTE"
    static const string DXF_KEY_BLOCK; // "BLOCK"
    static const string DXF_KEY_CIRCLE; // "CIRCLE"
    static const string DXF_KEY_DIMENSION; // "DIMENSION"
    static const string DXF_KEY_FACE3D; // "3DFACE"
    static const string DXF_KEY_INSERT; // "INSERT"
    static const string DXF_KEY_LINE; // "LINE"
    static const string DXF_KEY_LINE3D; // "3DLINE"
    static const string DXF_KEY_POINT; // "POINT"
    static const string DXF_KEY_POLYLINE; // "POLYLINE"
    static const string DXF_KEY_SEQEND; // "SEQEND"
    static const string DXF_KEY_SHAPE; // "SHAPE"
    static const string DXF_KEY_SOLID; // "SOLID"
    static const string DXF_KEY_TEXT; // "TEXT"
    static const string DXF_KEY_TRACE; // "TRACE"
    static const string DXF_KEY_LAYER; // "LAYER"
    static const string DXF_KEY_LTYPE; // "LTYPE"
    static const string DXF_KEY_STYLE; // "STYLE"
    static const string DXF_KEY_ENDTAB; // "ENDTAB"
    static const string DXF_KEY_VERTEX; // "VERTEX"
    static const string DXF_KEY_VIEW; // "VIEW"
    static const string DXF_KEY_VPORT; // "VPORT"
    static const string DXF_KEY_UCS; // "UCS"
    static const string DXF_KEY_ENDBLK; // "ENDBLK"
    static const string DXF_KEY_ACADVER; // "$ACADVER"
    static const string DXF_KEY_ANGBASE; // "$ANGBASE"
    static const string DXF_KEY_ANGDIR; // "$ANGDIR"
    static const string DXF_KEY_ATTDIA; // "$ATTDIA"
    static const string DXF_KEY_ATTMODE; // "$ATTMODE"
    static const string DXF_KEY_ATTREQ; // "$ATTREQ"
    static const string DXF_KEY_AUNITS; // "$AUNITS"
    static const string DXF_KEY_AUPREC; // "$AUPREC"
    static const string DXF_KEY_AXISMODE; // "$AXISMODE"
    static const string DXF_KEY_AXISUNIT; // "$AXISUNIT"
    static const string DXF_KEY_BLIPMODE; // "$BLIPMODE"
    static const string DXF_KEY_CECOLOR; // "$CELOCOR"
    static const string DXF_KEY_CELTYPE; // "$CELTYPE"
    static const string DXF_KEY_CHAMFERA; // "$CHAMFERA"
    static const string DXF_KEY_CHAMFERB; // "$CHAMFERB"
    static const string DXF_KEY_CLAYER; // "$CLAYER"
    static const string DXF_KEY_COORDS; // "$COORDS"
    static const string DXF_KEY_DIMALT; // "$DIMALT"
    static const string DXF_KEY_DIMALTD; // "$DIMALTD"
    static const string DXF_KEY_DIMALTF; // "$DIMALTF"
    static const string DXF_KEY_DIMAPOST; // "$DIMAPOST"
    static const string DXF_KEY_DIMASO; // "$DIMASO"
    static const string DXF_KEY_DIMASZ; // "$DIMASZ"
    static const string DXF_KEY_DIMBLK; // "$DIMBLK"
    static const string DXF_KEY_DIMBLK1; // "$DIMBLK1"
    static const string DXF_KEY_DIMBLK2; // "$DIMBLK2"
    static const string DXF_KEY_DIMCEN; // "$DIMCEN"
    static const string DXF_KEY_DIMDLE; // "$DIMDLE"
    static const string DXF_KEY_DIMDLI; // "$DIMDLI"
    static const string DXF_KEY_DIMEXE; // "$DIMEXE"
    static const string DXF_KEY_DIMEXO; // "$DIMEXO"
    static const string DXF_KEY_DIMLFAC; // "$DIMLFAC"
    static const string DXF_KEY_DIMLIM; // "$DIMLIM"
    static const string DXF_KEY_DIMPOST; // "$DIMPOST"
    static const string DXF_KEY_DIMRND; // "$DIMRND"
    static const string DXF_KEY_DIMSAH; // "$DIMSAH"
    static const string DXF_KEY_DIMSCALE; // "$DIMSCALE"
    static const string DXF_KEY_DIMSE1; // "$DIMSE1"
    static const string DXF_KEY_DIMSE2; // "$DIMSE2"
    static const string DXF_KEY_DIMSHO; // "$DIMSHO"
    static const string DXF_KEY_DIMSOXD; // "$DIMSOXD"
    static const string DXF_KEY_DIMTAD; // "$DIMTAD"
    static const string DXF_KEY_DIMTIH; // "$DIMTIH"
    static const string DXF_KEY_DIMTIX; // "$DIMTIX"
    static const string DXF_KEY_DIMTM; // "$DIMTM"
    static const string DXF_KEY_DIMTOFL; // "$DIMTOFL"
    static const string DXF_KEY_DIMTOH; // "$DIMTOH"
    static const string DXF_KEY_DIMTOL; // "$DIMTOL"
    static const string DXF_KEY_DIMTP; // "$DIMTP"
    static const string DXF_KEY_DIMTSZ; // "$DIMTSZ"
    static const string DXF_KEY_DIMTVP; // "$DIMTVP"
    static const string DXF_KEY_DIMTXT; // "$DIMTXT"
    static const string DXF_KEY_DIMZIN; // "$DIMZIN"
    static const string DXF_KEY_DRAGMODE; // "$DRAGMODE"
    static const string DXF_KEY_ELEVATION; // "$ELEVATION"
    static const string DXF_KEY_EXTMAX; // "$EXTMAX"
    static const string DXF_KEY_EXTMIN; // "$EXTMIN"
    static const string DXF_KEY_FILLETRAD; // "$FILLETRAD"
    static const string DXF_KEY_FILLMODE; // "$FILLMODE"
    static const string DXF_KEY_FLATLAND; // "$FLATLAND"
    static const string DXF_KEY_GRIDMODE; // "$GRIDMODE"
    static const string DXF_KEY_GRIDUNIT; // "$GRIDUNIT"
    static const string DXF_KEY_HANDLING; // "$HANDLING"
    static const string DXF_KEY_HANDSEED; // "$HANDSEED"
    static const string DXF_KEY_INSBASE; // "$INSBASE"
    static const string DXF_KEY_LIMCHECK; // "$LIMCHECK"
    static const string DXF_KEY_LIMMAX; // "$LIMMAX"
    static const string DXF_KEY_LIMMIN; // "$LIMMIN"
    static const string DXF_KEY_LTSCALE; // "$LTSCALE"
    static const string DXF_KEY_LUNITS; // "$LUNITS"
    static const string DXF_KEY_LUPREC; // "$LUPREC"
    static const string DXF_KEY_MENU; // "$MENU"
    static const string DXF_KEY_MIRRTEXT; // "$MIRRTEXT"
    static const string DXF_KEY_ORTHOMODE; // "$ORTHOMODE"
    static const string DXF_KEY_OSMODE; // "$OSMODE"
    static const string DXF_KEY_PDMODE; // "$PDMODE"
    static const string DXF_KEY_PDSIZE; // "$PDSIZE"
    static const string DXF_KEY_PLINEWID; // "$PLINEWID"
    static const string DXF_KEY_QTEXTMODE; // "$QTEXTMODE"
    static const string DXF_KEY_REGENMODE; // "$REGENMODE"
    static const string DXF_KEY_SKETCHINC; // "$SKETCHINC"
    static const string DXF_KEY_SKPOLY; // "$SKPOLY"
    static const string DXF_KEY_SNAPANG; // "$SNAPANG"
    static const string DXF_KEY_SNAPBASE; // "$SNAPBASE"
    static const string DXF_KEY_SNAPISOPAIR; // "$SNAPISOPAIR"
    static const string DXF_KEY_SNAPMODE; // "$SNAPMODE"
    static const string DXF_KEY_SNAPSTYLE; // "$SNAPSTYLE"
    static const string DXF_KEY_SNAPUNIT; // "$SNAPUNIT"
    static const string DXF_KEY_SPLFRAME; // "$SPLFRAME"
    static const string DXF_KEY_SPLINESEGS; // "$SPLINESEGS"
    static const string DXF_KEY_SPLINETYPE; // "$SPLINETYPE"
    static const string DXF_KEY_SURFTAB1; // "$SURFTAB1"
    static const string DXF_KEY_SURFTAB2; // "$SURFTAB2"
    static const string DXF_KEY_SURFTYPE; // "$SURFTYPE"
    static const string DXF_KEY_SURFU; // "$SURFU"
    static const string DXF_KEY_SURFV; // "$SURFV"
    static const string DXF_KEY_TDCREATE; // "$TDCREATE"
    static const string DXF_KEY_TDINDWG; // "$TDINDWG"
    static const string DXF_KEY_TDUPDATE; // "$TDUPDATE"
    static const string DXF_KEY_TDUSRTIMER; // "$TDUSRTIMER"
    static const string DXF_KEY_TEXTSIZE; // "$TEXTSIZE"
    static const string DXF_KEY_TEXTSTYLE; // "$TEXTSTYLE"
    static const string DXF_KEY_THICKNESS; // "$THICKNESS"
    static const string DXF_KEY_TRACEWID; // "$TRACEWID"
    static const string DXF_KEY_UCSNAME; // "$UCSNAME"
    static const string DXF_KEY_UCSORG; // "$UCSORG"
    static const string DXF_KEY_UCSXDIR; // "$UCSXDIR"
    static const string DXF_KEY_UCSYDIR; // "$UCSYDIR"
    static const string DXF_KEY_USERI1; // "$USERI1"
    static const string DXF_KEY_USERI2; // "$USERI2"
    static const string DXF_KEY_USERI3; // "$USERI3"
    static const string DXF_KEY_USERI4; // "$USERI4"
    static const string DXF_KEY_USERI5; // "$USERI5"
    static const string DXF_KEY_USERR1; // "$USERR1"
    static const string DXF_KEY_USERR2; // "$USERR2"
    static const string DXF_KEY_USERR3; // "$USERR3"
    static const string DXF_KEY_USERR4; // "$USERR4"
    static const string DXF_KEY_USERR5; // "$USERR5"
    static const string DXF_KEY_USRTIMER; // "$USRTIMER"
    static const string DXF_KEY_VIEWCTR; // "$VIEWCTR"
    static const string DXF_KEY_VIEWDIR; // "$VIEWDIR"
    static const string DXF_KEY_VIEWSIZE; // "$VIEWSIZE"
    static const string DXF_KEY_WORLDVIEW; // "$WORLDVIEW"

public:

    // Конструкторы
    // ============

    Tokenizer ();
    Tokenizer (istream *out);
    virtual ~Tokenizer ();

public:

    /*
     * Уведомление о неопознанной команде.
     */
    void badInstruction ();

    /*
     * Возвращает код команды.
     */
    int getCode () const;

    /*
     * Возвращает значение команды как string.
     */
    const string & getCommand () const;

    /*
     * Возвращает значение команды как double.
     */
    double getCommandAsDouble () const;

    /*
     * Возвращает значение команды как int.
     */
    int getCommandAsInt () const;

    /*
     * Сравнивает значение команды с заданным ключем.
     */
    bool compareCommand (const string &key) const;

    /*
     * Возвращает список ошибок.
     */
    const vector<string> & getErrors ();

    /*
     * Считывает следующую лексему.
     */
    void getToken ();

    /*
     * Возврат к предыдущей лексеме.
     */
    void gotoBack ();

private:

    // Недоступные конструкторы
    // ========================

    Tokenizer (const Tokenizer &obj);
    const Tokenizer & operator = (const Tokenizer &obj);

private:

    // Атрибуты
    // ========

    bool           isBack;
    int            line;
    int            code;
    string         command;
    istream        *stream;
    vector<string> errors;
};


inline int Tokenizer::getCode () const
{
    return code;
}

inline const string & Tokenizer::getCommand () const
{
    return command;
}

inline double Tokenizer::getCommandAsDouble () const
{
    return atof(command.c_str());
}

inline int Tokenizer::getCommandAsInt () const
{
    return atoi(command.c_str());
}

inline bool Tokenizer::compareCommand (const string &key) const
{
    return command == key;
}

inline const vector<string> & Tokenizer::getErrors ()
{
    return errors;
}

} // namespace

#endif // RU_TCL_DXF_Tokenizer_H
