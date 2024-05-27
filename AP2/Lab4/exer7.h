#ifndef exer7_h
#define exer7_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int i = 0, n = 0;

typedef struct
{
    int matricula;
    float notas[3];
} Aluno;
Aluno Turma[5];

void LeAluno()
{
    setlocale(LC_ALL, "Portuguese");
    for (i = 0; i < 5; i++)
    {
        printf("Informe sua matrícula:\n");
        scanf("%d", &Turma[i].matricula);
        for (n = 0; n < 3; n++)
        {
            printf("Digite a nota %d: ", n + 1);
            scanf("%f", &Turma[i].notas[n]);
        }
    }
}

void ImprimeTurma()
{
    setlocale(LC_ALL, "Portuguese");
    for (i = 0; i < 5; i++)
    {
        printf("      \n\nTURMA %d:\n", i + 1);
        printf("Matrícula: %d\n", Turma[i].matricula);
        printf("Notas:\n%.2f\n%.2f\n%.2f", Turma[i].notas[0], Turma[i].notas[1], Turma[i].notas[2]);
    }
}

float CalculaMediaAluno()
{
    return (Turma[i].notas[0] + Turma[i].notas[1] + Turma[i].notas[2]) / 3;
}

void main_exer7()
{
    setlocale(LC_ALL, "Portuguese");
    float media = 0;
    for (i = 0; i < 5; i++)
    {
        LeAluno();
    }
    ImprimeTurma();

    for (i = 0; i < 5; i++)
    {
        media = CalculaMediaAluno();
        printf("\nAluno : %d - Média: %f\n", Turma[i].matricula, media);
    }
}
#endif