/**
 * TFT Color scheme constants
 * MNi 10.2019
 * 
 */

#pragma once

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

#define TFT_COLOR_THEME_UNDEF   -1
#define TFT_COLOR_BLACK_THEME   0
#define TFT_COLOR_BLUE_THEME    1
#define TFT_COLOR_GREEN_THEME   2

#define TFT_COLOR_THEME   TFT_COLOR_BLUE_THEME

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
  #define TFT_MARLINUI_COLOR COLOR_WHITE
  #define TFT_MARLINBG_COLOR RGBto565(0x005dae)
  #define TFT_BTCANCEL_COLOR RGBto565(0xff7276)
  #define TFT_BTARROWS_COLOR RGBto565(0x35a5cf)
  #define TFT_BTOKMENU_COLOR RGBto565(0x3efff4)
#elif TFT_COLOR_THEME == TFT_COLOR_GREEN_THEME
  #define TFT_MARLINUI_COLOR 0xF794
  #define TFT_MARLINBG_COLOR 0x2BE7
  #define TFT_BTCANCEL_COLOR 0x962D
  #define TFT_BTARROWS_COLOR 0x5D0C
  #define TFT_BTOKMENU_COLOR 0xEF42
#else // default dark theme
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
#endif
