#include <stdio.h>
#include <stdlib.h>

int main(){

    float num = 1, menor= 3.4E+38, maior, soma;
    printf("Digite quantos valores positivos desejar, para encerrar digite 0 ou um valor negativo.\n");

    while (num > 0)
    {
        scanf("%f", &num);
        if (num > 0)
        {
            if (num < menor)
            {
                menor = num;
            }

            if (num > maior)
            {
                maior = num;
            }

            soma = soma + num;
        }
        else
        printf("Programa encerrado.\n");
    }

    printf("Maior: %f\nMenor: %f\nSoma: %f\n", maior, menor, soma);

    system("pause");
    return 0;
}
