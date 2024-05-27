#ifndef exer2_h
#define exer2_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int num_teste;

int posi_nega()
{
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o número para verificar se é positivo ou negativo.\n");
    scanf("%d", &num_teste);
    if (num_teste >= 0)
    {
        printf("Positivo.\n");
    }
    else
    {
        printf("Negavtivo.\n");
    }
    return 0;
}
#endif