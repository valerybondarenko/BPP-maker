/*
 * Header.h
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

#ifndef RU_TCL_DXF_Header_H
#define RU_TCL_DXF_Header_H

#include <string>

#include "Section.h"
#include "Point3d.h"

namespace ru_tcl_dxf
{

using namespace std;

/*
 * Класс Header представляет секцию заголовка в файле.
 */
class _TCL_DXF_CLASS Header : public Section
{
public:

    /*
     * Возвращает версию базы данных системы AUTOCAD.
     */
    const string & getACADVER () const;

    /*
     * Возвращает установку точки отсчета (направления) угла 0.
     */
    double getANGBASE () const;

    /*
     * Возвращает направление поворота при отсчета угла.
     * 0 = против часовой стрелки.
     * 1 = по часовой стрелке.
     */
    int getANGDIR () const;

    /*
     * Attribute entry dialogues, 1 = on, 0  = off.
     */
    int getATTDIA () const;

    /*
     * Возвращает режим видимости атрибутов.
     * 0 = атрибуты не отображаются.
     * 1 = нормальный, отображаются только "видимые" атрибуты.
     * 2 = отображаются все атрибуты.
     */
    int getATTMODE () const;

    /*
     * Attribute prompting during INSERT, 1 = on, 0 = off.
     */
    int getATTREQ () const;

    /*
     * Возвращает формат едениц измерения для углов.
     * 1 = Гадусы в десятичном виде.
     * 2 = Градусы/минуты/секунды.
     * 3 = Грады.
     * 4 = Радианы.
     * 5 = Геодезический формат.
     */
    int getAUNITS () const;

    /*
     * Возвращает точность представления угла (число знаков
     * в представлении дробной части значения).
     */
    int getAUPREC () const;

    /*
     * Возвращает отображение осей координат (0 = OFF, 1 = ON).
     */
    int getAXISMODE () const;

    /*
     * Возвращает цену деления по оси координат x и y.
     */
    const Point3d & getAXISUNIT () const;

    /*
     * Возвращает отображение вспомогательных отметок
     * (0 = OFF, 1 = ON).
     */
    int getBLIPMODE () const;

    /*
     * Возвращает текущий цвет объекта (0 = BYBLOCK, 256 = BYLAYER).
     */
    int getCECOLOR () const;

    /*
     * Возвращает текущий тип линии.
     */
    const string & getCELTYPE () const;

    /*
     * First chamfer distance.
     */
    double getCHAMFERA () const;

    /*
     * Second chamfer distance.
     */
    double getCHAMFERB () const;

    /*
     * Возвращает имя слоя.
     */
    const string & getCLAYER () const;

    /*
     * Возвращает режим отображения координат.
     * 0 = Статическое отображение.
     * 1 = Непрерывное динамическое отображение.
     * 2 = При выполнении условия.
     */
    int getCOORDS () const;

    /*
     * Alternate unit dimensioning performed if nonzero.
     */
    int getDIMALT () const;

    /*
     * Alternate unit decimal places.
     */
    int getDIMALTD () const;

    /*
     * Alternate unit scale factor.
     */
    double getDIMALTF () const;

    /*
     * Alternate dimensioning suffix.
     */
    const string & getDIMAPOST () const;

    /*
     * 1 = create associative dimensioning,
     * 0 = draw individual entities.
     */
    int getDIMASO () const;

    /*
     * Возвращает длину размерных стрелок.
     */
    double getDIMASZ () const;

    /*
     * Возвращает имя блока размерных стрелок.
     */
    const string & getDIMBLK () const;

    /*
     * First arrow block name.
     */
    const string & getDIMBLK1 () const;

    /*
     * Ssecond arrow block name.
     */
    const string & getDIMBLK2 () const;

    /*
     * Возвращает размер отметки (маркера) центра.
     */
    double getDIMCEN () const;

    /*
     * Возвращает длину концов размерной линии, выходящих за выносные линии.
     */
    double getDIMDLE () const;

    /*
     * Возвращает интервал между последовательными размерными линиями.
     */
    double getDIMDLI () const;

    /*
     * Возвращает длину концов выносных линий, выходящих за размерные линии.
     */
    double getDIMEXE () const;

    /*
     * Возвращает расстояние между границей объекта и началом выносной линии.
     */
    double getDIMEXO () const;

    /*
     * Linear measurements scale factor.
     */
    double getDIMLFAC () const;

    /*
     * Возвращает размерные линии (0 = OFF, 1 = ON).
     */
    int getDIMLIM () const;

    /*
     * General dimensioning suffix.
     */
    const string & getDIMPOST () const;

    /*
     * Возвращает точность задания размеров.
     */
    double getDIMRND () const;

    /*
     * Use separate arrow blocks if nonzero.
     */
    int getDIMSAH () const;

    /*
     * Возвращает линейный масштаб для размеров.
     */
    double getDIMSCALE () const;

    /*
     * Подавление вычерчивания 1-ой выносной линии
     * (0 = OFF, 1 = ON).
     */
    int getDIMSE1 () const;

    /*
     * Подавление вычерчивания 2-ой выносной линии
     * (0 = OFF, 1 = ON).
     */
    int getDIMSE2 () const;

    /*
     * 1 = Recompute dimensions while dragging,
     * 0 = drag original image.
     */
    int getDIMSHO () const;

    /*
     * Suppress outside-extensions dimension lines if nonzero.
     */
    int getDIMSOXD () const;

    /*
     * Надпись помещается над размерной линией (0 = OFF, 1 = ON).
     */
    int getDIMTAD () const;

    /*
     * Надпись, помещенная между выносными линиями,вычерчивается
     * горизонтально (0 = OFF, 1 = ON).
     */
    int getDIMTIH () const;

    /*
     * Force text inside extensions if nonzero.
     */
    int getDIMTIX () const;

    /*
     * Возвращает значение минусового допуска.
     */
    double getDIMTM () const;

    /*
     * If text outside extensions, force line between extensions if nonzero.
     */
    int getDIMTOFL () const;

    /*
     * Надпись, помещенная за выносными линиями, вычерчивается
     * горизонтально (0 = OFF, 1 = ON).
     */
    int getDIMTOH () const;

    /*
     * Размерные надписи включают допуски (0 = OFF, 1 = ON).
     */
    int getDIMTOL () const;

    /*
     * Возвращает значение плюсового допуска.
     */
    double getDIMTP () const;

    /*
     * Возвращает размер рисок (используемых вместо стрелок).
     */
    double getDIMTSZ () const;

    /*
     * Text vertical position.
     */
    double getDIMTVP () const;

    /*
     * Возвращает высоту текста в размерной надписи.
     */
    double getDIMTXT () const;

    /*
     * Отображение нулевых размеров (0 = OFF, 1 = ON).
     */
    int getDIMZIN () const;

    /*
     * Возвращает режим отслеживания.
     * 0 = OFF
     * 1 = ON
     * 2 = Auto
     */
    int getDRAGMODE () const;

    /*
     * Возвращает текущий уровень возвышения.
     */
    double getELEVATION () const;

    /*
     * Возвращает габариты чертежа (координата верхнего правого угла).
     */
    const Point3d & getEXTMAX () const;

    /*
     * Возвращает габариты чертежа (координата нижнего левого угла).
     */
    const Point3d & getEXTMIN () const;

    /*
     * Fast zoom enabled if nonzero.
     */
    int getFASTZOOM () const;

    /*
     * Возвращает радиус сопряжения.
     */
    double getFILLETRAD () const;

    /*
     * Режим закраски (0 = OFF, 1 = ON).
     */
    int getFILLMODE () const;

    /*
     * Force compatibility with older versions if nonzero.
     */
    int getFLATLAND () const;

    /*
     * Отображение координатной сетки (0 = OFF, 1 = ON).
     */
    int getGRIDMODE () const;

    /*
     * Возвращает шаг координатной сетки по оси x и y.
     */
    const Point3d & getGRIDUNIT () const;

    /*
     * Handles enabled if nonzero.
     */
    int getHANDLING () const;

    /*
     * Next available handle.
     */
    const string & getHANDSEED () const;

    /*
     * Возвращает базовую точку вставки (x, y, z).
     */
    const Point3d & getINSBASE () const;

    /*
     * Контроль границ чертежа (0 = OFF, 1 = ON).
     */
    int getLIMCHECK () const;

    /*
     * Возвращает границы чертежа (координата верхнего правого угла).
     */
    const Point3d & getLIMMAX () const;

    /*
     * Возвращает границы чертежа (координата нижнего левого угла).
     */
    const Point3d & getLIMMIN () const;

    /*
     * Возвращает линейный масштаб для типов линии.
     */
    double getLTSCALE () const;

    /*
     * Возвращает формат представления координат и расстояний.
     * 1 = Научный (экспотенциальный).
     * 2 = Десятичный.
     * 3 = Технический.
     * 4 = Архитектурный.
     */
    int getLUNITS () const;

    /*
     * Возвращает точность представления координат и расстояний
     * (число знаков в представлении дробной части значения).
     */
    int getLUPREC () const;

    /*
     * Возвращает имя файла текущего меню.
     */
    const string & getMENU () const;

    /*
     * MIRROR text if nonzero.
     */
    int getMIRRTEXT () const;

    /*
     * Режим "ортогонального" рисования (0 = OFF, 1 = ON).
     */
    int getORTHOMODE () const;

    /*
     * Возвращает режим нахождения заданной точки объекта.
     */
    int getOSMODE () const;

    /*
     * Возвращает режим отображения точки.
     */
    int getPDMODE () const;

    /*
     * Возвращает размер точки на экране.
     */
    double getPDSIZE () const;

    /*
     * Возвращает текущую (по умолчанию) ширину полилинии.
     */
    double getPLINEWID () const;

    /*
     * Режим быстрого отбражения текста (0 = OFF, 1 = ON).
     */
    int getQTEXTMODE () const;

    /*
     * Режим автоматической регенерации (0 = OFF, 1 = ON).
     */
    int getREGENMODE () const;

    /*
     * Возвращает текущее приращение при ручной прорисовке.
     */
    double getSKETCHINC () const;

    /*
     * 0=sketch lines, 1=sketch polylines.
     */
    int getSKPOLY () const;

    /*
     * Возвращает угол поворота сетки привязки.
     */
    double getSNAPANG () const;

    /*
     * Возвращает базовую точку привязки.
     */
    const Point3d & getSNAPBASE () const;

    /*
     * Возвращает вид в изометрии.
     * 0 = Слева.
     * 1 = Сверху.
     * 2 = Справа.
     */
    int getSNAPISOPAIR () const;

    /*
     * Режим установки разрешающей способности (0 = OFF, 1 = ON).
     */
    int getSNAPMODE () const;

    /*
     * Возвращает тип сетки привязки.
     * 0 = Стандартная.
     * 1 = Изометрическая.
     */
    int getSNAPSTYLE () const;

    /*
     * Возвращает интервал разрешения по оси x и y.
     */
    const Point3d & getSNAPUNIT () const;

    /*
     * Spline control polygon display,
     * 1 = on,
     * 0 = off.
     */
    int getSPLFRAME () const;

    /*
     * Number of line segments per spline patch.
     */
    int getSPLINESEGS () const;

    /*
     * Spline curve type for "PEDIT Spline".
     */
    int getSPLINETYPE () const;

    /*
     * Number of mesh tabulations in first direction.
     */
    int getSURFTAB1 () const;

    /*
     * Number of mesh tabulations in second direction.
     */
    int getSURFTAB2 () const;

    /*
     * Surface type for "PEDIT Smooth".
     */
    int getSURFTYPE () const;

    /*
     * Surface density (for "PEDIT Smooth") in M direction.
     */
    int getSURFU () const;

    /*
     * Surface density (for "PEDIT Smooth") in N direction.
     */
    int getSURFV () const;

    /*
     * Date/time of drawing creation.
     */
    double getTDCREATE () const;

    /*
     * Cumulative editing time for this drawing.
     */
    double getTDINDWG () const;

    /*
     * Date/time of last drawing update.
     */
    double getTDUPDATE () const;

    /*
     * User elapsed timer.
     */
    double getTDUSRTIMER () const;

    /*
     * Возвращает текущую (по умолчанию) высоту текста.
     */
    double getTEXTSIZE () const;

    /*
     * Current text style name.
     */
    const string & getTEXTSTYLE () const;

    /*
     * Возвращает текущую высоту (толщину) объектов.
     */
    double getTHICKNESS () const;

    /*
     * Возвращает текущую ширину полосы.
     */
    double getTRACEWID () const;

    /*
     * Name of current UCS.
     */
    const string & getUCSNAME () const;

    /*
     * Origin of current UCS (in WCS).
     */
    const Point3d & getUCSORG () const;

    /*
     * Direction of current UCS's X axis (in World coordinates).
     */
    const Point3d & getUCSXDIR () const;

    /*
     * Direction of current UCS's Y axis (in World coordinates).
     */
    const Point3d & getUCSYDIR () const;

    /*
     * Возвращает целочисленной значение, заданное пользователем.
     */
    int getUSERI1 () const;

    /*
     * Возвращает целочисленной значение, заданное пользователем.
     */
    int getUSERI2 () const;

    /*
     * Возвращает целочисленной значение, заданное пользователем.
     */
    int getUSERI3 () const;

    /*
     * Возвращает целочисленной значение, заданное пользователем.
     */
    int getUSERI4 () const;

    /*
     * Возвращает целочисленной значение, заданное пользователем.
     */
    int getUSERI5 () const;

    /*
     * Возвращает действительное значение, заданное пользователем.
     */
    double getUSERR1 () const;

    /*
     * Возвращает действительное значение, заданное пользователем.
     */
    double getUSERR2 () const;

    /*
     * Возвращает действительное значение, заданное пользователем.
     */
    double getUSERR3 () const;

    /*
     * Возвращает действительное значение, заданное пользователем.
     */
    double getUSERR4 () const;

    /*
     * Возвращает действительное значение, заданное пользователем.
     */
    double getUSERR5 () const;

    /*
     * 0 = timer off,
     * 1 = timer on.
     */
    int getUSRTIMER () const;

    /*
     * Возвращает положение текущего вида (его центр) на экране.
     */
    const Point3d & getVIEWCTR () const;

    /*
     * Возвращает текущую точку наблюдения.
     */
    const Point3d & getVIEWDIR () const;

    /*
     * Возвращает высоту текущего вида на экране.
     */
    double getVIEWSIZE () const;

    /*
     * 1 = set UCS to WCS during DVIEW/VPOINT,
     * 0 = don't change UCS
     */
    int getWORLDVIEW () const;

    /*
     * Считывание объекта из dxf файла.
     */
    void readDXF (Tokenizer &tokenizer);

private:

    const Point3d readPoint (Tokenizer &tokenizer);

private:

    // Атрибуты
    // ========

    string  ACADVER;
    double  ANGBASE;
    int     ANGDIR;
    int     ATTDIA;
    int     ATTMODE;
    int     ATTREQ;
    int     AUNITS;
    int     AUPREC;
    int     AXISMODE;
    Point3d AXISUNIT;
    int     BLIPMODE;
    int     CECOLOR;
    string  CELTYPE;
    string  CLAYER;
    double  CHAMFERA;
    double  CHAMFERB;
    int     COORDS;
    int     DIMALT;
    int     DIMALTD;
    double  DIMALTF;
    string  DIMAPOST;
    int     DIMASO;
    double  DIMASZ;
    string  DIMBLK;
    string  DIMBLK1;
    string  DIMBLK2;
    double  DIMCEN;
    double  DIMDLE;
    double  DIMDLI;
    double  DIMEXE;
    double  DIMEXO;
    double  DIMLFAC;
    int     DIMLIM;
    string  DIMPOST;
    double  DIMRND;
    int     DIMSAH;
    double  DIMSCALE;
    int     DIMSE1;
    int     DIMSE2;
    int     DIMSHO;
    int     DIMSOXD;
    int     DIMTAD;
    int     DIMTIH;
    int     DIMTIX;
    double  DIMTM;
    int     DIMTOFL;
    int     DIMTOH;
    int     DIMTOL;
    double  DIMTP;
    double  DIMTSZ;
    double  DIMTVP;
    double  DIMTXT;
    int     DIMZIN;
    int     DRAGMODE;
    double  ELEVATION;
    Point3d EXTMAX;
    Point3d EXTMIN;
    int     FASTZOOM;
    double  FILLETRAD;
    int     FILLMODE;
    int     FLATLAND;
    int     GRIDMODE;
    Point3d GRIDUNIT;
    int     HANDLING;
    string  HANDSEED;
    Point3d INSBASE;
    int     LIMCHECK;
    Point3d LIMMAX;
    Point3d LIMMIN;
    double  LTSCALE;
    int     LUNITS;
    int     LUPREC;
    string  MENU;
    int     MIRRTEXT;
    int     ORTHOMODE;
    int     OSMODE;
    int     PDMODE;
    double  PDSIZE;
    double  PLINEWID;
    int     QTEXTMODE;
    int     REGENMODE;
    double  SKETCHINC;
    int     SKPOLY;
    double  SNAPANG;
    Point3d SNAPBASE;
    int     SNAPISOPAIR;
    int     SNAPMODE;
    int     SNAPSTYLE;
    Point3d SNAPUNIT;
    int     SPLFRAME;
    int     SPLINESEGS;
    int     SPLINETYPE;
    int     SURFTAB1;
    int     SURFTAB2;
    int     SURFTYPE;
    int     SURFU;
    int     SURFV;
    double  TDCREATE;
    double  TDINDWG;
    double  TDUPDATE;
    double  TDUSRTIMER;
    double  TEXTSIZE;
    string  TEXTSTYLE;
    double  THICKNESS;
    double  TRACEWID;
    string  UCSNAME;
    Point3d UCSORG;
    Point3d UCSXDIR;
    Point3d UCSYDIR;
    int     USERI1;
    int     USERI2;
    int     USERI3;
    int     USERI4;
    int     USERI5;
    double  USERR1;
    double  USERR2;
    double  USERR3;
    double  USERR4;
    double  USERR5;
    int     USRTIMER;    
    Point3d VIEWCTR;
    Point3d VIEWDIR;
    double  VIEWSIZE;
    int     WORLDVIEW;
};


inline const string & Header::getACADVER () const
{
    return ACADVER;
}

inline double Header::getANGBASE () const
{
    return ANGBASE;
}

inline int Header::getANGDIR () const
{
    return ANGDIR;
}

inline int Header::getATTDIA () const
{
    return ATTDIA;
}

inline int Header::getATTMODE () const
{
    return ATTMODE;
}

inline int Header::getATTREQ () const
{
    return ATTREQ;
}

inline int Header::getAUNITS () const
{
    return AUNITS;
}

inline int Header::getAUPREC () const
{
    return AUPREC;
}

inline int Header::getAXISMODE () const
{
    return AXISMODE;
}

inline const Point3d & Header::getAXISUNIT () const
{
    return AXISUNIT;
}

inline int Header::getBLIPMODE () const
{
    return BLIPMODE;
}

inline int Header::getCECOLOR () const
{
    return CECOLOR;
}

inline const string & Header::getCELTYPE () const
{
    return CELTYPE;
}

inline double Header::getCHAMFERA () const
{
    return CHAMFERA;
}

inline double Header::getCHAMFERB () const
{
    return CHAMFERB;
}

inline const string & Header::getCLAYER () const
{
    return CLAYER;
}

inline int Header::getCOORDS () const
{
    return COORDS;
}

inline int Header::getDIMALT () const
{
    return DIMALT;
}

inline int Header::getDIMALTD () const
{
    return DIMALTD;
}

inline double Header::getDIMALTF () const
{
    return DIMALTF;
}

inline const string & Header::getDIMAPOST () const
{
    return DIMAPOST;
}

inline int Header::getDIMASO () const
{
    return DIMASO;
}

inline double Header::getDIMASZ () const
{
    return DIMASZ;
}

inline const string & Header::getDIMBLK () const
{
    return DIMBLK;
}

inline const string & Header::getDIMBLK1 () const
{
    return DIMBLK1;
}

inline const string & Header::getDIMBLK2 () const
{
    return DIMBLK2;
}

inline double Header::getDIMCEN () const
{
    return DIMCEN;
}

inline double Header::getDIMDLE () const
{
    return DIMDLE;
}

inline double Header::getDIMDLI () const
{
    return DIMDLI;
}

inline double Header::getDIMEXE () const
{
    return DIMEXE;
}

inline double Header::getDIMEXO () const
{
    return DIMEXO;
}

inline double Header::getDIMLFAC () const
{
    return DIMLFAC;
}

inline int Header::getDIMLIM () const
{
    return DIMLIM;
}

inline const string & Header::getDIMPOST () const
{
    return DIMPOST;
}

inline double Header::getDIMRND () const
{
    return DIMRND;
}

inline int Header::getDIMSAH () const
{
    return DIMSAH;
}

inline double Header::getDIMSCALE () const
{
    return DIMSCALE;
}

inline int Header::getDIMSE1 () const
{
    return DIMSE1;
}

inline int Header::getDIMSE2 () const
{
    return DIMSE2;
}

inline int Header::getDIMSHO () const
{
    return DIMSHO;
}

inline int Header::getDIMSOXD () const
{
    return DIMSOXD;
}

inline int Header::getDIMTAD () const
{
    return DIMTAD;
}

inline int Header::getDIMTIH () const
{
    return DIMTIH;
}

inline int Header::getDIMTIX () const
{
    return DIMTIX;
}

inline double Header::getDIMTM () const
{
    return DIMTM;
}

inline int Header::getDIMTOFL () const
{
    return DIMTOFL;
}

inline int Header::getDIMTOH () const
{
    return DIMTOH;
}

inline int Header::getDIMTOL () const
{
    return DIMTOL;
}

inline double Header::getDIMTP () const
{
    return DIMTP;
}

inline double Header::getDIMTSZ () const
{
    return DIMTSZ;
}

inline double Header::getDIMTVP () const
{
    return DIMTVP;
}

inline double Header::getDIMTXT () const
{
    return DIMTXT;
}

inline int Header::getDIMZIN () const
{
    return DIMZIN;
}

inline int Header::getDRAGMODE () const
{
    return DRAGMODE;
}

inline double Header::getELEVATION () const
{
    return ELEVATION;
}

inline const Point3d & Header::getEXTMAX () const
{
    return EXTMAX;
}

inline const Point3d & Header::getEXTMIN () const
{
    return EXTMIN;
}

inline int Header::getFASTZOOM () const
{
    return FASTZOOM;
}

inline double Header::getFILLETRAD () const
{
    return FILLETRAD;
}

inline int Header::getFILLMODE () const
{
    return FILLMODE;
}

inline int Header::getFLATLAND () const
{
    return FLATLAND;
}

inline int Header::getGRIDMODE () const
{
    return GRIDMODE;
}

inline const Point3d & Header::getGRIDUNIT () const
{
    return GRIDUNIT;
}

inline int Header::getHANDLING () const
{
    return HANDLING;
}

inline const string & Header::getHANDSEED () const
{
    return HANDSEED;
}

inline const Point3d & Header::getINSBASE () const
{
    return INSBASE;
}

inline int Header::getLIMCHECK () const
{
    return LIMCHECK;
}

inline const Point3d & Header::getLIMMAX () const
{
    return LIMMAX;
}

inline const Point3d & Header::getLIMMIN () const
{
    return LIMMIN;
}

inline double Header::getLTSCALE () const
{
    return LTSCALE;
}

inline int Header::getLUNITS () const
{
    return LUNITS;
}

inline int Header::getLUPREC () const
{
    return LUPREC;
}

inline const string & Header::getMENU () const
{
    return MENU;
}

inline int Header::getMIRRTEXT () const
{
    return MIRRTEXT;
}

inline int Header::getORTHOMODE () const
{
    return ORTHOMODE;
}

inline int Header::getOSMODE () const
{
    return OSMODE;
}

inline int Header::getPDMODE () const
{
    return PDMODE;
}

inline double Header::getPDSIZE () const
{
    return PDSIZE;
}

inline double Header::getPLINEWID () const
{
    return PLINEWID;
}

inline int Header::getQTEXTMODE () const
{
    return QTEXTMODE;
}

inline int Header::getREGENMODE () const
{
    return REGENMODE;
}

inline double Header::getSKETCHINC () const
{
    return SKETCHINC;
}

inline int Header::getSKPOLY () const
{
    return SKPOLY;
}

inline double Header::getSNAPANG () const
{
    return SNAPANG;
}

inline const Point3d & Header::getSNAPBASE () const
{
    return SNAPBASE;
}

inline int Header::getSNAPISOPAIR () const
{
    return SNAPISOPAIR;
}

inline int Header::getSNAPMODE () const
{
    return SNAPMODE;
}

inline int Header::getSNAPSTYLE () const
{
    return SNAPSTYLE;
}

inline const Point3d & Header::getSNAPUNIT () const
{
    return SNAPUNIT;
}

inline int Header::getSPLFRAME () const
{
    return SPLFRAME;
}

inline int Header::getSPLINESEGS () const
{
    return SPLINESEGS;
}

inline int Header::getSPLINETYPE () const
{
    return SPLINETYPE;
}

inline int Header::getSURFTAB1 () const
{
    return SURFTAB1;
}

inline int Header::getSURFTAB2 () const
{
    return SURFTAB2;
}

inline int Header::getSURFTYPE () const
{
    return SURFTYPE;
}

inline int Header::getSURFU () const
{
    return SURFU;
}

inline int Header::getSURFV () const
{
    return SURFV;
}

inline double Header::getTDCREATE () const
{
    return TDCREATE;
}

inline double Header::getTDINDWG () const
{
    return TDINDWG;
}

inline double Header::getTDUPDATE () const
{
    return TDUPDATE;
}

inline double Header::getTDUSRTIMER () const
{
    return TDUSRTIMER;
}

inline double Header::getTEXTSIZE () const
{
    return TEXTSIZE;
}

inline const string & Header::getTEXTSTYLE () const
{
    return TEXTSTYLE;
}

inline double Header::getTHICKNESS () const
{
    return THICKNESS;
}

inline double Header::getTRACEWID () const
{
    return TRACEWID;
}

inline const string & Header::getUCSNAME () const
{
    return UCSNAME;
}

inline const Point3d & Header::getUCSORG () const
{
    return UCSORG;
}

inline const Point3d & Header::getUCSXDIR () const
{
    return UCSXDIR;
}

inline const Point3d & Header::getUCSYDIR () const
{
    return UCSYDIR;
}

inline int Header::getUSERI1 () const
{
    return USERI1;
}

inline int Header::getUSERI2 () const
{
    return USERI2;
}

inline int Header::getUSERI3 () const
{
    return USERI3;
}

inline int Header::getUSERI4 () const
{
    return USERI4;
}

inline int Header::getUSERI5 () const
{
    return USERI5;
}

inline double Header::getUSERR1 () const
{
    return USERR1;
}

inline double Header::getUSERR2 () const
{
    return USERR2;
}

inline double Header::getUSERR3 () const
{
        return USERR3;
}

inline double Header::getUSERR4 () const
{
        return USERR4;
}

inline double Header::getUSERR5 () const
{
        return USERR5;
}

inline int Header::getUSRTIMER () const
{
        return USRTIMER;
}

inline const Point3d & Header::getVIEWCTR () const
{
        return VIEWCTR;
}

inline const Point3d & Header::getVIEWDIR () const
{
        return VIEWDIR;
}

inline double Header::getVIEWSIZE () const
{
        return VIEWSIZE;
}

inline int Header::getWORLDVIEW () const
{
        return WORLDVIEW;
}

} // namespace

#endif // RU_TCL_DXF_Header_H
