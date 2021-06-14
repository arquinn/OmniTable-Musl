#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>

#include "syscall.h"

static void dummy(void) { }
weak_alias(dummy, __vm_wait);

#define UNIT SYSCALL_MMAP2_UNIT
#define OFF_MASK ((-0x2000ULL << (8*sizeof(syscall_arg_t)-1)) | (UNIT-1))

void *__mmap(void *start, size_t len, int prot, int flags, int fd, off_t off) {
  long ret;
  if (off & OFF_MASK) {
    errno = EINVAL;
    return MAP_FAILED;
  }
  if (len >= PTRDIFF_MAX) {
    errno = ENOMEM;
    return MAP_FAILED;
  }
  if (flags & MAP_FIXED) {
    __vm_wait();
  }
  ret = __syscall(SYS_mmap2, start, len, prot, flags, fd, off/UNIT);
  /* Fixup incorrect EPERM from kernel. */
  if (ret == -EPERM && !start && (flags&MAP_ANON) && !(flags&MAP_FIXED))
    ret = -ENOMEM;
  return (void *)__syscall_ret(ret);
}
weak_alias(__mmap, mmap);

void *__mmap64(void *start, size_t len, int prot, int flags, int fd, loff_t off) {
  long ret;
  if (off & OFF_MASK) {
    errno = EINVAL;
    return MAP_FAILED;
  }
  if (len >= PTRDIFF_MAX) {
    errno = ENOMEM;
    return MAP_FAILED;
  }
  if (flags & MAP_FIXED) {
    __vm_wait();
  }
  ret = __syscall(SYS_mmap2, start, len, prot, flags, fd, off/UNIT);
  /* Fixup incorrect EPERM from kernel. */
  if (ret == -EPERM && !start && (flags&MAP_ANON) && !(flags&MAP_FIXED))
    ret = -ENOMEM;
  return (void *)__syscall_ret(ret);
}


weak_alias(__mmap64, mmap64);
