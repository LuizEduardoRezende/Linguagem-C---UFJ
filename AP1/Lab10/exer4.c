#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet_a[5], vet_b[5], i = 0, vet_c[10];

    for (i = 0; i < 5; i++)
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
        if (i % 2 == 0 && i != 1)
        {
            vet_c[i] = vet_a[i / 2];
        }
        else
        {
            vet_c[i] = vet_b[i / 2];
        }

        printf("Vetor C %d: %d\n", i + 1, vet_c[i]);
    }

    return 0;
}