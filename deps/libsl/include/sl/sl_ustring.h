#ifndef __SL_STRING_H__
#define __SL_STRING_H__ 

#include <sl/sl_defs.h>
#include <sl/sl_object.h>

#define SL_CHAR_SZ  7

typedef struct sl_uchar_t
{
    sl_c    buf[SL_CHAR_SZ];
} sl_uchar_t;

SL_API sl_uchar_t    sl_uchar_from(const sl_c *s);
SL_API sl_b         sl_uchar_equals(sl_uchar_t ch1, sl_uchar_t ch2);

typedef struct sl_ustring_t
{
    sl_extends_object();

    sl_c        *c_str; /* buffer. */
    sl_i         sz;    /* size of buffer. */
    sl_i         pos;   /* point to '\0' position. */
} sl_ustring_t;

SL_API sl_ustring_t* sl_ustring_new(const sl_c *str);
SL_API sl_ustring_t* sl_ustring_format(sl_i sz, const sl_c *fmt, ...);
SL_API void         sl_ustring_destruct(sl_ustring_t *me);

SL_API void         sl_ustring_append(sl_ustring_t *me, const sl_c *str);
SL_API sl_uchar_t    sl_ustring_get_char(sl_ustring_t *me, sl_i n);
SL_API void         sl_ustring_set_char(sl_ustring_t *me, sl_i n, sl_uchar_t ch);
SL_API sl_i         sl_ustring_char_count(sl_ustring_t *me);
SL_API sl_b         sl_ustring_equals(sl_ustring_t *s1, sl_ustring_t *s2);

SL_API sl_i         sl_ustring_index(sl_ustring_t *sl, sl_uchar_t ch);
SL_API sl_i         sl_ustring_index_end(sl_ustring_t *sl, sl_uchar_t ch);

SL_API void         sl_ustring_trim(sl_ustring_t *me, sl_uchar_t ch);
SL_API void         sl_ustring_trim_string(sl_ustring_t *me, sl_ustring_t *trim);
SL_API void         sl_ustring_trim_end_newline_char(sl_ustring_t *me);

#endif
