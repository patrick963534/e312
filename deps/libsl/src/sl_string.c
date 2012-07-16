#include <sl/sl_string.h>
#include <sl/sl_memory.h>

#define BUF_INIT_SZ 16

static void do_append_string(sl_string_t *me, const sl_c *str)
{
    const sl_c *s = str;
    sl_c *t = me->buf + me->pos;

    sl_assert(me->pos < me->sz);

    while (*s != 0)
    {
        *t++ = *s++;
        me->pos++;

        if (me->pos + 1 >= me->sz)
        {
            me->sz += me->sz;
            me->buf = sl_memory_renew(me->buf, me->sz);

            t = me->buf + me->pos;
        }
    }

    me->buf[me->pos] = '\0';

    sl_assert(me->pos < me->sz);
}

SL_API sl_string_t* sl_string_new(const sl_c *str)
{
    sl_string_t *me;

    me = (sl_string_t*)sl_object_new(sizeof(*me));

    me->destruct = (sl_destruct_func)sl_string_destruct;
    me->sz = BUF_INIT_SZ;
    me->buf = (sl_c*)sl_memory_new(me->sz);
    me->pos = 0;

    if (str)
        do_append_string(me, str);

    return me;
}

SL_API void sl_string_format(sl_string_t *me, sl_c *format, ...)
{

}

SL_API void sl_string_destruct(sl_string_t *me)
{
    sl_memory_delete(me->buf);
}

