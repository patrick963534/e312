#include <sl/sl_defs.h>
#include <sl/sl_log.h>
#include <stdio.h>

static sl_i nfail = 0;

SL_API sl_b cu_string_equals_(sl_c *expected, sl_c *str, const char *file, const char *func, int line)
{
    char *s1 = expected;
    char *s2 = str;
    sl_b ret = 1;

    while (*s1 || *s2)
    {
        if (*s1++ != *s2++)
        {
            ret = 0;
            break;
        }
    }

    if (!ret)
    {
        nfail++;

        sl_log("[%3d ]Function: %s, in file: %s:%d.\n", nfail, func, file, line);
        sl_log("      Expected: '%s'. But: '%s'.\n", expected, str);
    }

    return ret;
}

