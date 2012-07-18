#include <sl/sl_mld.h>

SL_API void* sl_mld_new(const sl_c *file, const sl_c *func, sl_i line, void *p)
{
    sl_unused(file);
    sl_unused(func);
    sl_unused(line);
    return p;
}

SL_API void* sl_mld_renew(const sl_c *file, const sl_c *func, sl_i line, void *p)
{
    sl_unused(file);
    sl_unused(func);
    sl_unused(line);
    return p;
}

SL_API void sl_mld_delete(const sl_c *file, const sl_c *func, sl_i line, void *p)
{
    sl_unused(file);
    sl_unused(func);
    sl_unused(line);
    sl_unused(p);
}
