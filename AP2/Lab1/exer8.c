#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0, p = 0;
    float numero[5] = {0, 0, 0, 0, 0}, maior_num = -214748364;

    for (i = 0; i < 5; i++)
    {
        printf("Digite o %d numero:\n", i + 1);
        scanf("%f", &numero[i]);

        if (numero[i] > maior_num)
        {
            maior_num = numero[i];
            p = i + 1;
        }
    }

    printf("O maior elemento de N e: %f e ele apareceu a primeira vez na posicao : %d", maior_num, p);

    return 0;
}