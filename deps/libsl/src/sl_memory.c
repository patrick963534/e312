#include <sl/sl_memory.h>
#include <sl/sl_libc_stdlib.h>

SL_API void* sl_memory_new(sl_i sz)
{
    return sl_calloc(1, sz);
}

SL_API void* sl_memory_renew(void *p, sl_i sz)
{
    return sl_realloc(p, sz);
}

SL_API void sl_memory_delete(void *p)
{
    return sl_free(p);
}

SL_API void sl_memory_zero(void *p, sl_i sz)
{
    char *b = (char*)p;
    char *be = b + sz;

    while (b < be)
        *b++ = 0;
}
