#include "TextParse.h"



unsigned short japanese_chars[ 256 ] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2000, // 0x40 - 0x4F
    0x0130, 0x0230, 0x1FFF, 0x0000, 0x0000, 0xFC30, 0x0000, 0x0000, 0x2620, 0x0000, 0x0000, 0x0000, 0x0C30, 0x0000, 0x3000, 0x3100, // 0x50 - 0x5F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4230, 0x4430, 0x4630, 0x4830, // 0x60 - 0x6F
    0x4A30, 0x4B30, 0x4C30, 0x4D30, 0x4F30, 0x5130, 0x5330, 0x5430, 0x5530, 0x5730, 0x5830, 0x0000, 0x5A30, 0x5B30, 0x5D30, 0x0000, // 0x70 - 0x7F
    0x5F30, 0x6030, 0x6130, 0x6330, 0x6430, 0x6630, 0x6730, 0x6830, 0x0000, 0x6A30, 0x6B30, 0x0000, 0x6D30, 0x6E30, 0x6F30, 0x7030, // 0x80 - 0x8F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7C30, 0x7E30, 0x7F30, 0x0000, 0x8230, 0x8330, 0x8430, 0x0000, 0x8830, 0x8930, 0x0000, // 0x90 - 0x9F
    0x8B30, 0x8C30, 0x8D30, 0x8F30, 0x9230, 0x9330, 0xA230, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0xB830, 0x0000, 0x0000, 0x0000, 0xC030, 0x0000, 0xC330, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x0000, 0x0000, 0xD030, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xE130, 0x0000, 0xE330, 0x0000, 0x0000, 0x0000, // 0xC0 - 0xCF
    0x0000, 0xEB30, 0x0000, 0x0000, 0xF330, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xBA4E, 0x0000, 0x0000, 0x0000, 0xFE5B, 0x0000, 0x0000, 0x7795, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



unsigned short japanese_chars_f8[ 256 ] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x60 - 0x6F
    0x7B30, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB130, 0x0000, 0x0000, 0x0000, 0x0000, // 0x70 - 0x7F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x80 - 0x8F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x004E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB65B, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



unsigned short japanese_chars_f9[ 256 ] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x0000, 0x095B, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x60 - 0x6F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x70 - 0x7F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x80 - 0x8F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5A9B, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



unsigned short japanese_chars_fa[ 256 ] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x0000, 0x0000, 0x0000, 0x0000, 0xBB59, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x60 - 0x6F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x70 - 0x7F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x80 - 0x8F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1D60, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xD453, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



unsigned short japanese_chars_fb[ 256 ] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0F5C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x60 - 0x6F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x70 - 0x7F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xF377, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x80 - 0x8F
    0x0000, 0x0000, 0x767D, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xCF65, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x6B5B, 0x0000, 0x0000, 0x5167, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



unsigned short japanese_chars_fc[ 256 ] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x60 - 0x6F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x70 - 0x7F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x80 - 0x8F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xE565, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0x745E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xB260, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



unsigned short japanese_chars_fd[ 256 ] = {
    // 0    1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3672, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x00 - 0x0F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x10 - 0x1F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x20 - 0x2F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xAE66, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x30 - 0x3F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x40 - 0x4F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x50 - 0x5F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x60 - 0x6F
    0x0000, 0x0000, 0x185A, 0x0000, 0x0000, 0x0E66, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x70 - 0x7F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x80 - 0x8F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0x90 - 0x9F
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xD869, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xA0 - 0xAF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xB0 - 0xBF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xC0 - 0xCF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xD0 - 0xDF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xE0 - 0xEF
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // 0xF0 - 0xFF
};



void
TextParse( Logger* export, File* file, const int offset )
{
    int data_offset = offset;
    std::vector< unsigned char > dialog;

    while( true )
    {
        u8 opcode = file->GetU8( data_offset );
        data_offset += 1;
        if( opcode == 0x00 )
        {
            export->LogW( "\n<End>\n" );
            break;
        }
        else if( opcode == 0x01 )
        {
            export->LogW( "\n" );
        }
        else if( opcode == 0x02 )
        {
            export->LogW( "\n<Window>\n" );
        }
        else if( opcode == 0x0f )
        {
            u8 sub_opcode = file->GetU8( data_offset );
            data_offset += 1;
            if( sub_opcode == 0x00 )
            {
                export->LogW( "<SpecialWait wait=\"" + HexToString( file->GetU8( data_offset ), 2, '0' ) + "\">" );
                data_offset += 1;
            }
            else if( sub_opcode == 0x01 )
            {
                export->LogW( "<SpecialLettersToRead number=\"" + HexToString( file->GetU8( data_offset ), 2, '0' ) + "\">" );
                data_offset += 1;
            }
            else if( sub_opcode == 0x02 )
            {
                export->LogW( "<SpecialWaitAndClose wait=\"" + HexToString( file->GetU8( data_offset ), 2, '0' ) + "\">" );
                data_offset += 1;
            }
            else if( sub_opcode == 0x05 )
            {
                export->LogW( "<SpecialCharacter char_id=\"" + HexToString( file->GetU8( data_offset ), 2, '0' ) + "\">" );
                data_offset += 1;
            }
            else
            {
                export->LogW( "<special>" + HexToString( sub_opcode, 2, '0' ) + "\n" );
                break;
            }
        }
        else if( opcode < 0xf8 )
        {
            if( japanese_chars[ opcode ] != 0x0000 )
            {
                dialog.push_back( japanese_chars[ opcode ] >> 8 );
                dialog.push_back( japanese_chars[ opcode ] & 0xff );
                export->Log( dialog );
                dialog.clear();
            }
            else
            {
                export->LogW( "[MISSING 0x" + HexToString( opcode, 2, '0' ) + "]" );
            }
        }
        else if( opcode == 0xf8 )
        {
            u8 sub_opcode = file->GetU8( data_offset );
            data_offset += 1;
            if( japanese_chars_f8[ sub_opcode ] != 0x0000 )
            {
                dialog.push_back( japanese_chars_f8[ sub_opcode ] >> 8 );
                dialog.push_back( japanese_chars_f8[ sub_opcode ] & 0xff );
                export->Log( dialog );
                dialog.clear();
            }
            else
            {
                export->LogW( "[MISSING 0xF8" + HexToString( sub_opcode, 2, '0' ) + "]" );
            }
        }
        else if( opcode == 0xf9 )
        {
            u8 sub_opcode = file->GetU8( data_offset );
            data_offset += 1;
            if( japanese_chars_f9[ sub_opcode ] != 0x0000 )
            {
                dialog.push_back( japanese_chars_f9[ sub_opcode ] >> 8 );
                dialog.push_back( japanese_chars_f9[ sub_opcode ] & 0xff );
                export->Log( dialog );
                dialog.clear();
            }
            else
            {
                export->LogW( "[MISSING 0xF9" + HexToString( sub_opcode, 2, '0' ) + "]" );
            }
        }
        else if( opcode == 0xfa )
        {
            u8 sub_opcode = file->GetU8( data_offset );
            data_offset += 1;
            if( japanese_chars_fa[ sub_opcode ] != 0x0000 )
            {
                dialog.push_back( japanese_chars_fa[ sub_opcode ] >> 8 );
                dialog.push_back( japanese_chars_fa[ sub_opcode ] & 0xff );
                export->Log( dialog );
                dialog.clear();
            }
            else
            {
                export->LogW( "[MISSING 0xFA" + HexToString( sub_opcode, 2, '0' ) + "]" );
            }
        }
        else if( opcode == 0xfb )
        {
            u8 sub_opcode = file->GetU8( data_offset );
            data_offset += 1;
            if( japanese_chars_fb[ sub_opcode ] != 0x0000 )
            {
                dialog.push_back( japanese_chars_fb[ sub_opcode ] >> 8 );
                dialog.push_back( japanese_chars_fb[ sub_opcode ] & 0xff );
                export->Log( dialog );
                dialog.clear();
            }
            else
            {
                export->LogW( "[MISSING 0xFB" + HexToString( sub_opcode, 2, '0' ) + "]" );
            }
        }
        else if( opcode == 0xfc )
        {
            u8 sub_opcode = file->GetU8( data_offset );
            data_offset += 1;
            if( japanese_chars_fc[ sub_opcode ] != 0x0000 )
            {
                dialog.push_back( japanese_chars_fc[ sub_opcode ] >> 8 );
                dialog.push_back( japanese_chars_fc[ sub_opcode ] & 0xff );
                export->Log( dialog );
                dialog.clear();
            }
            else
            {
                export->LogW( "[MISSING 0xFC" + HexToString( sub_opcode, 2, '0' ) + "]" );
            }
        }
        else if( opcode == 0xfd )
        {
            u8 sub_opcode = file->GetU8( data_offset );
            data_offset += 1;
            if( japanese_chars_fd[ sub_opcode ] != 0x0000 )
            {
                dialog.push_back( japanese_chars_fd[ sub_opcode ] >> 8 );
                dialog.push_back( japanese_chars_fd[ sub_opcode ] & 0xff );
                export->Log( dialog );
                dialog.clear();
            }
            else
            {
                export->LogW( "[MISSING 0xFD" + HexToString( sub_opcode, 2, '0' ) + "]" );
            }
        }
        else
        {
            export->Log( dialog );
            dialog.clear();
            export->LogW( "[MISSING 0x" + HexToString( opcode, 2, '0' ) + "]" );
            break;
        }
    }

    export->LogW( "\n" );
}