/*
 * Defines for low level memory management routines
 *
 * Copyright 1999 by Gray Watson
 *
 * This file is part of the dmalloc package.
 *
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies, and that the name of Gray Watson not be used in advertising
 * or publicity pertaining to distribution of the document or software
 * without specific, written prior permission.
 *
 * Gray Watson makes no representations about the suitability of the
 * software described herein for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * The author may be contacted via http://www.dmalloc.com/
 *
 * $Id: chunk.h,v 1.55 1999/03/07 23:05:40 gray Exp $
 */

#ifndef __CHUNK_H__
#define __CHUNK_H__

/* some argument defines */
#define CHUNK_PNT_EXACT		BIT_FLAG(0)	/* pointer must be on block */
#define CHUNK_PNT_LOOSE		BIT_FLAG(1)	/* looser checking */
#define CHUNK_PNT_NULL		BIT_FLAG(2)	/* watch for null char */

/*<<<<<<<<<<  The below prototypes are auto-generated by fillproto */

/*
 * Startup the low level malloc routines
 */
extern
int	_chunk_startup(void);

/*
 * Describe pnt from its FILE, LINE into BUF.  Returns BUF.
 */
extern
char	*_chunk_desc_pnt(char *buf, const int buf_size,
			const char *file, const unsigned int line);

/*
 * Run extensive tests on the entire heap
 */
extern
int	_chunk_check(void);

/*
 * Run extensive tests on PNT from FUNC. test PNT HOW_MUCH of MIN_SIZE
 * (or 0 if unknown).  CHECK is flags for types of checking (see
 * chunk.h).  returns [NO]ERROR
 */
extern
int	_chunk_pnt_check(const char *func, const void *pnt,
			 const int check, const int min_size);

/*
 * return some information associated with PNT, returns [NO]ERROR
 */
extern
int	_chunk_read_info(const void *pnt, unsigned int *size_p,
			 unsigned int *alloc_size_p, char **file_p,
			 unsigned int *line_p, void **ret_attr_p,
			 const char *where, unsigned long **seen_cp,
			 int *valloc_bp);

/*
 * Log the heap structure plus information on the blocks if necessary
 */
extern
void	_chunk_log_heap_map(void);

/*
 * Get a SIZE chunk of memory for FILE at LINE.  If CALLOC_B then
 * count this as a calloc not a malloc call.  If REALLOC_B then don't
 * count it as a malloc call.  If ALIGNMENT is greater than 0 then try
 * to align the returned block.
 */
extern
void	*_chunk_malloc(const char *file, const unsigned int line,
		       const unsigned long size, const int calloc_b,
		       const int realloc_b, const unsigned int alignment);

/*
 * Frees PNT from the heap.  REALLOC_B set if realloc is freeing a
 * pointer so doing count it as a free.  Returns FREE_ERROR or
 * FREE_NOERROR.
 *
 * NOTE: should be above _chunk_realloc which calls it.
 */
extern
int	_chunk_free(const char *file, const unsigned int line, void *pnt,
		    const int realloc_b);

/*
 * Reallocate a section of memory
 */
extern
void	*_chunk_realloc(const char *file, const unsigned int line,
			void *old_p, unsigned long new_size,
			const int recalloc_b);

/*
 * Log present free and used lists
 */
extern
void	_chunk_list_count(void);

/*
 * Log statistics on the heap
 */
extern
void	_chunk_stats(void);

/*
 * Dump the unfreed memory, logs the unfreed information to logger
 */
extern
void	_chunk_dump_unfreed(void);

/*<<<<<<<<<<   This is end of the auto-generated output from fillproto. */

#endif /* ! __CHUNK_H__ */
