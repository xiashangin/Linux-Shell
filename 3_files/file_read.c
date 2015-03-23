#include<unistd.h>
#include<stdlib.h>

int main(){
	char buffer[128] ;
	int nread ;
	
	nread = read(0 ,buffer ,128) ;
	if(nread == -1){
		write(2 ,"A read has occured\n" ,26) ;
	}
	if(write(1 ,buffer ,nread) != nread){
		write(2 ,"A write has occured\n" ,27) ;
	}
	exit(0) ;
}

/*
write

Here’s the syntax:
#include <unistd.h>
size_t read(int fildes, void *buf, size_t nbytes);
*/
