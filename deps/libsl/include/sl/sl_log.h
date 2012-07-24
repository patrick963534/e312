#ifndef __SL_LOG_H__
#define __SL_LOG_H__

#include <sl/sl_defs.h>
#include <sl/sl_libc_stdio.h>

#define log(fmt, arg...) do { sl_printf(fmt, arg); sl_fflush(stdout); } while(0)

#endif
