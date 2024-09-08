#include<stdio.h>
#include<unistd.h>


int main(){
	int x;
	x = 100;
	int y = fork();
	
	if(y<0){
	  fprintf(stderr,"Error!!!");}

	else if (y == 0) {
	  printf("This is child process\n");
	  x=150;
	  printf("Value of x in child process: %d\n",x);}
	else{
	  printf("This is parent process\n");
	  x = 200;
	 printf("Value of x in parent process:%d\n",x);}

return 0;
}
/**************************************
Josh Wakin

Using fork will create a copy of the original process and the the value of x, but because they are independant of one another
the value of x is different for the parent and child because the run seperatley from each other.
**************************************/
