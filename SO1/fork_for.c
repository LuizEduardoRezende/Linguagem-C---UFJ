#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int i;

    for(i = 0; i<3; i++)
        fork();
    sleep(40);

    return 0;
}
