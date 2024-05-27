#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {

pid_t pid;

pid = fork();

if(pid==0) { //filho
   printf("\nFilho %d\n", getpid());
   printf("\nFilho dormindo...\n");
   sleep(15);
   printf("\nFilho terminou.\n");
}
else { //pai
   printf("\nPai %d esperando...\n", getpid());
   wait(NULL);
   printf("\nPai terminou.\n");
}

return 0;

}

