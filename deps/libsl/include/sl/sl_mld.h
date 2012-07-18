#ifndef __SL_MLD_H__
#define __SL_MLD_H__

#include <sl/sl_defs.h>

SL_API void* sl_mld_new(sl_i sz, const sl_c *file, const sl_c *func, sl_i line);
SL_API void* sl_mld_renew(void *p, sl_i sz, const sl_c *file, const sl_c *func, sl_i line);
SL_API void  sl_mld_delete(void *p, const sl_c *file, const sl_c *func, sl_i line);

#endif
