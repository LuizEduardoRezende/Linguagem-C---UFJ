#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_a[5], num_b[5], i = 0;
    float num_c[5];
    int opcao;

    for (i = 0; i < 5; i++)
    {
        printf("Digite o %d valor para o vetor A.\n", i + 1);
        scanf("%d", &num_a[i]);
    }

    i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("Digite o %d valor para o vetor B.\n", i + 1);
        scanf("%d", &num_b[i]);
    }

    printf("\n");
    printf("Escolha uma operacao. 1 para soma, 2 para subtracao, 3 para multiplicacao, 4 para divisao.\n");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        i = 0;
        for (i = 0; i < 5; i++)
        {
            num_c[i] = num_a[i] + num_b[i];
        }
        break;
    case 2:
        i = 0;
        for (i = 0; i < 5; i++)
        {
            num_c[i] = num_a[i] - num_b[i];
        }
        break;
    case 3:
        i = 0;
        for (i = 0; i < 5; i++)
        {
            num_c[i] = num_a[i] * num_b[i];
        }
        break;
    case 4:
        i = 0;
        for (i = 0; i < 5; i++)
        {
            num_c[i] = (float)num_a[i] / (float)num_b[i];
        }
        break;
    default:
        printf("Opcao invalida.");

        break;
    }

    i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("%f\n", num_c[i]);
    }

    return 0;
}