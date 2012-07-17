#ifndef __CU_ALL_H__
#define __CU_ALL_H__

#include <sl/sl_defs.h>

SL_API sl_b cu_string_equals_(sl_c *str1, sl_c *str2);

#define cu_string_equals(str1, str2) do { if (!cu_string_equals_(str1, str2)) return; } while(0)

#endif
