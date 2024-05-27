#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i = 0, aluno_maiornotap1 = 0, aluno_maiormedia = 0, aluno_menormedia = 0;
    float maior_notap1 = 0, maior_media = 0, menor_media = 100000;
    struct alunos
    {
        int matricula;
        float p1, p2, p3, media;
        char nome[30];
    } aluno[5];

    for (i = 0; i < 5; i++)
    {
        printf("Informe seu nome:\n");
        scanf("%[^\n]", aluno[i].nome);
        fflush(stdin);
        printf("Informe sua matrícula:\n");
        scanf("%d", &aluno[i].matricula);
        fflush(stdin);
        printf("Informe sua nota na prova 1:\n");
        scanf("%f", &aluno[i].p1);
        fflush(stdin);
        printf("Informe sua nota na prova 2:\n");
        scanf("%f", &aluno[i].p2);
        fflush(stdin);
        printf("Informe sua nota na prova 3:\n");
        scanf("%f", &aluno[i].p3);
        fflush(stdin);

        // cálculo da média e identificador da menor e maior média geral.
        aluno[i].media = (aluno[i].p1 + aluno[i].p2 + aluno[i].p3) / 3;
        if (aluno[i].media > maior_media)
        {
            maior_media = aluno[i].media;
            aluno_maiormedia = i;
        }
        if (aluno[i].media < menor_media)
        {
            menor_media = aluno[i].media;
            aluno_menormedia = i;
        }

        // identificar o aluno com maior nota na p1
        if (aluno[i].p1 > maior_notap1)
        {
            maior_notap1 = aluno[i].p1;
            aluno_maiornotap1 = i;
        }

        if (aluno[i].media >= 6.0)
            printf("Parabéns %s você foi aprovado, sua média foi %.2f\n", aluno[i].nome, aluno[i].media);
        else
            printf("%s você foi reprovado, sua média foi %.2f\n", aluno[i].nome, aluno[i].media);

        printf("Pressione qualquer tecla para proseguir para o proximo aluno.\n");
        system("pause");
        system("cls");
    }

    printf("O aluno com maior nota na prova 1 foi %s.\n", aluno[aluno_maiornotap1].nome);
    printf("O aluno com maior média geral foi %s.\n", aluno[aluno_maiormedia].nome);
    printf("O aluno com menor média geral foi %s.\n", aluno[aluno_menormedia].nome);

    return 0;
}