#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(int argv,char ** argc){
    FILE *fread,*fwrite;
    char buff[100];
    fread=fopen(argc[1],"r");
    fwrite=fopen(argc[2],"w");
    if (fread==NULL){
        printf("File doesnt exist");
    }
    else{
        while(fgets(buff,100,fread)!=NULL){
            printf("%s",buff);
            fputs(buff,fwrite);
        }
    }
    fclose(fread);
    fclose(fwrite);

}