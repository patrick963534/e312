#include <sl/sl_log.h>
#include <sl/sl_libc_stdarg.h>

SL_API void sl_log_(const sl_c *type, const sl_c *fmt, ...)
{
    sl_c buf[256];
    slc_va_list va;

    slc_va_start(va, fmt);
    slc_vsnprintf(buf, sizeof(buf), fmt, va);
    slc_va_end(va);

    slc_printf("[%s] %s\r\n", type, buf);
    slc_fflush(stdout);
}
