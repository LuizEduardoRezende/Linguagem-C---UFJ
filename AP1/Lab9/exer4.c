#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, i, soma_mul3 = 0, resto_por3, resto_geral, validador_de_primo = 1, divisor = 2;
    float mult_primos = 1;
    
    printf("Digite um numero x e um y, nessa ordem, sendo x menor que y.\n");
    scanf("%d %d", &x, &y);
    i = x;

    for (i < y; i <= y; i++)
    {
        printf("\n%d", i); // todos números do intervalo entre x e y, incluido eles mesmos
        resto_por3 = i % 3;
        
        if(resto_por3 == 0)
        {
            soma_mul3 = soma_mul3 + i;
        }
        
        validador_de_primo = 1;
        divisor = 2;
        while (divisor < i)
        {
            resto_geral = i % divisor;
            if (resto_geral == 0)
            {
                validador_de_primo = 0;
            }
            divisor++;
        }

        if(validador_de_primo == 1)
        {
            mult_primos = mult_primos * i;
        }
    }


    printf("\nMultiplicacao dos numeros primos do intervalo entre x e y: %f\n", mult_primos);

    printf("Soma dos multiplos de 3 no intervalo entre x e y: %d\n", soma_mul3);

    if (x >= y) // saída caso a entrada seja inválida
    {
        printf("Entrada invalida, x deve ser menor que y.\n");
    }

    system("pause");
    return 0;
}