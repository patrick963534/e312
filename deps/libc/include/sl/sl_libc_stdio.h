#ifndef __SL_LIBC_STDIO_H__
#define __SL_LIBC_STDIO_H__

#include <stdio.h>

#define slc_clearerr clearerr    /* (FILE *stream); */
#define slc_fclose   fclose      /* (FILE *stream); */
#define slc_feof     feof        /* (FILE *stream); */
#define slc_ferror   ferror      /* (FILE *stream); */
#define slc_fflush   fflush      /* (FILE *stream); */
#define slc_fgetpos  fgetpos     /* (FILE *stream, fpos_t *pos); */
#define slc_fsetpos  fsetpos     /* (FILE *stream, const fpos_t *pos); */
#define slc_fseek    fseek       /* (FILE *stream, long int offset, int whence); */
#define slc_ftell    ftell       /* (FILE *stream); */
#define slc_rewind   rewind      /* (FILE *stream); */
#define slc_setbuf   setbuf      /* (FILE *stream, char *buffer); */
#define slc_setvbuf  setvbuf     /* (FILE *stream, char *buffer, int mode, size_t size); */
#define slc_fprintf  fprintf     /* (FILE *stream, const char *format, ...); */
#define slc_fscanf   fscanf      /* (FILE *stream, const char *format, ...); */
#define slc_vfprintf vfprintf    /* (FILE *stream, const char *format, va_list arg); */
#define slc_fgetc    fgetc       /* (FILE *stream); */
#define slc_getc     getc        /* (FILE *stream); */

#define slc_fgets    fgets       /* (char *str, int n,   FILE *stream); */
#define slc_fputc    fputc       /* (int char,           FILE *stream); */
#define slc_fputs    fputs       /* (const char *str,    FILE *stream); */
#define slc_putc     putc        /* (int char,           FILE *stream); */
#define slc_ungetc   ungetc      /* (int char,           FILE *stream); */

#define slc_fread    fread       /* (void *ptr, size_t size, size_t nmemb, FILE *stream); */
#define slc_freopen  freopen     /* (const char *filename, const char *mode, FILE *stream); */
#define slc_fwrite   fwrite      /* (const void *ptr, size_t size, size_t nmemb, FILE *stream); */

#define slc_fopen    fopen       /* (const char *filename, const char *mode); */
#define slc_remove   remove      /* (const char *filename); */
#define slc_rename   rename      /* (const char *old_filename, const char *new_filename); */

#define slc_tmpfile  tmpfile     /* (void); */
#define slc_tmpnam   tmpnam      /* (char *str); */

#define slc_printf   printf      /* (const char *format, ...); */
#define slc_sprintf  sprintf     /* (char *str, const char *format, ...); */
#define slc_vprintf  vprintf     /* (const char *format, va_list arg); */
#define slc_vsprintf vsprintf    /* (char *str, const char *format, va_list arg); */
#define slc_scanf    scanf       /* (const char *format, ...); */
#define slc_sscanf   sscanf      /* (const char *str, const char *format, ...); */

#define slc_getchar  getchar     /* (void); */
#define slc_gets     gets        /* (char *str); */
#define slc_putchar  putchar     /* (int char); */
#define slc_puts     puts        /* (const char *str); */
#define slc_perror   perror      /* (const char *str); */

#endif
