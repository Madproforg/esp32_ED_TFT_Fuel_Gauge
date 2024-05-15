/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font C:/Users/iande/Documents/SquareLine/assets/Eurose Wide-Heavy.ttf -o C:/Users/iande/Documents/SquareLine/assets\ui_font_Eurose16.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_EUROSE16
#define UI_FONT_EUROSE16 1
#endif

#if UI_FONT_EUROSE16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xf8, 0x1f, 0x80,

    /* U+0022 "\"" */
    0xef, 0xee, 0xe6, 0xe6,

    /* U+0023 "#" */
    0x2, 0x30, 0x19, 0x83, 0xff, 0x83, 0x30, 0x8,
    0xc3, 0xff, 0xc1, 0x10, 0xc, 0xc0,

    /* U+0024 "$" */
    0x3, 0x0, 0xff, 0xef, 0xff, 0xf8, 0xc7, 0xe3,
    0x3, 0xff, 0xc7, 0xff, 0xc0, 0xc7, 0xe3, 0x1f,
    0x8c, 0x77, 0xff, 0x8f, 0xfc, 0x3, 0x0,

    /* U+0025 "%" */
    0x7c, 0x6, 0x31, 0x83, 0xc, 0x61, 0x83, 0x18,
    0xc0, 0xfe, 0x60, 0x1f, 0x33, 0xe0, 0x19, 0x8c,
    0xc, 0x63, 0x6, 0x18, 0xc3, 0x6, 0x31, 0x80,
    0xf8,

    /* U+0026 "&" */
    0x1f, 0xe0, 0x7f, 0xe0, 0xe1, 0xc1, 0xc3, 0x81,
    0xe0, 0xf, 0xe3, 0x38, 0xf6, 0x70, 0x7c, 0xe0,
    0x3c, 0xff, 0xfc, 0xff, 0x90,

    /* U+0027 "'" */
    0xff, 0xf0,

    /* U+0028 "(" */
    0x3f, 0xf9, 0xce, 0x73, 0x9c, 0xe7, 0x3c, 0xf3,
    0x80,

    /* U+0029 ")" */
    0xe7, 0x9e, 0x73, 0x9c, 0xe7, 0x39, 0xcf, 0xfe,
    0x0,

    /* U+002A "*" */
    0x18, 0x99, 0xff, 0x3c, 0x66, 0x0,

    /* U+002B "+" */
    0xc, 0x3, 0xf, 0xff, 0xff, 0xc, 0x3, 0x0,
    0xc0,

    /* U+002C "," */
    0xfd, 0xf0,

    /* U+002D "-" */
    0xff, 0xf0,

    /* U+002E "." */
    0xfc,

    /* U+002F "/" */
    0x0, 0x38, 0x1, 0x80, 0x18, 0x1, 0x80, 0x18,
    0x1, 0xc0, 0x1c, 0x0, 0xc0, 0xc, 0x0, 0xc0,
    0xc, 0x0, 0xe0, 0x6, 0x0, 0x0,

    /* U+0030 "0" */
    0x3f, 0xf3, 0xff, 0xef, 0x3, 0xf8, 0x7, 0xe0,
    0x1f, 0x80, 0x7e, 0x1, 0xf8, 0x7, 0xf0, 0x3d,
    0xff, 0xe3, 0xff, 0x0,

    /* U+0031 "1" */
    0x7, 0x8f, 0xde, 0xfe, 0x70, 0x38, 0x1c, 0xe,
    0x7, 0x3, 0x81, 0xc0, 0xe0,

    /* U+0032 "2" */
    0x3f, 0xc7, 0xff, 0xe0, 0x7e, 0x7, 0x0, 0xf1,
    0xfe, 0x7f, 0xcf, 0xc0, 0xe0, 0xf, 0xff, 0xff,
    0xf0,

    /* U+0033 "3" */
    0x3f, 0xe3, 0xff, 0xfc, 0xe, 0x0, 0x70, 0x7f,
    0x3, 0xf8, 0x0, 0xfc, 0x7, 0xe0, 0x3b, 0xff,
    0x87, 0xf0,

    /* U+0034 "4" */
    0x1, 0xf0, 0xf, 0xc0, 0xf7, 0x7, 0x9c, 0x38,
    0x71, 0xc1, 0xcf, 0xff, 0xff, 0xff, 0x0, 0x70,
    0x1, 0xc0, 0x7, 0x0,

    /* U+0035 "5" */
    0xff, 0xef, 0xfe, 0xe0, 0xf, 0xfc, 0xff, 0xee,
    0x7, 0x0, 0x70, 0x7, 0xe0, 0x7f, 0xfe, 0x7f,
    0xc0,

    /* U+0036 "6" */
    0x3f, 0xc7, 0xff, 0xe0, 0x7e, 0x0, 0xff, 0xcf,
    0xff, 0xf0, 0xfe, 0x7, 0xf0, 0xf7, 0xfe, 0x3f,
    0xc0,

    /* U+0037 "7" */
    0xff, 0xff, 0xff, 0x0, 0xf0, 0x1e, 0x1, 0xc0,
    0x3c, 0x7, 0x80, 0xf0, 0xe, 0x1, 0xe0, 0x3c,
    0x0,

    /* U+0038 "8" */
    0x7f, 0xcf, 0xff, 0xe0, 0x7e, 0x7, 0x7f, 0xf7,
    0xfe, 0xe0, 0x7e, 0x7, 0xe0, 0x7f, 0xff, 0x3f,
    0xc0,

    /* U+0039 "9" */
    0x3f, 0xcf, 0xfe, 0xe0, 0x7e, 0x7, 0xff, 0xf7,
    0xff, 0x0, 0x7e, 0x7, 0xe0, 0x77, 0xfe, 0x3f,
    0xc0,

    /* U+003A ":" */
    0xfc, 0x0, 0x3f,

    /* U+003B ";" */
    0xfc, 0x0, 0x3f, 0x7c,

    /* U+003C "<" */
    0x0, 0xe0, 0xfc, 0x7e, 0x7e, 0xf, 0x0, 0xfc,
    0x3, 0xf0, 0xf, 0x0, 0x60,

    /* U+003D "=" */
    0xff, 0x80, 0x3f, 0xe0,

    /* U+003E ">" */
    0xc0, 0x1f, 0x0, 0xfc, 0x7, 0xf0, 0x3e, 0x3f,
    0xbf, 0x87, 0x80, 0x80, 0x0,

    /* U+003F "?" */
    0x3f, 0xdf, 0xff, 0x83, 0xf0, 0x70, 0x1e, 0x1f,
    0x87, 0x80, 0xe0, 0x0, 0x3, 0x80, 0x70, 0x0,

    /* U+0040 "@" */
    0x1f, 0xf8, 0xff, 0xfb, 0x9f, 0x9e, 0x7f, 0x3c,
    0xc6, 0x79, 0x8c, 0xf3, 0x19, 0xe7, 0xff, 0xe7,
    0xbc, 0xff, 0xf0, 0xff, 0xc0,

    /* U+0041 "A" */
    0x7, 0xc0, 0xf, 0xc0, 0x3f, 0x80, 0x77, 0x81,
    0xe7, 0x3, 0x8f, 0xf, 0xe, 0x1f, 0xfe, 0x7f,
    0xfc, 0xe0, 0x3f, 0xc0, 0x38,

    /* U+0042 "B" */
    0xff, 0xf7, 0xff, 0xf8, 0xf, 0xc0, 0x7f, 0xff,
    0x7f, 0xfb, 0x80, 0xfc, 0x7, 0xe0, 0x3f, 0xff,
    0xff, 0xfc,

    /* U+0043 "C" */
    0x3f, 0xf1, 0xff, 0xef, 0x3, 0xb8, 0xe, 0xe0,
    0x3, 0x80, 0xe, 0x0, 0x38, 0xe, 0xe0, 0x39,
    0xff, 0xe3, 0xff, 0x0,

    /* U+0044 "D" */
    0xff, 0xf3, 0xff, 0xee, 0x3, 0xf8, 0x7, 0xe0,
    0x1f, 0x80, 0x7e, 0x1, 0xf8, 0x7, 0xe0, 0x3f,
    0xff, 0xef, 0xff, 0x0,

    /* U+0045 "E" */
    0xff, 0xff, 0xff, 0x80, 0x70, 0xf, 0xff, 0xff,
    0xf8, 0x7, 0x0, 0xe0, 0x1f, 0xff, 0xff, 0x80,

    /* U+0046 "F" */
    0xff, 0xff, 0xff, 0x80, 0x70, 0xf, 0xff, 0xff,
    0xf8, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x80, 0x0,

    /* U+0047 "G" */
    0x3f, 0xf1, 0xff, 0xff, 0x1, 0xf8, 0x0, 0xe0,
    0x3, 0x87, 0xfe, 0x1f, 0xf8, 0x7, 0xe0, 0x3d,
    0xff, 0xf3, 0xff, 0x80,

    /* U+0048 "H" */
    0xe0, 0x1f, 0x80, 0x7e, 0x1, 0xf8, 0x7, 0xff,
    0xff, 0xff, 0xfe, 0x1, 0xf8, 0x7, 0xe0, 0x1f,
    0x80, 0x7e, 0x1, 0xc0,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0x80,

    /* U+004A "J" */
    0x0, 0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1,
    0xc0, 0x3f, 0x7, 0xe0, 0xff, 0xfc, 0xfe, 0x0,

    /* U+004B "K" */
    0xe0, 0x7b, 0x87, 0xce, 0x3e, 0x39, 0xe0, 0xff,
    0x3, 0xf8, 0xe, 0x78, 0x38, 0xf0, 0xe1, 0xe3,
    0x83, 0xce, 0x7, 0xc0,

    /* U+004C "L" */
    0xe0, 0x1c, 0x3, 0x80, 0x70, 0xe, 0x1, 0xc0,
    0x38, 0x7, 0x0, 0xe0, 0x1f, 0xff, 0xff, 0x80,

    /* U+004D "M" */
    0xf8, 0xf, 0xfe, 0x7, 0xff, 0x7, 0xff, 0xc3,
    0xfe, 0xe3, 0xbf, 0x79, 0xdf, 0x9d, 0xcf, 0xce,
    0xe7, 0xe3, 0xe3, 0xf1, 0xf1, 0xf8, 0x70, 0xe0,

    /* U+004E "N" */
    0xfc, 0x1f, 0xf0, 0x7f, 0xe1, 0xfb, 0xc7, 0xef,
    0x1f, 0x9e, 0x7e, 0x3d, 0xf8, 0xf7, 0xe1, 0xff,
    0x83, 0xfe, 0x7, 0xc0,

    /* U+004F "O" */
    0x3f, 0xf1, 0xff, 0xef, 0x3, 0xf8, 0x7, 0xe0,
    0x1f, 0x80, 0x7e, 0x1, 0xf8, 0x7, 0xf0, 0x3d,
    0xff, 0xe3, 0xff, 0x0,

    /* U+0050 "P" */
    0xff, 0xe7, 0xff, 0xb8, 0xf, 0xc0, 0x7e, 0x3,
    0xff, 0xfb, 0xff, 0x9c, 0x0, 0xe0, 0x7, 0x0,
    0x38, 0x0,

    /* U+0051 "Q" */
    0x3f, 0xf0, 0xff, 0xf3, 0xc0, 0xf7, 0x0, 0xee,
    0x1, 0xdc, 0x23, 0xb8, 0x77, 0x70, 0xfe, 0xf0,
    0x7c, 0xff, 0xfc, 0xff, 0xc0,

    /* U+0052 "R" */
    0xff, 0xe7, 0xff, 0xf8, 0xf, 0xc0, 0x7e, 0x3,
    0xff, 0xfb, 0xff, 0xdc, 0x7, 0xe0, 0x3f, 0x1,
    0xf8, 0xe,

    /* U+0053 "S" */
    0x3f, 0xe7, 0xff, 0xf8, 0xf, 0xc0, 0xf, 0xfe,
    0x1f, 0xfc, 0x0, 0xfc, 0x7, 0xe0, 0x3f, 0xff,
    0xcf, 0xf8,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0xc1, 0xc0, 0xe, 0x0, 0x70,
    0x3, 0x80, 0x1c, 0x0, 0xe0, 0x7, 0x0, 0x38,
    0x1, 0xc0,

    /* U+0055 "U" */
    0xe0, 0x3f, 0x1, 0xf8, 0xf, 0xc0, 0x7e, 0x3,
    0xf0, 0x1f, 0x80, 0xfc, 0x7, 0xe0, 0x3b, 0xff,
    0x8f, 0xf0,

    /* U+0056 "V" */
    0xe0, 0x1f, 0xe0, 0x39, 0xc0, 0xf3, 0xc1, 0xc3,
    0x87, 0x87, 0x8e, 0x7, 0x3c, 0xf, 0x70, 0xf,
    0xe0, 0x1f, 0x80, 0x1f, 0x0,

    /* U+0057 "W" */
    0xe0, 0x78, 0x3f, 0xc3, 0xe0, 0xe7, 0xf, 0x83,
    0x9e, 0x37, 0x1e, 0x39, 0xdc, 0x70, 0xe7, 0x79,
    0xc3, 0xdc, 0xee, 0x7, 0xe3, 0xf8, 0x1f, 0x87,
    0xe0, 0x3e, 0x1f, 0x0, 0xf0, 0x3c, 0x0,

    /* U+0058 "X" */
    0x70, 0x1c, 0xf0, 0x78, 0xf1, 0xe0, 0xf7, 0x80,
    0xfe, 0x0, 0xf8, 0x3, 0xf8, 0xf, 0x78, 0x3c,
    0x78, 0xf0, 0x7b, 0xc0, 0x78,

    /* U+0059 "Y" */
    0x70, 0x1e, 0xf0, 0x78, 0xf1, 0xe0, 0xf7, 0x80,
    0xfe, 0x0, 0xf8, 0x0, 0xe0, 0x1, 0xc0, 0x3,
    0x80, 0x7, 0x0, 0xe, 0x0,

    /* U+005A "Z" */
    0xff, 0xff, 0xff, 0xc0, 0x3c, 0x3, 0xc0, 0x7c,
    0x7, 0x80, 0x78, 0x7, 0x80, 0x78, 0x7, 0xff,
    0xff, 0xfe,

    /* U+005B "[" */
    0xff, 0xf9, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xff,
    0x80,

    /* U+005C "\\" */
    0xc0, 0x3, 0x0, 0xc, 0x0, 0x70, 0x1, 0xc0,
    0x6, 0x0, 0x18, 0x0, 0x60, 0x1, 0x80, 0xe,
    0x0, 0x38, 0x0, 0xc0, 0x3, 0x0,

    /* U+005D "]" */
    0xff, 0xce, 0x73, 0x9c, 0xe7, 0x39, 0xcf, 0xff,
    0x80,

    /* U+005E "^" */
    0xf, 0x1, 0xf8, 0x39, 0xc3, 0x8c, 0x70, 0xe0,

    /* U+005F "_" */
    0xff, 0xff, 0xff,

    /* U+0060 "`" */
    0xc3, 0x80,

    /* U+0061 "a" */
    0x3f, 0xcf, 0xff, 0xc3, 0xbf, 0xff, 0xff, 0xc1,
    0xff, 0xfb, 0xf7,

    /* U+0062 "b" */
    0xe0, 0x1c, 0x3, 0x80, 0x77, 0xcf, 0xff, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xff, 0xff, 0xbe, 0x0,

    /* U+0063 "c" */
    0x3f, 0xbf, 0xfe, 0x1f, 0x80, 0xe0, 0x38, 0x7f,
    0xfc, 0xfc,

    /* U+0064 "d" */
    0x0, 0xe0, 0x1c, 0x3, 0x9f, 0x7f, 0xff, 0xc1,
    0xf8, 0x3f, 0x7, 0xe0, 0xff, 0xfc, 0xfb, 0x80,

    /* U+0065 "e" */
    0x3f, 0x9f, 0xfb, 0x83, 0xff, 0xff, 0xff, 0xc1,
    0xdf, 0xf9, 0xfe,

    /* U+0066 "f" */
    0x3e, 0xfd, 0xc7, 0xff, 0xee, 0x1c, 0x38, 0x70,
    0xe1, 0xc0,

    /* U+0067 "g" */
    0x3e, 0xff, 0xff, 0x87, 0xf0, 0x7e, 0xf, 0xc3,
    0xdf, 0xf9, 0xf7, 0xe0, 0xef, 0xfc, 0xfe, 0x0,

    /* U+0068 "h" */
    0xe0, 0x38, 0xe, 0x3, 0xbe, 0xff, 0xf8, 0x7e,
    0x1f, 0x87, 0xe1, 0xf8, 0x7e, 0x1c,

    /* U+0069 "i" */
    0xfc, 0x7f, 0xff, 0xff, 0x80,

    /* U+006A "j" */
    0x77, 0x7, 0x77, 0x77, 0x77, 0x77, 0xfe,

    /* U+006B "k" */
    0xe0, 0x1c, 0x3, 0x80, 0x71, 0xce, 0x71, 0xdc,
    0x3f, 0x7, 0xf0, 0xef, 0x1c, 0xf3, 0x8f, 0x0,

    /* U+006C "l" */
    0xff, 0xff, 0xff, 0xff, 0x80,

    /* U+006D "m" */
    0xef, 0x9f, 0x7f, 0xff, 0xf8, 0x70, 0xfc, 0x38,
    0x7e, 0x1c, 0x3f, 0xe, 0x1f, 0x87, 0xf, 0xc3,
    0x87,

    /* U+006E "n" */
    0xef, 0xbf, 0xfe, 0x1f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87,

    /* U+006F "o" */
    0x3f, 0x9f, 0xff, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xff, 0xf9, 0xfc,

    /* U+0070 "p" */
    0xef, 0x9f, 0xff, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xff, 0xf7, 0x7c, 0xe0, 0x1c, 0x3, 0x80, 0x0,

    /* U+0071 "q" */
    0x3e, 0xff, 0xff, 0x83, 0xf0, 0x7e, 0xf, 0xc1,
    0xff, 0xf9, 0xf7, 0x0, 0xe0, 0x1c, 0x3, 0x80,

    /* U+0072 "r" */
    0xef, 0x7f, 0xf8, 0xfc, 0xe, 0x7, 0x3, 0x81,
    0xc0,

    /* U+0073 "s" */
    0x7f, 0xbf, 0xee, 0x1b, 0xfe, 0x7f, 0xf8, 0x7f,
    0xfd, 0xfe,

    /* U+0074 "t" */
    0x38, 0xe, 0xf, 0xfb, 0xfe, 0x38, 0xe, 0x3,
    0x80, 0xe7, 0x3f, 0xc7, 0xe0,

    /* U+0075 "u" */
    0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0xe1, 0xf8, 0xff,
    0xfd, 0xf7,

    /* U+0076 "v" */
    0xe0, 0xec, 0x39, 0xc7, 0x39, 0xc3, 0xb8, 0x77,
    0x7, 0xc0, 0xf8,

    /* U+0077 "w" */
    0xe3, 0x86, 0x63, 0xce, 0x73, 0xce, 0x76, 0xcc,
    0x76, 0x6c, 0x3e, 0x7c, 0x3e, 0x78, 0x3c, 0x78,

    /* U+0078 "x" */
    0x71, 0xc7, 0x70, 0xfc, 0xf, 0x81, 0xf0, 0x77,
    0x1c, 0xf7, 0x8f,

    /* U+0079 "y" */
    0xe1, 0xdc, 0x39, 0xc7, 0x39, 0xc3, 0xb8, 0x77,
    0x7, 0xc0, 0xf8, 0xf, 0x1, 0xc0, 0xf8, 0x1e,
    0x0,

    /* U+007A "z" */
    0xff, 0xff, 0xc1, 0xc3, 0xc3, 0x87, 0x83, 0xff,
    0xff,

    /* U+007B "{" */
    0x1f, 0x3f, 0x38, 0x38, 0x38, 0x38, 0xf8, 0xf8,
    0x38, 0x38, 0x38, 0x38, 0x3f, 0x1f,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xf8, 0xfc, 0x1c, 0x1c, 0x1c, 0x1c, 0x1f, 0x1f,
    0x1c, 0x1c, 0x1c, 0x1c, 0xfc, 0xf8,

    /* U+007E "~" */
    0x3c, 0x6f, 0xfd, 0x8e, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 109, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 107, .box_w = 3, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 6, .adv_w = 152, .box_w = 8, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 10, .adv_w = 264, .box_w = 14, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 24, .adv_w = 245, .box_w = 14, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 47, .adv_w = 314, .box_w = 18, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 271, .box_w = 15, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 81, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 95, .adv_w = 121, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 104, .adv_w = 121, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 113, .adv_w = 245, .box_w = 8, .box_h = 6, .ofs_x = 4, .ofs_y = 5},
    {.bitmap_index = 119, .adv_w = 195, .box_w = 10, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 128, .adv_w = 87, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 130, .adv_w = 92, .box_w = 6, .box_h = 2, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 132, .adv_w = 82, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 237, .box_w = 13, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 155, .adv_w = 245, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 175, .adv_w = 245, .box_w = 9, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 188, .adv_w = 245, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 245, .box_w = 13, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 223, .adv_w = 245, .box_w = 14, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 245, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 244, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 245, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 244, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 311, .adv_w = 245, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 82, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 82, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 335, .adv_w = 195, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 348, .adv_w = 165, .box_w = 9, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 352, .adv_w = 195, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 365, .adv_w = 207, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 381, .adv_w = 273, .box_w = 15, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 246, .box_w = 15, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 249, .box_w = 13, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 242, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 461, .adv_w = 262, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 481, .adv_w = 215, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 202, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 513, .adv_w = 252, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 533, .adv_w = 267, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 553, .adv_w = 96, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 558, .adv_w = 203, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 574, .adv_w = 248, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 594, .adv_w = 196, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 323, .box_w = 17, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 254, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 654, .adv_w = 249, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 674, .adv_w = 238, .box_w = 13, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 692, .adv_w = 266, .box_w = 15, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 713, .adv_w = 250, .box_w = 13, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 731, .adv_w = 233, .box_w = 13, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 749, .adv_w = 204, .box_w = 13, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 767, .adv_w = 262, .box_w = 13, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 785, .adv_w = 235, .box_w = 15, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 806, .adv_w = 350, .box_w = 22, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 837, .adv_w = 241, .box_w = 15, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 858, .adv_w = 232, .box_w = 15, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 879, .adv_w = 225, .box_w = 13, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 897, .adv_w = 121, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 906, .adv_w = 237, .box_w = 13, .box_h = 13, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 928, .adv_w = 121, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 937, .adv_w = 195, .box_w = 12, .box_h = 5, .ofs_x = 0, .ofs_y = 10},
    {.bitmap_index = 945, .adv_w = 195, .box_w = 12, .box_h = 2, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 948, .adv_w = 195, .box_w = 5, .box_h = 2, .ofs_x = 4, .ofs_y = 9},
    {.bitmap_index = 950, .adv_w = 205, .box_w = 11, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 961, .adv_w = 206, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 977, .adv_w = 191, .box_w = 10, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 987, .adv_w = 206, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1003, .adv_w = 198, .box_w = 11, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1014, .adv_w = 121, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1024, .adv_w = 206, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1040, .adv_w = 208, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1054, .adv_w = 82, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1059, .adv_w = 78, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1066, .adv_w = 187, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1082, .adv_w = 87, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1087, .adv_w = 300, .box_w = 17, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1104, .adv_w = 189, .box_w = 10, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1114, .adv_w = 202, .box_w = 11, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1125, .adv_w = 207, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1141, .adv_w = 207, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1157, .adv_w = 164, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1166, .adv_w = 193, .box_w = 10, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1176, .adv_w = 147, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1189, .adv_w = 206, .box_w = 10, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1199, .adv_w = 171, .box_w = 11, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1210, .adv_w = 252, .box_w = 16, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1226, .adv_w = 173, .box_w = 11, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1237, .adv_w = 168, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1254, .adv_w = 165, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1263, .adv_w = 195, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1277, .adv_w = 195, .box_w = 3, .box_h = 14, .ofs_x = 5, .ofs_y = -3},
    {.bitmap_index = 1283, .adv_w = 195, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1297, .adv_w = 184, .box_w = 11, .box_h = 3, .ofs_x = 0, .ofs_y = 5}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_Eurose16 = {
#else
lv_font_t ui_font_Eurose16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_EUROSE16*/

