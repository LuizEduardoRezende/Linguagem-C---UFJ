#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    float v1[5] = {0,0,0,0,0};
    float soma = 0;

    for(int i = 0; i<5; i++)
    {
        printf("Digite o %d numero:\n", i+1);
        scanf("%f", &v1[i]);
        fflush(stdin);
        soma += v1[i];
    }

    printf("Soma = %.3f\n", soma);
    for(int i = 0; i<5;i++)
        printf("Numero %d: %.2f\n", i+1, v1[i]);

    return 0;
}
