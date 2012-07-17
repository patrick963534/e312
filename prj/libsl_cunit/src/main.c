#include <stdio.h>
#include <sl/sl_string.h>

static void test_string(void)
{
    sl_string_t *str = sl_string_new("1234567890123456");
}

int main()
{
    printf("%s\n", str->c_str);

    sl_object_delete(str);

    return 1;
}
