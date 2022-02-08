#include "stdio.h"
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdlib.h>
#define SHM_SIZE (1024*1024)
#define SHM_MODE 0600
#define SEM_MODE 0600

#if defined(_GNU_LIBRARY_) && !defined(_SEM_SEMUN_UNDEFINED)
/*   union   semun   is   defined   by   including   <sys/sem.h>   */ 
#else 
/*   according   to   X/OPEN   we   have   to   define   it   ourselves   */ 
union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
#endif

struct ShM{
    int start;
    int end;
}* pSM;

const int N_CONSUMER = 3;//Number of consumers
const int N_BUFFER = 5;//Buffer capacity
int shmId = -1,semSetId=-1;
union semun su;//sem union, used to initialize the semaphore

//semSetId represents the id of the semaphore set
//semNum represents the index of the semaphore to be processed in the semaphore collection
void waitSem(int semSetId,int semNum)
{
    struct sembuf sb;
    sb.sem_num = semNum;
    sb.sem_op = -1;//Indicates that the semaphore is to be reduced by one
    sb.sem_flg = SEM_UNDO;//
    //The second parameter is of type sembuf [], representing an array
    //The third parameter represents the size of the array represented by the second parameter
    if(semop(semSetId,&sb,1) < 0){
        perror("waitSem failed");
        exit(1);
    }
}
void sigSem(int semSetId,int semNum)
{
    struct sembuf sb;
    sb.sem_num = semNum;
    sb.sem_op = 1;
    sb.sem_flg = SEM_UNDO;
    //The second parameter is of type sembuf [], representing an array
    //The third parameter represents the size of the array represented by the second parameter
    if(semop(semSetId,&sb,1) < 0){
        perror("waitSem failed");
        exit(1);
    }
}
//Must be called when mutual exclusion is guaranteed and the buffer is not full
void produce()
{
    int last = pSM->end;
    pSM->end = (pSM->end+1) % N_BUFFER;
    printf("Production %d\n",last);
}
//Must be called when mutual exclusion is guaranteed and the buffer is not empty
void consume()
{
    int last = pSM->start;
    pSM->start = (pSM->start + 1)%N_BUFFER;
    printf("Consume %d\n",last);
}

void init()
{
    //Buffer allocation and initialization
    if((shmId = shmget(IPC_PRIVATE,SHM_SIZE,SHM_MODE)) < 0)
    {
        perror("create shared memory failed");
        exit(1);
    }
    pSM = (struct ShM *)shmat(shmId,0,0);
    pSM->start = 0;
    pSM->end = 0;
    
    //Semaphore creation
    //The first one: the amount of synchronous semaphore, indicating the order, there must be space to produce
    //The second one: the amount of synchronization signal, indicating the order, and there must be products to consume
    //The third: mutually exclusive semaphore, the producer and each consumer cannot enter the buffer at the same time

    if((semSetId = semget(IPC_PRIVATE,3,SEM_MODE)) < 0)
    {
        perror("create semaphore failed");
        exit(1);
    }
    //Semaphore initialization, where su means union semun 
    su.val = N_BUFFER;//How many products can the warehouse receive
    if(semctl(semSetId,0,SETVAL, su) < 0){
        perror("semctl failed");
        exit(1);
    }
    su.val = 0;//No products currently
    if(semctl(semSetId,1,SETVAL,su) < 0){
        perror("semctl failed");
        exit(1);
    }
    su.val = 1;//Can enter the buffer when it is 1
    if(semctl(semSetId,2,SETVAL,su) < 0){
        perror("semctl failed");
        exit(1);
    }
}
int main()
{
    int i = 0,child = -1;
    init();
    //Create multiple (N_CONSUMER) consumer child processes
    for(i = 0; i < N_CONSUMER; i++)
    {
        if((child = fork()) < 0)//Failed to call fork
        {
            perror("the fork failed");
            exit(1);
        }
        else if(child == 0)//Child process
        {
            printf("I am the %d consumer child process, PID = %d\n",i,getpid());
            while(1)
            {
                waitSem(semSetId,1);//Must have products to consume
                waitSem(semSetId,2);//Lock buffer
                consume();//To obtain the product, the buffer needs to be modified
                sigSem(semSetId,2);//Release buffer
                sigSem(semSetId,0);//Inform producers that there is room
                sleep(2);//Consumption frequency
            }
            break;//Must have
        }
    }
    
    
    //Parent process starts production
    if(child > 0)
    {
        while(1)
        {
            waitSem(semSetId,0);//Get a space for storing products
            waitSem(semSetId,2);//Occupy product buffer
            produce();
            sigSem(semSetId,2);//Release product buffer
            sleep(1);//Produce one every two seconds
            sigSem(semSetId,1);//Inform consumers that there is a product
        }
    }
    return 0;
}