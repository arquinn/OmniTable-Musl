#include <stdlib.h>
#include <signal.h>
#include "syscall.h"
#include "atomic.h"
#include "ksigaction.h"

_Noreturn void abort(void)
{
  raise(SIGABRT);
  raise(SIGKILL);
  _Exit(127);
}
