#include <stdio.h>
#include <sl/sl_string.h>

int main()
{
    sl_string_t *str = sl_string_new("123456789012345");

    printf("%s\n", sl_string_to_char_array(str));
    return 1;
}
