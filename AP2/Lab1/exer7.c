#include <stdio.h>
#include <stdlib.h>

int main()
{
    int notaC[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int nota = -2, curso = 0;
    int notaM[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    do
    {
        while (curso != 1 && curso != 2)
        {
            printf("Qual seu curso ? Digite 1 para computacao e 2 para matematica.\n");
            scanf("%d", &curso);
        }
        if (curso == 1)
        {
            while (nota != 0 && nota != 5 && nota != 10)
            {
                printf("Digite sua nota para a refeicao. 0-Pessimo  5-Regular  10-Excelente\n");
                scanf("%d", &nota);
                switch (nota)
                {
                case 0:
                    notaC[1]++;
                    break;
                case 5:
                    notaC[5]++;
                    break;
                case 10:
                    notaC[10]++;
                    break;
                default:
                    printf("Nota invalida.\n");
                    break;
                }
            }
        }
        else
        {
            while (nota != 0 && nota != 5 && nota != 10)
            {
                printf("Digite sua nota para a refeicao. 0-Pessimo  5-Regular  10-Excelente\n");
                scanf("%d", &nota);
                switch (nota)
                {
                case 0:
                    notaM[1]++;
                    break;
                case 5:
                    notaM[5]++;
                    break;
                case 10:
                    notaM[10]++;
                    break;
                default:
                    printf("Nota invalida.\n");
                    break;
                }
            }
        }
    } while (nota != -1);

    return 0;
}