/**
 * TFT Color scheme constants
 * MNi 10.2019
 * 
 */

#pragma once

#define TFT_THEME_UNDEF   -1
#define TFT_BLACK_THEME   0
#define TFT_BLUE_THEME    1

#define TFT_THEME         TFT_BLACK_THEME

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

#if TFT_THEME == TFT_BLACK_THEME
  #define TFT_MARLINUI_COLOR 0x04DF
  #define TFT_MARLINBG_COLOR COLOR_BLACK
  #define TFT_BTCANCEL_COLOR 0xE0E4
  #define TFT_BTARROWS_COLOR 0x01EC
  #define TFT_BTOKMENU_COLOR 0xF7CC
#elif TFT_THEME == TFT_BLUE_THEME
  #define TFT_MARLINUI_COLOR COLOR_SILVER
  #define TFT_MARLINBG_COLOR 0x01F4
  #define TFT_BTCANCEL_COLOR COLOR_MAGENTA
  #define TFT_BTARROWS_COLOR COLOR_AQUA
  #define TFT_BTOKMENU_COLOR COLOR_YELLOW
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
