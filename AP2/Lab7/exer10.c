#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int v[5], *ptrV = v;
    int i = 0;
    int soma = 0;

    for(i = 0; i < 5; i++)
    {
        printf("Digite a posição %d vetor:\n", i+1);
        scanf("%d", &v[i]);
    }

    while( ptrV <= &v[4])
    {
        soma += *ptrV++;
    }

    printf("Soma: %d", soma);
    return 0;
}