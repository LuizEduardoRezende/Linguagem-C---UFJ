#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
 
#define THREADS_MAX 10

int mat[THREADS_MAX][THREADS_MAX];
int partial[THREADS_MAX];

void *function(void *param)
{
       int i = *((int *)(param));
       int j, sum=0;
       printf("thread %d> working...\n", i);
       for(j = 0; j < THREADS_MAX; j++) {
               sum += mat[i][j];
       }
       partial[i] = sum;
       printf("thread %d> done sum %d\n", i, sum);

       pthread_exit(NULL);
}

int main(void)
{
       pthread_t threads[THREADS_MAX];
       int args[THREADS_MAX];
       int i,j,linha, st=0;

       //inicialização da matriz e do array
       for(i=0; i<THREADS_MAX; i++) {
                partial[i]=0;
                for(j=0; j<THREADS_MAX; j++)
                        mat[i][j]=1;
        }

       for (i=0; i < THREADS_MAX; i++) {
                args[i] = i; 
                pthread_create(&threads[i], NULL, function, (void *) &args[i]);
       }

       printf("All threads created.\n");

       for (i = 0; i < THREADS_MAX; i++) {
               pthread_join(threads[i], NULL);
               //printf("thread %d> join\n", i);
       }

       printf("All threads terminated.\n");

       for (i = 0; i < THREADS_MAX; i++) {
                st += partial[i];
                //printf("partial[%d]=%d\n", i, partial[i]);

       }
       printf("Main> sumation = %d\n", st);

       return EXIT_SUCCESS;
}
