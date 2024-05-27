#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {

int i;

for(i=0; i<4; i++)
	fork();

sleep(40);

return 0;

}
