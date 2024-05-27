#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {

fork();

fork();

fork();

sleep(40);

return 0;

}

