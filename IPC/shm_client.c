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
    if ((shmid = shmget(key, 27, 0666)) < 0)
    {
        perror("shmgeterror\n");
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat\n");
    }
    // s=shm;
    // printf("%s",*shm);
     for (s = shm; *s != NULL; s++)
    {
        putchar(*s);
    }

    *shm = '*';
    exit(0);
}