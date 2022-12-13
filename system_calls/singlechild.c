#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int done, status;
    int cpid;
    cpid = fork();
    if (cpid == 0)
    {
        printf("Child process!\n");
        printf("PRocess id %d\n",getpid());
        printf("Parent Process id %d\n",getppid());
    }
    else
    {
        done = wait(&status);
        printf("Parent process!\n");
        printf("PRocess id %d\n",getpid());
        printf("Parent Process id %d\n",getppid());
    }
    return 0;
}