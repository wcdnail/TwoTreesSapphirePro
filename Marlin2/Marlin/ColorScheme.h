/**
 * TFT Color scheme constants
 * MNi 10.2019
 * 
 */

#pragma once

inline constexpr uint16_t RGBto565(uint32_t rgbv) {
  uint32_t r = (rgbv & 0x00ff0000) >> 16;
  uint32_t g = (rgbv & 0x0000ff00) >> 8;
  uint32_t b = (rgbv & 0x000000ff) >> 0;
  return (((r>>3)<<11) | ((g>>2)<<5) | (b>>3));
}

// see https://ee-programming-notepad.blogspot.com/2016/10/16-bit-color-generator-picker.html
// https://trolsoft.ru/ru/articles/rgb565-color-picker

#define COLOR_BLACK       0x0000  // #000000
#define COLOR_WHITE       0xFFFF  // #FFFFFF
#define COLOR_SILVER      0xC618  // #C0C0C0
#define COLOR_GREY        0x7BEF  // #808080
#define COLOR_DARKGREY    0x4208  // #404040
#define COLOR_DARKGREY2   0x39E7  // #303030
#define COLOR_DARK        0x0003  // Some dark color

#define COLOR_RED         0xF800  // #FF0000
#define COLOR_LIME        0x7E00  // #00FF00
#define COLOR_BLUE        0x001F  // #0000FF
#define COLOR_YELLOW      0xFFE0  // #FFFF00
#define COLOR_MAGENTA     0xF81F  // #FF00FF
#define COLOR_FUCHSIA     0xF81F  // #FF00FF
#define COLOR_CYAN        0x07FF  // #00FFFF
#define COLOR_AQUA        0x07FF  // #00FFFF

#define COLOR_MAROON      0x7800  // #800000
#define COLOR_GREEN       0x03E0  // #008000
#define COLOR_NAVY        0x000F  // #000080
#define COLOR_OLIVE       0x8400  // #808000
#define COLOR_PURPLE      0x8010  // #800080
#define COLOR_TEAL        0x0410  // #008080

#define COLOR_ORANGE      0xFC00  // #FF7F00

#if 0
// Indexes
#if ENABLED(FSMC_GRAPHICAL_TFT)
  #define CTHEME_ZEROINDEX              0
  #define CTHEME_DEFAULTS               (CTHEME_ZEROINDEX + 0)
  #define CTHEME_KILLSCREEN             (CTHEME_ZEROINDEX + 1)
  #define CTHEME_BOOTSCREEN1            (CTHEME_ZEROINDEX + 2)
  #define CTHEME_BOOTSCREEN2            (CTHEME_ZEROINDEX + 3)
  #define CTHEME_STATUS                 (CTHEME_ZEROINDEX + 4)
  #define CTHEME_SWITCH(Index)          u8g.getU8g()->arg_pixel.blue = Index
  #define CTHEME_GETINDEX(u8gptr)       u8gptr->arg_pixel.blue
#else
  #define CTHEME_DEFAULTS               1
  #define CTHEME_KILLSCREEN             1
  #define CTHEME_BOOTSCREEN1            1
  #define CTHEME_BOOTSCREEN2            1
  #define CTHEME_STATUS                 1
  #define CTHEME_SWITCH(Index)
#endif

#endif 

#define TFT_COLOR_THEME_UNDEF   -1
#define TFT_COLOR_BLACK_THEME   0
#define TFT_COLOR_BLUE_THEME    1
#define TFT_COLOR_GREEN_THEME   2
#define TFT_COLOR_THEME         TFT_COLOR_BLUE_THEME

#undef TFT_MARLINUI_COLOR
#undef TFT_MARLINBG_COLOR
#undef TFT_BTCANCEL_COLOR
#undef TFT_BTARROWS_COLOR
#undef TFT_BTOKMENU_COLOR

#if TFT_COLOR_THEME == TFT_COLOR_BLACK_THEME
  #define TFT_MARLINUI_COLOR 0x04DF
  #define TFT_MARLINBG_COLOR COLOR_BLACK
  #define TFT_BTCANCEL_COLOR 0xE0E4
  #define TFT_BTARROWS_COLOR 0x01EC
  #define TFT_BTOKMENU_COLOR 0xF7CC
#elif TFT_COLOR_THEME == TFT_COLOR_BLUE_THEME
  #define TFT_MARLINUI_COLOR        COLOR_WHITE
  #define TFT_BTCANCEL_BKCOLOR      RGBto565(0x720000)
  #define TFT_MARLINBG_COLOR        RGBto565(0x001efd)
  #define TFT_BTCANCEL_COLOR        RGBto565(0xed1e24)
  #define TFT_BTARROWDEC_COLOR      RGBto565(0x01107e)
  #define TFT_BTARROWDEC_BKCOLOR    RGBto565(0x412fb4)
  #define TFT_BTARROWINC_COLOR      RGBto565(0x01107e)
  #define TFT_BTARROWINC_BKCOLOR    RGBto565(0x412fb4)
  #define TFT_BTOKMENU_COLOR        RGBto565(0xfde200)
  #define TFT_BTOKMENU_BKCOLOR      RGBto565(0xffa000)
  // Boot screens
  #define TFT_COLOR_FG_DEFAULTS     TFT_MARLINUI_COLOR
  #define TFT_COLOR_BG_DEFAULTS     TFT_MARLINBG_COLOR
  #define TFT_COLOR_FG_BOOTSCREEN1  COLOR_WHITE
  #define TFT_COLOR_BG_BOOTSCREEN1  TFT_MARLINBG_COLOR
  #define TFT_COLOR_FG_BOOTSCREEN2  COLOR_WHITE
  #define TFT_COLOR_BG_BOOTSCREEN2  TFT_MARLINBG_COLOR
  // Kill screen
  #define TFT_COLOR_FG_KILLSCREEN   COLOR_YELLOW
  #define TFT_COLOR_BG_KILLSCREEN   COLOR_RED
  // Status screen
  #define TFT_COLOR_FG_STATUS_LOGO  RGBto565(0x0110c7)
  #define TFT_COLOR_BG_STATUS_LOGO  TFT_MARLINBG_COLOR
  #define TFT_COLOR_FG_HOTEND       TFT_MARLINUI_COLOR
  #define TFT_COLOR_BG_HOTEND       TFT_MARLINBG_COLOR
  #define TFT_COLOR_FG_HOTBED       TFT_MARLINUI_COLOR
  #define TFT_COLOR_BG_HOTBED       TFT_MARLINBG_COLOR
  #define TFT_COLOR_FG_FAN          RGBto565(0x8ad9ed)
  #define TFT_COLOR_BG_FAN          TFT_MARLINBG_COLOR
  #define TFT_COLOR_FG_XYZ_FRAME    RGBto565(0x00a6ff)
  #define TFT_COLOR_BG_XYZ_FRAME    TFT_MARLINBG_COLOR
  #define TFT_COLOR_FG_FR_SPD       RGBto565(0x8ad9ed)
  #define TFT_COLOR_BG_FR_SPD       TFT_MARLINBG_COLOR
  #define TFT_COLOR_FG_PBAR         TFT_MARLINUI_COLOR
  #define TFT_COLOR_BG_PBAR         TFT_MARLINBG_COLOR
  #define TFT_COLOR_FG_STAUS_LINE   RGBto565(0x00a6ff)
  #define TFT_COLOR_BG_STAUS_LINE   TFT_MARLINBG_COLOR
#elif TFT_COLOR_THEME == TFT_COLOR_GREEN_THEME
  #define TFT_MARLINUI_COLOR 0xF794
  #define TFT_MARLINBG_COLOR 0x2BE7
  #define TFT_BTCANCEL_COLOR 0x962D
  #define TFT_BTARROWS_COLOR 0x5D0C
  #define TFT_BTOKMENU_COLOR 0xEF42
#endif

#ifndef TFT_MARLINUI_COLOR
  #define TFT_MARLINUI_COLOR COLOR_WHITE
#endif
#ifndef TFT_MARLINBG_COLOR
  #define TFT_MARLINBG_COLOR COLOR_BLACK
#endif
#ifndef TFT_DISABLED_COLOR
  #define TFT_DISABLED_COLOR COLOR_DARK
#endif
#ifndef TFT_BTCANCEL_COLOR
  #define TFT_BTCANCEL_COLOR COLOR_RED
#endif
#ifndef TFT_BTARROWS_COLOR
  #define TFT_BTARROWS_COLOR COLOR_BLUE
#endif
#ifndef TFT_BTOKMENU_COLOR
  #define TFT_BTOKMENU_COLOR COLOR_RED
#endif

// --------------------------------------------------------------------------------------------------------------------

#define _TFT_FLG_NORMAL        0
#define _TFT_FLG_BOOT_SCREEN   1
#define _TFT_FLG_KILL_SCREEN   2
#define _TFT_FLG_STATUS_SCREEN 3
#define _TFT_SCREEN_MASK       0x1f

#if ENABLED(FSMC_GRAPHICAL_TFT)
  #ifdef __cplusplus
    extern "C" {
  #endif
      void tftSetFgColor(uint16_t v);
      void tftSetBgColor(uint16_t v);
      void tftSetFlags(uint16_t flags);
  #ifdef __cplusplus    
    }
  #endif
  #define CTHEME_SETC(CLR)            do { tftSetFgColor(CLR); } while (0)
  #define CTHEME_SETB(BK)             do { tftSetBgColor(BK); } while (0)
  #define CTHEME_SETCB(CLR, BK)       do { tftSetFgColor(CLR); tftSetBgColor(BK); } while (0)
  #define CTHEME_SEL(SYM)             CTHEME_SETCB(TFT_COLOR_FG_##SYM, TFT_COLOR_BG_##SYM)
  #define CTHEME_FLAGS(FLG)           do { tftSetFlags(FLG); } while (0)
#else
  #define CTHEME_SETC(CLR)
  #define CTHEME_SETB(BK)
  #define CTHEME_SETCB(CLR, BK)
  #define CTHEME_SEL(SYM)
  #define CTHEME_FLAGS(FLG)
#endif

// --------------------------------------------------------------------------------------------------------------------