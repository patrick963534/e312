#ifndef __SL_OBJECT_H__
#define __SL_OBJECT_H__

#include <sl/sl_defs.h>

#define sl_extends_object() \
    sl_i    sl_serial_check_id; /* use to check it's inheirate from sl_object_t. */ \
    sl_i    valid_check_id;     /* check whether object is released. */ \
    sl_i    heap_check_id       /* check is heap or stack. */

typedef struct sl_object_t
{
    sl_extends_object();
} sl_object_t;

SL_API sl_object_t sl_object_new(sl_i sz);

SL_API sl_b sl_object_is_valid(void *ptr);

SL_API void sl_object_delete(void *ptr);

#endif
