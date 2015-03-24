//Include the header files for all the functions you’re going to be using in this program:
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<sys/types.h>

//The void function writes a string to a temporary file 10,000 times and   then performs some arithmetic to generate load on the CPU:
void work(){
	FILE *f;
	int i;
	double x = 4.5;
	f = tmpfile();
	for(i = 0; i < 10000; i++) {
		fprintf(f,"Do some output\n");
		if(ferror(f)) {
			fprintf(stderr,"Error writing to temporary file\n");
			exit(1);
		}
	}
	for(i = 0; i < 100000000; i++)
		x = x*x*x + 3.21 ;
}
//The main function calls work and then uses the getrusage function to      discover how much CPU time it has used. It displays this information   onscreen:
int main(){
	struct rusage r_usage ;
	struct rlimit r_limit ;
	int priority ;

	work() ;
	getrusage(RUSAGE_SELF ,&r_usage) ; 
	printf("CPU usage : User = %ld.%06ld ,System = %ld.%06ld\n" , 			r_usage.ru_utime.tv_sec ,r_usage.ru_utime.tv_usec ,
		r_usage.ru_stime.tv_sec ,r_usage.ru_stime.tv_usec ) ;

	//Next, it calls getpriority and getrlimit to find out its current 		  priority and file size limits, respectively:	
	priority = getpriority(PRIO_PROCESS, getpid()) ;
	printf("Current priority = %d\n", priority) ;
	getrlimit(RLIMIT_FSIZE, &r_limit) ;
	printf("Current FSIZE limit: soft = %ld, hard = %ld\n",
		r_limit.rlim_cur, r_limit.rlim_max) ;

	//Finally, set a file size limit using setrlimit and call work 		  again, which fails because it attempts to create too large a file:
	r_limit.rlim_cur = 2048;
	r_limit.rlim_max = 4096;
	printf("Setting a 2K file size limit\n");
	setrlimit(RLIMIT_FSIZE, &r_limit);
	work();

	exit(0);
}
