#include <stdio.h>
#include <sl/sl_string.h>
#include <sl/sl_memory.h>
#include <sl/sl_list.h>
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

static void test_list()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    sl_list_t *list;
    int       *p;
    int        i;
    
    list = sl_list_new("int");
    for (i = 0; i < sl_count(a); i++)
    {
        sl_list_add(list, &a[i]);
    }

    i = 0;
    sl_list_for_each(p, list, int)
    {
        cu_int_equals(a[i++], *p);
    }
    cu_int_equals(10, i);

    sl_object_delete(list);
}

int a = 1 << 2;

int main()
{
    test_string();
    test_list();

    sl_memory_leak_report();

    return 1;
}
