#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet_a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, vet_b[5] = {0, 0, 0, 0, 0}, vet_par[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, vet_impar[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, aux[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, i = 0, j = 0;

    for (i = 0; i < 10; i++)
    {
        printf("Digite o %d valor para o vetor A.\n", i + 1);
        scanf("%d", &vet_a[i]);
    }

    for (i = 0; i < 5; i++)
    {
        printf("Digite o %d valor para o vetor B.\n", i + 1);
        scanf("%d", &vet_b[i]);
    }

    for (i = 0; i < 10; i++)
    {
        aux[i] = vet_a[i];
        j = 0;
        while (j < 5)
        {
            aux[i] = aux[i] + vet_b[j];
            j++;
        }
    }

    for (i = 0; i < 10; i++)
    {
        if (aux[i] % 2 == 0 && aux[i] != 1)
        {
            vet_par[i] = aux[i];
        }
        else
        {
            vet_impar[i] = aux[i];
        }
    }

    printf("\n");
    printf("Vetor par:\n");
    for (i = 0; i < 10; i++)
    {
        if (vet_par[i] > 0)
        {
            printf("%d\n", vet_par[i]);
        }
    }

    printf("Vetor impar:\n");
    for (i = 0; i < 10; i++)
    {
        if (vet_impar[i] > 0)
        {
            printf("%d\n", vet_impar[i]);
        }
    }

    return 0;
}