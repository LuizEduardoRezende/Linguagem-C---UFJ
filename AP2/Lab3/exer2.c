#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct aluno
{
    char nome[20], curso[20];
    int matricula;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct aluno alunos[5];
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("Informe o nome do aluno.\n");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        fflush(stdin);
        printf("Informe o número de matrícula.\n");
        scanf("%d", &alunos[i].matricula);
        fflush(stdin);
        printf("Informe o nome do curso.\n");
        fgets(alunos[i].curso, sizeof(alunos[i].curso), stdin);
        fflush(stdin);
    }

    for (i = 0; i < 5; i++)
    {
        printf("\n");
        printf("Nome: %s", alunos[i].nome);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Curso: %s\n", alunos[i].curso);
    }

    return 0;
}