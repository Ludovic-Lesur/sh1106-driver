/*
 * sh1106_font.c
 *
 *  Created on: 28 jan. 2025
 *      Author: Ludo
 */

#include "sh1106_font.h"

#ifndef SH1106_DRIVER_DISABLE_FLAGS_FILE
#include "sh1106_driver_flags.h"
#endif
#include "types.h"

#ifndef SH1106_DRIVER_DISABLE

/*** FONT local macros ***/

#define SH1106_FONT_CHAR_NULL                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
#define SH1106_FONT_CHAR_PERCENT                {0x61, 0x30, 0x1C, 0x06, 0x43, 0x00}
#define SH1106_FONT_CHAR_ARROW_TOP              {0x30, 0x3C, 0x3F, 0x3C, 0x30, 0x00}
#define SH1106_FONT_CHAR_ARROW_BOTTOM           {0x03, 0x0F, 0x3F, 0x0F, 0x03, 0x00}
#define SH1106_FONT_CHAR_PARENTHESIS_OPEN       {0x1C, 0x36, 0x63, 0x41, 0x41, 0x00}
#define SH1106_FONT_CHAR_PARENTHESIS_CLOSE      {0x41, 0x41, 0x63, 0x36, 0x1C, 0x00}
#define SH1106_FONT_CHAR_STAR                   {0x08, 0x1C, 0x3E, 0x1C, 0x08, 0x00}
#define SH1106_FONT_CHAR_DASH                   {0x08, 0x08, 0x08, 0x08, 0x08, 0x00}
#define SH1106_FONT_CHAR_DOT                    {0x00, 0x00, 0x60, 0x60, 0x00, 0x00}
#define SH1106_FONT_CHAR_SLASH                  {0x00, 0x70, 0x1C, 0x07, 0x00, 0x00}
#define SH1106_FONT_CHAR_0                      {0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00}
#define SH1106_FONT_CHAR_1                      {0x44, 0x42, 0x7F, 0x40, 0x40, 0x00}
#define SH1106_FONT_CHAR_2                      {0x62, 0x73, 0x59, 0x4B, 0x4E, 0x00}
#define SH1106_FONT_CHAR_3                      {0x22, 0x41, 0x49, 0x6B, 0x3E, 0x00}
#define SH1106_FONT_CHAR_4                      {0x38, 0x2C, 0x26, 0x73, 0x21, 0x00}
#define SH1106_FONT_CHAR_5                      {0x4F, 0x49, 0x49, 0x49, 0x79, 0x00}
#define SH1106_FONT_CHAR_6                      {0x7F, 0x49, 0x49, 0x49, 0x79, 0x00}
#define SH1106_FONT_CHAR_7                      {0x61, 0x31, 0x19, 0x0D, 0x07, 0x00}
#define SH1106_FONT_CHAR_8                      {0x7F, 0x49, 0x49, 0x49, 0x7F, 0x00}
#define SH1106_FONT_CHAR_9                      {0x4F, 0x49, 0x49, 0x49, 0x7F, 0x00}
#define SH1106_FONT_CHAR_INFERIOR               {0x08, 0x1C, 0x1C, 0x3E, 0x7F, 0x00}
#define SH1106_FONT_CHAR_EQUAL                  {0x24, 0x24, 0x24, 0x24, 0x24, 0x00}
#define SH1106_FONT_CHAR_SUPERIOR               {0x7F, 0x3E, 0x1C, 0x1C, 0x08, 0x00}
#define SH1106_FONT_CHAR_A                      {0x7E, 0x09, 0x09, 0x09, 0x7E, 0x00}
#define SH1106_FONT_CHAR_B                      {0x7F, 0x49, 0x49, 0x49, 0x3E, 0x00}
#define SH1106_FONT_CHAR_C                      {0x7F, 0x41, 0x41, 0x41, 0x41, 0x00}
#define SH1106_FONT_CHAR_D                      {0x41, 0x41, 0x7F, 0x41, 0x7F, 0x00}
#define SH1106_FONT_CHAR_E                      {0x7F, 0x49, 0x49, 0x49, 0x41, 0x00}
#define SH1106_FONT_CHAR_F                      {0x7F, 0x09, 0x09, 0x09, 0x01, 0x00}
#define SH1106_FONT_CHAR_G                      {0x7F, 0x41, 0x49, 0x49, 0x79, 0x00}
#define SH1106_FONT_CHAR_H                      {0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00}
#define SH1106_FONT_CHAR_I                      {0x41, 0x41, 0x7F, 0x41, 0x41, 0x00}
#define SH1106_FONT_CHAR_J                      {0x61, 0x41, 0x61, 0x7F, 0x01, 0x00}
#define SH1106_FONT_CHAR_K                      {0x7F, 0x08, 0x1E, 0x33, 0x61, 0x00}
#define SH1106_FONT_CHAR_L                      {0x7F, 0x40, 0x40, 0x40, 0x40, 0x00}
#define SH1106_FONT_CHAR_M                      {0x7F, 0x06, 0x0C, 0x06, 0x7F, 0x00}
#define SH1106_FONT_CHAR_N                      {0x7F, 0x06, 0x1C, 0x30, 0x7F, 0x00}
#define SH1106_FONT_CHAR_O                      {0x7F, 0x41, 0x41, 0x41, 0x7F, 0x00}
#define SH1106_FONT_CHAR_P                      {0x7F, 0x09, 0x09, 0x09, 0x0F, 0x00}
#define SH1106_FONT_CHAR_Q                      {0x7F, 0x41, 0x51, 0x61, 0x7F, 0x00}
#define SH1106_FONT_CHAR_R                      {0x7F, 0x19, 0x39, 0x69, 0x4F, 0x00}
#define SH1106_FONT_CHAR_S                      {0x6F, 0x49, 0x49, 0x49, 0x7B, 0x00}
#define SH1106_FONT_CHAR_T                      {0x01, 0x01, 0x7F, 0x01, 0x01, 0x00}
#define SH1106_FONT_CHAR_U                      {0x7F, 0x40, 0x40, 0x40, 0x7F, 0x00}
#define SH1106_FONT_CHAR_V                      {0x1F, 0x30, 0x60, 0x30, 0x1F, 0x00}
#define SH1106_FONT_CHAR_W                      {0x7F, 0x40, 0x70, 0x40, 0x7F, 0x00}
#define SH1106_FONT_CHAR_X                      {0x63, 0x36, 0x1C, 0x36, 0x63, 0x00}
#define SH1106_FONT_CHAR_Y                      {0x07, 0x0C, 0x78, 0x0C, 0x07, 0x00}
#define SH1106_FONT_CHAR_Z                      {0x71, 0x59, 0x4D, 0x47, 0x43, 0x00}
#define SH1106_FONT_CHAR_d                      {0x78, 0x48, 0x48, 0x48, 0x7F, 0X00}
#define SH1106_FONT_CHAR_m                      {0x78, 0x08, 0x78, 0x08, 0x78, 0x00}
#define SH1106_FONT_CHAR_s                      {0x5C, 0x54, 0x54, 0x54, 0x74, 0x00}
#define SH1106_FONT_CHAR_u                      {0x78, 0x40, 0x40, 0x40, 0x78, 0x00}
#define SH1106_FONT_CHAR_x                      {0x44, 0x28, 0x10, 0x28, 0x44, 0x00}
#define SH1106_FONT_CHAR_z                      {0x44, 0x64, 0x74, 0x5C, 0x4C, 0x00}
#define SH1106_FONT_CHAR_BRACKET_OPEN           {0x7F, 0x41, 0x41, 0x41, 0x00, 0x00}
#define SH1106_FONT_DEGREES                     {0x00, 0x0F, 0x09, 0x09, 0x0F, 0x00}
#define SH1106_FONT_CHAR_BRACKET_CLOSE          {0x00, 0x41, 0x41, 0x41, 0x7F, 0x00}

/*** FONT global variables ***/

const uint8_t SH1106_FONT[SH1106_FONT_TABLE_SIZE][SH1106_FONT_CHAR_WIDTH_PIXELS] = {
    SH1106_FONT_CHAR_NULL, // 0x20
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_PERCENT,
    SH1106_FONT_CHAR_NULL, // 0x26
    SH1106_FONT_CHAR_ARROW_TOP,
    SH1106_FONT_CHAR_PARENTHESIS_OPEN,
    SH1106_FONT_CHAR_PARENTHESIS_CLOSE,
    SH1106_FONT_CHAR_STAR,
    SH1106_FONT_CHAR_NULL, // 0x2B
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_DASH,
    SH1106_FONT_CHAR_DOT,
    SH1106_FONT_CHAR_SLASH, // 0x2F
    SH1106_FONT_CHAR_0,
    SH1106_FONT_CHAR_1,
    SH1106_FONT_CHAR_2,
    SH1106_FONT_CHAR_3,
    SH1106_FONT_CHAR_4,
    SH1106_FONT_CHAR_5,
    SH1106_FONT_CHAR_6,
    SH1106_FONT_CHAR_7,
    SH1106_FONT_CHAR_8,
    SH1106_FONT_CHAR_9,
    SH1106_FONT_CHAR_NULL, // 0x3A
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_INFERIOR,
    SH1106_FONT_CHAR_EQUAL,
    SH1106_FONT_CHAR_SUPERIOR,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_A,
    SH1106_FONT_CHAR_B,
    SH1106_FONT_CHAR_C,
    SH1106_FONT_CHAR_D,
    SH1106_FONT_CHAR_E,
    SH1106_FONT_CHAR_F,
    SH1106_FONT_CHAR_G,
    SH1106_FONT_CHAR_H,
    SH1106_FONT_CHAR_I,
    SH1106_FONT_CHAR_J,
    SH1106_FONT_CHAR_K,
    SH1106_FONT_CHAR_L,
    SH1106_FONT_CHAR_M,
    SH1106_FONT_CHAR_N,
    SH1106_FONT_CHAR_O,
    SH1106_FONT_CHAR_P,
    SH1106_FONT_CHAR_Q,
    SH1106_FONT_CHAR_R,
    SH1106_FONT_CHAR_S,
    SH1106_FONT_CHAR_T,
    SH1106_FONT_CHAR_U,
    SH1106_FONT_CHAR_V,
    SH1106_FONT_CHAR_W,
    SH1106_FONT_CHAR_X,
    SH1106_FONT_CHAR_Y,
    SH1106_FONT_CHAR_Z,
    SH1106_FONT_CHAR_BRACKET_OPEN,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_BRACKET_CLOSE,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_ARROW_BOTTOM,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_d,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_m,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_s,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_u,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_x,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_z,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_DEGREES,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL,
    SH1106_FONT_CHAR_NULL
};

#endif /* SH1106_DRIVER_DISABLE */
