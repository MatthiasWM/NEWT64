/*------------------------------------------------------------------------*/
/**
 * @file	config.h
 * @brief   Configuration for MinGW
 *
 * Copyright (C) 2005 M.Nukui All rights reserved.
 */


#ifndef	CONFIG_H
#define	CONFIG_H

/* マクロ定義 */
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_MEMORY_H 1
#define HAVE_UNISTD_H 1
#undef HAVE_ENDIAN_H
#undef HAVE_MACHINE_ENDIAN_H
#undef HAVE_TERMIOS_H

#undef HAVE_LIBICONV
#undef HAVE_DLOPEN
#define HAVE_MMAP 1
#define HAVE_CHDIR 1
#define HAVE_GETCWD 1
#undef HAVE_GETPWNAM

#define __PLATFORM__ "mingw"
#define __DYLIBSUFFIX__ ".dll"
#define __LIBDIR__ ""

#undef __IPOD__

#include <string.h>
#include <ctype.h>

#define strcasecmp _stricmp
#define strncasecmp _strnicmp

static inline char *strcasestr(const char *s, const char *find) {
    char c, sc;
    size_t len;
    if ((c = *find++) != 0) {
        c = (char)tolower((unsigned char)c);
        len = strlen(find);
        do {
            do {
                if ((sc = *s++) == 0) return (NULL);
            } while ((char)tolower((unsigned char)sc) != c);
        } while (_strnicmp(s, find, len) != 0);
        s--;
    }
    return ((char *)s);
}

#endif /* CONFIG_H */
