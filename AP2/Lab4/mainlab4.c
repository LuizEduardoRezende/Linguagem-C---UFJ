#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "exer2.h"
#include "exer3.h"
#include "exer4.h"
#include "exer5.h"
#include "exer6.h"
#include "exer7.h"

int main()
{
    int exer = -1;
    setlocale(LC_ALL, "Portuguese");

    do
    {
        printf("Digite o n�mero do exerc�cio para visualizar. Digite 0 para finzalizar o menu.\n");
        scanf("%d", &exer);
        switch (exer)
        {
        case 0:
            printf("Menu encerrado.\n");
            break;

        case 2: // exerc�cio 2
            posi_nega();
            break;

        case 3: // exerc�cio 3
            calculadora();
            break;

        case 4: // exerc�cio 4
            fatorial();
            break;

        case 5:
            preco();
            break;

        case 6:
            medias();
            break;

        case 7:
            main_exer7();
            break;

        default:
            printf("Exerc�cio inv�lido. Digite um exerc�cio v�lido.");
            break;
        }
    } while (exer != 0);

    return 0;
}