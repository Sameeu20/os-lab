#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
pid_t pid;
pid=fork();
if(pid<0)
{
printf("Error Fork Failed");
}
else if(pid==0)
{
printf("child id %d \n",getpid());
printf("Parent id %d \n",getppid());

}

else
{
printf("Child is %d \n",pid);
printf("Parent id %d \n ",getpid());
wait(NULL);
printf("Child Complete");
}

printf("\n Both Child and parent %d \n",getpid());

return 0;
}

