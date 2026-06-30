/*
===========================================================================
q_vfs.h - libretro VFS shim for the Quake 3 filesystem layer.

All real file I/O in the libretro build is routed through libretro-common's
filestream_* API (streams/file_stream.c), which dispatches to the frontend's
RETRO_ENVIRONMENT_GET_VFS_INTERFACE when present and otherwise falls back to
libretro-common's own vfs_implementation.c. This header lets qcommon/files.c
and qcommon/ioapi.c use a thin, stdio-shaped surface (Q_FILE / Q_f*) without
sprinkling RETRO_VFS_* constants throughout the engine.

There are NO non-VFS file paths in the libretro build: do not call fopen/
fread/fwrite/fseek/ftell/fclose directly from engine code.
===========================================================================
*/

#ifndef __Q_VFS_H__
#define __Q_VFS_H__

#include <stdio.h>   /* SEEK_SET / SEEK_CUR / SEEK_END */
#include <stddef.h>  /* size_t */
#include <streams/file_stream.h>
#include <libretro.h>

typedef RFILE Q_FILE;

/* Translate an fopen()-style mode string to RETRO_VFS_FILE_ACCESS_* flags.
 * Only the modes the engine actually uses are handled: rb, wb, ab, r+b. */
static INLINE unsigned Q_VFS_TranslateMode(const char *mode)
{
   int has_read   = 0;
   int has_write  = 0;
   int has_append = 0;
   int has_plus   = 0;
   const char *p;

   for (p = mode; p && *p; p++)
   {
      switch (*p)
      {
         case 'r': has_read   = 1; break;
         case 'w': has_write  = 1; break;
         case 'a': has_append = 1; break;
         case '+': has_plus   = 1; break;
         default: break; /* 'b'/'t' are no-ops for the VFS */
      }
   }

   if (has_append)
      return RETRO_VFS_FILE_ACCESS_READ_WRITE |
             RETRO_VFS_FILE_ACCESS_UPDATE_EXISTING;
   if (has_plus)
   {
      if (has_write)
         return RETRO_VFS_FILE_ACCESS_READ_WRITE;
      return RETRO_VFS_FILE_ACCESS_READ_WRITE |
             RETRO_VFS_FILE_ACCESS_UPDATE_EXISTING;
   }
   if (has_write)
      return RETRO_VFS_FILE_ACCESS_WRITE;
   /* default: read */
   (void)has_read;
   return RETRO_VFS_FILE_ACCESS_READ;
}

static INLINE Q_FILE *Q_fopen(const char *path, const char *mode)
{
   if (!path || !mode)
      return NULL;
   return filestream_open(path, Q_VFS_TranslateMode(mode),
         RETRO_VFS_FILE_ACCESS_HINT_NONE);
}

static INLINE size_t Q_fread(void *ptr, size_t size, size_t nmemb, Q_FILE *f)
{
   int64_t got;
   if (!f || size == 0)
      return 0;
   got = filestream_read(f, ptr, (int64_t)(size * nmemb));
   if (got <= 0)
      return 0;
   return (size_t)got / size;
}

static INLINE size_t Q_fwrite(const void *ptr, size_t size, size_t nmemb, Q_FILE *f)
{
   int64_t put;
   if (!f || size == 0)
      return 0;
   put = filestream_write(f, ptr, (int64_t)(size * nmemb));
   if (put <= 0)
      return 0;
   return (size_t)put / size;
}

static INLINE int Q_fseek(Q_FILE *f, long offset, int whence)
{
   int seekpos;
   if (!f)
      return -1;
   switch (whence)
   {
      case SEEK_SET: seekpos = RETRO_VFS_SEEK_POSITION_START;   break;
      case SEEK_CUR: seekpos = RETRO_VFS_SEEK_POSITION_CURRENT; break;
      case SEEK_END: seekpos = RETRO_VFS_SEEK_POSITION_END;     break;
      default: return -1;
   }
   return (filestream_seek(f, (int64_t)offset, seekpos) < 0) ? -1 : 0;
}

static INLINE long Q_ftell(Q_FILE *f)
{
   if (!f)
      return -1L;
   return (long)filestream_tell(f);
}

static INLINE int Q_fclose(Q_FILE *f)
{
   if (!f)
      return 0;
   return filestream_close(f);
}

static INLINE int Q_fflush(Q_FILE *f)
{
   if (!f)
      return 0;
   return filestream_flush(f);
}

static INLINE int Q_ferror(Q_FILE *f)
{
   if (!f)
      return 1;
   return filestream_error(f);
}

/* Formatted write helpers for the few call sites (bot logging, weight dumps)
 * that used fprintf/vfprintf against a stream. Expands into a fixed buffer then
 * issues a single filestream write. Truncates beyond 4 KB per call, which is
 * ample for log lines. */
#include <stdarg.h>

static INLINE int Q_vfprintf(Q_FILE *f, const char *fmt, va_list ap)
{
   char    buf[4096];
   int     len;
   if (!f)
      return -1;
   len = vsnprintf(buf, sizeof(buf), fmt, ap);
   if (len <= 0)
      return len;
   if (len > (int)sizeof(buf) - 1)
      len = (int)sizeof(buf) - 1;
   return (int)Q_fwrite(buf, 1, (size_t)len, f);
}

static INLINE int Q_fprintf(Q_FILE *f, const char *fmt, ...)
{
   int     ret;
   va_list ap;
   va_start(ap, fmt);
   ret = Q_vfprintf(f, fmt, ap);
   va_end(ap);
   return ret;
}

#endif /* __Q_VFS_H__ */
