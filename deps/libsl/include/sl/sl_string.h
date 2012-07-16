#ifndef __SL_STRING_H__
#define __SL_STRING_H__ 

#include <sl/sl_defs.h>
#include <sl/sl_object.h>

typedef struct sl_string_t
{
    sl_extends_object();

    sl_i    *buf;   /* buffer. */
    sl_i     sz;    /* size of buffer. */
    sl_i     pos;   /* point to '\0' position. */
} sl_string_t;

SL_API sl_string_t* sl_string_new(const sl_c *str);
SL_API void         sl_string_append(sl_string_t *me, sl_string_t *src);
SL_API void         sl_string_format(sl_string_t *me, sl_c *format, ...);
SL_API sl_c*        sl_string_to_char_array(sl_string_t *me);
SL_API void         sl_string_destruct(sl_string_t *me);

#endif
