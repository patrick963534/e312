#include <sl/sl_mld.h>
#include <sl/sl_memory.h>

SL_API void* sl_mld_new(sl_i sz, const sl_c *file, const sl_c *func, sl_i line)
{
    return sl_memory_new_(sz);
}

SL_API void* sl_mld_renew(void *p, sl_i sz, const sl_c *file, const sl_c *func, sl_i line)
{
    return sl_memory_renew_(p, sz);
}

SL_API void  sl_mld_delete(void *p, const sl_c *file, const sl_c *func, sl_i line)
{
    sl_memory_delete_(p);
}
