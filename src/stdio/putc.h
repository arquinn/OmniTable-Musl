#include "stdio_impl.h"

static inline int do_putc(int c, FILE *f)
{
  return putc_unlocked(c, f);
}
