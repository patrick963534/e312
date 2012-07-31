#include <sl/sl_file.h>
#include <sl/sl_string.h>
#include <sl/sl_memory.h>
#include <sl/sl_libc_stdio.h>

struct sl_file_t
{
    sl_extends_object();

    sl_string_t     *filename;
    FILE            *fd;
};

SL_API sl_file_t* sl_file_new(const sl_c *path)
{
    sl_file_t *me;

    me = (sl_file_t*)sl_object_new(sizeof(*me));

    me->tname    = "file";
    me->destruct = (sl_destruct_func)sl_file_destruct;
    me->filename = sl_string_new(path);
    me->fd       = slc_fopen(path, "r+");

    if (!me->fd)
        me->fd = slc_fopen(path, "w+");

    return me;
}

SL_API void sl_file_destruct(sl_file_t *me)
{
    slc_fclose(me->fd);
    sl_object_delete(me->filename);

    sl_object_destruct(me);
}

SL_API sl_b sl_file_eof(sl_file_t *me)
{
    sl_assert(me->fd);
    return slc_feof(me->fd);
}

SL_API sl_string_t* sl_file_read_line(sl_file_t *me)
{
    sl_string_t *s;
    sl_c buf[32];
    sl_i i;

    sl_assert(me->fd);

    s = sl_string_new(0);
    while (!slc_feof(me->fd))
    {
        sl_memory_zero(buf, sizeof(buf));
        slc_fgets(buf, sizeof(buf), me->fd);
        sl_string_append(s, buf);

        for (i = 0; i < sizeof(buf); i++)
            if (buf[i] == '\n')
                goto done;
    }

done:
    sl_string_trim_end_newline_char(s);
    
    return s;
}

SL_API void sl_file_write_line(sl_file_t *me, sl_string_t *s)
{
    /* we don't write the '\0' character. */
    sl_assert(me->fd);
    slc_fwrite(s->c_str, s->pos, 1, me->fd);
    slc_fwrite("\n", 1, 1, me->fd);
}

SL_API void sl_file_read(sl_file_t *me, sl_c *buf, sl_i sz)
{
    sl_assert(me->fd);
    slc_fread(buf, (sl_ui)sz, 1, me->fd);
}

SL_API void sl_file_write(sl_file_t *me, const sl_c *buf, sl_i sz)
{
    sl_assert(me->fd);
    slc_fwrite(buf, (sl_ui)sz, 1, me->fd);
}

SL_API sl_i sl_file_read_int(sl_file_t *me)
{
    sl_i v = 0x12345678;
    sl_assert(me->fd);
    slc_fread((sl_c*)&v, sizeof(v), 1, me->fd);
    return v;
}

SL_API sl_f sl_file_read_float(sl_file_t *me)
{
    sl_f v = 0x12345678;
    sl_assert(me->fd);
    slc_fread((sl_c*)&v, sizeof(v), 1, me->fd);
    return v;
}

SL_API sl_d sl_file_read_double(sl_file_t *me)
{
    sl_d v = 0x1234567812345678;
    sl_assert(me->fd);
    slc_fread((sl_c*)&v, sizeof(v), 1, me->fd);
    return v;
}

SL_API void sl_file_write_int(sl_file_t *me, sl_i v)
{
    sl_assert(me->fd);
    slc_fwrite((sl_c*)&v, sizeof(v), 1, me->fd);
}

SL_API void sl_file_write_float(sl_file_t *me, sl_f v)
{
    sl_assert(me->fd);
    slc_fwrite((sl_c*)&v, sizeof(v), 1, me->fd);
}

SL_API void sl_file_write_double(sl_file_t *me, sl_d v)
{
    sl_assert(me->fd);
    slc_fwrite((sl_c*)&v, sizeof(v), 1, me->fd);
}

SL_API void sl_file_seek(sl_file_t *me, sl_ul pos, sl_file_seek_mode_e mode)
{
    switch (mode)
    {
        case sl_file_seek_mode_set:
            slc_fseek(me->fd, pos, SEEK_SET); break;
        case sl_file_seek_mode_end:
            slc_fseek(me->fd, pos, SEEK_END); break;
        case sl_file_seek_mode_current:
            slc_fseek(me->fd, pos, SEEK_CUR); break;
        default:
            sl_assert(0);
    }
}

SL_API sl_ul sl_file_length(sl_file_t *me)
{
    sl_ul cur;
    sl_ul l;

    cur = slc_ftell(me->fd);
    slc_fseek(me->fd, 0, SEEK_END);
    l = slc_ftell(me->fd);

    slc_fseek(me->fd, cur, SEEK_SET);

    return l;
}

