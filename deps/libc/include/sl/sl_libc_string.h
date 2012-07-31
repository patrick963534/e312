#ifndef __SL_LIBC_STRING_H__
#define __SL_LIBC_STRING_H__

#define slc_memchr   memchr  /* (const void *str, int c, size_t n); */
#define slc_memcmp   memcmp  /* (const void *str1, const void *str2, size_t n); */
#define slc_memcpy   memcpy  /* (void *str1, const void *str2, size_t n); */
#define slc_memmove  memmove /* (void *str1, const void *str2, size_t n); */
#define slc_memset   memset  /* (void *str, int c, size_t n); */
#define slc_strcat   strcat  /* (char *str1, const char *str2); */
#define slc_strncat  strncat /* (char *str1, const char *str2, size_t n); */
#define slc_strchr   strchr  /* (const char *str, int c); */
#define slc_strcmp   strcmp  /* (const char *str1, const char *str2); */
#define slc_strncmp  strncmp /* (const char *str1, const char *str2, size_t n); */
#define slc_strcoll  strcoll /* (const char *str1, const char *str2); */
#define slc_strcpy   strcpy  /* (char *str1, const char *str2); */
#define slc_strncpy  strncpy /* (char *str1, const char *str2, size_t n); */
#define slc_strcspn  strcspn /* (const char *str1, const char *str2); */
#define slc_strerror strerror/* (int errnum); */
#define slc_strlen   strlen  /* (const char *str); */
#define slc_strpbrk  strpbrk /* (const char *str1, const char *str2); */
#define slc_strrchr  strrchr /* (const char *str, int c); */
#define slc_strspn   strspn  /* (const char *str1, const char *str2); */
#define slc_strstr   strstr  /* (const char *str1, const char *str2); */
#define slc_strtok   strtok  /* (char *str1, const char *str2); */
#define slc_strxfrm  strxfrm /* (char *str1, const char *str2, size_t n); */
#define slc_strdup   strdup  /* (const char *s); */

#endif
