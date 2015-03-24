#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int args ,char *argv[]){
	char *var ,*value ;
	
	//printf("args %d\n" ,args) ;
	//he first few lines after the declaration of main ensure that the 		  program, environ.c , has beencalled correctly with just one or 	   two arguments:
	if(args == 1 || args > 3){
		fprintf(stderr ,"usage: environ var [value]\n") ;
		exit(1) ;
	}	

	//That done, you fetch the value of the variable from the 		  environment, using getenv :
	var = argv[1] ;
	value = getenv(var) ;
	if(value)
		printf("Variable : %s has value : %s\n", var ,value) ;
	else
		printf("Variable %s has no value\n", var) ;
	
	//Next, check whether the program was called with a second 		  argument. If it was, you set the variable to the value of that 	   argument by constructing a string of the form name=value and then 	      calling putenv :
	if(args == 3){
		char *string ;
		value = argv[2] ;
		string = malloc(strlen(var) + strlen(value) + 2) ;
		if(!string){
			fprintf(stderr ,"out of memory\n") ;
			exit(1) ;	
		}
		strcpy(string ,var) ;
		strcat(string ,"=") ;
		strcat(string ,value) ;
		printf("Calling putenv with: %s\n",string);
		if(putenv(string) != 0)
			printf("New value of %s is %s\n", var, value);
		else
			printf("New value of %s is null??\n", var);

		//Finally, you discover the new value of the variable by 			  calling getenv once again:
		value = getenv(var);
		if(value)
			printf("New value of %s is %s\n", var, value);
		else
			printf("New value of %s is null?\n", var);
	}
	exit(0) ;
}
