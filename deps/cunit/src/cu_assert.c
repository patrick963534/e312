#include <sl/sl_defs.h>
#include <sl/sl_log.h>
#include <stdio.h>

static sl_i nfail = 0;

SL_API sl_b cu_string_equals_(const sl_c *expected, const sl_c *str, const char *file, const char *func, int line)
{
    const char *s1 = expected;
    const char *s2 = str;
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

        sl_log("[%3d ]Function: %s, in file: %s:%d.", nfail, func, file, line);
        sl_log("      Expected: '%s'. But: '%s'.", expected, str);
    }

    return ret;
}

SL_API sl_b cu_int_equals_(sl_i expected, sl_i v, const char *file, const char *func, int line)
{
    if (expected != v)
    {
        nfail++;

        sl_log("[%3d ]Function: %s, in file: %s:%d.", nfail, func, file, line);
        sl_log("      Expected: '%d'. But: '%d'.", expected, v);

        return 0;
    }

    return 1;
}

SL_API sl_b cu_pointer_equals_(void *expected, void *v, const char *file, const char *func, int line)
{
    if (expected != v)
    {
        nfail++;

        sl_log("[%3d ]Function: %s, in file: %s:%d.", nfail, func, file, line);
        sl_log("      Expected: '0x%x'. But: '0x%x'.", expected, v);

        return 0;
    }

    return 1;
}
