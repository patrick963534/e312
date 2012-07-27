#ifndef __CU_ALL_H__
#define __CU_ALL_H__

#include <sl/sl_defs.h>

#define CU_DEBUG_INFO const sl_c *file, const sl_c *func, sl_i line

SL_API sl_b cu_string_equals_ (sl_c *exp, sl_c *str, CU_DEBUG_INFO);
SL_API sl_b cu_int_equals_    (sl_i exp, sl_i v, CU_DEBUG_INFO);
SL_API sl_b cu_pointer_equals_(void *exp, void *v, CU_DEBUG_INFO);

#define cu_check_2_values(func_, v1, v2)                \
    do {                                                \
        if (!func_(v1, v2,                              \
            __FILE__, __FUNCTION__, __LINE__))          \
        {                                               \
            return;                                     \
        }                                               \
    } while(0)

#define cu_string_equals(exp, str) \
            cu_check_2_values(cu_string_equals_, exp, str)
#define cu_int_equals(exp, v) \
            cu_check_2_values(cu_int_equals_, exp, v)
#define cu_assert(exp) \
            cu_check_2_values(cu_int_equals_, !!(exp), 1)
#define cu_pointer_equals(exp, v) \
            cu_check_2_values(cu_pointer_equals_, exp, v)

#endif
