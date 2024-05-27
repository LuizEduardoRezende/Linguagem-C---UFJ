#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child_pid;
    child_pid = fork();

    if (child_pid < 0) //erro na criação do processo 
    {

        fprintf(stderr, "Erro ao criar processo filho\n");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0) //processo filho
    {

        printf("Processo filho (PID=%d) criado.\n", getpid());
    }
    else //processo pai
    {

        printf("Processo pai (PID=%d) criou o processo filho (PID=%d).\n", getpid(), child_pid);

        sleep(5);
        printf("Utilize o comando: kill -9 %d\n", getpid());
        printf("Processo pai (PID=%d) terminando.\n", getpid());
    }

    return 0;
}
