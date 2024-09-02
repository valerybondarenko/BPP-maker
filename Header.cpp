/*
 * Header.cpp
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

#include "Header.h"

namespace ru_tcl_dxf
{

using namespace std;

void Header::readDXF (Tokenizer &tokenizer)
    {
        while (true)
        {
            tokenizer.getToken();

            if (tokenizer.getCode() == 0 && tokenizer.compareCommand(Tokenizer::DXF_KEY_ENDSEC) == true)
                return;

            if (tokenizer.getCode() == 9)
            {
                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ACADVER) == true)
                {
                    tokenizer.getToken();
                    ACADVER = tokenizer.getCommand();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ANGBASE) == true)
                {
                    tokenizer.getToken();
                    ANGBASE = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ANGDIR) == true)
                {
                    tokenizer.getToken();
                    ANGDIR = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ATTDIA) == true)
                {
                    tokenizer.getToken();
                    ATTDIA = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ATTMODE) == true)
                {
                    tokenizer.getToken();
                    ATTMODE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ATTREQ) == true)
                {
                    tokenizer.getToken();
                    ATTREQ = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_AUNITS) == true)
                {
                    tokenizer.getToken();
                    AUNITS = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_AUPREC) == true)
                {
                    tokenizer.getToken();
                    AUPREC = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_AXISMODE) == true)
                {
                    tokenizer.getToken();
                    AXISMODE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_AXISUNIT) == true)
                {
                    AXISUNIT = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_BLIPMODE) == true)
                {
                    tokenizer.getToken();
                    BLIPMODE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_CECOLOR) == true)
                {
                    tokenizer.getToken();
                    CECOLOR = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_CELTYPE) == true)
                {
                    tokenizer.getToken();
                    CELTYPE = tokenizer.getCommand();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_CHAMFERA) == true)
                {
                    tokenizer.getToken();
                    CHAMFERA = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_CHAMFERB) == true)
                {
                    tokenizer.getToken();
                    CHAMFERB = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_CLAYER) == true)
                {
                    tokenizer.getToken();
                    CLAYER = tokenizer.getCommand();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_COORDS) == true)
                {
                    tokenizer.getToken();
                    COORDS = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMALT) == true)
                {
                    tokenizer.getToken();
                    DIMALT = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMALTD) == true)
                {
                    tokenizer.getToken();
                    DIMALTD = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMALTF) == true)
                {
                    tokenizer.getToken();
                    DIMALTF = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMAPOST) == true)
                {
                    tokenizer.getToken();
                    DIMAPOST = tokenizer.getCommand();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMASO) == true)
                {
                    tokenizer.getToken();
                    DIMASO = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMASZ) == true)
                {
                    tokenizer.getToken();
                    DIMASZ = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMBLK) == true)
                {
                    tokenizer.getToken();
                    DIMBLK = tokenizer.getCommand();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMBLK1) == true)
                {
                    tokenizer.getToken();
                    DIMBLK1 = tokenizer.getCommand();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMBLK2) == true)
                {
                    tokenizer.getToken();
                    DIMBLK2 = tokenizer.getCommand();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMCEN) == true)
                {
                    tokenizer.getToken();
                    DIMCEN = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMDLE) == true)
                {
                    tokenizer.getToken();
                    DIMDLE = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMDLI) == true)
                {
                    tokenizer.getToken();
                    DIMDLI = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMEXE) == true)
                {
                    tokenizer.getToken();
                    DIMEXE = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMEXO) == true)
                {
                    tokenizer.getToken();
                    DIMEXO = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMLFAC) == true)
                {
                    tokenizer.getToken();
                    DIMLFAC = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMLIM) == true)
                {
                    tokenizer.getToken();
                    DIMLIM = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMPOST) == true)
                {
                    tokenizer.getToken();
                    DIMPOST = tokenizer.getCommand();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMRND) == true)
                {
                    tokenizer.getToken();
                    DIMRND = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMSAH) == true)
                {
                    tokenizer.getToken();
                    DIMSAH = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMSCALE) == true)
                {
                    tokenizer.getToken();
                    DIMSCALE = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMSE1) == true)
                {
                    tokenizer.getToken();
                    DIMSE1 = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMSE2) == true)
                {
                    tokenizer.getToken();
                    DIMSE2 = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMSHO) == true)
                {
                    tokenizer.getToken();
                    DIMSHO = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMSOXD) == true)
                {
                    tokenizer.getToken();
                    DIMSOXD = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMTAD) == true)
                {
                    tokenizer.getToken();
                    DIMTAD = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMTIH) == true)
                {
                    tokenizer.getToken();
                    DIMTIH = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMTIX) == true)
                {
                    tokenizer.getToken();
                    DIMTIX = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMTM) == true)
                {
                    tokenizer.getToken();
                    DIMTM = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMTOFL) == true)
                {
                    tokenizer.getToken();
                    DIMTOFL = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMTOH) == true)
                {
                    tokenizer.getToken();
                    DIMTOH = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMTOL) == true)
                {
                    tokenizer.getToken();
                    DIMTOL = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMTP) == true)
                {
                    tokenizer.getToken();
                    DIMTP = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMTSZ) == true)
                {
                    tokenizer.getToken();
                    DIMTSZ = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMTVP) == true)
                {
                    tokenizer.getToken();
                    DIMTVP = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMTXT) == true)
                {
                    tokenizer.getToken();
                    DIMTXT = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DIMZIN) == true)
                {
                    tokenizer.getToken();
                    DIMZIN = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_DRAGMODE) == true)
                {
                    tokenizer.getToken();
                    DRAGMODE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ELEVATION) == true)
                {
                    tokenizer.getToken();
                    ELEVATION = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_EXTMAX) == true)
                {
                    EXTMAX = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_EXTMIN) == true)
                {
                    EXTMIN = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_FILLETRAD) == true)
                {
                    tokenizer.getToken();
                    FILLETRAD = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_FILLMODE) == true)
                {
                    tokenizer.getToken();
                    FILLMODE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_FLATLAND) == true)
                {
                    tokenizer.getToken();
                    FLATLAND = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_GRIDMODE) == true)
                {
                    tokenizer.getToken();
                    GRIDMODE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_GRIDUNIT) == true)
                {
                    GRIDUNIT = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_HANDLING) == true)
                {
                    tokenizer.getToken();
                    HANDLING = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_HANDSEED) == true)
                {
                    tokenizer.getToken();
                    HANDSEED = tokenizer.getCommand();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_INSBASE) == true)
                {
                    INSBASE = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_LIMCHECK) == true)
                {
                    tokenizer.getToken();
                    LIMCHECK = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_LIMMAX) == true)
                {
                    LIMMAX = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_LIMMIN) == true)
                {
                    LIMMIN = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_LTSCALE) == true)
                {
                    tokenizer.getToken();
                    LTSCALE = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_LUNITS) == true)
                {
                    tokenizer.getToken();
                    LUNITS = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_LUPREC) == true)
                {
                    tokenizer.getToken();
                    LUPREC = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_MENU) == true)
                {
                    tokenizer.getToken();
                    MENU = tokenizer.getCommand();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_MIRRTEXT) == true)
                {
                    tokenizer.getToken();
                    MIRRTEXT = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_ORTHOMODE) == true)
                {
                    tokenizer.getToken();
                    ORTHOMODE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_OSMODE) == true)
                {
                    tokenizer.getToken();
                    OSMODE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_PDMODE) == true)
                {
                    tokenizer.getToken();
                    PDMODE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_PDSIZE) == true)
                {
                    tokenizer.getToken();
                    PDSIZE = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_PLINEWID) == true)
                {
                    tokenizer.getToken();
                    PLINEWID = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_QTEXTMODE) == true)
                {
                    tokenizer.getToken();
                    QTEXTMODE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_REGENMODE) == true)
                {
                    tokenizer.getToken();
                    REGENMODE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SKETCHINC) == true)
                {
                    tokenizer.getToken();
                    SKETCHINC = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SKPOLY) == true)
                {
                    tokenizer.getToken();
                    SKPOLY = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SNAPANG) == true)
                {
                    tokenizer.getToken();
                    SNAPANG = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SNAPBASE) == true)
                {
                    SNAPBASE = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SNAPISOPAIR) == true)
                {
                    tokenizer.getToken();
                    SNAPISOPAIR = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SNAPMODE) == true)
                {
                    tokenizer.getToken();
                    SNAPMODE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SNAPSTYLE) == true)
                {
                    tokenizer.getToken();
                    SNAPSTYLE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SNAPUNIT) == true)
                {
                    SNAPUNIT = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SPLFRAME) == true)
                {
                    tokenizer.getToken();
                    SPLFRAME = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SPLINESEGS) == true)
                {
                    tokenizer.getToken();
                    SPLINESEGS = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SPLINETYPE) == true)
                {
                    tokenizer.getToken();
                    SPLINETYPE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SURFTAB1) == true)
                {
                    tokenizer.getToken();
                    SURFTAB1 = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SURFTAB2) == true)
                {
                    tokenizer.getToken();
                    SURFTAB2 = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SURFTYPE) == true)
                {
                    tokenizer.getToken();
                    SURFTYPE = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SURFU) == true)
                {
                    tokenizer.getToken();
                    SURFU = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_SURFV) == true)
                {
                    tokenizer.getToken();
                    SURFV = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_TDCREATE) == true)
                {
                    tokenizer.getToken();
                    TDCREATE = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_TDINDWG) == true)
                {
                    tokenizer.getToken();
                    TDINDWG = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_TDUPDATE) == true)
                {
                    tokenizer.getToken();
                    TDUPDATE = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_TDUSRTIMER) == true)
                {
                    tokenizer.getToken();
                    TDUSRTIMER = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_TEXTSIZE) == true)
                {
                    tokenizer.getToken();
                    TEXTSIZE = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_TEXTSTYLE) == true)
                {
                    tokenizer.getToken();
                    TEXTSTYLE = tokenizer.getCommand();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_THICKNESS) == true)
                {
                    tokenizer.getToken();
                    THICKNESS = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_TRACEWID) == true)
                {
                    tokenizer.getToken();
                    TRACEWID = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_UCSNAME) == true)
                {
                    tokenizer.getToken();
                    UCSNAME = tokenizer.getCommand();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_UCSORG) == true)
                {
                    UCSORG = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_UCSXDIR) == true)
                {
                    UCSXDIR = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_UCSYDIR) == true)
                {
                    UCSYDIR = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_USERI1) == true)
                {
                    tokenizer.getToken();
                    USERI1 = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_USERI2) == true)
                {
                    tokenizer.getToken();
                    USERI2 = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_USERI3) == true)
                {
                    tokenizer.getToken();
                    USERI3 = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_USERI4) == true)
                {
                    tokenizer.getToken();
                    USERI4 = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_USERI5) == true)
                {
                    tokenizer.getToken();
                    USERI5 = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_USERR1) == true)
                {
                    tokenizer.getToken();
                    USERR1 = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_USERR2) == true)
                {
                    tokenizer.getToken();
                    USERR2 = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_USERR3) == true)
                {
                    tokenizer.getToken();
                    USERR3 = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_USERR4) == true)
                {
                    tokenizer.getToken();
                    USERR4 = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_USERR5) == true)
                {
                    tokenizer.getToken();
                    USERR5 = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_USRTIMER) == true)
                {
                    tokenizer.getToken();
                    USRTIMER = tokenizer.getCommandAsInt();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_VIEWCTR) == true)
                {
                    VIEWCTR = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_VIEWDIR) == true)
                {
                    VIEWDIR = readPoint(tokenizer);
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_VIEWSIZE) == true)
                {
                    tokenizer.getToken();
                    VIEWSIZE = tokenizer.getCommandAsDouble();
                    continue;
                }

                if (tokenizer.compareCommand(Tokenizer::DXF_KEY_WORLDVIEW) == true)
                {
                    tokenizer.getToken();
                    WORLDVIEW = tokenizer.getCommandAsInt();
                    continue;
                }
            }
        }
    }

const Point3d Header::readPoint (Tokenizer &tokenizer)
{
    Point3d point;
    bool    end = false;

    while (end == false)
    {
        tokenizer.getToken();

        switch ( tokenizer.getCode() )
        {
            case 0:
            {
                end = true;
                break;
            }
            case 9:
            {
                end = true;
                break;
            }
            case 10:
            {
                point.setX( tokenizer.getCommandAsDouble() );
                break;
            }
            case 20:
            {
                point.setY( tokenizer.getCommandAsDouble() );
                break;
            }
            case 30:
            {
                point.setZ( tokenizer.getCommandAsDouble() );
                break;
            }
            default:
            {
                tokenizer.badInstruction();
                break;
            }
        }
    }

    tokenizer.gotoBack();

    return point;
}

} // namespace
