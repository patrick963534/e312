#ifndef __SL_LIST_H__
#define __SL_LIST_H__

#include <sl/sl_defs.h>
#include <sl/sl_object.h>
#include <sl/sl_string.h>

typedef struct sl_list_node_s sl_list_node_s;

typedef struct sl_list_t
{
    sl_extends_object();

    sl_string_t     *tag;
    sl_list_node_s  *head;
    sl_list_node_s  *pos;
    int              count; /* private, don't use it directly. */
} sl_list_t;

SL_API sl_list_t*       sl_list_new(const char *tag);
SL_API void             sl_list_destruct(sl_list_t *me);
SL_API void             sl_list_add(sl_list_t *me, void *v);
SL_API int              sl_list_index(sl_list_t *me, void *v);
SL_API sl_b             sl_list_contains(sl_list_t *me, void *v);
SL_API void             sl_list_remove(sl_list_t *me, void *v);
SL_API void*            sl_list_at(sl_list_t *me, int index);
SL_API sl_i             sl_list_count(sl_list_t *me);
SL_API void             sl_list_clear(sl_list_t *me);
SL_API void*            sl_list_begin(sl_list_t *me);
SL_API void*            sl_list_next(sl_list_t *me);
SL_API sl_b             sl_list_end(sl_list_t *me);

#define sl_list_for_each(Pos, Me, Type) \
    for (Pos = (Type*)sl_list_begin(Me); !sl_list_end(Me); Pos = (Type*)sl_list_next(Me))

#endif
