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
    me->fd       = slc_fopen(path, "rw");

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
    return slc_feof(me->fd);
}

SL_API sl_string_t* sl_file_next_line(sl_file_t *me)
{
    sl_string_t *s;
    sl_c buf[32];
    sl_i i;

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

