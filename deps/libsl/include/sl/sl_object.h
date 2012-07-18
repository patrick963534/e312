#ifndef __SL_OBJECT_H__
#define __SL_OBJECT_H__

#include <sl/sl_defs.h>

typedef void (*sl_destruct_func)(void *me_);

#define sl_extends_object() \
    sl_i    serial_check_id; /* use to check it's inheirate from sl_object_t. */ \
    sl_i    valid_check_id;  /* check whether object is released. */ \
    sl_i    heap_check_id;   /* check is heap or stack. */ \
    sl_destruct_func destruct

/**
 All of the sl_object_t or its derived type have to be in heap.
*/
typedef struct sl_object_t
{
    sl_extends_object();
} sl_object_t;

SL_API sl_object_t* sl_object_new(sl_i sz);
SL_API void         sl_object_delete(void *me_);
SL_API sl_b         sl_object_is_valid(void *me_);
SL_API void         sl_object_destruct(void *me_);

#endif
