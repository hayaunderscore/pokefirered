#include "global.h"
#include "text_window_graphics.h"

const u16 gSignpostWindow_Gfx[] = INCGFX_U16("graphics/text_window/signpost.png", ".4bpp", "-num_tiles 19 -Wnum_tiles");

static const u16 sUserFrame_Type1_Gfx[] = INCGFX_U16("graphics/text_window/type1.png", ".4bpp");
static const u16 sUserFrame_Type2_Gfx[] = INCGFX_U16("graphics/text_window/type2.png", ".4bpp");
static const u16 sUserFrame_Empty1[16] = {0};
static const u16 sUserFrame_Type3_Gfx[] = INCGFX_U16("graphics/text_window/type3.png", ".4bpp");
static const u16 sUserFrame_Type4_Gfx[] = INCGFX_U16("graphics/text_window/type4.png", ".4bpp");
static const u16 sUserFrame_Type5_Gfx[] = INCGFX_U16("graphics/text_window/type5.png", ".4bpp");
static const u16 sUserFrame_Type6_Gfx[] = INCGFX_U16("graphics/text_window/type6.png", ".4bpp");
static const u16 sUserFrame_Type7_Gfx[] = INCGFX_U16("graphics/text_window/type7.png", ".4bpp");
static const u16 sUserFrame_Type8_Gfx[] = INCGFX_U16("graphics/text_window/type8.png", ".4bpp");
static const u16 sUserFrame_Empty2[16] = {0};
static const u16 sUserFrame_Type9_Gfx[] = INCGFX_U16("graphics/text_window/type9.png", ".4bpp");
static const u16 sUserFrame_Type10_Gfx[] = INCGFX_U16("graphics/text_window/type10.png", ".4bpp");
static const u16 sUserFrame_Empty3[16] = {0};

static const u16 sUserFrame_Type1_Pal[] = INCGFX_U16("graphics/text_window/type1.png", ".gbapal");
static const u16 sUserFrame_Type2_Pal[] = INCGFX_U16("graphics/text_window/type2.png", ".gbapal");
static const u16 sUserFrame_Type3_Pal[] = INCGFX_U16("graphics/text_window/type3.png", ".gbapal");
static const u16 sUserFrame_Type4_Pal[] = INCGFX_U16("graphics/text_window/type4.png", ".gbapal");
static const u16 sUserFrame_Type5_Pal[] = INCGFX_U16("graphics/text_window/type5.png", ".gbapal");
static const u16 sUserFrame_Type6_Pal[] = INCGFX_U16("graphics/text_window/type6.png", ".gbapal");
static const u16 sUserFrame_Type7_Pal[] = INCGFX_U16("graphics/text_window/type7.png", ".gbapal");
static const u16 sUserFrame_Type8_Pal[] = INCGFX_U16("graphics/text_window/type8.png", ".gbapal");
static const u16 sUserFrame_Type9_Pal[] = INCGFX_U16("graphics/text_window/type9.png", ".gbapal");
static const u16 sUserFrame_Type10_Pal[] = INCGFX_U16("graphics/text_window/type10.png", ".gbapal");

const u16 gStdTextWindow_Gfx[] = INCGFX_U16("graphics/text_window/std.png", ".4bpp");
const u16 gQuestLogWindow_Gfx[] = INCGFX_U16("graphics/text_window/quest_log.png", ".4bpp");

const u16 gTextWindowPalettes[][16] = {
    INCGFX_U16("graphics/text_window/stdpal_0.pal", ".gbapal"),
    INCGFX_U16("graphics/text_window/stdpal_1.pal", ".gbapal"),
    INCGFX_U16("graphics/text_window/stdpal_2.pal", ".gbapal"),
    INCGFX_U16("graphics/text_window/stdpal_3.pal", ".gbapal"),
    INCGFX_U16("graphics/text_window/stdpal_4.pal", ".gbapal")
};

const struct TextWindowGraphics gUserFrames[] = {
    {sUserFrame_Type1_Gfx,  sUserFrame_Type1_Pal},
    {sUserFrame_Type2_Gfx,  sUserFrame_Type2_Pal},
    {sUserFrame_Type3_Gfx,  sUserFrame_Type3_Pal},
    {sUserFrame_Type4_Gfx,  sUserFrame_Type4_Pal},
    {sUserFrame_Type5_Gfx,  sUserFrame_Type5_Pal},
    {sUserFrame_Type6_Gfx,  sUserFrame_Type6_Pal},
    {sUserFrame_Type7_Gfx,  sUserFrame_Type7_Pal},
    {sUserFrame_Type8_Gfx,  sUserFrame_Type8_Pal},
    {sUserFrame_Type9_Gfx,  sUserFrame_Type9_Pal},
    {sUserFrame_Type10_Gfx, sUserFrame_Type10_Pal},
};

const struct TextWindowGraphics *GetUserWindowGraphics(u8 idx)
{
#ifdef BUGFIX
    if (idx >= ARRAY_COUNT(gUserFrames))
#else
    if (idx >= 20) // Using the RSE number of elements
#endif
        return &gUserFrames[0];
    else
        return &gUserFrames[idx];
}
