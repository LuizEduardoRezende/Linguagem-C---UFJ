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
            printf("Hora invláida. Informe um valor válido.\n");
        }
    } while (h.hora < 0 || h.hora >= 24);
    printf("\n");

    do
    {
        printf("Informe os minutos.\n");
        scanf("%f", &h.minuto);
        if (h.minuto < 0 || h.minuto >= 60)
        {
            printf("Minutos invláidos. Informe um valor válido.\n");
        }
    } while (h.minuto < 0 || h.minuto >= 60);
    printf("\n");

    do
    {
        printf("Informe os segundos.\n");
        scanf("%f", &h.segundo);
        if (h.segundo < 0 || h.segundo >= 60)
        {
            printf("Segundos invláidos. Informe um valor válido.\n");
        }
    } while (h.segundo < 0 || h.segundo >= 60);
    printf("\n");

    do
    {
        printf("Informe o dia.\n");
        scanf("%d", &d.dia);
        if (d.dia <= 0 || d.dia > 31)
        {
            printf("Dia invláido. Informe um valor válido.\n");
        }
    } while (d.dia <= 0 || d.dia > 31);

    do
    {
        printf("Informe o mês (de 1 até 12).\n");
        scanf("%d", &d.mes);
        if (d.mes <= 0 || d.mes > 12)
        {
            printf("Mês invláido. Informe um valor válido.\n");
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
        strcpy(d.mes_escrito,"Março");
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
            printf("Ano invláido. Informe um valor válido.\n");
        }
    } while (d.ano < 0);

    printf("Digite seu texo para anotação.\n");
    fflush(stdin);
    fgets(a.texto, sizeof(a.texto), stdin);
    fflush(stdin);

    printf("O horário é: %.2f horas, %.2f minutos, %.2f segundos.\n", h.hora, h.minuto, h.segundo);
    printf("A data é: Dia %d de %s de %d .\n", d.dia, d.mes_escrito, d.ano);
    printf("Sua anotação é: %s .", a.texto);

    return 0;
}