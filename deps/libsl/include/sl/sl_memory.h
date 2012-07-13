#ifndef __SL_MEMORY_H__
#define __SL_MEMORY_H__

#include <sl/sl_defs.h>
#include <sl/sl_libc_stdlib.h>

SL_API void*    sl_memory_new(int sz);
SL_API void*    sl_memory_renew(void *p, int sz);
SL_API void     sl_memory_set(void *p, int v, int sz);
SL_API void     sl_memory_delete(void *p);

#endif
