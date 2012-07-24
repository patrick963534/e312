#ifndef __CU_ALL_H__
#define __CU_ALL_H__

#include <sl/sl_defs.h>

SL_API sl_b cu_string_equals_(sl_c *expected, sl_c *str, const sl_c *file, const sl_c *func, sl_i line);

#define cu_string_equals(expected, str)                 \
    do {                                                \
        if (!cu_string_equals_(expected, str,           \
            __FILE__, __FUNCTION__, __LINE__))          \
        {                                               \
            return;                                     \
        }                                               \
    } while(0)

#endif
