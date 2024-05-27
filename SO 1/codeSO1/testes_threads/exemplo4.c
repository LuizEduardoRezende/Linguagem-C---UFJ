#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
 
#define THREADS_MAX 50

void *function(void *param)
{
       int id = *((int *)(param));
       int i, loops = 10;
       for(i = 0; i < loops; i++)
       {
               printf("thread %d: loop %d\n", id, i);
               //sleep(1);
       }
       pthread_exit(NULL);
}

int main(void)
{
       pthread_t threads[THREADS_MAX];
       int thread_args[THREADS_MAX];
       int i;
       char thname[10];

       //printf("pre-execution\n");
       for (i = 0; i < THREADS_MAX; i++)
       {
               thread_args[i] = i;
               pthread_create(&threads[i], NULL, function, (void *) &thread_args[i]);
               sprintf(thname, "thread[%d]", i);
               pthread_setname_np(threads[i], thname);
       }
       //printf("mid-execution\n");

       for (i = 0; i < THREADS_MAX; i++)
       {
               pthread_join(threads[i], NULL);
       }
       //printf("post-execution\n");
       return EXIT_SUCCESS;
}
