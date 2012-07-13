#include <sl/sl_object.h>
#include <sl/sl_memory.h>

#define SL_SERIAL_CHECK_ID      0xf1f1a1a1
#define SL_HEAP_CHECK_ID        0xe1e1b1b2
#define SL_VALID_CHECK_ID       0xd1d1c11

SL_API sl_object_t sl_object_new(sl_i sz)
{
    sl_object_t *me = (sl_object_t*)sl_memory_new(sz);

    return me;
}

SL_API sl_b sl_object_is_valid(void *me_)
{
    sl_to_me(sl_object_t);

    if (me->sl_serial_check_id != SL_SERIAL_CHECK_ID ||
        me->valid_check_id != SL_VALID_CHECK_ID)
    {
        return 0;
    }

    return 1;
}

SL_API void sl_object_delete(void *me_)
{
    sl_to_me(sl_object_t);

    if (!me || me->sl_serial_id != SL_SERIAL_CHECK_ID)
        return;
    
    me->valid_check_id = 0;

    if (me->is_heap)
    {
        
    }
}
