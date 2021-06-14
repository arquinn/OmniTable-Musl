#include <dirent.h>
#include <unistd.h>
#include "__dirent.h"

void seekdir(DIR *dir, long off)
{
	dir->tell = lseek(dir->fd, off, SEEK_SET);
	dir->buf_pos = dir->buf_end = 0;
}
