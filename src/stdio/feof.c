#include "stdio_impl.h"

#undef feof

int feof(FILE *f)
{
	int ret = !!(f->flags & F_EOF);
	return ret;
}

weak_alias(feof, feof_unlocked);
weak_alias(feof, _IO_feof_unlocked);
