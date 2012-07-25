#include <stdio.h>
#include <sl/sl_string.h>
#include <sl/sl_log.h>
#include <cu/cu_all.h>

static void test_string(void)
{
    sl_string_t *str;

    str = sl_string_new("1234567890123456");
    cu_string_equals("1234567890123456", str->c_str);
    cu_int_equals(16, sl_string_char_count(str));
    sl_log("%s", str->c_str);
    sl_object_delete(str);

    str = sl_string_new("ñ");
    cu_string_equals("ñ", str->c_str);
    cu_int_equals(1, sl_string_char_count(str));
    sl_log("%s", str->c_str);
    sl_object_delete(str);

    str = sl_string_new("龙之谷");
    cu_string_equals("龙之谷", str->c_str);
    cu_int_equals(3, sl_string_char_count(str));
    sl_log("%s", str->c_str);
    sl_object_delete(str);

    str = sl_string_format(20, "hello %s", "world");
    cu_int_equals(11, sl_string_char_count(str));
    sl_log("%s", str->c_str);
    sl_object_delete(str);

    str = sl_string_format(11, "hello %s", "world");
    cu_pointer_equals(NULL, str);
    sl_object_delete(str);

}

int a = 1 << 2;

int main()
{
    test_string();

    return 1;
}
