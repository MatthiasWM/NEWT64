/**
 * @file	NewtIconv.c
 * @brief   文字コード処理（libiconv使用）
 *
 * @author  M.Nukui
 * @date	2005-07-17
 *
 * Copyright (C) 2005 M.Nukui All rights reserved.
 */


/* ヘッダファイル */
#include "NewtIconv.h"


static uint32_t getUtf8Char(uint8_t const** sp)
{
    const uint8_t* s = *sp;
    uint32_t c = *s++;
    if (c < 0x80) {
        ;
    } else if (c < 0xE0) {
        uint32_t c1 = *s++;
        c = ((c & 0x1F) << 6) | (c1 & 0x3F);
    } else if (c < 0xF0) {
        uint32_t c1 = *s++;
        uint32_t c2 = *s++;
        c = ((c & 0x0F) << 12) | ((c1 & 0x3F) << 6) | (c2 & 0x3F);
    } else if (c < 0xF8) {
        uint32_t c1 = *s++;
        uint32_t c2 = *s++;
        uint32_t c3 = *s++;
        c = ((c & 0x07) << 18) | ((c1 & 0x3F) << 12) | ((c2 & 0x3F) << 6) | (c3 & 0x3F);
    } else {
        c = '?';
    }
    *sp = s;
    return c;
}


static void putUtf16Char(uint8_t** dp, uint32_t c)
{
    uint8_t* d = *dp;
    if (c > 0x10FFFF)
        c = '?';
    if (c < 0x10000) {
        *d++ = c >> 8;
        *d++ = c;
    } else {
        uint16_t c1 = ((c - 0x10000) >> 10) + 0xD800;
        *d++ = c1 >> 8;
        *d++ = c1;
        uint16_t c2 = ((c - 0x10000) & 0x03FF) + 0xDC00;
        *d++ = c2 >> 8;
        *d++ = c2;
    }
    *dp = d;
}


static uint32_t getUtf16Char(uint8_t const** sp)
{
    uint8_t const* s = *sp;
    uint32_t c = (s[0] << 8) | s[1]; s += 2;
    if ((c & 0xFC00) == 0xD800) {
        uint32_t c2 = (s[0] << 8) | s[1]; s += 2;
        c = 0x10000 + ((c - 0xD800) << 10) + (c2 - 0xDC00);
    }
    *sp = s;
    return c;
}


static void putUtf8Char(uint8_t** dp, uint32_t c)
{
    uint8_t* d = *dp;
    if (c > 0x10FFFF)
        c = '?';
    if (c < 128) {
        *d++ = c;
    } else if (c < 2048) {
        *d++ = 0xC0 | (c >> 6);
        *d++ = 0x80 | (c & 0x3F);
    } else if (c < 65536) {
        *d++ = 0xE0 | (c >> 12);
        *d++ = 0x80 | ((c >> 6) & 0x3F);
        *d++ = 0x80 | (c & 0x3F);
    } else {
        *d++ = 0xF0 | (c >> 18);
        *d++ = 0x80 | ((c >> 12) & 0x3F);
        *d++ = 0x80 | ((c >> 6) & 0x3F);
        *d++ = 0x80 | (c & 0x3F);
    }
    *dp = d;
}


/** 
 * Read utf-8 text and convert to utf-16
 *
 * @param src[in] utf-8 string to convert
 * @param srclen[in] length of string in bytes to convert
 * @param dstlenp[out] length of utf-16 string in bytes
 *
 * @return converted string
 *
 * @note Converted character string must be freed by the caller
 */
char* NewtUtf8To16(const char* src, size_t srclen, size_t* dstlenp)
{
    uint8_t* dBuffer = (uint8_t*)malloc(srclen * 4);
    uint8_t* d = dBuffer;
    const uint8_t* sBuffer = (uint8_t*)src;
    const uint8_t* s = sBuffer;

    while (s - sBuffer < srclen) {
        uint32_t c = getUtf8Char(&s);
        putUtf16Char(&d, c);
    }
    size_t n = d - dBuffer;
    *d++ = 0;
    *d++ = 0;
    *dstlenp = n;
    return realloc(dBuffer, n + 2);
}



/**
 * Read utf-16 text and convert to utf-8
 *
 * @param src[in] utf-16 string to convert
 * @param srclen[in] length of string in bytes to convert
 * @param dstlenp[out] length of utf-8 string in bytes
 *
 * @return converted string
 *
 * @note Converted character string must be freed by the caller
 */
char* NewtUtf16To8(const char* src, size_t srclen, size_t* dstlenp)
{
    uint8_t* dBuffer = (uint8_t*)malloc(srclen * 2);
    uint8_t* d = dBuffer;
    const uint8_t* sBuffer = (uint8_t*)src;
    const uint8_t* s = sBuffer;

    while (s - sBuffer < srclen) {
        uint32_t c = getUtf16Char(&s);
        putUtf8Char(&d, c);
    }
    size_t n = d - dBuffer;
    *d++ = 0;
    *dstlenp = n;
    return realloc(dBuffer, n + 1);
}

