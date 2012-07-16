#include <sl/sl_string.h>
#include <sl/sl_memory.h>

#define BUF_INIT_SZ 16

static sl_i ucs_to_char_array(sl_c *buf, sl_i sz, sl_i ucs)
{
    buf[0] = (sl_c)ucs;

    return 1; /* return count of real bytes. */
}

static sl_i get_next_ucs(const sl_c *str, sl_i *offset)
{
    sl_i ret = str[*offset];

    *offset = *offset + 1;

    return ret;
}

static void do_append_string(sl_string_t *me, const sl_c *str)
{
    sl_i *t;
    sl_i ucs;
    sl_i offset;

    sl_assert(me->pos < me->sz);

    offset = 0;
    t = me->buf + me->pos;

    while (0 != (ucs = get_next_ucs(str, &offset)))
    {
        *t++ = ucs;
        me->pos++;

        sl_assert(offset < 20);

        if (me->pos + 1 >= me->sz)
        {
            me->sz += me->sz;
            me->buf = sl_memory_renew(me->buf, me->sz * sizeof(me->buf[0]));

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
    me->buf = (sl_i*)sl_memory_new(me->sz * sizeof(me->buf[0]));
    me->pos = 0;

    if (str)
        do_append_string(me, str);

    return me;
}

SL_API sl_c* sl_string_to_char_array(sl_string_t *me)
{
    sl_c *ret, *pos;
    sl_c  buf[6];
    sl_i  i, j, bsz;
    sl_i  sz, c;

    sz = me->pos + 1;
    ret = sl_memory_new(sz);
    pos = ret;
    c = 0;

    for (i = 0; i <= me->pos; i++)
    {
        bsz = ucs_to_char_array(buf, sizeof(buf), me->buf[i]);

        for (j = 0; j < bsz; j++)
        {
            pos[c++] = buf[j];

            if (c >= sz)
            {
                sz += sz;
                ret = sl_memory_renew(ret, sz);
                pos = ret;
            }
        }
    }

    return ret;
}

SL_API void sl_string_format(sl_string_t *me, sl_c *format, ...)
{

}

SL_API void sl_string_destruct(sl_string_t *me)
{
    sl_memory_delete(me->buf);
}

