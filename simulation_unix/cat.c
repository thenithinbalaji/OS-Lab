#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argv, char **argc)
{
    int fp;
    char buff[1];
    fp = open(argc[1],O_RDWR,"0");
    if (fp == -1)
    {
        printf("Doesnt exists");
    }
    else{
        while(read(fp,buff,sizeof(buff))!=0){
            printf("%s",buff);
        }
    }
    close(fp);
    return 0;
}