#include <stdio.h>
#include <sl/sl_string.h>

static void test_string(void)
{
    sl_string_t *str = sl_string_new("1234567890123456");
    sl_object_delete(str);
}

int main()
{
    test_string();
    return 1;
}
