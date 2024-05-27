#ifndef exer3_h
#define exer3_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

float x = 0, y = 0, resul = 0;
int opcao = 0;

float somar()
{
    setlocale(LC_ALL, "Portuguese");
    resul = x + y;
    return resul;
}

float subtrair()
{
    resul = x - y;
    return resul;
}

float multiplicar()
{
    resul = x * y;
    return resul;
}

float dividir()
{
    resul = x / y;
    return resul;
}

int calculadora()
{
    printf("Digite x e y para realizar uma operação.\n");
    printf("X: ");
    scanf("%f", &x);
    printf("Y: ");
    scanf("%f", &y);

    printf("Digite 0 para encerrar o menu, 1 para soma, 2 para subtrair, 3 para multiplicar ou 4 para diidir.\n");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 0:
        printf("Menu encerrado.\n");
        break;
    case 1:
        printf("X + Y = %f\n", somar());
        break;
    case 2:
        printf("X - Y = %f\n", subtrair());
        break;
    case 3:
        printf("X * Y = %f\n", multiplicar());
        break;
    case 4:
        printf("X / Y = %f\n", dividir());
        break;
    default:
        printf("Escolha uma opção válida.\n");
        break;
    }
    return 0;
}

#endif