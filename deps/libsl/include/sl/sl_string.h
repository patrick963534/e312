#ifndef __SL_STRING_H__
#define __SL_STRING_H__ 

#include <sl/sl_defs.h>
#include <sl/sl_object.h>

#define SL_CHAR_SZ  7

typedef struct sl_char_t
{
    sl_c    buf[SL_CHAR_SZ];
} sl_char_t;

/**
 Description:
    Get the 1st UTF-8 multi-bytes character from @s.
 Remark:
    Try NOT to modify sl_char_t object.
*/
SL_API sl_char_t    sl_char_from(const sl_c *s);

SL_API sl_b         sl_char_equals(sl_char_t ch1, sl_char_t ch2);

/**
 Description:
     Both sl_c* and sl_string_t are used to identify a UTF-8.
     Only sl_string_t can used to do modification.
*/ 
typedef struct sl_string_t
{
    sl_extends_object();

    sl_c        *c_str; /* buffer. */
    sl_i         sz;    /* size of buffer. */
    sl_i         pos;   /* point to '\0' position. */
} sl_string_t;

/**
 Description:
     Create a sl_string_t by an UTF-8 string.
 @str: Assert @str is an UTF-8 string.
*/
SL_API sl_string_t* sl_string_new(const sl_c *str);

/**
 Description:
     Format a string to create a sl_string_t instance.
 @fmt: Assert @fmt is an UTF-8 string.
 @sz:  The maximize size of buffer. 
 @return: If the real result larger than sz, then return NULL.
          Assert the returning value sl_string_t.c_str is an UTF-8 string.
*/
SL_API sl_string_t* sl_string_format(sl_i sz, const sl_c *fmt, ...);

/**
 Description:
     Append a @str string to the end of @me string.
 @me: Assert @me.c_str is an UTF-8 string.
 @str: Assert it's an UTF-8 string.
*/
SL_API void         sl_string_append(sl_string_t *me, const sl_c *str);

/**
 Description:
     Get a small string to indicate a UTF-8 multi-bytes character.
     Get the @n mutli-byte character in @me string.
 @n: The nth multi-byte character.
 @return: It's a UTF-8 string, with a multi-byte character.
*/
SL_API sl_char_t    sl_string_get_char(sl_string_t *me, sl_i n);

/**
 Update the nth multi-bytes character to @ch in @me string.
 @ch: Assert it's an UTF-8 string.
*/
SL_API void         sl_string_set_char(sl_string_t *me, sl_i pos, const sl_char_t ch);

/**
 @return: Get count of characters in UTF-8 string @me.
 @remark: Each character might be multi-bytes.
*/
SL_API sl_i         sl_string_char_count(sl_string_t *me);

/**
 Check string @str1 and @str2 are the same. We advise @str1 and @str2 are 
 both UTF-8 string.
*/
SL_API sl_b         sl_string_equals(const sl_string_t *s1, const sl_string_t *s2);

SL_API void sl_string_trim_string(sl_string_t *me, sl_string_t *trim);

SL_API void         sl_string_trim(sl_string_t *me, sl_char_t ch);

/**
 Destructor of sl_string_t, it will be invoked automaticlly  
 when call sl_object_delete(...) 
*/
SL_API void         sl_string_destruct(sl_string_t *me);

#endif
