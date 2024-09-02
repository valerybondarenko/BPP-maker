/*
 * Tokenizer.cpp
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

#include "Tokenizer.h"
#include <stdio.h>

namespace ru_tcl_dxf
{

using namespace std;

const string Tokenizer::DXF_KEY_BLOCKS      = "BLOCKS";
const string Tokenizer::DXF_KEY_ENDSEC      = "ENDSEC";
const string Tokenizer::DXF_KEY_EOF         = "EOF";
const string Tokenizer::DXF_KEY_ENTITIES    = "ENTITIES";
const string Tokenizer::DXF_KEY_HEADER      = "HEADER";
const string Tokenizer::DXF_KEY_SECTION     = "SECTION";
const string Tokenizer::DXF_KEY_TABLE       = "TABLE";
const string Tokenizer::DXF_KEY_TABLES      = "TABLES";
const string Tokenizer::DXF_KEY_LAYER_TABLE = "LAYER";
const string Tokenizer::DXF_KEY_LTYPE_TABLE = "LTYPE";
const string Tokenizer::DXF_KEY_STYLE_TABLE = "STYLE";
const string Tokenizer::DXF_KEY_VIEW_TABLE  = "VIEW";
const string Tokenizer::DXF_KEY_VPORT_TABLE = "VPORT";
const string Tokenizer::DXF_KEY_UCS_TABLE   = "UCS";
const string Tokenizer::DXF_KEY_ARC         = "ARC";
const string Tokenizer::DXF_KEY_ATTDEF      = "ATTDEF";
const string Tokenizer::DXF_KEY_ATTRIB      = "ATTRIBUTE";
const string Tokenizer::DXF_KEY_BLOCK       = "BLOCK";
const string Tokenizer::DXF_KEY_CIRCLE      = "CIRCLE";
const string Tokenizer::DXF_KEY_DIMENSION   = "DIMENSION";
const string Tokenizer::DXF_KEY_FACE3D      = "3DFACE";
const string Tokenizer::DXF_KEY_INSERT      = "INSERT";
const string Tokenizer::DXF_KEY_LINE        = "LINE";
const string Tokenizer::DXF_KEY_LINE3D      = "3DLINE";
const string Tokenizer::DXF_KEY_POINT       = "POINT";
const string Tokenizer::DXF_KEY_POLYLINE    = "POLYLINE";
const string Tokenizer::DXF_KEY_SEQEND      = "SEQEND";
const string Tokenizer::DXF_KEY_SHAPE       = "SHAPE";
const string Tokenizer::DXF_KEY_SOLID       = "SOLID";
const string Tokenizer::DXF_KEY_TEXT        = "TEXT";
const string Tokenizer::DXF_KEY_TRACE       = "TRACE";
const string Tokenizer::DXF_KEY_LAYER       = "LAYER";
const string Tokenizer::DXF_KEY_LTYPE       = "LTYPE";
const string Tokenizer::DXF_KEY_STYLE       = "STYLE";
const string Tokenizer::DXF_KEY_ENDTAB      = "ENDTAB";
const string Tokenizer::DXF_KEY_VERTEX      = "VERTEX";
const string Tokenizer::DXF_KEY_VIEW        = "VIEW";
const string Tokenizer::DXF_KEY_VPORT       = "VPORT";
const string Tokenizer::DXF_KEY_UCS         = "UCS";
const string Tokenizer::DXF_KEY_ENDBLK      = "ENDBLK";
const string Tokenizer::DXF_KEY_ACADVER     = "$ACADVER";
const string Tokenizer::DXF_KEY_ANGBASE     = "$ANGBASE";
const string Tokenizer::DXF_KEY_ANGDIR      = "$ANGDIR";
const string Tokenizer::DXF_KEY_ATTDIA      = "$ATTDIA";
const string Tokenizer::DXF_KEY_ATTMODE     = "$ATTMODE";
const string Tokenizer::DXF_KEY_ATTREQ      = "$ATTREQ";
const string Tokenizer::DXF_KEY_AUNITS      = "$AUNITS";
const string Tokenizer::DXF_KEY_AUPREC      = "$AUPREC";
const string Tokenizer::DXF_KEY_AXISMODE    = "$AXISMODE";
const string Tokenizer::DXF_KEY_AXISUNIT    = "$AXISUNIT";
const string Tokenizer::DXF_KEY_BLIPMODE    = "$BLIPMODE";
const string Tokenizer::DXF_KEY_CECOLOR     = "$CELOCOR";
const string Tokenizer::DXF_KEY_CELTYPE     = "$CELTYPE";
const string Tokenizer::DXF_KEY_CHAMFERA    = "$CHAMFERA";
const string Tokenizer::DXF_KEY_CHAMFERB    = "$CHAMFERB";
const string Tokenizer::DXF_KEY_CLAYER      = "$CLAYER";
const string Tokenizer::DXF_KEY_COORDS      = "$COORDS";
const string Tokenizer::DXF_KEY_DIMALT      = "$DIMALT";
const string Tokenizer::DXF_KEY_DIMALTD     = "$DIMALTD";
const string Tokenizer::DXF_KEY_DIMALTF     = "$DIMALTF";
const string Tokenizer::DXF_KEY_DIMAPOST    = "$DIMAPOST";
const string Tokenizer::DXF_KEY_DIMASO      = "$DIMASO";
const string Tokenizer::DXF_KEY_DIMASZ      = "$DIMASZ";
const string Tokenizer::DXF_KEY_DIMBLK      = "$DIMBLK";
const string Tokenizer::DXF_KEY_DIMBLK1     = "$DIMBLK1";
const string Tokenizer::DXF_KEY_DIMBLK2     = "$DIMBLK2";
const string Tokenizer::DXF_KEY_DIMCEN      = "$DIMCEN";
const string Tokenizer::DXF_KEY_DIMDLE      = "$DIMDLE";
const string Tokenizer::DXF_KEY_DIMDLI      = "$DIMDLI";
const string Tokenizer::DXF_KEY_DIMEXE      = "$DIMEXE";
const string Tokenizer::DXF_KEY_DIMEXO      = "$DIMEXO";
const string Tokenizer::DXF_KEY_DIMLFAC     = "$DIMLFAC";
const string Tokenizer::DXF_KEY_DIMLIM      = "$DIMLIM";
const string Tokenizer::DXF_KEY_DIMPOST     = "$DIMPOST";
const string Tokenizer::DXF_KEY_DIMRND      = "$DIMRND";
const string Tokenizer::DXF_KEY_DIMSAH      = "$DIMSAH";
const string Tokenizer::DXF_KEY_DIMSCALE    = "$DIMSCALE";
const string Tokenizer::DXF_KEY_DIMSE1      = "$DIMSE1";
const string Tokenizer::DXF_KEY_DIMSE2      = "$DIMSE2";
const string Tokenizer::DXF_KEY_DIMSHO      = "$DIMSHO";
const string Tokenizer::DXF_KEY_DIMSOXD     = "$DIMSOXD";
const string Tokenizer::DXF_KEY_DIMTAD      = "$DIMTAD";
const string Tokenizer::DXF_KEY_DIMTIH      = "$DIMTIH";
const string Tokenizer::DXF_KEY_DIMTIX      = "$DIMTIX";
const string Tokenizer::DXF_KEY_DIMTM       = "$DIMTM";
const string Tokenizer::DXF_KEY_DIMTOFL     = "$DIMTOFL";
const string Tokenizer::DXF_KEY_DIMTOH      = "$DIMTOH";
const string Tokenizer::DXF_KEY_DIMTOL      = "$DIMTOL";
const string Tokenizer::DXF_KEY_DIMTP       = "$DIMTP";
const string Tokenizer::DXF_KEY_DIMTSZ      = "$DIMTSZ";
const string Tokenizer::DXF_KEY_DIMTVP      = "$DIMTVP";
const string Tokenizer::DXF_KEY_DIMTXT      = "$DIMTXT";
const string Tokenizer::DXF_KEY_DIMZIN      = "$DIMZIN";
const string Tokenizer::DXF_KEY_DRAGMODE    = "$DRAGMODE";
const string Tokenizer::DXF_KEY_ELEVATION   = "$ELEVATION";
const string Tokenizer::DXF_KEY_EXTMAX      = "$EXTMAX";
const string Tokenizer::DXF_KEY_EXTMIN      = "$EXTMIN";
const string Tokenizer::DXF_KEY_FILLETRAD   = "$FILLETRAD";
const string Tokenizer::DXF_KEY_FILLMODE    = "$FILLMODE";
const string Tokenizer::DXF_KEY_FLATLAND    = "$FLATLAND";
const string Tokenizer::DXF_KEY_GRIDMODE    = "$GRIDMODE";
const string Tokenizer::DXF_KEY_GRIDUNIT    = "$GRIDUNIT";
const string Tokenizer::DXF_KEY_HANDLING    = "$HANDLING";
const string Tokenizer::DXF_KEY_HANDSEED    = "$HANDSEED";
const string Tokenizer::DXF_KEY_INSBASE     = "$INSBASE";
const string Tokenizer::DXF_KEY_LIMCHECK    = "$LIMCHECK";
const string Tokenizer::DXF_KEY_LIMMAX      = "$LIMMAX";
const string Tokenizer::DXF_KEY_LIMMIN      = "$LIMMIN";
const string Tokenizer::DXF_KEY_LTSCALE     = "$LTSCALE";
const string Tokenizer::DXF_KEY_LUNITS      = "$LUNITS";
const string Tokenizer::DXF_KEY_LUPREC      = "$LUPREC";
const string Tokenizer::DXF_KEY_MENU        = "$MENU";
const string Tokenizer::DXF_KEY_MIRRTEXT    = "$MIRRTEXT";
const string Tokenizer::DXF_KEY_ORTHOMODE   = "$ORTHOMODE";
const string Tokenizer::DXF_KEY_OSMODE      = "$OSMODE";
const string Tokenizer::DXF_KEY_PDMODE      = "$PDMODE";
const string Tokenizer::DXF_KEY_PDSIZE      = "$PDSIZE";
const string Tokenizer::DXF_KEY_PLINEWID    = "$PLINEWID";
const string Tokenizer::DXF_KEY_QTEXTMODE   = "$QTEXTMODE";
const string Tokenizer::DXF_KEY_REGENMODE   = "$REGENMODE";
const string Tokenizer::DXF_KEY_SKETCHINC   = "$SKETCHINC";
const string Tokenizer::DXF_KEY_SKPOLY      = "$SKPOLY";
const string Tokenizer::DXF_KEY_SNAPANG     = "$SNAPANG";
const string Tokenizer::DXF_KEY_SNAPBASE    = "$SNAPBASE";
const string Tokenizer::DXF_KEY_SNAPISOPAIR = "$SNAPISOPAIR";
const string Tokenizer::DXF_KEY_SNAPMODE    = "$SNAPMODE";
const string Tokenizer::DXF_KEY_SNAPSTYLE   = "$SNAPSTYLE";
const string Tokenizer::DXF_KEY_SNAPUNIT    = "$SNAPUNIT";
const string Tokenizer::DXF_KEY_SPLFRAME    = "$SPLFRAME";
const string Tokenizer::DXF_KEY_SPLINESEGS  = "$SPLINESEGS";
const string Tokenizer::DXF_KEY_SPLINETYPE  = "$SPLINETYPE";
const string Tokenizer::DXF_KEY_SURFTAB1    = "$SURFTAB1";
const string Tokenizer::DXF_KEY_SURFTAB2    = "$SURFTAB2";
const string Tokenizer::DXF_KEY_SURFTYPE    = "$SURFTYPE";
const string Tokenizer::DXF_KEY_SURFU       = "$SURFU";
const string Tokenizer::DXF_KEY_SURFV       = "$SURFV";
const string Tokenizer::DXF_KEY_TDCREATE    = "$TDCREATE";
const string Tokenizer::DXF_KEY_TDINDWG     = "$TDINDWG";
const string Tokenizer::DXF_KEY_TDUPDATE    = "$TDUPDATE";
const string Tokenizer::DXF_KEY_TDUSRTIMER  = "$TDUSRTIMER";
const string Tokenizer::DXF_KEY_TEXTSIZE    = "$TEXTSIZE";
const string Tokenizer::DXF_KEY_TEXTSTYLE   = "$TEXTSTYLE";
const string Tokenizer::DXF_KEY_THICKNESS   = "$THICKNESS";
const string Tokenizer::DXF_KEY_TRACEWID    = "$TRACEWID";
const string Tokenizer::DXF_KEY_UCSNAME     = "$UCSNAME";
const string Tokenizer::DXF_KEY_UCSORG      = "$UCSORG";
const string Tokenizer::DXF_KEY_UCSXDIR     = "$UCSXDIR";
const string Tokenizer::DXF_KEY_UCSYDIR     = "$UCSYDIR";
const string Tokenizer::DXF_KEY_USERI1      = "$USERI1";
const string Tokenizer::DXF_KEY_USERI2      = "$USERI2";
const string Tokenizer::DXF_KEY_USERI3      = "$USERI3";
const string Tokenizer::DXF_KEY_USERI4      = "$USERI4";
const string Tokenizer::DXF_KEY_USERI5      = "$USERI5";
const string Tokenizer::DXF_KEY_USERR1      = "$USERR1";
const string Tokenizer::DXF_KEY_USERR2      = "$USERR2";
const string Tokenizer::DXF_KEY_USERR3      = "$USERR3";
const string Tokenizer::DXF_KEY_USERR4      = "$USERR4";
const string Tokenizer::DXF_KEY_USERR5      = "$USERR5";
const string Tokenizer::DXF_KEY_USRTIMER    = "$USRTIMER";
const string Tokenizer::DXF_KEY_VIEWCTR     = "$VIEWCTR";
const string Tokenizer::DXF_KEY_VIEWDIR     = "$VIEWDIR";
const string Tokenizer::DXF_KEY_VIEWSIZE    = "$VIEWSIZE";
const string Tokenizer::DXF_KEY_WORLDVIEW   = "$WORLDVIEW";


Tokenizer::Tokenizer ()
:
    isBack(false),
    line(0),
    code(-1),
    command(""),
    stream(0),
    errors()
{
}

Tokenizer::Tokenizer (istream *out)
:
    isBack(false),
    line(0),
    code(-1),
    command(""),
    stream(out),
    errors()
{
}

Tokenizer::~Tokenizer ()
{
}

void Tokenizer::badInstruction ()
{
    char str[1024];

    sprintf(str, "Unknow instruction at line %i: code [%i], command [%s]",
            line, code, command.c_str());

    errors.insert(errors.end(), str);
}

void Tokenizer::getToken ()
{
    if (isBack == true)
        isBack = false;
    else
    {
        string str;

        (*stream) >> code;
        stream->ignore();
        getline(*stream, command, '\n');

        line += 2;
    }
}

void Tokenizer::gotoBack ()
{
    isBack = true;
}

} // namespace

