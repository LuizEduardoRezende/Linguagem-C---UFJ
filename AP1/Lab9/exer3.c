#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 2, soma = 0, f = 0;

    for (i = 2; i <= 100; i = i + 2)
    {
        printf("%d\n", i);
        soma = soma + i;
    }

    printf("A soma dos primeiros 50 numeros pares e: %d\n", soma);

    system("pause");
    return 0;
}