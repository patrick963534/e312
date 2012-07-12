#ifndef __SL_LIBC_STDLIB_H__
#define __SL_LIBC_STDLIB_H__

#include <stdlib.h>

#define sl_atof     atof    /* (const char *str); */
#define sl_atoi     atoi    /* (const char *str); */
#define sl_atol     atol    /* (const char *str); */
#define sl_strtod   strtod  /* (const char *str, char **endptr); */
#define sl_strtol   strtol  /* (const char *str, char **endptr, int base); */
#define sl_strtoul  strtoul /* (const char *str, char **endptr, int base); */

#define sl_calloc   calloc  /* (size_t nitems, size_t size); */
#define sl_free     free    /* (void *ptr); */
#define sl_malloc   malloc  /* (size_t size); */
#define sl_realloc  realloc /* (void *ptr, size_t size); */

#define sl_abort    abort   /* (void); */
#define sl_atexit   atexit  /* (void (*func)(void)); */
#define sl_exit     exit    /* (int status); */
#define sl_getenv   getenv  /* (const char *name); */
#define sl_system   system  /* (const char *string); */

#define sl_bsearch  bsearch /* (const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)); */
#define sl_qsort    qsort   /* (void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)); */

#define sl_abs      abs     /* (int x); */
#define sl_div      div     /* (int numer, int denom); */
#define sl_labs     labs    /* (long int x); */
#define sl_ldiv     ldiv    /* (long int numer, long int denom); */
#define sl_rand     rand    /* (void); */
#define sl_srand    srand   /* (unsigned int seed); */

#define sl_mblen    mblen    /* (const char *str, size_t n); */
#define sl_mbstowcs mbstowcs /* (schar_t *pwcs, const char *str, size_t n); */
#define sl_mbtowc   mbtowc   /* (whcar_t *pwc, const char *str, size_t n); */
#define sl_wcstombs wcstombs /* (char *str, const wchar_t *pwcs, size_t n); */
#define sl_wctomb   wctomb   /* (char *str, wchar_t wchar); */

#endif
