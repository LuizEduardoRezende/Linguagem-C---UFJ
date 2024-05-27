#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

pid_t pid;
int   status;

pid = fork();

if(pid==0) { //filho
   pid_t filho = getpid();
   printf("\nFilho> meu pid %d\n", filho);
   printf("\nFilho> dormindo...\n");
   sleep(30);
   //while(1);
   printf("\nFilho> terminei\n");
   exit(0);
}
else { //pai
   pid_t pai = getpid();
   printf("\nPai> meu pid %d\n", pai);
   //while(1);
   sleep(15);
   //pid = wait(&status);
   printf("\nPai> meu filho %d terminou com status=%d\n", pid, status);
   printf("\nPai> terminei\n\n");
}

return 0;

}

