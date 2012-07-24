#ifndef __SL_LOG_H__
#define __SL_LOG_H__

#include <sl/sl_defs.h>
#include <sl/sl_libc_stdio.h>

SL_API void sl_log_(const sl_c *type, const sl_c *fmt, ...);

#define sl_log(fmt, arg...)     sl_log_("[INFO]", fmt, arg)

//#define sl_log(fmt, arg...) do { sl_printf(fmt, arg); sl_fflush(stdout); } while(0)

#endif
