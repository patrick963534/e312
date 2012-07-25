#ifndef __CU_ALL_H__
#define __CU_ALL_H__

#include <sl/sl_defs.h>

SL_API sl_b cu_string_equals_(sl_c *expected, sl_c *str, const sl_c *file, const sl_c *func, sl_i line);

SL_API sl_b cu_int_equals_(sl_i expected, sl_i v, const sl_c *file, const sl_c *func, sl_i line);

SL_API sl_b cu_pointer_equals_(void *expected, void *v, const sl_c *file, const sl_c *func, sl_i line);

#define cu_check_2_values(func_, v1, v2)                \
    do {                                                \
        if (!func_(v1, v2,                              \
            __FILE__, __FUNCTION__, __LINE__))          \
        {                                               \
            return;                                     \
        }                                               \
    } while(0)

#define cu_string_equals(expected, str) \
            cu_check_2_values(cu_string_equals_, expected, str)

#define cu_int_equals(expected, v) \
            cu_check_2_values(cu_int_equals_, expected, v)

#define cu_pointer_equals(expected, v) \
            cu_check_2_values(cu_pointer_equals_, expected, v)
#endif
