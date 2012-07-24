#include <sl/sl_log.h>
#include <sl/sl_libc_stdarg.h>

SL_API void sl_log_(const sl_c *type, const sl_c *fmt, ...)
{
    sl_c buf[256];
    sl_va_list va;

    sl_va_start(va, fmt);
    sl_vsnprintf(buf, sizeof(buf), fmt, va);
    sl_va_end(va);

    sl_printf("[%s] %s\r\n", type, buf);
    sl_fflush(stdout);
}
