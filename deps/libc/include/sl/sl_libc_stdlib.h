#ifndef __SL_LIBC_STDLIB_H__
#define __SL_LIBC_STDLIB_H__

#include <stdlib.h>

#define slc_atof     atof    /* (const char *str); */
#define slc_atoi     atoi    /* (const char *str); */
#define slc_atol     atol    /* (const char *str); */
#define slc_strtod   strtod  /* (const char *str, char **endptr); */
#define slc_strtol   strtol  /* (const char *str, char **endptr, int base); */
#define slc_strtoul  strtoul /* (const char *str, char **endptr, int base); */

#define slc_calloc   calloc  /* (size_t nitems, size_t size); */
#define slc_free     free    /* (void *ptr); */
#define slc_malloc   malloc  /* (size_t size); */
#define slc_realloc  realloc /* (void *ptr, size_t size); */

#define slc_abort    abort   /* (void); */
#define slc_atexit   atexit  /* (void (*func)(void)); */
#define slc_exit     exit    /* (int status); */
#define slc_getenv   getenv  /* (const char *name); */
#define slc_system   system  /* (const char *string); */

#define slc_bsearch  bsearch /* (const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)); */
#define slc_qsort    qsort   /* (void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)); */

#define slc_abs      abs     /* (int x); */
#define slc_div      div     /* (int numer, int denom); */
#define slc_labs     labs    /* (long int x); */
#define slc_ldiv     ldiv    /* (long int numer, long int denom); */
#define slc_rand     rand    /* (void); */
#define slc_srand    srand   /* (unsigned int seed); */

#define slc_mblen    mblen    /* (const char *str, size_t n); */
#define slc_mbstowcs mbstowcs /* (schar_t *pwcs, const char *str, size_t n); */
#define slc_mbtowc   mbtowc   /* (whcar_t *pwc, const char *str, size_t n); */
#define slc_wcstombs wcstombs /* (char *str, const wchar_t *pwcs, size_t n); */
#define slc_wctomb   wctomb   /* (char *str, wchar_t wchar); */

#endif
