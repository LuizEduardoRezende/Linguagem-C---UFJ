#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int sum;  //this data is shared by the thread(s)

void *runner(void *param); //threads call this function

int main(int argc, char const *argv[])
{
	pthread_t tid; //thread identifier
	pthread_attr_t attr; //set of thread attributes
	int rstatus;

	if(argc < 2) {
		printf ("Main> Argumento faltando.\n");
		printf ("Main> Forma correta: <nome_programa> <int>.\n");
  	exit(1);
	}

	//set the default attributes of the thread
	pthread_attr_init(&attr);

	//create the thread
	rstatus = pthread_create(&tid, &attr, runner, (void *)argv[1]);

	if(rstatus != 0) {
  	printf ("Main> Erro ao criar a thread.\n");
  	exit(1);
  }

	printf("Main> Thread runner foi criada com sucesso.\n");
	pthread_setname_np(tid, "runner"); //muda o nome da thread tid

	//wait for the thread to exit
	pthread_join(tid,NULL);

	printf("Main> sum = %d\n", sum);

	return 0;
}


void *runner(void *param) {
	int i, upper = atoi(param);
	sum = 0;

	for(i = 1; i <= upper; i++) {
		sum += i;
		printf("runner> sum = %d\n", sum);
		sleep(2);
	}

	pthread_exit(0);
}

