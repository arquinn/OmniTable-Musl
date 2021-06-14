#include "stdio_impl.h"

void clearerr(FILE *f)
{
	f->flags &= ~(F_EOF|F_ERR);
}

weak_alias(clearerr, clearerr_unlocked);
