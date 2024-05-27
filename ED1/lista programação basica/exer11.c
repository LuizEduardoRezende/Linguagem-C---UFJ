#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    int i = 1, j = 1;

    for( i = 1; i<10; i++)
    {
        for( j = 1; j < 10; j++)
        {
            printf("%d x %d = %d \t", i, j, i*j);
        }
        printf("\n");
    }


    return 0;
}
