/*
 * sh1106_font.h
 *
 *  Created on: 28 jan. 2025
 *      Author: Ludo
 */

#ifndef __SH1106_FONT_H__
#define __SH1106_FONT_H__

#ifndef SH1106_DRIVER_DISABLE_FLAGS_FILE
#include "sh1106_driver_flags.h"
#endif
#include "types.h"

#ifndef SH1106_DRIVER_DISABLE

/*** SH1106 FONT macros ***/

#define SH1106_FONT_ASCII_TABLE_SIZE    128
#define SH1106_FONT_ASCII_TABLE_OFFSET  32
#define SH1106_FONT_TABLE_SIZE          (SH1106_FONT_ASCII_TABLE_SIZE - SH1106_FONT_ASCII_TABLE_OFFSET)
#define SH1106_FONT_CHAR_WIDTH_PIXELS   6

/*** SH1106_FONT global variables ***/

extern const uint8_t SH1106_FONT[SH1106_FONT_TABLE_SIZE][SH1106_FONT_CHAR_WIDTH_PIXELS];

#endif /* SH1106_DRIVER_DISABLE */

#endif /* __SH1106_FONT_H__ */
