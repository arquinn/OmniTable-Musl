#include <unistd.h>
#include "syscall.h"

int ftruncate(int fd, off_t length)
{
	return syscall(SYS_ftruncate, fd, __SYSCALL_LL_O(length));
}

int ftruncate64(int fd, loff_t length)
{
	return syscall(SYS_ftruncate64, fd, __SYSCALL_LL_O(length));
}


