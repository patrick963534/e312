#include <stdio.h>
#include <sl/sl_string.h>
#include <cu/cu_all.h>

static void test_string(void)
{
    sl_string_t *str;

    cu_string_equals("aab1", "aaa");

    str = sl_string_new("1234567890123456");
    printf("%s\n", str->c_str);
    sl_object_delete(str);

    str = sl_string_new("ñ");
    printf("%s\n", str->c_str);
    sl_object_delete(str);

    str = sl_string_new("龙之谷");
    printf("%s\n", str->c_str);
    sl_object_delete(str);
}

int a = 1 << 2;

int main()
{
    test_string();
    return 1;
}
