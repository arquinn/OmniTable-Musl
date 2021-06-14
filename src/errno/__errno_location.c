#include <errno.h>

hidden int static_errno_loc;
int *__errno_location(void)
{
  return &static_errno_loc;
}

weak_alias(__errno_location, ___errno_location);
