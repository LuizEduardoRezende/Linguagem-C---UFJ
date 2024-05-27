#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

/*Rotina que será executada pelos dois threads*/
void * routine(void *arg);

int main (int argc, char *argv[])
{
	pthread_t tidA;
	pthread_t tidB;
	void * thread_res;
	int rstatus;
	
	/*tenta iniciar a thread, indicando a função 'routine' 
	e passando como argumento a string "Thread A"*/
	rstatus = pthread_create (&tidA, NULL, routine, (void*)("Thread A"));
	pthread_setname_np(tidA, "ThreadA"); //muda o nome da thread tid

	/*verifica se ocorreu algum erro na chamada de pthread_create*/
	if(rstatus != 0)
	{
		printf ("Erro ao criar a thread A.\n");
		exit(EXIT_FAILURE);
	}

	printf ("Thread A criada com sucesso!\n");

	/*tenta iniciar a thread, indicando novamente a função 'routine' 
	e passando como argumento a string "Thread B"*/
	rstatus = pthread_create (&tidB, NULL, routine, (void*)("Thread B"));
	pthread_setname_np(tidB, "ThreadB"); //muda o nome da thread tid


	/*verifica se ocorreu algum erro na chamada de pthread_create*/
	if(rstatus != 0)
	{
		printf ("Erro ao criar a thread B.\n");
		exit(EXIT_FAILURE);
	}

	printf ("Thread B criada com sucesso!\n");


	/*aguarda finalização da thread A identificado por tidA.
	O retorno é passado pelo ponteiro thread_res*/
	rstatus = pthread_join (tidA, &thread_res);

	if(rstatus != 0)
	{
		printf ("Erro ao aguardar finalização da thread A.\n");
		exit(EXIT_FAILURE);
	}

	printf ("\nThread A finalizada! Retorno = %s\n", (char *)thread_res);


	/*aguarda finalização da thread B identificado por tidB.
	O retorno é passado pelo ponteiro thread_res*/
	rstatus = pthread_join (tidB, &thread_res);

	if(rstatus != 0)
	{
		printf ("Erro ao aguardar finalização da thread B.\n");
		exit(EXIT_FAILURE);
	}

	printf ("\nThread B finalizada! Retorno = %s\n", (char *)thread_res);

	return 0;
}

//--------------------------------------------------------------------------------

void * routine(void *arg)
{
	int contador = 30;

	/*procedimento para decrementar um contador e exibir o seu valor*/
	while(contador--)
	{
		//printf("%s> contador = %d\n", (char *)arg, contador);
		if(strcmp((char *)arg,"Thread A")==0)
			printf("A");
		else if(strcmp((char *)arg,"Thread B")==0)
			printf("B");
		else
			printf("x");
		//sleep(1);
	}

	/*finaliza a função retornando o argumento que foi recebido*/
	pthread_exit(arg);
}
