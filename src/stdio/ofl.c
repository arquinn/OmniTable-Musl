#include "stdio_impl.h"

static FILE *ofl_head;

FILE **__ofl_lock()
{
	return &ofl_head;
}

void __ofl_unlock()
{
}
