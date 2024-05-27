#include <stdio.h>
#include <stdlib.h>

int main()
{
    char carac;
    int N, i = 0, j = 0;
    printf("Digite um caractere para fazer metade de uma arvore de natal.\n");
    scanf(" %c", &carac);
    printf("Digite o numero de ramos de sua arvore de natal.\n");
    scanf("%d", &N);

    for (j = 0; j < N; j++)
    {
        i = 0;
        for (i = 0; i <= j; i++)
        {
            printf("%c", carac);
        }
        printf("\n");

    }

    system("pause");
    return 0;
}