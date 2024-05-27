#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    int numeros[3] = {0,0,0};

    for(int i = 0; i<3; i++)
    {
        printf("Digite o %d numero.\n", i+1);
        scanf("%d", &numeros[i]);
        fflush(stdin);
    }

    for(int i = 0; i<3;i++)
    printf("O quadrado do %d numero e: %d\n", i+1, numeros[i] * numeros[i]);
    
    return 0;
}
