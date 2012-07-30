#include <sl/sl_string.h>
#include <sl/sl_log.h>
#include <sl/sl_memory.h>
#include <sl/sl_libc_string.h>
#include <sl/sl_libc_stdarg.h>

#define BUF_INIT_SZ 16

/**
 U+0000  - U+007F    0xxxxxxx
 U+0080  - U+07FF    110xxxxx    10xxxxxx
 U+0800  - U+FFFF    1110xxxx    10xxxxxx    10xxxxxx
 U+10000 - U+10FFFF  11110xxx    10xxxxxx    10xxxxxx    10xxxxxx
*/

static const sl_i u8_prefix[6] = {
    0x00, /* binary: 0.         */
    0x06, /* binary: 110.       */
    0x0E, /* binary: 1110.      */
    0x1E, /* binary: 11110.     */
    0x3E, /* binary: 111110.    */
    0x7E, /* binary: 1111110.   */
};

static const sl_c u8_trail_bytes[256] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, 3,3,3,3,3,3,3,3,4,4,4,4,5,5,5,5,
};

static sl_b check_is_u8_string(const sl_c *str)
{
    sl_uc *u8;
    sl_i   nb;
    sl_i   i;

    u8 = (sl_uc*)str;

    while (*u8) 
    {
        nb = u8_trail_bytes[*u8];

        /* only verify for non-ascii character. */
        if (nb != 0 && (*u8) >> (8 - (nb + 2)) != u8_prefix[nb])
            goto fail;

        u8++;

        for (i = 1; i < nb + 1; i++, u8++)
            if (*u8 == 0 || ((*u8) >> 6) != 0x02)
                goto fail;
    }

    return 1;

fail:
    sl_log("String '%' is not a UTF-8 encoded string.", str);
    return 0;
}

static void update_buffer(sl_string_t *me)
{
    if (me->pos + 1 >= me->sz)
    {
        me->sz += me->sz;
        me->c_str = sl_memory_renew(me->c_str, me->sz);
    }
}

SL_API sl_char_t sl_char_from(const sl_c *s)
{
    sl_char_t ch;
    sl_i      nb;
    sl_i      i;

    nb = u8_trail_bytes[(sl_uc)*s] + 1;

    for (i = 0; i < SL_CHAR_SZ; i++)
    {
        if (i < nb)
            ch.buf[i] = s[i];
        else
            ch.buf[i] = 0;
    }

    return ch;
}

SL_API sl_b sl_char_equals(sl_char_t ch1, sl_char_t ch2)
{
    sl_i      i;

    for (i = 0; i < SL_CHAR_SZ; i++)
        if (ch1.buf[i] != ch2.buf[i])
            return 0;

    return 1;
}

SL_API sl_string_t* sl_string_new(const sl_c *str)
{
    sl_string_t *me;

    me = (sl_string_t*)sl_object_new(sizeof(*me));

    me->tname    = "string";
    me->destruct = (sl_destruct_func)sl_string_destruct;
    me->sz       = BUF_INIT_SZ;
    me->c_str    = sl_memory_new(me->sz);
    me->pos      = 0;

    if (str)
        sl_string_append(me, str);

    return me;
}

SL_API sl_string_t* sl_string_format(int sz, const sl_c *fmt, ...)
{
    sl_string_t *me;
    sl_c        *buf;
    slc_va_list  va;
    sl_i         n;

    sl_assert(sz > 0);

    /* the reason of +1 is used to include the '\0' */
    buf = sl_memory_new(sz + 1);

    slc_va_start(va, fmt);
    n = slc_vsnprintf(buf, sz + 1, fmt, va);
    slc_va_end(va);

    if (n < sz)
        me = sl_string_new(buf);
    else
        me = NULL;

    sl_memory_delete(buf);

    return me;
}

SL_API void sl_string_append(sl_string_t *me, const sl_c *str)
{
    sl_assert(me);
    sl_assert(str);
    sl_assert(me->pos < me->sz);
    sl_assert(check_is_u8_string(str));

    while (*str)
    {
        me->c_str[me->pos++] = *str;
        update_buffer(me);
        str++;
    }

    me->c_str[me->pos] = '\0';

    sl_assert(me->pos < me->sz);
}

SL_API sl_char_t sl_string_get_char(sl_string_t *me, sl_i n)
{
    sl_uc       *s;
    sl_uc       *e;
    sl_char_t    ch;
    sl_i         c;

    s = (sl_uc*)me->c_str;
    e = (sl_uc*)(me->c_str + me->sz);
    c = 0;

    while (*s)
    {
        if (c == n)
            return sl_char_from((sl_c*)s);

        c++;
        s = s + (u8_trail_bytes[*s] + 1);

        sl_assert(s < e);
    }

    return ch;
}

SL_API void sl_string_set_char(sl_string_t *me, sl_i n, const sl_char_t ch)
{
    sl_uc  *s, *sp;
    sl_i    c, nb, i;

    sp = s = sl_memory_new(me->sz);
    sl_memory_copy(s, me->sz, me->c_str, me->sz);

    sl_memory_zero(me->c_str, me->sz);
    me->pos = 0;
    c = 0;

    while (*sp)
    {
        nb = (u8_trail_bytes[*sp] + 1);

        if (c == n)
        {
            sl_string_append(me, ch.buf);
        }
        else
        {
            for (i = 0; i < nb; i++)
            {
                me->c_str[me->pos++] = sp[i];
                update_buffer(me);
            }
        }

        c++;
        sp = sp + nb;

        sl_assert(sp < s + me->sz);
    }

    sl_memory_delete(s);
    sl_assert(n < c);
}

SL_API sl_i sl_string_char_count(sl_string_t *me)
{
    sl_i   n;
    sl_uc *s;
    sl_uc *e;

    n = 0;
    s = (sl_uc*)me->c_str;
    e = (sl_uc*)(me->c_str + me->sz);

    while (*s)
    {
        n++;
        s = s + (u8_trail_bytes[*s] + 1);

        sl_assert(s < e);
    }

    return n;
}

SL_API sl_b sl_string_equals(const sl_string_t *str1, const sl_string_t *str2)
{
    const sl_c *s;
    const sl_c *d;

    assert(str1 != 0 && str2 != 0);

    s = str1->c_str;
    d = str2->c_str;
    
    while (*s && *d)
    {
        if (*s != *d)
            return 0;
    }

    return 1;
}

static void to_char_array(sl_string_t *me, sl_char_t **arr, sl_i *count)
{
    sl_char_t *chs;
    sl_i       c, i;
    sl_uc     *s;

    c = sl_string_char_count(me);
    chs = sl_memory_new(sizeof(chs[0]) * c);

    s = (sl_uc*)me->c_str;
    for (i = 0; i < c; i++)
    {
        chs[i] = sl_char_from((sl_c*)s);
        s = s + (u8_trail_bytes[*s] + 1);
    }

    *arr = chs;
    *count = c;
}

static sl_b sl_string_include(sl_string_t *me, sl_char_t ch)
{
    sl_uc *s;

    s = (sl_uc*)me->c_str;
    while (*s)
    {
        if (sl_char_equals(sl_char_from((sl_c*)s), ch))
            return 1;

        s = s + (u8_trail_bytes[*s] + 1);
    }

    return 0;
}

SL_API void sl_string_trim_string(sl_string_t *me, sl_string_t *trim)
{
    sl_char_t *chs;
    sl_i       c, i, is, ie;

    to_char_array(me, &chs, &c);

    sl_memory_zero(me->c_str, me->sz);
    me->pos = 0;

    for (is = 0; is < c; is++)
        if (!sl_string_include(trim, chs[is]))
            break;

    for (ie = c - 1; ie >= 0; ie--)
        if (!sl_string_include(trim, chs[ie]))
            break;

    for (i = is; i <= ie; i++)
        sl_string_append(me, chs[i].buf);

    sl_memory_delete(chs);
}

SL_API void sl_string_trim(sl_string_t *me, sl_char_t ch)
{
    sl_char_t *chs;
    sl_i       c, i, is, ie;

    to_char_array(me, &chs, &c);

    sl_memory_zero(me->c_str, me->sz);
    me->pos = 0;

    for (is = 0; is < c; is++)
        if (!sl_char_equals(chs[is], ch))
            break;

    for (ie = c - 1; ie >= 0; ie--)
        if (!sl_char_equals(chs[ie], ch))
            break;

    for (i = is; i <= ie; i++)
        sl_string_append(me, chs[i].buf);

    sl_memory_delete(chs);
}

SL_API void sl_string_destruct(sl_string_t *me)
{
    sl_memory_delete(me->c_str);

    sl_object_destruct(me);
}

