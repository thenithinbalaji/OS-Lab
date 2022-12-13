#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main(int argv,char ** argc){
    DIR *d;
    struct dirent *dir_info;
    d=opendir(argc[1]);
    if(d==NULL){
        printf("Directory doesnt exists");
    }
    else{
        while((dir_info=readdir(d))!=NULL){
            printf("%s\n",dir_info->d_name);
        }
    }
    closedir(d);
    return 0;
}