#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quant_primo = 0, num = 0, aux = 0, resto, divisor = 2, validador = 1;

    do
    {
        printf("Digite um numero para verificar se ele e primo.\n");
        scanf("%d", &num);
        divisor = 2;

        while (divisor < num)
        {
            resto = num % divisor;
            if (resto == 0)
            {
                validador = 0;
            }
            divisor++;
        }

        if (validador == 1)
        {
            quant_primo++;
        }

        validador = 1;
        aux++;
    } while (aux < 5);

    printf("Quantidade de numeros primos digitados: %d \n", quant_primo);

    system("pause");
    return 0;
}