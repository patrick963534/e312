#include <sl/sl_memory.h>
#include <sl/sl_libc_stdlib.h>

SL_API void* sl_memory_new_(sl_i sz, SL_DEBUG_FILE_INFO_PARAM)
{
    return slc_calloc(1, sz);
}

SL_API void* sl_memory_renew_(void *p, sl_i sz, SL_DEBUG_FILE_INFO_PARAM)
{
    return slc_realloc(p, sz);
}

SL_API void sl_memory_delete_(void *p, SL_DEBUG_FILE_INFO_PARAM)
{
    slc_free(p);
}

SL_API void sl_memory_zero(void *p, sl_i sz)
{
    char *b = (char*)p;
    char *be = b + sz;

    while (b < be)
        *b++ = 0;
}
