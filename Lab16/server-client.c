/*
Process Communication using shared memory
*/

---server.c---
#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 100

int main(int argc,char* argv[])
{
    int shmid;
    key_t key;
    char * shm;
    key=9876;

    shmid=shmget(key,SHSIZE,IPC_CREAT | 0666 );

    if (shmid < 0 )
    {
        perror("shmget");
        exit(1);
    }

    shm=shmat(shmid,NULL,0);
    
    if( shm == (char*)-1)
    {
        perror("shmat");
        exit(1);
    }

    memcpy(shm,"Try Message",11);
    char *s;
    s=shm;
    s+=11;

    *s=0;
    while( *shm != '*' )
    {
                     sleep(1);
     }

    return 0;

}


---client.c---
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 100
int main(int argc,char* argv[])
{
    int shmid;
    key_t key;
    char * shm;
    key=9876;

    shmid=shmget(key,SHSIZE,0666 );

    if (shmid < 0 )
    {
        perror("shmget");
        exit(1);
    }

    shm=shmat(shmid,NULL,0);
    
    if( shm == (char*)-1)
    {
        perror("shmat");
        exit(1);
    }

        char *s;

    for ( s=shm ; *s!=0 ; s++ )
    {
        printf("%c",*s);
    }

    printf("\n");
    *shm='*';
    return 0;

}
