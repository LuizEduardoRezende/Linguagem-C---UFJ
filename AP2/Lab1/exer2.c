#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 0;
    int dezena = 0;

    printf("Digite um numero com mais de duas casas decimais para que a dezena seja selecionada.\n");
    scanf("%d", &numero);

    if (numero > 100)
    {
        while (numero >= 100)
        {
            numero = numero / 10;
        }
        dezena = numero % 10;
        printf("Dezena do numero : %d", dezena);
    }
    else
    {
        if(numero < 10)
        {
            printf("Numero digitado menor que 10.\n");
        }
        else
        {
            dezena = numero % 10;
            printf("Dezena do numero : %d", dezena);
        }
    }

    return 0;
}