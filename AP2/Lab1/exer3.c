#include <stdio.h>
#include <stdlib.h>

int main()
{
    float celsius = 0, kelvin = 0, fh = 0;
    int escolha = 10;

    printf("Digite uma temperatura em Graus Celsius.\n");
    scanf("%f", &celsius);

    while(escolha != 0)
    {
        printf("Digite 1 para receber a temperatura em kelvin, 2 para receber em Fahrenheit ou 0 para encerrar o menu.\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 0:

            printf("Menu encerrado.\n");
            break;
            case 1:

            kelvin = celsius + 273.15;
            printf("Temperatura em Kelvin : %.2f\n", kelvin);
            break;

            case 2:

            fh = (celsius * 1.8) + 32;
            printf("Temperatura em Graus Fahrenheit: %.2f\n", fh);
            break;

            default:
            printf("Opcao inválida.\n");
            break;
        }
    }

    return 0;
}