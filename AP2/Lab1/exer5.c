#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salario = 0, imposto = 0;

    printf("Digite o salario com duas casas depois da virgula.\n");
    scanf("%f", &salario);

    if (salario <= 2000)
    {
        imposto = 0;
    }
    else
    {
        if (salario <= 3000)
        {
            salario = salario - 2000;
            imposto = salario * 0.08;
        }

        if (salario > 3000 && salario <= 4500)
        {
            salario = salario - 3000;
            imposto = 80 + (salario * 0.18);
        }

        if (salario > 4500)
        {
            salario = salario - 4500;
            imposto = 80 + 270 + (salario * 0.28);
        }
    }

    if (imposto > 0)
    {
        printf("O imposto para esse salario e de: %.2f RS .\n", imposto);
    }
    else
    {
        printf("Imposto insento.\n");
    }

    return 0;
}