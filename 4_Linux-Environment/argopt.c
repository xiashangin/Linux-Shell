#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int args ,char *argv[]){
	int opt ;
	while((opt = getopt(args ,argv ,"if:lr")) != -1){
		switch(opt){
			case 'i' :
			case 'l' :
			case 'r' :
				printf("opt : %c\n" ,opt) ;
				break ;
			case 'f' :
				printf("filename : %s\n" ,optarg) ;
				break ;
			case ':' :
				printf("option needs a value\n") ;
				break ;
			case '?' :
				printf("unknown option %c\n" ,optopt) ;
				break ;
		}
	}
	for(;optind < args ;optind++)
		printf("argument : %s\n" ,argv[optind]) ;
	exit(0) ;
}
