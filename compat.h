/*
 * header file for compatibility functions.
 *
 * Copyright 1992 by Gray Watson and the Antaire Corporation
 *
 * This file is part of the malloc-debug package.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library (see COPYING-LIB); if not, write to the
 * Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * The author of the program may be contacted at gray.watson@antaire.com
 *
 * $Id: compat.h,v 1.6 1993/03/31 00:35:40 gray Exp $
 */

#ifndef __COMPAT_H__
#define __COMPAT_H__

#include "malloc.h"			/* for IMPORT ... */

/*<<<<<<<<<<  The below prototypes are auto-generated by fillproto */

/*
 * copy LEN characters from FROM to TO
 */
#if __GNUC__ < 2
IMPORT	char	*memcpy(char * to, const char * from, int len);
#endif

/*
 * compare LEN characters, return -1,0,1 if STR1 is <,==,> STR2
 */
#if __GNUC__ < 2
IMPORT	int	memcmp(const char * str1, const char * str2, int len);
#endif

/*
 * set LEN characters in STR to character CH
 */
IMPORT	char	*memset(char * str, int ch, int len);

/*
 * find CH in STR by searching backwards through the string
 */
IMPORT	char	*strchr(const char * str, int ch);

/*
 * find CH in STR by searching backwards through the string
 */
IMPORT	char	*strrchr(const char * str, int ch);

/*
 * concatenate STR2 onto the end of STR1
 */
IMPORT	char	*strcat(char * str1, const char * str2);

/*
 * returns -1,0,1 on whether STR1 is <,==,> STR2
 */
IMPORT	int	strcmp(const char * str1, const char * str2);

/*
 * return the length in characters of STR
 */
IMPORT	int	strlen(const char * str);

/*
 * get the next token from STR (pass in NULL on the 2nd, 3rd, etc. calls),
 * tokens are a list of characters deliminated by a character from DELIM.
 * writes null into STR to end token.
 */
IMPORT	char	*strtok(char * str, char * delim);

/*<<<<<<<<<<   This is end of the auto-generated output from fillproto. */

#endif /* ! __COMPAT_H__ */
