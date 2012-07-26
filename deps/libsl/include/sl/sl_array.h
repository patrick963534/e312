#ifndef __SL_ARRAY_H__
#define __SL_ARRAY_H__

#include <sl/sl_defs.h>

typedef struct sl_array_t
{
   sl_extends_object();

   sl_object_t  *objects;
   sl_i          sz;
} sl_array_t;

SL_API sl_array_t* sl_array_new();
SL_API sl_array_t* sl_array_add(sl_array_t *me, sl_object_t *o);
SL_API sl_array_t* sl_array_set(sl_array_t *me, int index, sl_object_t *o);
SL_API sl_array_t* sl_array_remove(sl_array_t *me, int index);

#define sl_array_for_each(Pos, Me)  \
    for (Pos = Me->objects; Pos != Me->objects + Me->sz; Pos++)

#endif
