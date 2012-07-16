#ifndef __SL_STRING_H__
#define __SL_STRING_H__ 

#include <sl/sl_defs.h>
#include <sl/sl_object.h>

/* ucs char. */
typedef sl_i sl_uchar_t;

typedef struct sl_string_t
{
    sl_extends_object();

    sl_uchar_t  *buf;   /* buffer. */
    sl_i         sz;    /* size of buffer. */
    sl_i         pos;   /* point to '\0' position. */
} sl_string_t;

/* in UTF-8, str might be multi-bytes to indicate an uchar. */
SL_API sl_uchar_t   sl_uchar_from_char_array(sl_c *str);
SL_API sl_c*        sl_uchar_to_char_array(sl_uchar_t ch);

SL_API sl_string_t* sl_string_new(const sl_c *str);
SL_API void         sl_string_append(sl_string_t *me, sl_string_t *src);
SL_API void         sl_string_format(sl_string_t *me, sl_c *format, ...);
SL_API sl_c*        sl_string_to_char_array(sl_string_t *me);
SL_API sl_uchar_t   sl_string_uchar_get(sl_string_t *me, sl_i index);
SL_API void         sl_string_uchar_set(sl_string_t *me, sl_uchar_t ch, sl_i index);
SL_API sl_b         sl_string_equals(sl_string_t *me, sl_string_t *str);
SL_API void         sl_string_destruct(sl_string_t *me);

#endif
