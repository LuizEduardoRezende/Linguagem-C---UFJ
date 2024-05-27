#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    int X = 0, Y = 0;
    int soma_pares = 0, mult_impar = 1;

    printf("Digite um X e um Y, sendo X menor que Y:\n");
    printf("X:\n");
    scanf("%d", &X);
    fflush(stdin);
    printf("Y:\n");
    scanf("%d", &Y);
    fflush(stdin);

    for(int i = X; i <= Y; i ++){
        if( i%2 == 0)
        {
            soma_pares += i;
        }
        else
        {
            mult_impar *= i;
        }
    }

    printf("Soma dos pares nesse intervalo: %d\n", soma_pares);
    printf("Multiplicacao dos impares nesse intervalo: %d\n", mult_impar);




    return 0;
}
