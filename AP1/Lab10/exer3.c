#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, i = 0, flag_maior50 = 0;

    for (i = 0; i < 10; i++)
    {
        printf("Digite o numero para a posicao %d do vetor.\n", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < 10; i++)
    {
        if (vetor[i] > 50)
        {
            printf("Posicao %d do vetor = %d\n", i + 1, vetor[i]);
            flag_maior50 = 1;
        }
    }

    if (flag_maior50 == 0)
    {
        printf("Nao existe nenhum numero maior que 50 neste vetor.\n");
    }

    return 0;
}