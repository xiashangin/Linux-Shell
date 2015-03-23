#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	open ("myFile", O_CREAT, S_IRUSR|S_IXOTH);
	return 0 ;
}

/*
write

Here’s the syntax:
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int open(const char *path, int oflags);
int open(const char *path, int oflags, mode_t mode);
	Strictly speaking, you don’t need to include sys/types.h 	 and sys/stat.h to use open on systems
	that comply with POSIX standards, but they may be necessary 		on some UNIX systems.
*/
