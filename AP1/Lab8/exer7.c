#include <stdio.h>
#include <stdlib.h>

int main()
{
    float aux, altura, idade, soma_altura, quant_50anos, media;
    do
    {
        printf("Digite a altura em metros e idade em anos, respectivamente.\n");
        scanf("%f %f", &altura, &idade);
        if (idade >= 50)
        {
            soma_altura = soma_altura + altura;
            quant_50anos++;
        }

        aux++;
    } while (aux < 6);

    media = soma_altura / quant_50anos;
    printf("A media das alturas das pessoas com mais de 50 anos e: %.2f\n", media);

    system("pause");
    return 0;
}