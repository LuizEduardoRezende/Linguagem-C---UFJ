#include <stdio.h>
#include <stdlib.h>

int main()
{
    float lado1 = 0, lado2 = 0, lado3 = 0;
    int i = 0;

    printf("Digite 3 lados de um triangulo para serem analisados.\n");

    while (lado1 <= 0 || lado2 <= 0 || lado3 <= 0)
    {
        printf("Digite apenas valores positivos.\n");

        printf("Digite o lado 1: \n");
        scanf("%f", &lado1);

        printf("Digite o lado 2: \n");
        scanf("%f", &lado2);

        printf("Digite o lado 3: \n");
        scanf("%f", &lado3);
    }

    if (lado1 + lado2 > lado3 && lado2 + lado3 > lado1 && lado3 + lado1 > lado2)
    {
        printf("Esses valores podem formar um trinagulo.\n");
    }
    else
    {
        printf("Esses valores nao podem formar um triangulo.\n");
    }

    if (lado1 == lado2)
    {
        if (lado1 == lado3)
        {
            printf("E um triangulo equilatero.\n");
        }
        else
        {
            printf("E um triangulo isosceles.\n");
        }
    }
    else
    {
        if (lado1 == lado3)
        {
            printf("E um triangulo isosceles.\n");
        }
        else
        {
            if (lado2 == lado3)
            {
                printf("E um triangulo isosceles.\n");
            }
            else
            {
                printf("E um triangulo escaleno.\n");
            }
        }
    }

    return 0;
}