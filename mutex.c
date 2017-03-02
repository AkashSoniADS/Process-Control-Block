#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

pthread_t tid[2]; //array of thread id
int value;
pthread_mutex_t lock; //lock for mutual exclusion

//function to generate random numbers without using seed
int identifier()
{
	int id;
	id = rand();
	return id;
}

void sum(int val)
{
	int a = identifier()/100;
	int b = identifier()/100;
	printf("\nNumber 1 : %d",a);
	printf("\nNumber 2 : %d",b);
	long int c = a + b;
	printf("\nThe answer for process %d for addition of two numbers is %ld",value,c);

}


void* doMath(void *arg)
{
    pthread_mutex_lock(&lock); //locking the thread when working
   
    unsigned long i = 0;
    value += 1;
    printf("\n Thread %d started\n", value);
    
	sum(value);
    //for(i=0; i<(0xFFFFFFFF);i++);
	printf("\n Thread %d finished\n", value);
	sleep(2);
    pthread_mutex_unlock(&lock); //unlocking the thread

    return NULL;
}

//function for addition

int main(void)
{
    int i = 0;
    int err;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    while(i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &doMath, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }
	//thread join
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);//destroying the lock

    return 0;
}
