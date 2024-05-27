#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, divisor = 2, resto, validador = 1;
    printf("Digite um valor positivo para verificar se ele eh primo.\n");
    scanf("%d", &num);
    while (divisor < num)
    {
        resto = num % divisor;
        if (resto == 0)
            validador = 0;
        divisor++;
    }

    if (validador == 1)
        printf("O numero %d eh primo.\n", num);
    else
        printf("O numero %d nao eh primo.\n", num);

    system("pause");
    return 0;
}