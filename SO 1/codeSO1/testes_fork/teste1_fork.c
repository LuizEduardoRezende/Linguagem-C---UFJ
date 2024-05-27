#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int value = 5;

int main() {

pid_t pid;

pid = fork();

if (pid == 0) { /* processo-filho */
	//int value = 0;
	value += 15;
	printf("\nCHILD: value = %d\n",value); /* LINHA B */
	return 0;
}
else if (pid > 0) { /* processo-pai */
	wait(NULL);
	printf("\nPARENT: value = %d\n",value); /* LINHA A */
	return 0;
}
}

