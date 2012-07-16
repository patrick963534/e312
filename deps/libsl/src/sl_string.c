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
    sl_uchar_t  *t;
    sl_i         ucs;
    sl_i         offset;

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

    *t = '\0';

    sl_assert(me->pos < me->sz);
}

SL_API sl_uchar_t sl_uchar_from_char_array(sl_c *str)
{
    sl_uchar_t ch;
    /* TODO */
    return ch;
}

SL_API sl_c* sl_uchar_to_char_array(sl_uchar_t ch)
{
    /* TODO */
    return 0;
}

SL_API sl_string_t* sl_string_new(const sl_c *str)
{
    sl_string_t *me;

    me = (sl_string_t*)sl_object_new(sizeof(*me));

    me->destruct = (sl_destruct_func)sl_string_destruct;
    me->sz = BUF_INIT_SZ;
    me->buf = (sl_uchar_t*)sl_memory_new(me->sz * sizeof(me->buf[0]));
    me->pos = 0;
    me->c_str = NULL;

    if (str)
        do_append_string(me, str);

    return me;
}

SL_API sl_uchar_t sl_string_uchar_get(sl_string_t *me, sl_i index)
{
    sl_assert(index <= me->pos);

    return me->buf[index];
}

SL_API void sl_string_uchar_set(sl_string_t *me, sl_uchar_t ch, sl_i index)
{
    sl_assert(index <= me->pos);

    me->buf[index] = ch;
}

SL_API sl_c* sl_string_to_char_array(sl_string_t *me)
{
    sl_c *ret, *pos;
    sl_c  buf[6];
    sl_i  i, j, bsz;
    sl_i  sz, c;

    if (me->c_str)
        sl_memory_delete(me->c_str);

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

    me->c_str = ret;
    return ret;
}

SL_API void sl_string_format(sl_string_t *me, sl_c *format, ...)
{

}

SL_API sl_b sl_string_equals(sl_string_t *me, sl_string_t *str)
{
    sl_uchar_t *s = me->buf;
    sl_uchar_t *d = str->buf;

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
    sl_memory_delete(me->buf);

    if (me->c_str)
        sl_memory_delete(me->c_str);
}

