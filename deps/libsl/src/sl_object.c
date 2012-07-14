#include <sl/sl_object.h>
#include <sl/sl_memory.h>

#define SL_SERIAL_CHECK_ID      0xf1f1a1a1
#define SL_HEAP_CHECK_ID        0xe1e1b1b2
#define SL_VALID_CHECK_ID       0xd1d1c11

SL_API void sl_object_destruct(void *me_)
{
    sl_unused(me_);
}

SL_API sl_object_t* sl_object_new(sl_i sz)
{
    sl_object_t *me;

    assert(sizeof(*me) >= sz);
    
    me = (sl_object_t*)sl_memory_new(sz);

    me->serial_check_id = SL_SERIAL_CHECK_ID;
    me->valid_check_id = SL_VALID_CHECK_ID;
    me->destruct = sl_object_destruct;

    return me;
}

SL_API sl_b sl_object_is_valid(void *me_)
{
    sl_to_me(sl_object_t);

    if (!me)
        return 0;

    sl_assert(me->serial_check_id == SL_SERIAL_CHECK_ID);

    return me->valid_check_id == SL_VALID_CHECK_ID;
}

SL_API void sl_object_delete(void *me_)
{
    sl_to_me(sl_object_t);

    if (!me)
        return;

    sl_assert(me->serial_check_id == SL_SERIAL_CHECK_ID);
    sl_assert(me->valid_check_id  == SL_VALID_CHECK_ID);
    
    if (me->destruct)
        me->destruct(me_);

    me->valid_check_id = 0;

    if (me->heap_check_id == SL_HEAP_CHECK_ID)
        sl_free(me);
}
