#include <stdio.h>
#include <sl/sl_string.h>

static int get_int()
{
    return 0;
}

static int v[] = {
    get_int(),
    get_int(),
    get_int(),
    get_int(),
};

int main()
{
    sl_string_t *str = sl_string_new("123456789012345");
    printf("%s\n", sl_string_to_char_array(str));

    sl_object_delete(str);

    printf("%d", v[0]);

    return 1;
}
