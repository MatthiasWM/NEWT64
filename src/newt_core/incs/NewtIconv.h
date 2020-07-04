/*------------------------------------------------------------------------*/
/**
 * @file	NewtIconv.h
 * @brief   文字コード処理（libiconv使用）
 *
 * @author  M.Nukui
 * @date	2005-07-17
 *
 * Copyright (C) 2005 M.Nukui All rights reserved.
 */


#ifndef	NEWTICONV_H
#define	NEWTICONV_H


/* ヘッダファイル */
#include "NewtType.h"


#ifdef __cplusplus
extern "C" {
#endif

char *      NewtUtf8To16(const char* src, size_t srclen, size_t* dstlenp);
char *      NewtUtf16To8(const char* src, size_t srclen, size_t* dstlenp);

#ifdef __cplusplus
}
#endif

#endif /* NEWTICONV_H */
