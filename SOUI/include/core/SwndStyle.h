//////////////////////////////////////////////////////////////////////////
//   File Name: SwndStyle.h
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "res.mgr/sstringpool.h"
#include "res.mgr/SSkinPool.h"
#include "SSkin.h"

namespace SOUI
{

class SOUI_EXP SwndStyle : public SObject
{
    SOUI_CLASS_NAME(SwndStyle, L"style")

    enum
    {
        Align_Left               = 0x000UL, // valign = top
        Align_Center             = 0x100UL, // valign = middle
        Align_Right              = 0x200UL, // valign = bottom

        VAlign_Top               = 0x0000UL, // valign = top
        VAlign_Middle            = 0x1000UL, // valign = middle
        VAlign_Bottom            = 0x2000UL, // valign = bottom
    };
public:
    SwndStyle();


    COLORREF m_crBg;
    COLORREF m_crBorder;

    int m_nMarginX;
    int m_nMarginY;
    int m_nSpacing;
    BOOL m_bDotted;

    SStringW m_strCursor;
    SStringW m_strSkinName,m_strNcSkinName;

    UINT GetTextAlign();
    int GetStates();
    COLORREF GetTextColor(int iState);
    IFontPtr GetTextFont(int iState);
    void SetTextColor(int iState,COLORREF cr){m_crText[iState]=cr;}
protected:
    UINT m_nTextAlign;
    UINT m_uAlign,m_uVAlign;
    COLORREF m_crText[4];
    IFontPtr m_ftText[4];

    SOUI_ATTRS_BEGIN()
        ATTR_STRINGW(L"skin", m_strSkinName, TRUE)
        ATTR_STRINGW(L"ncskin", m_strNcSkinName, TRUE)
        ATTR_HEX(L"textmode", m_nTextAlign, TRUE)

        ATTR_ENUM_BEGIN(L"align", UINT, TRUE)
            ATTR_ENUM_VALUE(L"left", Align_Left)
            ATTR_ENUM_VALUE(L"center", Align_Center)
            ATTR_ENUM_VALUE(L"right", Align_Right)
        ATTR_ENUM_END(m_uAlign)
        ATTR_ENUM_BEGIN(L"valign", UINT, TRUE)
            ATTR_ENUM_VALUE(L"top", VAlign_Top)
            ATTR_ENUM_VALUE(L"middle", VAlign_Middle)
            ATTR_ENUM_VALUE(L"bottom", VAlign_Bottom)
        ATTR_ENUM_END(m_uVAlign)

        ATTR_COLOR(L"crbg", m_crBg, TRUE)
        ATTR_COLOR(L"crborder", m_crBorder, TRUE)

        ATTR_FONT(L"font", m_ftText[0], TRUE)
        ATTR_FONTEX(L"font2", m_ftText[0], TRUE)
        ATTR_FONT(L"font.hover", m_ftText[1], TRUE)
        ATTR_FONTEX(L"font2.hover", m_ftText[1], TRUE)
        ATTR_FONT(L"font.push", m_ftText[2], TRUE)
        ATTR_FONTEX(L"font2.push", m_ftText[2], TRUE)
        ATTR_FONT(L"font.disable", m_ftText[3], TRUE)
        ATTR_FONTEX(L"font2.disable", m_ftText[3], TRUE)

        ATTR_COLOR(L"crtext", m_crText[0], TRUE)
        ATTR_COLOR(L"crtext.hover", m_crText[1], TRUE)
        ATTR_COLOR(L"crtext.push", m_crText[2], TRUE)
        ATTR_COLOR(L"crtext.disable", m_crText[3], TRUE)

        ATTR_INT(L"x-margin", m_nMarginX, TRUE)
        ATTR_INT(L"y-margin", m_nMarginY, TRUE)
        ATTR_INT(L"margin", m_nMarginX = m_nMarginY, TRUE) // 这样比较bt，不过.....凑合用吧
        ATTR_INT(L"spacing", m_nSpacing, TRUE)
        ATTR_STRINGW(L"cursor",m_strCursor,FALSE)
        ATTR_INT(L"dotted",m_bDotted,FALSE)
    SOUI_ATTRS_END()
};


}//namespace SOUI