#ifndef __SL_LIBC_STRING_H__
#define __SL_LIBC_STRING_H__

#define sl_memchr   memchr  /* (const void *str, int c, size_t n); */
#define sl_memcmp   memcmp  /* (const void *str1, const void *str2, size_t n); */
#define sl_memcpy   memcpy  /* (void *str1, const void *str2, size_t n); */
#define sl_memmove  memmove /* (void *str1, const void *str2, size_t n); */
#define sl_memset   memset  /* (void *str, int c, size_t n); */
#define sl_strcat   strcat  /* (char *str1, const char *str2); */
#define sl_strncat  strncat /* (char *str1, const char *str2, size_t n); */
#define sl_strchr   strchr  /* (const char *str, int c); */
#define sl_strcmp   strcmp  /* (const char *str1, const char *str2); */
#define sl_strncmp  strncmp /* (const char *str1, const char *str2, size_t n); */
#define sl_strcoll  strcoll /* (const char *str1, const char *str2); */
#define sl_strcpy   strcpy  /* (char *str1, const char *str2); */
#define sl_strncpy  strncpy /* (char *str1, const char *str2, size_t n); */
#define sl_strcspn  strcspn /* (const char *str1, const char *str2); */
#define sl_strerror strerror/* (int errnum); */
#define sl_strlen   strlen  /* (const char *str); */
#define sl_strpbrk  strpbrk /* (const char *str1, const char *str2); */
#define sl_strrchr  strrchr /* (const char *str, int c); */
#define sl_strspn   strspn  /* (const char *str1, const char *str2); */
#define sl_strstr   strstr  /* (const char *str1, const char *str2); */
#define sl_strtok   strtok  /* (char *str1, const char *str2); */
#define sl_strxfrm  strxfrm /* (char *str1, const char *str2, size_t n); */

#endif
