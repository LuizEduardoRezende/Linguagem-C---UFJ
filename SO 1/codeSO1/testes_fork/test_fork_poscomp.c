#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
   int i;
   for(i=0;i<3;i++)
      fork();
   while(1);
   return 0;
}
