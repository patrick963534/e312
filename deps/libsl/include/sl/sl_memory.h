#ifndef __SL_MEMORY_H__
#define __SL_MEMORY_H__

#include <sl/sl_defs.h>

SL_API void*    sl_memory_new(sl_i sz);
SL_API void*    sl_memory_renew(void *p, sl_i sz);
SL_API void     sl_memory_delete(void *p);
SL_API void     sl_memory_zero(void *p, sl_i sz);

#endif
