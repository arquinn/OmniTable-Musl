#include <stdlib.h>
#include "libc.h"

#define COUNT 32

static void (*funcs[COUNT])(void);
static int count;

void __funcs_on_quick_exit()
{
	void (*func)(void);
	while (count > 0) {
		func = funcs[--count];
		func();
	}
}

int at_quick_exit(void (*func)(void))
{
	int r = 0;
	if (count == 32) r = -1;
	else funcs[count++] = func;
	return r;
}
