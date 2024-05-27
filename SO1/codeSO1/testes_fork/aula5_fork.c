#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid;

	//fork a child process
	pid = fork();

	if(pid<0) {
		fprintf(stderr, "Fork failed");
		return 1;
	}
	else if(pid==0) { //child process
		printf("Initializing child:\n");
		execlp("./aula5", "aula5", NULL);
	}
	else { //parent process
		//parent will wait for the child to complete
		printf("Parent waiting...");
		wait(NULL);
		printf("Child complete\n");
	}
	
	return 0;
}
