#include <sl/sl_string.h>
#include <sl/sl_memory.h>

SL_API sl_string_t* sl_string_new()
{
    sl_string_t *me;

    me = (sl_string_t*)sl_object_new(sizeof(*me));
    me->destruct = (sl_destruct_func)sl_string_destruct;
    me->sz = 32;
    me->buf = (sl_c*)sl_memory_new(me->sz);

    return me;
}

SL_API sl_string_t* sl_string_from_char_array(const sl_c *str)
{
    return 0;
}

SL_API void sl_string_destruct(sl_string_t *me)
{
    sl_memory_delete(me->buf);
}

