#include <sl/sl_string.h>
#include <sl/sl_memory.h>

#define BUF_INIT_SZ 16

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
    return NULL;
}

SL_API void sl_string_append(sl_string_t *me, const sl_c *str)
{
    sl_c *t;

    sl_assert(me);
    sl_assert(str);
    sl_assert(me->pos < me->sz);

    /**
     TODO: Check @str is an UTF-8 string, don't care about performance thing.
    */

    t = me->c_str + me->pos;

    while (0 != (*t++ = *str++))
    {
        me->pos++;

        if (me->pos + 1 >= me->sz)
        {
            me->sz += me->sz;
            me->c_str = sl_memory_renew(me->c_str, me->sz);

            t = me->c_str + me->pos;
        }
    }

    *t = '\0';

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

