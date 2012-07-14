#ifndef __SL_STRING_H__
#define __SL_STRING_H__ 

#include <sl/sl_defs.h>
#include <sl/sl_object.h>

typedef struct sl_string_t
{
    sl_extends_object();

    sl_c    *buf;
    int      sz;

} sl_string_t;

SL_API sl_string_t* sl_string_new();
SL_API sl_string_t  sl_string_const(const sl_c *str);
SL_API void         sl_string_destruct(sl_string_t *me_);

#endif
