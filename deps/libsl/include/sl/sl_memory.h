#ifndef __SL_MEMORY_H__
#define __SL_MEMORY_H__

#include <sl/sl_defs.h>
#include <sl/sl_mld.h>

SL_API void     sl_memory_zero(void *p, sl_i sz);
SL_API void*    sl_memory_new_(sl_i sz);
SL_API void*    sl_memory_renew_(void *p, sl_i sz);
SL_API void*    sl_memory_delete_(void *p);

#define SL_DEBUG_FILE_INFO  __FILE__, __FUNCTION__, __LINE__

#define sl_memory_new(sz)      sl_mld_new(SL_DEBUG_FILE_INFO,   sl_memory_new_(sz))
#define sl_memory_renew(p, sz) sl_mld_renew(SL_DEBUG_FILE_INFO, sl_memory_renew_(p, sz))
#define sl_memory_delete(p)    sl_mld_renew(SL_DEBUG_FILE_INFO, sl_memory_delete_(p))

#endif
