#include <stdio.h>
#include <sl/sl_string.h>
#include <sl/sl_memory.h>
#include <sl/sl_list.h>
#include <sl/sl_log.h>
#include <cu/cu_all.h>

static void test_char(void)
{
    sl_string_t     *str;
    sl_char_t  ch;

    str = sl_string_new("1234567890123456");
    ch  = sl_char_from(str->c_str);
    cu_string_equals("1", ch.buf);
    sl_object_delete(str);

    str = sl_string_new("ñ");
    ch  = sl_char_from(str->c_str);
    cu_string_equals("ñ", ch.buf);
    sl_object_delete(str);

    str = sl_string_new("龙之谷");
    ch  = sl_char_from(str->c_str);
    cu_string_equals("龙", ch.buf);
    sl_object_delete(str);
}

static void test_string(void)
{
    sl_string_t *str;
    sl_char_t    ch;

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

    str = sl_string_new("good morning.");
    sl_string_append(str, "guys");
    cu_string_equals("good morning.guys", str->c_str);
    sl_object_delete(str);

    str = sl_string_new("good morning.");
    ch  = sl_string_get_char(str, 5);
    cu_string_equals("m", ch.buf);
    sl_object_delete(str);

    str = sl_string_new("龙之谷");
    ch  = sl_string_get_char(str, 1);
    cu_string_equals("之", ch.buf);
    sl_object_delete(str);

    str = sl_string_new("龙之谷");
    sl_string_set_char(str, 2, sl_char_from("渊"));
    sl_string_set_char(str, 1, sl_char_from("蛇"));
    cu_string_equals("龙蛇渊", str->c_str);
    sl_object_delete(str);
}

static void test_list()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    sl_list_t *list;
    int       *p;
    int        i;
    
    /* test loop through */
    {
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

    /* test get item by id and remove. */
    {
        list = sl_list_new("int");
        for (i = 0; i < sl_count(a); i++)
        {
            sl_list_add(list, &a[i]);
        }

        cu_int_equals(a[5], *((int*)sl_list_at(list, 5)));

        sl_list_remove(list, sl_list_at(list, 5));

        sl_list_for_each(p, list, int)
        {
            cu_assert(*p != a[5]);
        }

        sl_object_delete(list);
    }
}

int a = 1 << 2;

int main()
{
    test_string();
    test_char();
    test_list();

    sl_memory_leak_report();

    return 1;
}
