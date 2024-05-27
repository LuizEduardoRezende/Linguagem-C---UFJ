#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main(){
    float v1[4], v2[4];
    float produto;

    for(int i = 0; i<4; i++)
    {
        printf("Digite o %d numero para o vetor 1:\n", i + 1);
        scanf("%f", &v1[i]);
        fflush(stdin);
    }

    for(int i = 0; i<4; i++)
    {
        printf("Digite o %d numero para o vetor 2:\n", i + 1);
        scanf("%f", &v2[i]);
        fflush(stdin);
        produto += v1[i] * v2[i];
    }

    printf("O produto escalar entre os dois vetores e: %.2f\n", produto);





    return 0;
}
