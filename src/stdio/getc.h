#include "stdio_impl.h"

static inline int do_getc(FILE *f)
{
  return getc_unlocked(f);
}
