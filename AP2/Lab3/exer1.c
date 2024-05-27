#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct horario
    {
        float hora, minuto, segundo;
    } h;

    struct data
    {
        int dia, mes, ano;
        char mes_escrito[15];
    } d;

    struct agenda
    {
        char texto[50];
    } a;

    do
    {
        printf("Informe a hora.\n");
        scanf("%f", &h.hora);
        if (h.hora < 0 || h.hora >= 24)
        {
            printf("Hora invl�ida. Informe um valor v�lido.\n");
        }
    } while (h.hora < 0 || h.hora >= 24);
    printf("\n");

    do
    {
        printf("Informe os minutos.\n");
        scanf("%f", &h.minuto);
        if (h.minuto < 0 || h.minuto >= 60)
        {
            printf("Minutos invl�idos. Informe um valor v�lido.\n");
        }
    } while (h.minuto < 0 || h.minuto >= 60);
    printf("\n");

    do
    {
        printf("Informe os segundos.\n");
        scanf("%f", &h.segundo);
        if (h.segundo < 0 || h.segundo >= 60)
        {
            printf("Segundos invl�idos. Informe um valor v�lido.\n");
        }
    } while (h.segundo < 0 || h.segundo >= 60);
    printf("\n");

    do
    {
        printf("Informe o dia.\n");
        scanf("%d", &d.dia);
        if (d.dia <= 0 || d.dia > 31)
        {
            printf("Dia invl�ido. Informe um valor v�lido.\n");
        }
    } while (d.dia <= 0 || d.dia > 31);

    do
    {
        printf("Informe o m�s (de 1 at� 12).\n");
        scanf("%d", &d.mes);
        if (d.mes <= 0 || d.mes > 12)
        {
            printf("M�s invl�ido. Informe um valor v�lido.\n");
        }
    } while (d.mes <= 0 || d.mes > 12);

    switch (d.mes)
    {
    case 1:
        strcpy(d.mes_escrito,"Janeiro");
        break;
    case 2:
        strcpy(d.mes_escrito,"Fevereiro");
        break;
    case 3:
        strcpy(d.mes_escrito,"Mar�o");
        break;
    case 4:
        strcpy(d.mes_escrito,"Abril");
        break;
    case 5:
        strcpy(d.mes_escrito,"Maio");
        break;
    case 6:
        strcpy(d.mes_escrito,"Junho");
        break;
    case 7:
        strcpy(d.mes_escrito,"Julho");
        break;
    case 8:
        strcpy(d.mes_escrito,"Agosto");
        break;
    case 9:
        strcpy(d.mes_escrito,"Setembro");
        break;
    case 10:
        strcpy(d.mes_escrito,"Outubro");
        break;
    case 11:
        strcpy(d.mes_escrito,"Novembro");
        break;
    case 12:
        strcpy(d.mes_escrito,"Dezembro");
        break;
    default:
        break;
    }

    do
    {
        printf("Informe o ano.\n");
        scanf("%d", &d.ano);
        if (d.ano < 0)
        {
            printf("Ano invl�ido. Informe um valor v�lido.\n");
        }
    } while (d.ano < 0);

    printf("Digite seu texo para anota��o.\n");
    fflush(stdin);
    fgets(a.texto, sizeof(a.texto), stdin);
    fflush(stdin);

    printf("O hor�rio �: %.2f horas, %.2f minutos, %.2f segundos.\n", h.hora, h.minuto, h.segundo);
    printf("A data �: Dia %d de %s de %d .\n", d.dia, d.mes_escrito, d.ano);
    printf("Sua anota��o �: %s .", a.texto);

    return 0;
}