#include "stdio_impl.h"
#include <errno.h>

int fileno(FILE *f)
{
	
	int fd = f->fd;
	
	if (fd < 0) {
		errno = EBADF;
		return -1;
	}
	return fd;
}

weak_alias(fileno, fileno_unlocked);
