#ifndef __SL_FILE_H__
#define __SL_FILE_H__

#include <sl/sl_defs.h>
#include <sl/sl_string.h>

typedef struct sl_file_t sl_file_t;

SL_API sl_file_t*       sl_file_new(const sl_c *path);
SL_API void             sl_file_destruct(sl_file_t *me);
SL_API sl_string_t*     sl_file_next_line(sl_file_t *me);
SL_API sl_b             sl_file_eof(sl_file_t *me);
SL_API void             sl_file_read(sl_file_t *me, sl_c *buf, sl_i sz);
SL_API void             sl_file_write(sl_file_t *me, const sl_c *buf, sl_i sz);

SL_API sl_i             sl_file_read_int(sl_file_t *me);
SL_API sl_f             sl_file_read_float(sl_file_t *me);
SL_API sl_d             sl_file_read_double(sl_file_t *me);

SL_API void             sl_file_write_int(sl_file_t *me, sl_i v);
SL_API void             sl_file_write_float(sl_file_t *me, sl_f v);
SL_API void             sl_file_write_double(sl_file_t *me, sl_d v);

#endif
