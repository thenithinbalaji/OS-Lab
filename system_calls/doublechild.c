#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int done,status;
    int cpid1,cpid2;
    ((cpid1=fork())&&(cpid2=fork()));
    if(cpid1==0){
        printf("Child1\n");
        printf("PRocess id %d\n",getpid());
        printf("Parent Process id %d\n",getppid());
    }
    else if(cpid2==0){
        sleep(2);
        printf("child2\n");
        printf("PRocess id %d\n",getpid());
        printf("Parent Process id %d\n",getppid());
    }
    else{
        done=wait(&status);
        sleep(3);
        printf("Parent\n");
        printf("PRocess id %d\n",getpid());
        printf("Parent Process id %d\n",getppid());
    }
    return 0;
}
