#ifndef __SL_MEMORY_H__
#define __SL_MEMORY_H__

#include <sl/sl_defs.h>

/**
 The memory lib provide memory leak detection. It just let you know
 whether there's memory leak, and provide little information, you should
 NOT expect it provide very good information. You SHOULD have a habit
 to test memory leak everytime when you add new codes ASAP.
*/

#define SL_DEBUG_FILE_INFO_ARGS   __FILE__, __FUNCTION__, __LINE__
#define SL_DEBUG_FILE_INFO_PARAM  const sl_c *file, const sl_c *func, sl_i line

SL_API void   sl_memory_leak_report();
SL_API void   sl_memory_zero(void *p, sl_i sz);
SL_API void   sl_memory_copy(void *dst, sl_i dst_sz, void *src, sl_i src_sz);
SL_API void*  sl_memory_new_(sl_i sz, SL_DEBUG_FILE_INFO_PARAM);
SL_API void*  sl_memory_renew_(void *p, sl_i sz, SL_DEBUG_FILE_INFO_PARAM);
SL_API void   sl_memory_delete_(void *p, SL_DEBUG_FILE_INFO_PARAM);

#define sl_memory_new(sz)      sl_memory_new_(sz, SL_DEBUG_FILE_INFO_ARGS)
#define sl_memory_renew(p, sz) sl_memory_renew_(p, sz, SL_DEBUG_FILE_INFO_ARGS)
#define sl_memory_delete(p)    sl_memory_delete_(p, SL_DEBUG_FILE_INFO_ARGS)

#endif
