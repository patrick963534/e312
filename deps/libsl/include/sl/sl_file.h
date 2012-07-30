#ifndef __SL_FILE_H__
#define __SL_FILE_H__

#include <sl/sl_defs.h>
#include <sl/sl_string.h>

typedef struct sl_file_t sl_file_t;

SL_API sl_file_t*       sl_file_new(const sl_c *path);
SL_API void             sl_file_destruct(sl_file_t *me);
SL_API sl_string_t*     sl_file_next_line(sl_file_t *me);

#endif
