#ifndef exer4_h
#define exer4_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int N = 0, fat = 1;

int fatorial()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Digite um número para calcular o fatorial.\n");
    scanf("%d", &N);
    int i = 0;
    i = N;
    for (fat = 1; i > 0; i--)
    {
        fat *= i;
    }
    printf("Fatorial de %d é : %d\n", N, fat);
    return 0;
}
#endif