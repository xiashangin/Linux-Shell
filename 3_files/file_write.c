#include<unistd.h>
#include<stdlib.h>

int main(){
	if((write(1 ,"Here is some data\n" ,18)) != 18)
		write(2 ,"A error occurs!\n" ,46) ;
	exit(0) ;
}

/*
write

Here’s the syntax:
#include <unistd.h>
size_t write(int fildes, const void *buf, size_t nbytes);

*/
