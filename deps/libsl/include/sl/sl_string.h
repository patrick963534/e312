#ifndef __SL_STRING_H__
#define __SL_STRING_H__ 

#include <sl/sl_defs.h>
#include <sl/sl_object.h>

#define SL_CHAR_SZ  7

typedef struct sl_char_t
{
    sl_c    buf[SL_CHAR_SZ];
} sl_char_t;

SL_API sl_char_t    sl_char_from(const sl_c *s);
SL_API sl_b         sl_char_equals(sl_char_t ch1, sl_char_t ch2);

typedef struct sl_string_t
{
    sl_extends_object();

    sl_c        *c_str; /* buffer. */
    sl_i         sz;    /* size of buffer. */
    sl_i         pos;   /* point to '\0' position. */
} sl_string_t;

SL_API sl_string_t* sl_string_new(const sl_c *str);
SL_API sl_string_t* sl_string_format(sl_i sz, const sl_c *fmt, ...);
SL_API void         sl_string_append(sl_string_t *me, const sl_c *str);
SL_API sl_char_t    sl_string_get_char(sl_string_t *me, sl_i n);
SL_API void         sl_string_set_char(sl_string_t *me, sl_i n, sl_char_t ch);
SL_API sl_i         sl_string_char_count(sl_string_t *me);
SL_API sl_b         sl_string_equals(sl_string_t *s1, sl_string_t *s2);
SL_API void         sl_string_trim_string(sl_string_t *me, sl_string_t *trim);
SL_API void         sl_string_trim(sl_string_t *me, sl_char_t ch);
SL_API void         sl_string_destruct(sl_string_t *me);

#endif
