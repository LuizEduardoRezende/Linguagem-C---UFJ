#include <stdio.h>
#include <stdlib.h>

int main()
{
    char mesmaior, mesmenor;
    int mes[13], i, maior = 0, menor = 9e+10, d = 0, e = 0;

    for (i = 0; i < 12; i++)
    {
        printf("Digite o valor para a media do mes %d.\n", i + 1);
        scanf("%d", &mes[i]);
        if (maior < mes[i])
        {
            maior = mes[i];
            d = i + 1;
        }
        if (menor > mes[i])
        {
            menor = mes[i];
            e = i + 1;
        }
    }

    switch (d)
    {
    case 1:
        printf("A maior temperatura foi %d graus em Janeiro.\n", maior);
        break;
    case 2:
        printf("A maior temperatura foi %d graus em Fevereiro.\n", maior);
        break;
    case 3:
        printf("A maior temperatura foi %d graus em Março.\n", maior);
        break;
    case 4:
        printf("A maior temperatura foi %d graus em Abril.\n", maior);
        break;
    case 5:
        printf("A maior temperatura foi %d graus em Maio.\n", maior);
        break;
    case 6:
        printf("A maior temperatura foi %d graus em Junho.\n", maior);
        break;
    case 7:
        printf("A maior temperatura foi %d graus em Julho.\n", maior);
        break;
    case 8:
        printf("A maior temperatura foi %d graus em Agosto.\n", maior);
        break;
    case 9:
        printf("A maior temperatura foi %d graus em Setembro\n", maior);
        break;
    case 10:
        printf("A maior temperatura foi %d graus em Outubro.\n", maior);
        break;
    case 11:
        printf("A maior temperatura foi %d graus em Novembro.\n", maior);
        break;
    case 12:
        printf("A maior temperatura foi %d graus em Dezembro.\n", maior);
        break;
    }

    switch (e)
    {
    case 1:
        printf("A menor temperatura foi %d graus em Janeiro.\n", menor);
        break;
    case 2:
        printf("A menor temperatura foi %d graus em Fevereiro.\n", menor);
        break;
    case 3:
        printf("A menor temperatura foi %d graus em Março.\n", menor);
        break;
    case 4:
        printf("A menor temperatura foi %d graus em Abril.\n", menor);
        break;
    case 5:
        printf("A menor temperatura foi %d graus em Maio.\n", menor);
        break;
    case 6:
        printf("A menor temperatura foi %d graus em Junho.\n", menor);
        break;
    case 7:
        printf("A menor temperatura foi %d graus em Julho.\n", menor);
        break;
    case 8:
        printf("A menor temperatura foi %d graus em Agosto.\n", menor);
        break;
    case 9:
        printf("A menor temperatura foi %d graus em Setembro.\n", menor);
        break;
    case 10:
        printf("A menor temperatura foi %d graus em Outubro.\n", menor);
        break;
    case 11:
        printf("A menor temperatura foi %d graus em Novembro.\n", menor);
        break;
    case 12:
        printf("A menor temperatura foi %d graus em Dezembro.\n", menor);
        break;
    }

    return 0;
}