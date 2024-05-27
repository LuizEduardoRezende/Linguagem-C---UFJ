#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Cria um processo filho
    pid = fork();

    if (pid < 0) {
        // Erro ao criar o processo filho
        perror("Erro ao criar processo filho");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Código executado pelo processo filho

        printf("Processo filho (PID: %d) criado.\n", getpid());

        // Processo filho dorme por 10 segundos
        sleep(10);

        // Processo filho termina
        exit(EXIT_SUCCESS);
    } else {
        // Código executado pelo processo pai

        printf("Processo pai (PID: %d) aguardando o processo filho (PID: %d).\n", getpid(), pid);

        // Processo pai espera pelo filho
        wait(NULL);

        printf("Processo filho finalizado, mas agora é um processo zumbi.\n");

        // Aguarda algum tempo para observar o processo zumbi
        sleep(15);

        printf("Usando o comando 'ps' para mostrar os processos atuais:\n");
        system("ps -o pid,ppid,stat,cmd");

        // Agora, use o comando 'kill' para eliminar o processo zumbi
        // Substitua <pid_do_filho> pelo PID do processo filho
        // Você pode encontrar o PID do processo filho no resultado do comando 'ps'
        // Exemplo: kill -9 <pid_do_filho>
    }

    return 0;
}
