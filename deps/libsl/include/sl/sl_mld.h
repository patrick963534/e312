#ifndef __SL_MLD_H__
#define __SL_MLD_H__

#include <sl/sl_defs.h>

SL_API void* sl_mld_new(const sl_c *file, const sl_c *func, sl_i line, void *p);
SL_API void* sl_mld_renew(const sl_c *file, const sl_c *func, sl_i line, void *p);
SL_API void  sl_mld_delete(const sl_c *file, const sl_c *func, sl_i line, void *p);

#endif
