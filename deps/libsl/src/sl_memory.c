#include <sl/sl_memory.h>
#include <sl/sl_libc_assert.h>
#include <sl/sl_libc_stdlib.h>
#include <sl/sl_libc_stdio.h>

typedef struct node_s
{
    sl_i            sz;
    void           *p;
    const sl_c     *file;
    const sl_c     *func;
    sl_i            line;

    struct node_s  *next;
} node_s;

static node_s *head = NULL;

static node_s* create_node(void *p, sl_i sz, SL_DEBUG_FILE_INFO_PARAM)
{
    node_s *node;

    node = (node_s*)slc_calloc(1, sizeof(*node));
    node->sz   = sz;
    node->p    = p;
    node->file = file;
    node->func = func;
    node->line = line;

    return node;
}

static void add_node(void *p, sl_i sz, SL_DEBUG_FILE_INFO_PARAM)
{
    node_s *node;

    if (head == NULL)
        head = (node_s*)slc_calloc(1, sizeof(*head));

    node = create_node(p, sz, file, func, line);
    node->next  = head->next;
    head->next  = node;
}

static void del_node(void *p)
{
    node_s *prev, *next;
    
    prev = head;
    next = head->next;

    while (next != 0)
    {
        if (next->p == p)
        {
            prev->next = next->next;
            slc_free(next);
            return;
        }

        prev = next;
        next = next->next;
    }

    /* fail to find the pointer. please verify where the pointer from. */
    sl_assert(1);
}

SL_API void* sl_memory_new_(sl_i sz, SL_DEBUG_FILE_INFO_PARAM)
{
    void *p = slc_calloc(1, sz);
    add_node(p, sz, file, func, line);

    return p;
}

SL_API void* sl_memory_renew_(void *p, sl_i sz, SL_DEBUG_FILE_INFO_PARAM)
{
    del_node(p);
    p = slc_realloc(p, sz);
    add_node(p, sz, file, func, line);

    return p;
}

SL_API void sl_memory_delete_(void *p, SL_DEBUG_FILE_INFO_PARAM)
{
    del_node(p);
    slc_free(p);
}

SL_API void sl_memory_zero(void *p, sl_i sz)
{
    char *b = (char*)p;
    char *be = b + sz;

    while (b < be)
        *b++ = 0;
}

SL_API void sl_memory_copy(void *dst, sl_i dst_sz, void *src, sl_i src_sz)
{
    sl_c *s, *d, *se, *de;

    s  = (sl_c*)src;
    d  = (sl_c*)dst;
    se = s + src_sz;
    de = d + dst_sz;

    while (s < se && d < de)
        *d++ = *s++;
}

SL_API void sl_memory_leak_report()
{
    node_s *next;
    int count;
    
    count = 0;
    next  = head->next;

    while (next != 0)
    {
        printf("/**************************/\n");
        printf("function: %s in %s:%d. \n", next->func, next->file, next->line);
        printf("pointer: 0x%x\n", (sl_ui)next->p);

        count += next->sz;
        next = next->next;
    }

    printf("/**************************/\n");

    if (count == 0)
        printf("No memory leak detected.\n");
    else
        printf("Memory leak size: %d bytes.\n", count);
}
