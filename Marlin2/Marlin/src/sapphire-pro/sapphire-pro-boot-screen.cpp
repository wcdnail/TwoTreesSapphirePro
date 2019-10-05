
#include "../../inc/MarlinConfig.h"

#if HAS_GRAPHICAL_LCD && PIN_EXISTS(FSMC_CS) && defined(SAPPHIRE_PRO_BOOT_SCREEN)

#include "HAL_LCD_com_defines.h"
#include "ultralcd_DOGM.h"

#include "sapphire-pro-boot-screen.h"

#define SAPPHIRE_BOOTSCREEN_BMPCX 480
#define SAPPHIRE_BOOTSCREEN_BMPCY 320

#ifndef SAPPHIRE_BOOTSCREEN_BMP_BYTEWIDTH
  #define SAPPHIRE_BOOTSCREEN_BMP_BYTEWIDTH CEILING(SAPPHIRE_BOOTSCREEN_BMPCX, 8)
#endif
#ifndef SAPPHIRE_BOOTSCREEN_BMPHEIGHT
  #define SAPPHIRE_BOOTSCREEN_BMPHEIGHT (sizeof(sapphire_boot_screen) / (SAPPHIRE_BOOTSCREEN_BMP_BYTEWIDTH))
#endif

#if ENABLED(LCD_USE_DMA_FSMC)
  extern void LCD_IO_WriteSequence(uint16_t *data, uint16_t length);
  extern void LCD_IO_WriteSequence_Async(uint16_t *data, uint16_t length);
  extern void LCD_IO_WaitSequence_Async();
  extern void LCD_IO_WriteMultiple(uint16_t color, uint32_t count);
#endif

#define U8G_ESC_DATA(x) (uint8_t)(x >> 8), (uint8_t)(x & 0xFF)

#define LCD_COLUMN      0x2A   /* Colomn address register */
#define LCD_ROW         0x2B   /* Row address register */
#define LCD_WRITE_RAM   0x2C

#define BS_SAPPHIRE_FORECLR 0xFFE7
#define BS_SAPPHIRE_BACKCLR 0xF800

static const uint8_t seqFullScreen[] = {
  U8G_ESC_ADR(0), LCD_COLUMN, U8G_ESC_ADR(1), 0x00, 0x00, U8G_ESC_DATA(LCD_FULL_PIXEL_WIDTH),
  U8G_ESC_ADR(0), LCD_ROW,    U8G_ESC_ADR(1), 0x00, 0x00, U8G_ESC_DATA(LCD_FULL_PIXEL_HEIGHT),
  U8G_ESC_ADR(0), LCD_WRITE_RAM, U8G_ESC_ADR(1),
  U8G_ESC_END
};

extern void drawMonoImageTFT35(const uint8_t *data, u8g_t *u8g, u8g_dev_t *dev, uint16_t length, uint16_t height, uint16_t color);
extern uint8_t u8g_dev_tft_480x320_init(u8g_t *u8g, u8g_dev_t *dev);

void drawSapphireProBootscreen(void)
{
  u8g_t  *u8gptr = u8g.getU8g();
  u8g_dev_t *dev = &u8g_dev_tft_480x320_upscale_from_128x64;

  u8g_dev_tft_480x320_init(u8gptr, dev);

  u8g_WriteEscSeqP(u8gptr, dev, seqFullScreen);
  #ifdef LCD_USE_DMA_FSMC
    LCD_IO_WriteMultiple(BS_SAPPHIRE_BACKCLR, (LCD_FULL_PIXEL_WIDTH * LCD_FULL_PIXEL_HEIGHT));
  #else
    memset2(buffer, TFT_MARLINBG_COLOR, 160);
    for (uint16_t i = 0; i < 960; i++)
      u8g_WriteSequence(u8g, dev, 160, (uint8_t *)buffer);
  #endif
  u8g_WriteEscSeqP(u8gptr, dev, seqFullScreen);
  drawMonoImageTFT35(sapphireBootScreenPixmap, u8gptr, dev, SAPPHIRE_BOOTSCREEN_BMPCX, SAPPHIRE_BOOTSCREEN_BMPCY, BS_SAPPHIRE_FORECLR);
}

#endif