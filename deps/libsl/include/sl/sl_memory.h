#ifndef __SL_MEMORY_H__
#define __SL_MEMORY_H__

#include <sl/sl_defs.h>
#include <sl/sl_mld.h>

/**
 Similar with bzero, lower performance one, but it's OK for me. 
*/
SL_API void     sl_memory_zero(void *p, sl_i sz);

/**
 Which is the very base malloc memory method.
*/
SL_API void*    sl_memory_new_(sl_i sz);

/**
 Which is the very base realloc memory method.
*/
SL_API void*    sl_memory_renew_(void *p, sl_i sz);

/**
 Which is the very base free memory method.
*/
SL_API void*    sl_memory_delete_(void *p);

#define SL_DEBUG_FILE_INFO  __FILE__, __FUNCTION__, __LINE__
#define sl_memory_new(sz)      sl_mld_new(sz, SL_DEBUG_FILE_INFO)
#define sl_memory_renew(p, sz) sl_mld_renew(p, sz, SL_DEBUG_FILE_INFO)
#define sl_memory_delete(p)    sl_mld_delete(p, SL_DEBUG_FILE_INFO)

#endif
