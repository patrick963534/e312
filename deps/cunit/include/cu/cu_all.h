#ifndef __CU_ALL_H__
#define __CU_ALL_H__

#include <sl/sl_defs.h>

SL_API sl_b cu_string_equals_(sl_c *expected, sl_c *str);

#define cu_string_equals(expected, str) do { if (!cu_string_equals_(expected, str)) return; } while(0)

#endif
