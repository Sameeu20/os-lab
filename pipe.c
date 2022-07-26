#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
int fd[2];
pid_t pid;

if(pipe(fd)==-1)
	{
	printf("Error Occured ");
	return 1;
	}
pid=fork();
if(pid==0)
{
printf("Child process is writing to pipe \n");
close(fd[0]);
int x;
printf("Input a number ");
scanf("%d",&x);
if(write(fd[1],&x,sizeof(int))==-1)
{
printf("error occured in writing to pipe");
return 2;
}
close(fd[1]);
}
else
{
printf("Parent process is reading from pipe");
close(fd[1]);

int y;
if(read(fd[0],&y,sizeof(int))==-1)
{
printf("Error occured in reading to pipe");
return 3;
}
close(fd[0]);
printf("\n got from child process %d \n",y);
wait(NULL);
return 0;
}
}
