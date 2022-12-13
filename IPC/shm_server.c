#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main()
{
    key_t key = 6002;
    int shmid;
    char *s, *shm;
    if ((shmid = shmget(key, 27, IPC_CREAT | 0666)) < 0)
    {
        perror("shmgeterror\n");
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat\n");
    }
    s = shm;
    printf("Enter the string to be shared :");
    while (*s != '\n')
    {
        *s = getchar();
        s++;
    }

    *s = NULL;
    // *shm = NULL;
    while (*shm != '*')
    {
        sleep(1);
    }
    exit(0);
    return 0;
}