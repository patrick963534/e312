#ifndef __SL_LIBC_STDIO_H__
#define __SL_LIBC_STDIO_H__

#include <stdio.h>

#define sl_clearerr clearerr    /* (FILE *stream); */
#define sl_fclose   fclose      /* (FILE *stream); */
#define sl_feof     feof        /* (FILE *stream); */
#define sl_ferror   ferror      /* (FILE *stream); */
#define sl_fflush   fflush      /* (FILE *stream); */
#define sl_fgetpos  fgetpos     /* (FILE *stream, fpos_t *pos); */
#define sl_fsetpos  fsetpos     /* (FILE *stream, const fpos_t *pos); */
#define sl_fseek    fseek       /* (FILE *stream, long int offset, int whence); */
#define sl_ftell    ftell       /* (FILE *stream); */
#define sl_rewind   rewind      /* (FILE *stream); */
#define sl_setbuf   setbuf      /* (FILE *stream, char *buffer); */
#define sl_setvbuf  setvbuf     /* (FILE *stream, char *buffer, int mode, size_t size); */
#define sl_fprintf  fprintf     /* (FILE *stream, const char *format, ...); */
#define sl_fscanf   fscanf      /* (FILE *stream, const char *format, ...); */
#define sl_vfprintf vfprintf    /* (FILE *stream, const char *format, va_list arg); */
#define sl_fgetc    fgetc       /* (FILE *stream); */
#define sl_getc     getc        /* (FILE *stream); */

#define sl_fgets    fgets       /* (char *str, int n,   FILE *stream); */
#define sl_fputc    fputc       /* (int char,           FILE *stream); */
#define sl_fputs    fputs       /* (const char *str,    FILE *stream); */
#define sl_putc     putc        /* (int char,           FILE *stream); */
#define sl_ungetc   ungetc      /* (int char,           FILE *stream); */

#define sl_fread    fread       /* (void *ptr, size_t size, size_t nmemb, FILE *stream); */
#define sl_freopen  freopen     /* (const char *filename, const char *mode, FILE *stream); */
#define sl_fwrite   fwrite      /* (const void *ptr, size_t size, size_t nmemb, FILE *stream); */

#define sl_fopen    fopen       /* (const char *filename, const char *mode); */
#define sl_remove   remove      /* (const char *filename); */
#define sl_rename   rename      /* (const char *old_filename, const char *new_filename); */

#define sl_tmpfile  tmpfile     /* (void); */
#define sl_tmpnam   tmpnam      /* (char *str); */

#define sl_printf   printf      /* (const char *format, ...); */
#define sl_sprintf  sprintf     /* (char *str, const char *format, ...); */
#define sl_vprintf  vprintf     /* (const char *format, va_list arg); */
#define sl_vsprintf vsprintf    /* (char *str, const char *format, va_list arg); */
#define sl_scanf    scanf       /* (const char *format, ...); */
#define sl_sscanf   sscanf      /* (const char *str, const char *format, ...); */

#define sl_getchar  getchar     /* (void); */
#define sl_gets     gets        /* (char *str); */
#define sl_putchar  putchar     /* (int char); */
#define sl_puts     puts        /* (const char *str); */
#define sl_perror   perror      /* (const char *str); */

#endif
