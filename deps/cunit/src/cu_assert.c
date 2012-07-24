#include <sl/sl_defs.h>
#include <sl/sl_log.h>

SL_API sl_b cu_string_equals_(sl_c *expected, sl_c *str, const char *file, const char *func, int line)
{
    char *s1 = expected;
    char *s2 = str;
    sl_b ret = 1;

    while (*s1 && *s2)
    {
        if (*s1++ != *s2++)
        {
            ret = 0;
            break;
        }
    }

    if (!ret)
    {
        log("Function: %s, in file: %s:%d.\n", func, file, line);
        log("Expected: '%s'. But: '%s'.\n", expected, str);
    }

    return ret;
}

