#include <sl/sl_string.h>
#include <sl/sl_log.h>
#include <sl/sl_memory.h>
#include <sl/sl_libc_string.h>

#define BUF_INIT_SZ 16

/**
 U+0000  - U+007F    0xxxxxxx
 U+0080  - U+07FF    110xxxxx    10xxxxxx
 U+0800  - U+FFFF    1110xxxx    10xxxxxx    10xxxxxx
 U+10000 - U+10FFFF  11110xxx    10xxxxxx    10xxxxxx    10xxxxxx
*/

static const sl_i u8_prefix[6] = {
    0x00, /* binary: 0. */ 
    0x06, /* binary: 110. */
    0x0E, /* binary: 1110. */
    0x1E, /* binary: 11110. */ 
    0x3E, /* binary: 111110. */ 
    0x7E, /* binary: 1111110. */
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

/**
 Will move to other file which process u8 stuff or charset stuff.
*/
static sl_b check_is_u8_string(const sl_c *str)
{
    sl_uc *u8;
    sl_i   nb;
    sl_i   i;

    u8 = (sl_uc*)str;

    while (*u8) 
    {
        nb = u8_trail_bytes[*u8];

        if ((*u8) >> (8 - nb - 2) != u8_prefix[nb])
            return 0;

        u8++;

        for (i = 1; i < nb + 1; i++, u8++)
            if (*u8 == 0 || ((*u8) >> 6) != 0x02)
                return 0;
    }

    return 1;
}

static void update_buffer(sl_string_t *me)
{
    if (me->pos + 1 >= me->sz)
    {
        me->sz += me->sz;
        me->c_str = sl_memory_renew(me->c_str, me->sz);
    }
}

SL_API sl_string_t* sl_string_new(const sl_c *str)
{
    sl_string_t *me;

    me = (sl_string_t*)sl_object_new(sizeof(*me));

    me->destruct = (sl_destruct_func)sl_string_destruct;
    me->sz       = BUF_INIT_SZ;
    me->pos      = 0;
    me->c_str    = sl_memory_new(me->sz);

    if (str)
        sl_string_append(me, str);

    return me;
}

SL_API sl_string_t* sl_string_format(const sl_c *fmt, ...)
{
    sl_string_t *me;
    const sl_c  *f;

    me = sl_string_new(NULL);
    f = fmt;

    while (*f)
    {
        if (*f != '%')
        {
            me->c_str[me->pos++] = *f;
            update_buffer(me);
        }
        else
        {
            switch (*(f + 1))
            {
                case 's':
                    sl_log("%s", "get pattern string.");
                    f++;
                    break;
                default:
                    break;
            }
        }

        f++;
    }

    me->c_str[me->pos] = '\0';

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

SL_API sl_c* sl_string_get_char(sl_string_t *me, sl_i n)
{
    /**
     TODO: get a small string to identify a UTF-8 multi-bytes character.
    */

    return NULL;
}

SL_API void sl_string_set_char(sl_string_t *me, sl_i pos, sl_c *ch)
{
    /**
     TODO: @ch is an UTF-8 string, we pick the first multi-bytes character to do replacing.
    */
}

SL_API sl_b sl_string_equals(const sl_c *str1, const sl_c *str2)
{
    const sl_c *s = str1;
    const sl_c *d = str2;

    assert(s != 0 && d != 0);
    
    while (*s && *d)
    {
        if (*s != *d)
            return 0;
    }

    return 1;
}

SL_API void sl_string_destruct(sl_string_t *me)
{
    sl_memory_delete(me->c_str);
}

