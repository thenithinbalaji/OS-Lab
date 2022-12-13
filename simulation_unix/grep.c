#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argv, char **argc)
{
    FILE *fp;
    char buff[100];
    char *p;
    fp = fopen(argc[1], "r");
    if (fp == NULL)
    {
        printf("FILE DOESNT EXISTS");
    }
    else
    {
        // while(fgets(buff,100,fp)!=NULL){
        //     // printf("%s",buff);
        //     if(strstr(buff,argc[2])){
        //         printf("%s",argc[2]);
        //     }
        // }
        while (fgets(buff, 100, fp) != NULL)
        {
            // printf("%s",buff);
            if ((p = strstr(buff, argc[2])))
            {
                printf("%s", argc[2]);
            }
        }
    }
    fclose(fp);
}