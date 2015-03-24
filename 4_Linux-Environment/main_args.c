#include<stdio.h>
#include<stdlib.h>

int main(int args ,char *argv[]){
	int arg ;
	for(arg = 0 ;arg < args ;arg++){
		if(argv[arg][0] == '-')
			printf("option : %s\n" ,argv[arg] + 1) ;
		else
			printf("command %d : %s\n" ,arg ,argv[arg]) ;
	}
	exit(0) ;
}
