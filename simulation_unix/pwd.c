#include<stdio.h>
#include<unistd.h>

int main() {
    char buff[100];
    getcwd(buff, 100);
    printf("%s", buff);
}