#ifndef __SL_STRING_H__
#define __SL_STRING_H__ 

#include <sl/sl_defs.h>
#include <sl/sl_object.h>

typedef struct sl_string_t
{
    sl_extends_object();

    sl_c    *_buf;
    int      _sz;
} sl_string_t;

#endif
