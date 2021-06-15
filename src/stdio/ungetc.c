#include "stdio_impl.h"

int ungetc(int c, FILE *f)
{
	if (c == EOF) return c;

	

	if (!f->rpos) __toread(f);
	if (!f->rpos || f->rpos <= f->buf - UNGET) {
		
		return EOF;
	}

	*--f->rpos = c;
	f->flags &= ~F_EOF;

	
	return (unsigned char)c;
}
