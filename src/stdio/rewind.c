#include "stdio_impl.h"

void rewind(FILE *f)
{
	
	__fseeko_unlocked(f, 0, SEEK_SET);
	f->flags &= ~F_ERR;
	
}
