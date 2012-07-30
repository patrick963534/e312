#include <sl/sl_list.h>
#include <sl/sl_memory.h>

struct sl_list_node_s
{
    struct sl_list_node_s *prev;
    struct sl_list_node_s *next;
    void          *data;
};

SL_API sl_list_t* sl_list_new(const char *tag)
{
    sl_list_t *me;

    me = (sl_list_t*)sl_object_new(sizeof(*me));

    me->destruct = (sl_destruct_func)sl_list_destruct;
    me->tname    = "list";
    me->tag      = sl_string_new(tag);
    me->count    = 0;
    me->head     = sl_memory_new(sizeof(*me->head));

    me->head->next = me->head;
    me->head->prev = me->head;

    return me;
}

SL_API void sl_list_destruct(sl_list_t *me)
{
    sl_list_clear(me);
    sl_memory_delete(me->head);
    sl_object_delete(me->tag);
    sl_object_destruct(me);
}

SL_API void sl_list_add(sl_list_t *me, void *v)
{
    sl_list_node_s *prev = me->head->prev;
    sl_list_node_s *next = me->head;
    sl_list_node_s *n;

    n = sl_memory_new(sizeof(*n));
    n->data = v;

    next->prev = n;
    n->next    = next;
    n->prev    = prev;
    prev->next = n;

    me->count++;
}

SL_API int sl_list_index(sl_list_t *me, void *v)
{
    sl_list_node_s *cur;
    int i;

    i = 0;
    cur = me->head->next;

    while (cur != me->head)
    {
        if (cur->data == v)
            return i;

        i++;
        cur = cur->next;
    }

    return -1;
}

SL_API void sl_list_remove(sl_list_t *me, void *v)
{
    sl_list_node_s *cur, *prev;

    prev = me->head;
    cur  = me->head->next;

    while (cur != me->head)
    {
        if (cur->data == v)
        {
            prev->next = cur->next;
            cur->next->prev = prev;

            sl_memory_delete(cur);

            break;
        }

        prev = cur;
        cur  = cur->next;
    }
}

SL_API void* sl_list_at(sl_list_t *me, int index)
{
    sl_list_node_s *cur;
    int i; 

    if (index > me->count)
        return NULL;

    i = 0;
    cur = me->head->next;

    while (cur != me->head)
    {
        if (i == index)
            return cur->data;

        i++;
        cur = cur->next;
    }

    return NULL;
}

SL_API sl_i sl_list_count(sl_list_t *me)
{
    return me->count;
}

SL_API void sl_list_clear(sl_list_t *me)
{
    sl_list_node_s *cur, *temp;

    cur = me->head->next;

    while (cur != me->head)
    {
        temp = cur;
        cur  = cur->next;
        sl_memory_delete(temp);
    }
}

SL_API void* sl_list_begin(sl_list_t *me)
{
    if (me->count == 0)
        return NULL;

    me->pos = me->head->next;

    return me->pos->data;
}

SL_API void* sl_list_next(sl_list_t *me)
{
    me->pos = me->pos->next;

    return me->pos->data;
}

SL_API sl_b sl_list_end(sl_list_t *me)
{
    return me->pos == me->head;
}
