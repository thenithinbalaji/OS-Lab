#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
    int fd[2];
    pipe(fd);
    int done, status, pid;
    pid = fork();
    char writemsg[20], readmsg[20];
    if (pid == 0) 
    {
        close(fd[0]);
        printf("Child is Sender\nEnter the msg to sent into buffer : ");
        fgets(writemsg,20,stdin);
        write(fd[1], writemsg, sizeof(writemsg));
        close(fd[1]);
    } else {
        done = wait(&status);
        close(fd[1]);
        printf("Parent is Reader\n");
        read(fd[0], readmsg, sizeof(readmsg));
        printf("Message: %s\n", readmsg);
        close(fd[0]);
    }
}












