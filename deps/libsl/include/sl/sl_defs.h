#ifndef __SL_DEFS_H__
#define __SL_DEFS_H__

#include <sl/sl_libc_defs.h>
#include <sl/sl_libc_assert.h>

#define sl_to_me(type_)     type_ *me = (type_*)me_
#define sl_unused(v)        (void)(v)

#define sl_min(a, b)        ((a) < (b) ? (a) : (b))
#define sl_max(a, b)        ((a) < (b) ? (b) : (a))

#endif
