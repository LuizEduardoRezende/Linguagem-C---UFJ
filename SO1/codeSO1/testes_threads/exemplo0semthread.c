#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int sum;

void runner(void *param);

int main(int argc, char const* argv[])
{
	int rstatus;

	if (argc < 2) {
		printf("Main> Argumento faltando.\n");
		printf("Main> Forma correta: <nome_programa> <int>.\n");
		exit(1);
	}

	runner((void *)argv[1]);

	printf("Main> sum = %d\n", sum);

	return 0;
}


void runner(void *param) {
	int i, upper = atoi(param);
	sum = 0;

	for(i = 1; i <= upper; i++) {
		sum += i;
		printf("runner> sum = %d\n", sum);
		sleep(2);
	}
}

