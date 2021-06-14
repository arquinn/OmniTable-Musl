#include <stdlib.h>
#include <stddef.h>
#include <netdb.h>
#include "lookup.h"

void freeaddrinfo(struct addrinfo *p)
{
	size_t cnt;
	for (cnt=1; p->ai_next; cnt++, p=p->ai_next);
	struct aibuf *b = (void *)((char *)p - offsetof(struct aibuf, ai));
	b -= b->slot;
	if (!(b->ref -= cnt)) free(b);
}
