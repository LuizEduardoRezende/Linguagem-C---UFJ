#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "exer2.h"
#include "exer3.h"
#include "exer4.h"
#include "exer5.h"
#include "exer6.h"

int main()
{
    int esc;
    int par_impar;                             // declaração de variaveis para o exercicio 2
    int x, y;                                  // declaração de variaveis para o exercicio 3
    int fator1, fator2;                        // declaração de variaveis para o exercicio 4
    int n, p; float combinacao;                // declaração de variaveis para o exercicio 5
    int i = 0; float taxas[4], horas[4];       // declaração de variaveis para o exercicio 6

    setlocale(LC_ALL, "Portuguese");
    printf("\nEscolha qual exercício deseja escolher : \n");
    scanf("%d", &esc);
    switch (esc)
    {
    case 2:
        printf("\nInsira um número para saber se ele é ímpar ou par:\nInsira: ");
        scanf("%d", &par_impar);
        par_impar = Par_Impar(par_impar);
        if (par_impar == 1)
        {
            system("cls");
            printf("\nO valor inserido é par.\n");
        }
        else
        {
            system("cls");
            printf("\nO valor inserido é ímpar.\n");
        }

        break;
    case 3:
        printf("\nInsira 2 números para saber o máximo divisor comum entre eles.\nInsira:\n ");
        scanf("%d %d", &x, &y);
        printf("\nO MDC é %d", divisor(x, y));
        break;
    case 4:
        printf("\nInsira dois números.\nInsira:\n ");
        scanf("%d %d", &fator1, &fator2);
        printf("\nO resultado da multiplição é: %d\n", multiplica(fator1, fator2));
        break;
    case 5:
        printf("Digite o n, n = quantidade total de elementos.\n");
        scanf("%d", &n);
        printf("Digite o p, p = partes dos elementos do conjunto.\n");
        scanf("%d", &p);
        combinacao = (float)fatorial(n) /  ( (float)fatorial(p) * (float)fatorial(n-p) ) ;
        printf("%f", combinacao);

        break;
    case 6:
        for(i = 0; i < 3; i++)
        {
            printf("Digite a quantidade de horas do carro %d:\n", i+1);
            scanf("%f", &horas[i]);
        }

        for(i = 0; i < 3; i++)
        {
            taxas[i] = calculataxa(horas[i]);
        }

        taxas[3] = taxas[0] + taxas[1] + taxas[2];
        horas[3] = horas[0] + horas[1] + horas[2];

        printf("Carro\tHoras\t          Taxas\n");
        printf("1\t%f\t%f\n", horas[0], taxas[0]);
        printf("2\t%f\t%f\n", horas[1], taxas[1]);
        printf("3\t%f\t%f\n", horas[2], taxas[2]);
        printf("Total\t%f\t%f\n", horas[3], taxas[3]);

        break;
    default:
        printf("Exercício inválido.\n");
        break;
    }

    return 0;
}