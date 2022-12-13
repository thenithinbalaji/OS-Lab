#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int fd[2];
    pipe(fd);
    int pid, status, done;
    pid = fork();
    if (pid == 0) {
        close(fd[0]);
        dup2(fd[1],1);
        close(fd[1]);
        execlp("ls","ls",NULL);
        
    } else {
        done=wait(&status);
        close(fd[1]);
        dup2(fd[0],0);
        close(fd[0]);
        execlp("wc","wc","-l",NULL);
    }
}